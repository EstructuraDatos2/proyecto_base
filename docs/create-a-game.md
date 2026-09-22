# 🎮 Crear un nuevo juego

El engine está diseñado para soportar múltiples juegos dentro de la carpeta:

```text id="4p4d9f"
games/
```

Cada juego es independiente.

---

# 📁 Estructura recomendada

Ejemplo:

```text id="o7shhd"
games/
└── pong/
    ├── main.c
    ├── scenes/
    ├── maps/
    ├── entities/
    └── systems/
```

---

# 🧠 Filosofía

Cada juego puede:

✅ Reutilizar el engine  
✅ Compartir sistemas  
✅ Tener lógica propia  
✅ Tener escenas independientes  

---

# 🚀 Paso 1 — Crear carpeta

```text id="m7z2kr"
games/pong/
```

---

# 🚀 Paso 2 — Crear main.c

Ejemplo:

```c id="6e3wkk"
#include "../../engine/engine.h"
#include "scenes/game_scene.h"

int main() {

    EngineConfig config = {
        40,
        20
    };

    engine_init(config);

    engine_set_scene(&gameScene);

    engine_run();

    engine_shutdown();

    return 0;
}
```

---

# 🚀 Paso 3 — Crear escena

```text id="3t3jlv"
games/pong/scenes/
```

---

# 📦 Escena mínima

```c id="2jk7d8"
Scene gameScene = {
    game_init,
    game_update,
    game_render,
    game_destroy
};
```
> [!NOTE]
> Puedes revisar la carpeta games/dungeon/scenes
> Existen 2 niveles donde puedes ver la estructura general
---

# 🚀 Paso 4 — Compilar

Actualizar:

```text id="8mdp2g"
build.bat
```

Ejemplo:

```bash id="r8y6sv"
gcc engine/*.c games/*.c games/pong/scenes/*.c games/pong/*.c -o pong.exe
```

---

# 🎮 Múltiples juegos

Puedes tener:

```text id="r8p1m5"
games/
├── dungeon/
├── pong/
├── snake/
├── tetris/
└── platformer/
```

---

# 🧠 Sistemas reutilizables

Todos los juegos pueden usar:

```text id="b0y9pr"
tilemap.c
collision.c
entity.h
```

Pero NO es obligatorio.

Cada juego puede extender el engine.

---

# 📌 Recomendación

Mantén separado:

| Carpeta  | Responsabilidad   |
| -------- | ----------------- |
| scenes   | Estados del juego |
| maps     | Tilemaps          |
| entities | Entidades         |
| systems  | Sistemas extra    |

---

# 🎨 Ejemplo visual

```text id="z0w76q"
PONG
├── scenes/
├── entities/
├── ui/
└── audio/
```

---

# 🚀 Ideas de proyectos

✅ Pong
✅ Snake
✅ RPG
✅ Roguelike
✅ Shooter
✅ Tower Defense
✅ Pacman

---

# ⚠️ Error común

Poner TODA la lógica en:

```text id="6xx4tc"
main.c
```

---

# ✅ Correcto

Separar responsabilidades:

```text id="h3iwdv"
main.c
scenes/
systems/
entities/
```
