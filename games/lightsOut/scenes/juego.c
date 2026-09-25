#include "juego.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"
#include "../../../engine/engine.h"
#include "../../../engine/timer.h"

// #include "../../tilemap.h"
// #include "../../entity.h"

// PROTOTIPOS
void juego1_init();
void juego1_update();
void juego1_render();
void juego1_destroy();

Scene juego1 = {
    juego1_init,
    juego1_update,
    juego1_render,
    juego1_destroy
};

void juego1_init() {
    // Configuraciones
    timer_reset();
}

void juego1_update() {
    // Logica de juego
    if(key_down(KEY_ESCAPE)) {
        engine_stop();
    }
}

void juego1_render() {
    renderer_set_viewport(2, 5);

    // Título
    renderer_draw_text(3, 1, "==================");
    renderer_draw_text(7, 2, "LIGHTS OUT");
    renderer_draw_text(3, 3, "==================");

    // Tablero
    // TODO Dibujar mapas

    // Información
    renderer_draw_text(1, 18, timer_get_time());
    renderer_draw_text(1, 19, "Objetivo: Apagar todas");
    renderer_draw_text(11, 20, "las luces");
    renderer_draw_text(1, 21, "ESC - Salir");
}

void juego1_destroy() {
    // Eliminar elementos creados
}