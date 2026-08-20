#ifndef SCENE_H
#define SCENE_H

typedef struct {
    void (*init)();
    void (*update)();
    void (*render)();
    void (*destroy)();

} Scene;

#endif