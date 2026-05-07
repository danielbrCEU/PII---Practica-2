# PII---Practica-2

Entregable 2
Conocimientos previos
1.1. Stacks: Un stack o pila es una lista ordinal o estructura de datos en la que el modo de acceso
a sus elementos es de tipo LIFO (del inglés Last In First Out, el último en entrar, primero en
salir) que permite almacenar y recuperar datos. Se aplica en multitud de ocasiones
informática debido a su simplicidad y ordenación implícita de la propia estructura.
Para poder usar el contenedor stack debemos añadir a la cabecera de nuestro programa
#include <stack>.
En este ejercicio, se recomiendo usar stacks para ir ordenando los puntos que formarán parte
del perímetro del convexhull.
1.2. Operaciones básicas de un stack o pila
• Para el manejo de datos se cuenta con dos operaciones básicas: apilar (push), que coloca
un objeto en la pila, y su operación inversa: retirar (pop), que saca el último elemento
apilado.
• El acceso a los elementos de la pila es siempre desde la parte superior de ésta, es decir,
al último objeto apilado. La operación que permite la obtención de este elemento sin
retíralo de la lista es top.
• Para conocer el tamaño de la pila podremos emplear el método size que retorna un
entero y para conocer si la pila está llena o vacía podemos llamar a los métodos empty
y full que retornan un valor booleano.
2.1. Vectores: Esta clase genérica permite almacenar una colección de objetos del mismo tipo.
Al igual en listas o arrays, podemos acceder a los elementos del contenedor vector usando un
índice y el operador de indexación ([i]), y además estos elementos ocupan posiciones contiguas
de memoria.
Para poder usar el contenedor vector debemos añadir a la cabecera de nuestro programa
#include <vector>.
Dado que implementa un template, debemos indicar en nuestro programa el tipo de dato de los
elementos de la colección. Esto lo hacemos mediante la siguiente sintaxis: std::vector<T>
identificador;
Ejemplo de inicialización de un vector de 5 elementos de tipo struct Point: std::vector<Point>
puntos(5);
2.2. Operaciones básicas de un vector
• Para conocer el tamaño de un vector podremos emplear el método size que retorna un
entero y para conocer si el vector está lleno podemos llamar al método empty retorna
un valor booleano.
• En cuanto al acceso a los elementos, los métodos back y front devuelven la referencia al
último y primer elemento de la lista respectivamente. En caso de querer insertar un
elemento en la última posición de la lista utilizamos el método push_back.
• Para iterar por el vector desde el inicio hasta el final podemos utilizar los métodos begin
y end, y en caso de que deseemos iterar en sentido reverso podemos utilizar rbegin y
rend.
3. Librería SFML para Visual Studio
Simple and Fast Multimedia Library (SFML) es una biblioteca de desarrollo de
software multiplataforma diseñada para proveer una simple interfaz de programación para
diversos elementos multimedia en computadoras. Está escrita en C++, con versiones homólogas
disponibles
en Ada, C, Crystal, D, Euphoria, Go, Java, Julia, .NET, Nim, OCaml, Python, Ruby y Rust.[3] Se han
desarrollado versiones experimentales para Android y iOS con el lanzamiento de SFML 2.2.[4]
Fuente: Wikipedia
Link para descarga y pasos de instalación.
Instalación de SFML descargando el paquete estable más actualizado v3.0.0 de 64-bits. Extraer
de la carpeta comprimida la carpeta “SFML-3.0.0” y colocarlo en la raíz del equipo. A
continuación, edita las propiedades del proyecto para todas las configuraciones de la plataforma
x64.
Primero, indica en bibliotecas adicionales de C++ la carpeta include del SDK, y en las bibliotecas
adicionales del vinculador (linker) la carpeta lib del SDK.
Una vez completado, indicar en las entradas del vinculador las librerías “sfml-graphics.lib”, “sfml-
system.lib”, “sfml-window.lib” y “sfml-network.lib” en las dependencias adicionales.
Por último, incluye los archivos dlls de la carpeta de binarios en la capeta de tu proyecto de visual
studio.
A continuación, tenéis un código para poner en el archivo main y probar si las librerías se han
cargado y configurado correctamente:
#include <SFML/Graphics.hpp>
int main(){
sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);
while (window.isOpen())
{
while (const std::optional event = window.pollEvent())
{
if (event->is<sf::Event::Closed>())
window.close();
}
window.clear();
window.draw(shape);
window.display();
}
}
Convex hull
El convexhull o evolvente convexa es un algoritmo que, dados los puntos de un objeto en el
espacio, permite crear un polígono que encierra a todos los puntos de dicha nube. Existen varios
algoritmos importantes para resolver este problema: Quickhull, Jarvis y Graham.
Podéis encontrar una descripción del algoritmo en la Wikipedia, es recomendable leerlo tanto
en inglés cómo en español. Link.
El objetivo es implementar el algoritmo y dibujar con la librería SFML los puntos del conjunto y
la envolvente. Recordad que en la página oficial de la librería SFML podéis encontrar información
y tutoriales, recordad usar la versión 3.0.0, hay variaciones con respecto a las anteriores.
En la página siguiente hay una guía de implementación de otros años. No es necesario emplear
una pila para su implementación.
