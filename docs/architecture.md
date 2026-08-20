# 🏗️ Arquitectura del Engine

El engine utiliza una arquitectura modular basada en:

* Engine Core
* Renderer
* Input
* Scenes
* Tilemaps
* Entities

---

# 📌 Flujo principal

Cada frame sigue este orden:

```text
INPUT
  ↓
UPDATE
  ↓
RENDER
  ↓
PRESENT
  ↓
SLEEP
```

---

# 🔁 Game Loop

El loop principal vive en:

```c
engine_run();
```

Código simplificado:

```c
while(running) {

    input_update();

    engine_update();

    renderer_clear();

    engine_render();

    renderer_present();

    timer_update();
}
```

---

# 🧠 Responsabilidades

| Sistema   | Responsabilidad   |
| --------- | ----------------- |
| engine    | Coordina todo     |
| renderer  | Dibujar           |
| input     | Leer teclado      |
| scenes    | Estados del juego |
| tilemap   | Mapas             |
| collision | Colisiones        |
| timer     | Control FPS       |

---

# 🎬 Escenas

Las escenas representan estados del juego:

* Menú principal
* Gameplay
* Pausa
* Game Over
* Créditos

Cada escena es independiente.

---

# 🧩 Modularidad

Cada sistema está separado en:

```text
.c  -> implementación
.h  -> interfaz pública
```

Ejemplo:

```text
renderer.c
renderer.h
```

---

# ⚠️ Importante

El engine actualmente es:

✅ Single-thread
✅ ASCII
✅ Basado en consola
✅ Frame-based

No utiliza:

* GPU
* OpenGL
* SDL
* ECS
* Audio

---

# 🧱 Escalabilidad

El diseño actual permite agregar:

* Cámaras
* Audio
* IA
* ECS
* Animaciones
* Colores
* Menús
* Inventarios
* Pathfinding
