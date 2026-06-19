# Gestor de Escenas y Keyframes de Animación

> Proyecto Integrador — Programación I (SIS-112)  
> Universidad Católica Boliviana "San Pablo" — Gestión 1/2026

---

## Carátula

| Campo | Detalle |
|---|---|
| **Asignatura** | Programación I — SIS-112 |
| **Docente** | Pamela Shirley Valenzuela Fernández |
| **Gestión** | 1/2026 — Semana 19 |
| **Integrante 1** | Estudiante Uno |
| **Integrante 2** | Estudiante Dos |
| **Carrera** | Ingeniería de Sistemas |
| **Repositorio** | https://github.com/usuario/GestorKeyframes |

---

## Descripción del dominio

El sistema administra los datos de una animación 2D gestionando **keyframes** (fotogramas clave). Un keyframe representa el estado de un objeto animado en un instante de tiempo: su posición, rotación, escala y tipo de interpolación.

Este tipo de herramienta corresponde a la capa de datos que usan softwares como Blender, Adobe Animate o Unity internamente. En lugar de renderizar gráficos, el programa gestiona esa información desde consola con C++ estructurado.

### Struct principal: `Keyframe`

```cpp
struct Keyframe {
    int    id;        // Identificador único
    string escena;    // Nombre del clip  ej: "escena_01"
    int    frame;     // Número de fotograma  ej: 0, 12, 24
    string objeto;    // Elemento animado  ej: "personaje_A"
    float  posX;      // Posición X en espacio 2D
    float  posY;      // Posición Y en espacio 2D
    float  rotacion;  // Ángulo en grados (0.0 – 360.0)
    float  escalaX;   // Factor de escala X  (1.0 = normal)
    float  escalaY;   // Factor de escala Y  (1.0 = normal)
    string ease;      // Interpolación: "linear", "ease_in", "ease_out"
};
```

### Structs auxiliares (retorno múltiple — Req. 2)

```cpp
struct ResultadoBusqueda { int indice; int operaciones; bool encontrado; };
struct MetricaOrden      { string algoritmo; int comparaciones; int intercambios; double tiempoMs; };
struct ReporteComparativo{ MetricaOrden burbuja; MetricaOrden intercalacion; string ganador; };
```

---

## Estructura del proyecto

```
GestorKeyframes/
├── include/
│   ├── cliente.h       → Structs: Keyframe, ResultadoBusqueda, MetricaOrden
│   ├── archivos.h      → Declaraciones de persistencia CSV + seeding
│   ├── crud.h          → Declaraciones CRUD
│   ├── busqueda.h      → Declaraciones búsqueda secuencial, binaria iterativa y recursiva
│   └── ordenacion.h    → Declaraciones Bubble Sort, Merge Sort y reporte comparativo
├── src/
│   ├── archivos.cpp    → cargarKeyframes(), guardarKeyframes(), seedDatos()
│   ├── crud.cpp        → agregar, eliminar, modificar, listar
│   ├── busqueda.cpp    → búsqueda secuencial, binaria iterativa, binaria recursiva
│   └── ordenacion.cpp  → Bubble Sort con métricas, Merge Sort con métricas, reporte
├── data/
│   └── animaciones.csv → Archivo de persistencia (generado automáticamente)
├── main.cpp            → Solo llamadas a funciones; sin lógica de negocio
└── README.md           → Este archivo
```

---

## Instrucciones de compilación y ejecución

### Requisitos

- Compilador `g++` con soporte C++11 o superior
- Compatible con Linux, macOS y Windows (MinGW / WSL)

### Compilar en una línea

```bash
g++ -std=c++11 -Wall -o gestor main.cpp src/archivos.cpp src/crud.cpp src/busqueda.cpp src/ordenacion.cpp
```

### Ejecutar

```bash
./gestor          # Linux / macOS
gestor.exe        # Windows
```

### En Code::Blocks o Dev-C++

1. Crear un proyecto vacío
2. Agregar todos los archivos `.cpp` y `.h` al proyecto
3. En las opciones del compilador asegurarse de tener `-std=c++11`
4. Compilar y ejecutar con F9

> **Nota:** La carpeta `data/` debe existir junto al ejecutable. Si no existe, crearla manualmente antes de ejecutar.

