# 🔁 Game Loop

El game loop es el corazón del engine.

Todo el videojuego funciona alrededor de este ciclo.

---

# 🧠 ¿Qué es un game loop?

Es un ciclo infinito que:

1. Lee input
2. Actualiza lógica
3. Renderiza
4. Espera
5. Repite

---

# 📌 Flujo visual

```text id="o1m7o2"
     INPUT
       ↓
    UPDATE
       ↓
    RENDER
       ↓
    PRESENT
       ↓
    TIMER 
       ↓
    REPETIR
```

---

# ⚙️ Implementación actual

```c id="5z2tpm"
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

# ⌨️ Input Phase

```c id="5x2g7i"
input_update();
```

Lee el teclado.

---

# 🧠 Update Phase

```c id="sk2q1z"
engine_update();
```

Actualiza:

* Movimiento
* IA
* Física
* Colisiones
* Gameplay
* Toda tu lógica

---

# 🎨 Render Phase

```c id="gj4v0x"
engine_render();
```

Dibuja:

* Mapas
* Entidades
* UI
* Texto

---

# 📺 Present Phase

```c id="s9m8vt"
renderer_present();
```

Muestra el framebuffer en consola.

---

# ⏱️ Timer Phase

```c id="5x2t1i"
timer_update();
```

Actualmente usa:

```c id="4m9p8d"
Sleep(100);
```

Aproximadamente:

```text id="s8c1w4"
10 FPS
```

---

# 🧠 ¿Por qué existe el timer?

Sin pausa:

❌ El juego consumiría CPU excesivamente
❌ El movimiento sería demasiado rápido

---

# 🎮 ¿Qué significa FPS?

```text id="m2q6tu"
Frames Per Second
```

Cantidad de frames renderizados por segundo.

---

# 📌 Ejemplo

```text id="0v2q0r"
60 FPS = 60 frames por segundo
```

---

# ⚠️ Limitación actual

El engine actualmente usa:

```text id="6j5q0z"
Fixed timestep simple
```

Todavía NO tiene:

❌ Delta time
❌ Interpolación
❌ FPS variable
❌ Sincronización real

---

# ❌ Error común

Hacer render dentro de update.

❌ Incorrecto:

```c id="x7y1mt"
void update() {
    renderer_draw_text(...);
}
```

---

# ✅ Correcto

Separar:

```text id="9s0t7f"
update() -> lógica
render() -> dibujo
```

---

# 🧠 Filosofía

El game loop está diseñado para ser:

✅ Simple
✅ Legible
✅ Educativo
✅ Fácil de modificar

---

# 🎮 Importancia

TODO en un videojuego depende del game loop.

Si entiendes esto:
✅ entiendes la base de un engine.
