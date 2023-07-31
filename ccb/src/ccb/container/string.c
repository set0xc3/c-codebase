#include "ccb/container/string.h"

CString
str_replace(CMemoryArena *arena, const CString replace, const CString a,
            const CString b)
{
    LOG_DEBUG("replace.size: %d\n", replace.size);
    LOG_DEBUG("a.size: %d\n", a.size);
    LOG_DEBUG("b.size: %d\n", b.size);

    CString fixed = { 0 };

    if (a.size > b.size)
    {
        str_copy(arena, &fixed, &replace);
    }
    else
    {
        CString src = replace;
        src.size    = replace.size + b.size - a.size;
        str_copy(arena, &fixed, &src);
    }

    LOG_DEBUG("fixed.size: %d\n", fixed.size);

    {
        u32 find_count = 0;
        for (u32 i = 0; i < fixed.size; i++)
        {
            for (u32 j = 0; j < a.size; j++)
            {
                if (fixed.data[i + j] == a.data[j])
                {
                    find_count++;
                    if (find_count == a.size)
                    {
                        // memmove(&fixed.str[i + j],
                        //         &fixed.str[i + b.size - a.size],
                        //         i + b.size - a.size);
                        // memcpy(&fixed.str[i], b.str, b.size);
                        LOG_DEBUG("Finded: %s\n", &fixed.data[i + j]);
                        break;
                    }
                }
                else
                {
                    find_count = 0;
                }
            }
        }
    }

    LOG_DEBUG("%s\n", fixed.data);
    return fixed;
}

CString
str_path_fix(CMemoryArena *arena, const CString path)
{
    LOG_DEBUG("path: %s\n", path.data);

    if (path.size <= 3)
    {
        return path;
    }

    CString fixed;
    str_copy(arena, &fixed, &path);

    // fix - \\
    // fix - /./
    // fix - ../
    for (u32 i = 0; i < fixed.size; i++)
    {
        if (fixed.data[i] == '\\')
        {
            fixed.data[i] = '/';
        }
    }

    u32 pos        = 0;
    u32 fixed_size = 0;
    for (u32 i = 0; i < fixed.size; i++)
    {
        if (fixed.data[i] == '.' && fixed.data[i + 1] == '.'
            && fixed.data[i + 2] == '/')
        {
            u32 last_count = 0;
            for (u32 j = 0; j < pos; j++)
            {
                if (fixed.data[i - j] == '/')
                {
                    last_count++;
                    if (last_count == 2)
                    {
                        last_count = 0;
                        LOG_DEBUG("%s\n", &fixed.data[i - j]);
                        memcpy(&fixed.data[i - j], &fixed.data[i + 2],
                               strlen(&fixed.data[i + 2]));
                        fixed_size = i + 2;
                        break;
                    }
                }
            }

            // LOG_DEBUG("%s\n", &fixed.data[i]);
            // LOG_DEBUG("%s\n", &fixed.data[i + 3]);
        }
        pos++;
    }
    // fixed.data[fixed_size] = '\0';

    LOG_DEBUG("fixed: %s\n", fixed.data);
    return fixed;
}
