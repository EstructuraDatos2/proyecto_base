# 🎬 Escenas

Las escenas son el corazón del engine.

Cada pantalla del juego debe ser una escena independiente.

---

# 🧠 ¿Qué es una escena?

Una escena representa un estado del juego.

Ejemplos:

* Menú principal
* Nivel 1
* Nivel 2
* Pantalla de pausa
* Game Over

---

# 📦 Estructura básica

Cada escena necesita:

```c
void init();
void update();
void render();
void destroy();
```

---

# 🔨 Ejemplo completo

```c
#include "../../../engine/scene.h"

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

# ⚙️ Función init()

Se ejecuta UNA sola vez al entrar a la escena.

Usos comunes:

✅ Cargar mapas
✅ Inicializar jugadores
✅ Configurar variables
✅ Reservar memoria

Ejemplo:

```c
void game_init() {
    map = tilemap_load("maps/level1.txt");
}
```

---

# 🔁 Función update()

Se ejecuta cada frame.

Aquí va toda la lógica:

* Movimiento
* IA
* Colisiones
* Input
* Física

Ejemplo:

```c
if(key_down(KEY_W)) {
    player.y--;
}
```

---

# 🎨 Función render()

Dibuja todo en pantalla.

Ejemplo:

```c
renderer_draw_map(&map);
renderer_draw_entity(&player);
```

---

# 🧹 Función destroy()

Libera memoria y recursos.

MUY IMPORTANTE ⚠️

Ejemplo:

```c
tilemap_destroy(&map);
```

---

# 🔄 Cambiar de escena

Usa:

```c
engine_set_scene(&level2Scene);
```

---

# 📌 Flujo visual

```text
init()
   ↓
update()
render()
update()
render()
update()
render()
   ↓
destroy()
```

---

# ❌ Error común

NO cargues mapas dentro de `render()`.

❌ Incorrecto:

```c
void render() {
    map = tilemap_load(...);
}
