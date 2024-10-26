
# So_Long

**So_Long** es un proyecto desarrollado como parte del plan de estudios de la escuela 42. El objetivo del proyecto es crear un pequeño videojuego en 2D utilizando la biblioteca **MinilibX**. Este proyecto permite explorar los conceptos de gráficos en 2D, manejo de eventos y estructuras de datos en C.

## Tabla de contenidos

- [Descripción](#descripción)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Compilación e Instalación](#compilación-e-instalación)
- [Uso](#uso)
- [Detalles Técnicos](#detalles-técnicos)
- [Autores](#autores)

## Descripción

En el proyecto **So_Long**, se crea un pequeño videojuego en 2D donde el jugador controla un personaje que debe moverse a través de un mapa, recoger objetos y alcanzar una salida para ganar. El mapa está diseñado utilizando un archivo de texto que define las diferentes características del nivel, como paredes, caminos, coleccionables y la salida.

## Estructura del Proyecto

El proyecto incluye los siguientes componentes principales:

- **Gestión de Gráficos**: Uso de la biblioteca MinilibX para la creación de la ventana del juego y la visualización de imágenes.
- **Manejo de Eventos**: Control del movimiento del personaje a través de eventos del teclado.
- **Carga de Mapas**: Lectura y validación de un archivo de mapa para definir el entorno del juego.

## Compilación e Instalación

1. **Clona el repositorio**:
   ```bash
   git clone https://github.com/samuelhm/so_long.git
   cd so_long
   ```

2. **Compila el proyecto** usando el comando `make`:
   ```bash
   make
   ```

3. **Ejecuta el programa** pasando el archivo de mapa como argumento:

   ```bash
   ./so_long maps/map.ber
   ```

   Asegúrate de tener un archivo de mapa válido con la extensión `.ber`.

## Uso

En el juego, el jugador puede moverse utilizando las teclas de dirección del teclado. El objetivo es recoger todos los objetos del mapa y llegar a la salida.

- **Teclas de Movimiento**: Usar las teclas de dirección o `W`, `A`, `S`, `D` para mover el personaje.
- **Objetivo**: Recoger todos los coleccionables y alcanzar la salida marcada en el mapa.

## Detalles Técnicos

- **Biblioteca MinilibX**: El proyecto utiliza la biblioteca gráfica MinilibX para crear la ventana del juego y gestionar los eventos.
- **Gestión de Eventos**: Uso de hooks para capturar eventos de teclado y cerrar la ventana.
- **Validación del Mapa**: Se valida que el mapa tenga una estructura rectangular, una cantidad correcta de elementos y que sea jugable.

## Autores

- **Samuel H. M.** - [GitHub](https://github.com/samuelhm)

