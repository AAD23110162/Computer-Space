# Proyecto de Modelado en C++ del Juego Computer Space de 1971.

## Descripción

Este proyecto tiene como objetivo recrear el clásico juego de arcade **Computer Space** de 1971 utilizando el lenguaje de programación C++. Computer Space es reconocido como uno de los primeros videojuegos de arcade comerciales y este proyecto busca rendir homenaje a ese hito en la historia de los videojuegos.

## Características

- Recreación lo mas fiel posible del juego original de Computer Space.
- Gráficos y sonidos retro para mantener la autenticidad del juego.
- Código escrito en C++ y modelado en su mayoria con clases y objetos.

## Compilacion y ejecucion del juego
Para compilar y ejecutar la version final del juego, introduzca en la terminal el comando `make run`; con este comando se compilaran todas las librerias y el programa principal del juego (`main.cpp`), creando asi el archivo ejecutables para poder correrlo.

Sin embargo; si desea ejecutar la version de prueba del juego, introduzca en la terminal el comando `make runPrueba`; con este comando ejecutara el programa de prueba (`prueba.cpp`), el cual puede contener algunas futuras mejoras que aun no se terminan de realizar en el juego.

## Funcionamiento del Programa Principal  (`main.cpp`)

El programa principal es responsable de coordinar la animación de varios elementos gráficos que componen la introducción y ejecución del juego **Computer Space** que se esta modelado en un inicio para recrear sus graficos con ASCII ART. A continuación se detalla su funcionamiento hasta el avance actual del modelado del juego; en donde se muestra una animacion basica de la mayoria de sus elementos que lo componen:

1. **Inclusión de Librerías y Declaración de Espacio de Nombres:**
   - Se incluyen las librerías necesarias y se declara el espacio de nombres.

2. **Inicialización de Archivos y Listas de Dibujos:**
   - Se inicializan objetos de la clase `Archivo` para leer los archivos de texto que contienen la representación ASCII de los dibujos del juego.
   - Se crea una lista de dibujos (`dibujos1` y `dibujos2`) donde se almacenarán los objetos de la clase `Dibujo` correspondientes a cada parte de la animación.

3. **Creación de Dibujos:**
   - Se utiliza un objeto de la clase `Crea` para crear instancias de los objetos de la clase `Dibujo` a partir de los archivos de texto.
   - Se especifica el número de instancias a crear para cada dibujo.

4. **Creación de Vectores de Posiciones Iniciales y Desplazamientos:**
   - Se crean vectores para almacenar las posiciones iniciales y los desplazamientos de cada dibujo en la animación.

5. **Creación de la Pantalla:**
   - Se crea un objeto de la clase `Screen` con dimensiones fijas para representar la pantalla del juego.

6. **Inicialización de Anima y Animación de los Dibujos:**
   - Se crean objetos de la clase `Anima` para animar los dibujos en la pantalla.
   - Se establecen las posiciones iniciales de los dibujos.
   - Se actualizan y dibujan los dibujos en la pantalla durante un número específico de iteraciones, con una duración determinada entre iteraciones.
   - Entre cada animación, se utiliza la función `this_thread::sleep_for` para pausar la ejecución durante un período específico.

7. **Finalización del Programa:**
   - El programa finaliza retornando 0 al sistema operativo.

   El programa principal coordina las diferentes etapas de la animación, desde la presentación inicial del juego hasta la ejecución y la conclusión de la partida, mostrando los diferentes elementos gráficos en la pantalla y controlando su movimiento y apariencia.

Cada instancia de `Anima` se encarga de manejar la animación de un conjunto específico de dibujos, aplicando desplazamientos y actualizando su posición en la pantalla en cada iteración. Estos desplazamientos están predefinidos para cada etapa de la animación, lo que permite crear efectos visuales y movimientos específicos para cada elemento del juego.

Finalmente, el programa termina su ejecución después de completar todas las animaciones y retorna 0 al sistema operativo.

Este enfoque modular y estructurado facilita la coordinación de los diferentes elementos gráficos y su animación, permitiendo una implementación eficiente y mantenible del juego **Computer Space** que se esta diseñando en C++.

## Clases

### Clase `Dibujo`

La clase `Dibujo` se encarga de representar un elemento gráfico en la pantalla utilizando ASCII art. Cada objeto de esta clase tiene una posición en el eje X y en el eje Y, así como un contenido que define su forma mediante una lista de strings que representan las líneas de la imagen ASCII.

#### Atributos:

- `posicionX`: Representa la posición en el eje X del dibujo en la pantalla.
- `posicionY`: Representa la posición en el eje Y del dibujo en la pantalla.
- `contenido`: Lista de strings que representan las líneas del dibujo en ASCII art.

#### Métodos:

