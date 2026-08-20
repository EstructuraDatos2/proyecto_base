# ⌨️ Input System

El sistema de input permite detectar teclas presionadas por el usuario en tiempo real.

Actualmente el engine utiliza:

```text id="x3q2pt"
GetAsyncKeyState()
```

de la API de Windows.

---

# 🧠 ¿Cómo funciona?

Cada frame:

1. El engine lee el teclado
2. Guarda el estado de las teclas
3. El juego consulta esas teclas

---

# 🔁 Flujo del input

```text id="4l2m1v"
Jugador presiona tecla
          ↓
input_update()
          ↓
Estado almacenado
          ↓
key_down()
```

---

# 📦 Archivo principal

```text id="u0mk7p"
engine/input.c
engine/input.h
```

---

# 🎮 Teclas disponibles

Actualmente:

```c id="3yhv0j"
KEY_W
KEY_A
KEY_S
KEY_D
KEY_ESCAPE
```

---

# 📥 Leer input

Ejemplo:

```c id="p18tt8"
if(key_down(KEY_W)) {
    player.y--;
}
```

---

# 🎮 Movimiento completo

```c id="4cifg6"
if(key_down(KEY_W)) nextY--;
if(key_down(KEY_S)) nextY++;
if(key_down(KEY_A)) nextX--;
if(key_down(KEY_D)) nextX++;
```

---

# 🧠 ¿Qué devuelve key_down()?

```c id="v0lt2j"
1 = tecla presionada
0 = tecla no presionada
```

---

# ⚙️ ¿Dónde se actualiza?

Dentro del game loop:

```c id="xld0um"
input_update();
```

Esto ocurre cada frame.

---

# 🔍 Implementación interna

```c id="9xcz0w"
keys[KEY_W] = GetAsyncKeyState('W');
```

El estado se guarda en:

```c id="c3uj8g"
static short keys[256];
```

---

# ⚠️ Limitaciones actuales

Actualmente el sistema:

❌ No detecta mouse
❌ No detecta gamepads
❌ No tiene input buffering
❌ No diferencia press/release
❌ No soporta remapeo

---
# 🎮 Filosofía del sistema

El input busca ser:

✅ Simple
✅ Directo
✅ Fácil de entender
✅ Educativo

La idea es priorizar claridad antes que complejidad.