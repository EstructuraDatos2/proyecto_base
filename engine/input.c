#include <windows.h>
#include "input.h"

static short keys[256];

void input_update() {

    keys[KEY_W] = GetAsyncKeyState('W');
    keys[KEY_A] = GetAsyncKeyState('A');
    keys[KEY_S] = GetAsyncKeyState('S');
    keys[KEY_D] = GetAsyncKeyState('D');

    keys[KEY_ESCAPE] = GetAsyncKeyState(VK_ESCAPE);
}

int key_down(int key) {

    return keys[key];
}