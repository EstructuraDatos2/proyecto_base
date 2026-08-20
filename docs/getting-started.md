# 🚀 Getting Started

Bienvenido a **ASCII Dungeon Engine**.

Este engine fue creado con fines educativos para aprender:

* 🎮 Desarrollo de videojuegos
* 🧠 Estructuras de datos
* ⚙️ Arquitectura de motores
* 🧩 Modularidad en C
* 💾 Memoria dinámica

---

# 📦 Requisitos

Antes de comenzar necesitas:

* Windows
* GCC (TDM-GCC o MinGW)
* Consola CMD

---

# 🔨 Compilar el proyecto

## Método rápido

Ejecuta:

```bash
build.bat
```

---

## Método manual

Abre una consola y ejecuta el siguiente comando:
```bash
gcc engine/*.c games/*.c games/dungeon/scenes/*.c games/dungeon/*.c -o game.exe
```
> [!NOTE]
> El nombre del archivo se debfine despues del parámetro -o NOMBRE.exe
### ▶️ Ejecutar
Luego solo tienes que ejecutar el archivo compilado:
```bash
game.exe
```

---

# 🎮 Controles

| Tecla | Acción    |
| ----- | --------- |
| W     | Arriba    |
| A     | Izquierda |
| S     | Abajo     |
| D     | Derecha   |
| ESC   | Salir     |

---

# 📁 Estructura general

```text
engine/     -> Núcleo del engine
games/      -> Juegos y sistemas reutilizables
docs/       -> Documentación
```

---

# 🧠 Filosofía del engine

El engine está diseñado para:

✅ Ser simple
✅ Ser educativo
✅ Ser modular
✅ Facilitar experimentación
✅ Integrar estructuras de datos

NO intenta competir con engines modernos.

Su propósito es aprender arquitectura y programación de videojuegos desde cero.

---

# 🗺️ Próximo paso

Continúa con:

➡️ `architecture.md`
