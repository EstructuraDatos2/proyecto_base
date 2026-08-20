# 🗺️ Tilemaps

Los tilemaps representan el mundo del juego utilizando caracteres ASCII.

Cada carácter es un tile.

---

# 🧠 ¿Qué es un tile?

Un tile es una unidad del mapa.

Ejemplo:

```text id="tq1n1m"
#
@
D
.
~
```

Cada símbolo puede representar algo diferente.

---

# 📦 Estructura TileMap

```c id="n7mx7x"
typedef struct {
    int width;
    int height;

    char** tiles;
} TileMap;
```

---

# 📁 Crear mapas

Los mapas se almacenan como archivos `.txt`.

Ejemplo:

```text id="d67h9v"
################
#              #
#     ###      #
#              #
################
```

---

# 📥 Cargar mapas

```c id="d18r2l"
TileMap map = tilemap_load("maps/level1.txt");
```

---

# ⚙️ ¿Qué hace tilemap_load()?

El engine:

1. Abre el archivo
2. Calcula ancho y alto
3. Reserva memoria dinámica
4. Copia caracteres
5. Construye el mapa

---

# 🧠 Representación interna

```text id="10p7ry"
tiles[y][x]
```

Ejemplo:

```text id="1qh1qo"
tiles[3][5]
```

Accede al tile:

* fila 3
* columna 5

---

# 📌 Convención actual

| Tile    | Significado |
| ------- | ----------- |
| #       | Pared       |
| espacio | Caminable   |
| D       | Puerta      |

---

# 🚪 Ejemplo de puerta

```text id="2v4u2t"
########
#      D
########
```

Verificación:

```c id="5e7yyv"
if(map.tiles[y][x] == 'D') {
    engine_set_scene(...);
}
```

---

# 🚶 Tiles caminables

El engine utiliza:

```c id="5nsj7m"
tilemap_is_walkable()
```

y

```c id="5ikj7v"
tilemap_entity_is_walkable()
```

---

# 🧱 Colisiones por tiles

Actualmente:

```text id="9dr7l5"
# = sólido
```

Todo lo demás es caminable.

---

# 📏 Tamaño del mapa

El tamaño depende del archivo `.txt`.

Ejemplo:

```text id="j5mn5z"
20 caracteres = ancho
10 líneas = alto
```

---

# 🧹 Liberar memoria

MUY IMPORTANTE ⚠️

Siempre destruir mapas:

```c id="vjlwmz"
tilemap_destroy(&map);
```

---

# ❌ Error común

NO olvides destruir mapas.

Incorrecto:

```c id="9vbjlwm"
map = tilemap_load(...);
```

sin:

```c id="6yjlwm"
tilemap_destroy(&map);
```

Esto genera fugas de memoria.

---

# 🧠 Recomendación

Mantén una leyenda clara de tiles.

Ejemplo:

```text id="x0jz0i"
# = pared
D = puerta
E = enemigo
T = tesoro
```

Esto hace los mapas mucho más fáciles de mantener.
