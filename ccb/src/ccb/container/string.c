#include "ccb/container/string.h"

CString
str_lit(const char *c)
{
    CString result;
    result.data = (char *)c;
    result.size = strlen(c);
    return result;
}

CString
str_alloc(CMemoryArena *arena, const u64 size)
{
    CString result_str;
    result_str.data = PushArrayZero(arena, char, size);
    result_str.size = size;
    return result_str;
}

b8
str_eq(const CString left, const CString right)
{
    b8 result = !strcmp(left.data, right.data);
    return result;
}

CString
str_concast(CMemoryArena *arena, const CString *a, const CString *b)
{
    CString result = str_alloc(arena, a->size + b->size);
    MemoryCopyArray(result.data, a->data, char, a->size);
    MemoryCopyArray(result.data + a->size, b->data, char, b->size);
    result.data[result.size] = '\0';
    return result;
}

CString
str_prefix(const CString *str, const u64 size)
{
    CString result;
    result.data = str->data;
    result.size = ClampTop(size, str->size);
    return result;
}

u32
str_find_all(const CString *str, const char find)
{
    u32 result = 0;
    u64 pos    = str->size;

    for (u64 i = 0; i < pos; i++)
    {
        if (str->data[i] == find)
        {
            result++;
        }
    }

    return result;
}

CString
str_find_first(const CString *str, const char find, const u64 offset)
{
    CString result;
    result.data = strchr(str->data, find);
    result.size = strlen(result.data);
    return result;
}

CString
str_find_last(const CString *str, const char find, const u64 offset)
{
    CString result = *str;
    u64     pos    = str->size;
    for (u64 i = 0; i < offset + 1; i++)
    {
        for (u64 j = 0; j < pos; j++)
        {
            if (str->data[Clamp(pos - j - i, 0, str->size)] == find)
            {
                pos         = Clamp(pos - j - i, 0, str->size);
                result.data = str->data + pos + 1;
                result.size = str->size - pos - 1;
                break;
            }
            else if (!Clamp(pos - j - i, 0, str->size) && str->data[j] == find)
            {
                result.data = str->data + 1;
                result.size = str->size - 1;
                break;
            }
            else if (!Clamp(pos - j - i, 0, str->size))
            {
                result = *str;
                break;
            }
        }
    }
    return result;
}
