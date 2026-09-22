#include "juego.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"
#include "../../../engine/engine.h"

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
}

void juego1_update() {
    // Logica de juego
    if(key_down(KEY_ESCAPE)) {
        juego1_destroy();
    }
}

void juego1_render() {
    renderer_set_viewport(1, 3);
    renderer_draw_text(1, 1, "LIGHTS OUT");
    renderer_draw_text(1, 21, "Tiempo: 10:08");
}

void juego1_destroy() {
    // Eliminar elementos creados
    engine_stop();
}