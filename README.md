# PII - Práctica 2: Envolvente Convexa (Graham Scan)

Implementación visual del algoritmo de Graham para calcular la envolvente convexa de un conjunto de puntos, usando SFML 3.

## Algoritmo

Sean los puntos `puntos[0...n-1]` del array de entrada.

1. Busca el punto más bajo comparando las coordenadas `y` de todos los puntos. Si hay dos puntos con el mismo valor `y`, se considera el de menor `x`. El punto más bajo es `P0`. Se pone `P0` en la primera posición del stack.
2. Considera los `n-1` puntos restantes y ordénalos por ángulo polar en sentido antihorario alrededor de `puntos[0]`. Si el ángulo polar de dos puntos es el mismo, pon primero el punto más cercano.
3. Una vez ordenados, comprueba si dos o más puntos tienen el mismo ángulo. Si los tienen, elimina todos excepto el más alejado de `P0`. Añade dicho punto al stack de tamaño `m`.
4. Si el tamaño del array es menor que 3, devolver.
5. Crear una pila vacía `S` y empujar `puntos[0]`, `puntos[1]` y `puntos[2]` a `S`.
6. Procesa los `m-3` puntos restantes uno a uno. Para cada `puntos[i]`:
   1. Seguir quitando puntos de la pila mientras la orientación de los 3 puntos siguientes no sea antihoraria (o no giren a la izquierda):
      - a) Punto situado junto al superior de la pila
      - b) Punto en la parte superior de la pila
      - c) `puntos[i]`
   2. Empuja `puntos[i]` a `S`.

## Requisitos

- CMake 3.20 o superior
- Compilador C++17 (clang, g++, MSVC)
- SFML 3 (opcional: si no está instalado, CMake lo descarga automáticamente vía `FetchContent`)

## Compilación y ejecución

### macOS

Instalar dependencias con Homebrew (opcional, acelera el build):

```bash
brew install cmake sfml
```

Compilar y ejecutar:

```bash
cmake -S . -B build
cmake --build build
./build/practica_2
```

### Windows

Requisitos: [CMake](https://cmake.org/download/) y [Visual Studio](https://visualstudio.microsoft.com/) (con "Desktop development with C++") o MinGW.

Desde PowerShell o `cmd` en la raíz del proyecto:

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\practica_2.exe
```

> Si SFML no está instalado en el sistema, CMake lo descargará y compilará automáticamente vía `FetchContent` (puede tardar varios minutos la primera vez). Las DLLs necesarias se copian al directorio del ejecutable en el paso `POST_BUILD`.