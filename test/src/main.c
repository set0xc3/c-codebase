#include <base/defines.h>
#include <core/logger.h>
#include <math/matrix.h>
#include <math/vector.h>
#include <memory/arena.h>
#include <os/os.h>

#include "test/window.c"

int
main(int argc, char *argv[])
{
    LOG_INFO("Test:\n");

    CVector3 vec0 = vec3_init(4, 4, 4);
    CMatrix4 mat0 = mat4_identity();
    CMatrix4 mat1 = mat4_identity();
    CMatrix4 mat2 = mat4_mul(mat0, mat1);
    CVector3 vec1 = mat4_mul_vec3(mat0, vec0);

    CWindow *window = MemoryAllocStruct(CWindow);
    MemoryZeroStruct(window, CWindow);

    os_startup();

    test_window_open(window);
    test_window_close(window);

    os_shutdown();

    MemoryFree(window);

    return 0;
}
