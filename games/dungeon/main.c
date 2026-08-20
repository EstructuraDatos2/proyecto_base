#include "../../engine/engine.h" // Imporamos el engine para que se ejecute
#include "scenes/level1_scene.h" // Importamos la escena principal, de aqui se movera a otras escenas.

int main() {
    EngineConfig screenConfig = {
        30,
        16
    };
    
    // INIT: Configuracion inicial de pantalla
    engine_init(screenConfig);

    // SET_SCENE: Escena inicial del juego
    engine_set_scene(&level1Scene);

    // RUN: Ejecuta el loop principal
    engine_run();

    // SHUTDOWN: Realiza limpieza, libera memoria y recursos utilizados
    engine_shutdown();

    return 0;
}