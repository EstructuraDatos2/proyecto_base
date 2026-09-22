#include "../../engine/engine.h" // Imporamos el engine para que se ejecute
#include "scenes/juego.h" // Importamos la escena principal, de aqui se movera a otras escenas.

int main() {
    EngineConfig screenConfig = {
        20,
        25
    };
    
    // INIT: Configuracion inicial de pantalla
    engine_init(screenConfig);

    // SET_SCENE: Escena inicial del juego
    engine_set_scene(&juego1);

    // RUN: Ejecuta el loop principal
    engine_run();

    // SHUTDOWN: Realiza limpieza, libera memoria y recursos utilizados
    engine_shutdown();

    return 0;
}