- `Dibujo()`: Constructor por defecto que inicializa la posición del dibujo en (0, 0).
- `Dibujo(int posicionX, int posicionY)`: Constructor que permite inicializar la posición del dibujo con valores específicos.
- `Dibujo(list<string> contenido, int posicionX, int posicionY)`: Constructor que permite inicializar el contenido y la posición del dibujo.
- `void Dibujar(ftxui::Screen &Pantalla)`: Método que dibuja el contenido del dibujo en una pantalla dada.
- `void DesplazarX(int distancia)`: Método que desplaza el dibujo horizontalmente.
- `void DesplazarY(int distancia)`: Método que desplaza el dibujo verticalmente.
- `void EstablecerPosicion(int x, int y)`: Método que establece la posición del dibujo en la pantalla.
- Destructor: No se especifica un destructor, por lo que se utiliza el destructor predeterminado.

### Clase `Crea`

La clase `Crea` se encarga de crear instancias de objetos de la clase `Dibujo` a partir de un archivo de texto y almacenarlos en una lista.

#### Métodos:

- `Crea()`: Constructor por defecto.
- `void crea(Archivo &archivo, std::list<Dibujo> &dibujos, size_t num_instances)`: Método que crea un número específico de instancias de dibujos a partir de un archivo y las agrega a una lista de dibujos.


### Clase `Archivo`

La clase `Archivo` se encarga de leer el contenido de un archivo de texto y almacenarlo en una lista para ser utilizado posteriormente en la creación de objetos de la clase `Dibujo`.

#### Atributos:

- `archivo`: Objeto de tipo `fstream` utilizado para leer el contenido del archivo.
- `contenido`: Lista de strings que almacena el contenido del archivo.

#### Métodos:

- `Archivo(string path)`: Constructor que recibe la ruta del archivo como parámetro y lee su contenido para almacenarlo en la lista `contenido`.
- `Dibujo CrearDibujo()`: Método que crea un objeto de la clase `Dibujo` utilizando el contenido almacenado en el archivo y devuelve dicho objeto.


### Clase `Anima`

La clase `Anima` se encarga de animar una secuencia de dibujos en una pantalla, desplazándolos y actualizando su posición en cada iteración.

#### Atributos:

- `dibujos_`: Referencia a una lista de objetos de la clase `Dibujo` que serán animados.
- `posicionesIniciales_`: Referencia a un vector de pares de enteros que representan las posiciones iniciales de los dibujos.
- `desplazamientos_`: Referencia a un vector de pares de enteros que representan los desplazamientos de los dibujos en cada iteración.

#### Métodos:

- `Anima(std::list<Dibujo> &dibujos, std::vector<std::pair<int, int>> &posicionesIniciales, std::vector<std::pair<int, int>> &desplazamientos)`: Constructor que recibe referencias a las listas de dibujos, posiciones iniciales y desplazamientos.
- `void EstablecerPosicionesIniciales()`: Método que establece las posiciones iniciales de los dibujos antes de iniciar la animación.
- `void ActualizarYDibujar(Screen &pantalla, size_t iteraciones, std::chrono::milliseconds duracion)`: Método que actualiza y dibuja los dibujos en la pantalla durante un número específico de iteraciones, con una duración determinada entre iteraciones.

## Uso de la libreria **FTXUI** en este proyecto

**FTXUI** es una libreria en C++ de código abierto que proporciona herramientas para crear interfaces de usuario en la terminal de manera eficiente y sencilla. Permite la creación de elementos gráficos interactivos, como botones, cajas de selección, menús desplegables, etc., y facilita la manipulación y animación de estos elementos en la terminal. Su objetivo es proporcionar una experiencia de usuario fluida y agradable, incluso en entornos de terminal limitados, y permite a los desarrolladores crear aplicaciones de terminal ricas y dinámicas con facilidad.

La librería FTXUI se está utilizando en este proyecto para facilitar la creación de interfaces de usuario basadas en texto y la manipulación de elementos gráficos en la terminal.

### ¿Por qué se está usando la librería ftxui?

- Facilidad de uso: ftxui proporciona una API fácil de usar para la creación de interfaces de usuario en la terminal, lo que permite desarrollar aplicaciones interactivas de manera sencilla y eficiente.

- Rendimiento: Esta biblioteca está diseñada para ser eficiente y proporcionar una experiencia de usuario fluida incluso en entornos de terminal más limitados.

- Flexibilidad: Permite crear una amplia variedad de elementos gráficos, como botones, cuadros de texto, listas, etc., lo que facilita la creación de interfaces de usuario ricas y dinámicas.

### ¿Para qué se está usando la librería ftxui?

- Representación gráfica: Se utiliza para representar gráficamente los diferentes elementos del juego, como el título, la versión, la nave, los ovnis, etc., en la pantalla de la terminal.

- Manipulación de elementos: Permite mover, redimensionar y actualizar dinámicamente los elementos gráficos en respuesta a la interacción del usuario o a eventos específicos del juego.

- Animación: La librería ftxui facilita la animación de los elementos gráficos, lo que permite crear efectos visuales llamativos y dinámicos durante la ejecución del juego.