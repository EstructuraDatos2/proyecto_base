# ASCII Dungeon Engine

Motor simple de videojuegos ASCII en lenguaje C diseñado con fines educativos.

El proyecto está enfocado en enseñar:

* Modularidad en C
* Manejo de memoria dinámica
* Arquitectura básica de motores
* Escenas y game loop
* Tilemaps
* Colisiones
* Renderizado ASCII

---

# Características

* Renderizado ASCII en consola
* Sistema de escenas
* Tilemaps desde archivos `.txt`
* Colisiones por tiles
* Entidades simples
* Input en tiempo real
* Viewports
* Arquitectura modular
* Código educativo y extensible

---

# Estructura del proyecto

```text
.
├── engine/                # Núcleo del engine
│   ├── engine.c
│   ├── renderer.c
│   ├── input.c
│   ├── scene.c
│   └── timer.c
│
├── games/                 # Sistemas reutilizables y juegos
│   ├── collision.c
│   ├── tilemap.c
│   ├── entity.h
│   │
│   └── dungeon/           # Juego demo
│       ├── main.c
│       ├── maps/
│       └── scenes/
│
├── docs/                  # Documentación completa
│
└── build.bat
```

---

# Compilar el proyecto

## Requisitos

* GCC (TDM-GCC recomendado)
* Windows
* Consola CMD

## Compilar

```bash
build.bat
```

O manualmente:

```bash
gcc engine/*.c games/*.c games/dungeon/scenes/*.c games/dungeon/*.c -o game.exe
```

---

# Ejecutar

```bash
game.exe
```

---

# Cómo funciona el engine

El engine sigue una arquitectura basada en escenas.

Cada frame ejecuta:

1. Lectura de input
2. Actualización lógica
3. Renderizado
4. Presentación en consola
5. Control de tiempo/FPS

El loop principal se encuentra en:

```c
engine_run();
```

---

# Crear un nuevo juego

Puedes crear un nuevo juego dentro de `games/`.

Ejemplo:

```text
games/
└── pong/
    ├── main.c
    ├── scenes/
    ├── maps/
    └── entities/
```

Luego solo debes compilar agregando los archivos al comando GCC.

---

# Escenas

Cada escena debe implementar:

```c
void init();
void update();
void render();
void destroy();
```

Y registrarse así:

```c
Scene gameScene = {
    init,
    update,
    render,
    destroy
};
```

Las escenas permiten separar:

* Menús
* Gameplay
* Niveles
* Pantallas de pausa
* Game Over

---

# Tilemaps

Los mapas se cargan desde archivos `.txt`.

Ejemplo:

```text
################
#              #
#      ###     #
#              #
################
```

Carga:

```c
TileMap map = tilemap_load("maps/level1.txt");
```

---

# Colisiones

Las colisiones funcionan por tiles sólidos.

Actualmente:

* `#` = pared
* ` ` = espacio caminable

Verificación:

```c
tilemap_entity_is_walkable(&map, &player, nextX, nextY)
```

---

# Renderizado

El renderer utiliza un framebuffer ASCII interno.

Funciones principales:

```c
renderer_draw_char()
renderer_draw_text()
renderer_draw_entity()
renderer_draw_map()
```

---

# Viewport

El viewport permite mover el área de dibujo.

Ejemplo:

```c
renderer_set_viewport(1, 2);
```

Esto desplaza todo el renderizado posterior.

Útil para:

* HUD
* Cámaras
* Interfaces
* Márgenes

---

# Input

Input soportado actualmente:

```c
KEY_W
KEY_A
KEY_S
KEY_D
KEY_ESCAPE
```

Uso:

```c
if(key_down(KEY_W)) {
    player.y--;
}
```

---

# Objetivo educativo

Este motor está diseñado como base para implementar:

* Listas enlazadas
* Árboles binarios
* Grafos
* Pathfinding
* IA
* Inventarios dinámicos
* Sistemas de diálogos
* Gestión de entidades dinámicas

Todo dentro de un videojuego funcional en C.

---

# Próximas mejoras

* Cámara dinámica
* Sistema de sprites animados
* Soporte para colores
* UI/HUD avanzado
* Audio
* Gestión dinámica de entidades
* Pathfinding BFS/DFS
* Sistema de eventos

---

# Documentación

La documentación completa se encuentra en:

```text
docs/
```

---

# Licencia

Proyecto educativo.
