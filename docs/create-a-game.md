# 🎮 Crear un juego nuevo — Guía rápida

Esta guía explica cómo crear un juego funcional desde cero usando el **ASCII Dungeon Engine**.

La idea es empezar con lo mínimo:

- `main.c`
- una escena principal (`.c` + `.h`)
- `maps/` solamente si el juego necesita un mapa

No necesitas crear `entities/`, `systems/` ni otras carpetas hasta que realmente las necesites.

---

## 1. Crear la carpeta del juego

Dentro de `games/`, crea una carpeta con el nombre de tu juego.

Por ejemplo:

```text
games/
└── miJuego/
```

Dentro crea:

```text
games/
└── miJuego/
    ├── main.c
    └── scenes/
        ├── juego.c
        └── juego.h
```

Si tu juego utilizará un mapa, agrega:

```text
games/
└── miJuego/
    ├── main.c
    ├── maps/
    │   └── level1.txt
    └── scenes/
        ├── juego.c
        └── juego.h
```

---

# 2. Crear `main.c`

Copia esta estructura:

```c
#include "../../engine/engine.h"
#include "scenes/juego.h"

int main() {

    EngineConfig config = {
        30,
        16
    };

    engine_init(config);

    engine_set_scene(&juego);

    engine_run();

    engine_shutdown();

    return 0;
}
```

### ¿Qué hace?

En orden:

```text
engine_init()
      ↓
carga la escena inicial
      ↓
engine_run()
      ↓
ejecuta el juego
      ↓
engine_shutdown()
```

⚠️ La línea más importante es:

```c
engine_set_scene(&juego);
```

Sin ella, el engine no tiene ninguna escena que actualizar ni dibujar.

---

# 3. Crear `juego.h`

En:

```text
games/miJuego/scenes/juego.h
```

coloca:

```c
#ifndef JUEGO_H
#define JUEGO_H

#include "../../../engine/scene.h"

extern Scene juego;

#endif
```

Este archivo permite que `main.c` conozca la escena `juego`.

---

# 4. Crear `juego.c`

En:

```text
games/miJuego/scenes/juego.c
```

coloca:

```c
#include "juego.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"
#include "../../../engine/engine.h"

void juego_init();
void juego_update();
void juego_render();
void juego_destroy();

Scene juego = {
    juego_init,
    juego_update,
    juego_render,
    juego_destroy
};

void juego_init() {
    // Configuración inicial
}

void juego_update() {
    // Lógica del juego

    if(key_down(KEY_ESCAPE)) {
        engine_stop();
    }
}

void juego_render() {
    renderer_draw_text(2, 2, "MI JUEGO");
    renderer_draw_text(2, 4, "Hola mundo!");
}

void juego_destroy() {
    // Liberar recursos
}
```

Con esto ya tienes un juego funcional.

Al ejecutarlo deberías ver algo parecido a:

```text
  MI JUEGO

  Hola mundo!
```

Y `ESC` debe cerrar el juego.

---

# 5. Si necesitas un mapa

Solo crea la carpeta:

```text
games/miJuego/maps/
```

y dentro, por ejemplo:

```text
level1.txt
```

Un mapa mínimo puede ser:

```text
##############################
#                            #
#                            #
#                            #
#                            #
#                            #
##############################
```

`#` representa una pared y los espacios representan zonas caminables.

Los mapas se cargan desde una escena:

```c
TileMap map;

void juego_init() {
    map = tilemap_load("games/miJuego/maps/level1.txt");
}
```

Para dibujarlo:

```c
void juego_render() {
    renderer_draw_map(&map);
}
```

Y cuando la escena termine:

```c
void juego_destroy() {
    tilemap_destroy(&map);
}
```

Por lo tanto, el flujo de un mapa es:

```text
init()
  ↓
cargar mapa

render()
  ↓
dibujar mapa

destroy()
  ↓
liberar mapa
```

⚠️ No cargues el mapa dentro de `render()`. `render()` se ejecuta muchas veces.

---

# 6. Compilar el juego

Cada juego debe tener su propio comando de compilación.

Para `miJuego`:

```bash
gcc engine/*.c games/*.c games/miJuego/scenes/*.c games/miJuego/*.c -o miJuego.exe
```

Después:

```bash
miJuego.exe
```

Puedes agregar este comando a `build.bat` si quieres compilarlo fácilmente.

Por ejemplo:

```bat
gcc engine/*.c games/*.c games/miJuego/scenes/*.c games/miJuego/*.c -o miJuego.exe

miJuego.exe
```

---

# 7. Estructura mínima final

Sin mapa:

```text
games/
└── miJuego/
    ├── main.c
    └── scenes/
        ├── juego.c
        └── juego.h
```

Con mapa:

```text
games/
└── miJuego/
    ├── main.c
    ├── maps/
    │   └── level1.txt
    └── scenes/
        ├── juego.c
        └── juego.h
```

Eso es todo lo necesario para comenzar.

Después puedes agregar:

```text
entities/
systems/
```

solamente cuando el juego realmente los necesite.