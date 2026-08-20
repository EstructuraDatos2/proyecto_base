#ifndef ENGINE_H
#define ENGINE_H

#include "scene.h"

typedef struct {
    int width;
    int height;
} EngineConfig;

void engine_init(EngineConfig config);
void engine_run();
void engine_stop();
void engine_shutdown();

void engine_set_scene(Scene* scene);
void engine_update();
void engine_render();

#endif