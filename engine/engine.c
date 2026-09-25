#include <stdio.h>
#include "engine.h"
#include "input.h"
#include "renderer.h"
#include "timer.h"

static int running = 1;
static Scene* currentScene = NULL;

void engine_init(EngineConfig config) {
    renderer_init(&config.width, &config.height);
    timer_init();
}

void engine_run() {
    while(running) {
        input_update(); // Leer teclado
        engine_update(); // Actualizar lógica
        renderer_clear(); // Limpiar framebuffer
        engine_render(); // Dibujar escena actual
        renderer_present(); // Mostrar framebuffer en consola
        timer_update(); // control FPS/ticks
    }
}

void engine_stop() {
    running = 0;
}

void engine_shutdown() {
    renderer_shutdown();
}

void engine_set_scene(Scene *scene) {
    currentScene = scene;

    if (currentScene->init != NULL) {
        currentScene->init();
    }
}

void engine_update() {
    if (currentScene != NULL && currentScene->update != NULL) {
        currentScene->update();
    }
}

void engine_render() {
    if (currentScene != NULL && currentScene->render != NULL) {
        currentScene->render();
    }
}