#include "forge/input/input.h"

struct InputState
{
    b32 last_key[KEY_CODE_COUNT];
    b32 key[KEY_CODE_COUNT];

    b32 last_button[MOUSE_BUTTON_COUNT];
    b32 button[MOUSE_BUTTON_COUNT];

    V2F position;
    V2F wheel;
};