---

## Guía de uso rápido

Al iniciar, el programa carga automáticamente `data/animaciones.csv`. Si el archivo no existe o está vacío, el sistema inserta **10 registros de prueba automáticamente** (seeding) para poder probar todas las funciones de inmediato.

### Menú principal

```
1.  Agregar keyframe
2.  Eliminar keyframe
3.  Modificar keyframe
4.  Listar todos los keyframes
5.  Listar por escena
6.  Ordenar por frame (Bubble Sort)
7.  Reporte comparativo Bubble Sort vs Merge Sort   ← Req. 3
8.  Buscar por objeto (búsqueda secuencial)
9.  Búsqueda binaria iterativa vs recursiva          ← Req. 4
10. Guardar en CSV
11. Ver contenido del CSV
12. Intercalar dos archivos CSV
13. Generar reporte PDF
 0. Salir
```

### Flujo recomendado para la defensa oral

```
1. Ejecutar el programa  →  se cargan los 10 registros de prueba
2. Opción 4             →  listar todos para ver los datos
3. Opción 7             →  reporte comparativo (Bubble vs Merge)
4. Opción 6             →  ordenar la timeline por frame
5. Opción 9             →  buscar frame X con iterativa Y recursiva
6. Opción 13            →  generar PDF del reporte
7. Opción 10            →  guardar y salir
```

### Ejemplo de sesión

```
Opcion: 7
╔═══════════════════════════════════════════════════════╗
║         REPORTE COMPARATIVO DE ORDENACION            ║
╚═══════════════════════════════════════════════════════╝
  Metrica                    Bubble Sort   Merge Sort
  ---------------------------------------------------------
  Comparaciones realizadas   9             19
  Intercambios/movimientos   0             (usa aux.)
  Tiempo de ejecucion (ms)   0.0030        0.0110
  ---------------------------------------------------------
  GANADOR: >> Bubble Sort optimizado <<
```

---

## Requisitos cubiertos

| Req. | Pts | Estado | Descripción |
|------|-----|--------|-------------|
| 1 | 10 | ✅ | Librerías propias `.h/.cpp`; `main.cpp` solo llama funciones |
| 2 | 10 | ✅ | `ResultadoBusqueda` — retorno múltiple (índice + operaciones) |
| 3 | 15 | ✅ | Bubble Sort vs Merge Sort con métricas y reporte comparativo |
| 4 | 15 | ✅ | Búsqueda binaria iterativa **y** recursiva con contador de llamadas |
| 5a | 15 | ✅ | `seedDatos()` — carga automática de 10 registros en primera ejecución |
| 5b | 10 | ✅ | CRUD completo + reporte exportable en PDF (opción 13) |
| 6 | 10 | ⬜ | Repositorio público en GitHub (ver sección siguiente) |
| 7 | 15 | ✅ | Este README |

---

## Historial de commits sugerido

Para cumplir el Req. 6 y demostrar trabajo equitativo:

```
git init
git add .
git commit -m "Estructura inicial del proyecto - Integrante 1"

# Integrante 1 implementa:
git add src/archivos.cpp include/archivos.h
git commit -m "feat: módulo de persistencia CSV y seeding de datos"

git add src/crud.cpp include/crud.h
git commit -m "feat: CRUD completo sobre vector<Keyframe>"

# Integrante 2 implementa:
git add src/ordenacion.cpp include/ordenacion.h
git commit -m "feat: Bubble Sort y Merge Sort con métricas comparativas"

git add src/busqueda.cpp include/busqueda.h
git commit -m "feat: búsqueda binaria iterativa y recursiva con retorno múltiple"

git add src/reporte.cpp include/reporte.h
git commit -m "feat: generador de reporte PDF"

git add README.md
git commit -m "docs: README con instrucciones, structs y guía de uso"

git push origin main
```
---

## Compilación con Makefile (opcional)

```makefile
CXX     = g++
CXXFLAGS= -std=c++11 -Wall
SRCS    = main.cpp src/archivos.cpp src/crud.cpp src/busqueda.cpp src/ordenacion.cpp src/reporte.cpp
TARGET  = gestor

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
```

```bash
make        # compilar
make clean  # limpiar
```

