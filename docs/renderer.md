# 🎨 Renderer

El renderer es el sistema encargado de dibujar todo en pantalla.

En este engine el renderizado es ASCII, por lo que cada carácter representa un pixel visual del juego.

---

# 🧠 ¿Cómo funciona?

El renderer utiliza un framebuffer interno:

```text id="2zz2yq"
char** screen
```

Este framebuffer almacena todos los caracteres antes de mostrarlos en consola.

---

# 📌 Flujo del renderer

```text id="84w4d0"
Limpiar pantalla
        ↓
Dibujar mapa
        ↓
Dibujar entidades
        ↓
Dibujar UI/texto
        ↓
Mostrar framebuffer
```

---

# 🚀 Inicializar renderer

El engine lo hace automáticamente:

```c id="wnw2x7"
renderer_init(width, height);
```

Ejemplo:

```c id="vwq5ri"
EngineConfig config = {
    30,
    16
};
```

Esto crea una pantalla ASCII de:

```text id="7nlf4v"
30 columnas
16 filas
```

---

# 🧹 Limpiar pantalla

Cada frame:

```c id="i2wovz"
renderer_clear();
```

Esto rellena el framebuffer con espacios vacíos.

---

# ✏️ Dibujar caracteres

```c id="q2n7xy"
renderer_draw_char(x, y, '@');
```

Ejemplo visual:

```text id="uqqsq2"
     @
```

---

# 📝 Dibujar texto

```c id="ifv6hn"
renderer_draw_text(1, 1, "HP: 100");
```

Resultado:

```text id="8wdw2f"
HP: 100
```

---

# 👤 Dibujar entidades

```c id="d3vgd9"
renderer_draw_entity(&player);
```

Una entidad contiene:

```c id="1eu5a8"
typedef struct {
    int x;
    int y;

    int width;
    int height;

    char sprite;
} Entity;
```

---

# 🗺️ Dibujar mapas

```c id="8znk7o"
renderer_draw_map(&map);
```

Esto recorre todos los tiles del mapa y los dibuja.

---

# 📺 Viewport

El viewport desplaza el área de dibujo.

Ejemplo:

```c id="g5qgwo"
renderer_set_viewport(1, 2);
```

Todo lo que se dibuje después tendrá un offset.

---

# 🧠 Ejemplo visual

Sin viewport:

```text id="ohg8be"
########
# @    #
########
```

Con viewport `(2,1)`:

```text id="3m0tfm"

  ########
  # @    #
  ########
```

---

# 🎮 Uso del viewport

Ideal para:

✅ HUD
✅ Cámaras
✅ Márgenes
✅ Interfaces
✅ Split screen

---

# 📤 Mostrar pantalla

```c id="b9pznw"
renderer_present();
```

Esto imprime el framebuffer completo en consola.

Internamente usa:

```c id="5z9m2m"
system("cls");
```

y luego imprime todos los caracteres.

---

# ❌ Error común

NO dibujes fuera de pantalla.

Incorrecto:

```c id="xvr3fw"
renderer_draw_char(999, 999, '@');
```

Aunque el engine lo protege, es mala práctica.