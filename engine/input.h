#ifndef INPUT_H
#define INPUT_H

enum {
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D,
    KEY_ESCAPE
};

void input_update();

int key_down(int key);

#endif