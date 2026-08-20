# 🎬 Ejemplo — Escena Básica

Este ejemplo muestra la estructura mínima necesaria para crear una escena funcional.

---

# 📁 Estructura

```text id="j8r4x0"
games/mygame/scenes/
├── game_scene.c
└── game_scene.h
```

---

# 📦 Header

```c id="e8v5z1"
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "../../../engine/scene.h"

extern Scene gameScene;

#endif
```

---

# ⚙️ Implementación

```c id="r0m8d2"
#include "game_scene.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"

void game_init();
void game_update();
void game_render();
void game_destroy();

Scene gameScene = {
    game_init,
    game_update,
    game_render,
    game_destroy
};
```

---

# 🚀 init()

```c id="v4n7s3"
void game_init() {

}
```

Aquí normalmente:

* cargas mapas,
* inicializas entidades,
* reservas memoria.

---

# 🔁 update()

```c id="x2k5m1"
void game_update() {

}
```

Aquí:

* lees input,
* actualizas lógica,
* manejas colisiones.

---

# 🎨 render()

```c id="q1t9w4"
void game_render() {

    renderer_draw_text(
        5,
        5,
        "HELLO WORLD"
    );
}
```

Resultado:

```text id="6o2q4y"
HELLO WORLD
```

---

# 🧹 destroy()

```c id="f3m6k7"
void game_destroy() {

}
```

Aquí:

* liberas memoria,
* destruyes mapas,
* limpias recursos.

---

# 🎮 Flujo completo

```text id="m7t0p1"
engine_set_scene()
        ↓
init()

update()
render()

update()
render()

update()
render()

destroy()
```

---

# 🚀 Usar escena

En `main.c`:

```c id="w9r4y2"
engine_set_scene(&gameScene);
```

---

# ⚠️ Error común

Poner render dentro de update.

❌ Incorrecto:

```c id="y5x8v0"
void update() {
    renderer_draw_text(...);
}
```

---

# ✅ Correcto

```text id="g7q2p5"
update() -> lógica
render() -> dibujo
```

---

# 🎨 Expandir escena

Después puedes agregar:

✅ Jugador
✅ Tilemaps
✅ Enemigos
✅ UI
✅ Colisiones
✅ Audio
✅ IA

---

# 🧠 Filosofía

Las escenas permiten:

✅ Separación
✅ Organización
✅ Escalabilidad
✅ Reutilización

Son una de las bases más importantes de cualquier engine.
