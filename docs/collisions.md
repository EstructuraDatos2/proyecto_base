# 💥 Colisiones

Las colisiones evitan que las entidades atraviesen objetos sólidos.

En este engine existen dos sistemas:

* Colisiones entre entidades
* Colisiones contra tilemaps

---

# 🧱 Colisiones por tiles

El sistema principal actualmente es:

```text id="0k5z0w"
Entidad vs Tilemap
```

---

# 🧠 ¿Cómo funciona?

Antes de mover una entidad:

1. Se calcula la nueva posición
2. Se verifica si el tile es sólido
3. Si es válido → se mueve
4. Si no → se bloquea

---

# 📌 Ejemplo

```c id="ptq7j2"
int nextX = player.x;
int nextY = player.y;
```

Movimiento:

```c id="7oqo2h"
if(key_down(KEY_W)) nextY--;
```

Verificación:

```c id="v6b4u6"
if(tilemap_entity_is_walkable(&map, &player, nextX, nextY)) {
    player.x = nextX;
    player.y = nextY;
}
```

---

# 🚧 Tiles sólidos

Actualmente:

```text id="jlwm3f"
# = sólido
```

---

# 🧠 Verificación interna

El engine revisa:

```text id="mjlwm3"
tiles[y][x]
```

Si encuentra `#`:

```c id="jlwm38"
return 0;
```

---

# 👤 Colisiones entre entidades

También existe:

```c id="n7jlwm"
entity_collides()
```

---

# 📦 Estructura Entity

```c id="mqjlwm"
typedef struct {
    int x;
    int y;

    int width;
    int height;

    char sprite;
} Entity;
```

---

# 📐 Bounding Box Collision

El sistema usa AABB:

```text id="zjlwm3"
Axis Aligned Bounding Box
```

---

# 🧠 Visualización

```text id="jlwm32"
AAAA
AAAA

   BBBB
   BBBB
```

Si se superponen:

✅ Hay colisión

---

# 🔍 Ejemplo

```c id="1jlwm3"
if(entity_collides(&player, &enemy)) {
    printf("Hit!");
}
```

---

# 🎮 Posibles usos

* Enemigos
* Proyectiles
* Objetos
* NPCs
* Trampas
* Loot

---

# ⚠️ Limitación actual

Las entidades todavía:

❌ No tienen velocidad
❌ No tienen física
❌ No tienen aceleración
❌ No tienen masas

---

# ❌ Error común

Mover primero y verificar después.

❌ Incorrecto:

```c id="gjlwm3"
player.x++;

if(collision) {
    ...
}
```

---

# ✅ Correcto

Primero verificar:

```c id="rjlwm3"
nextX = player.x + 1;

if(valid) {
    player.x = nextX;
}
```
