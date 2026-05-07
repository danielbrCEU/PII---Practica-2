# PII---Practica-2

PASOS:
Sean los puntos[0... n-1] del array de puntos de entrada.
1) Busca el punto más bajo comparando las coordenadas y de todos los puntos. Si hay dos
puntos con el mismo valor y, entonces se considera el punto con menor valor de coordenada
x. El punto más bajo es P0. Pon P0 en la primera posición del stack.
2) Considerar los n-1 puntos restantes y ordenarlos por ángulo polar en sentido antihorario
alrededor de puntos[0]. Si el ángulo polar de dos puntos es el mismo, pon primero el punto
más cercano.
3) Una vez ordenados, comprueba si dos o más puntos tienen el mismo ángulo. Si dos o más
puntos tienen el mismo ángulo, entonces elimina todos los puntos con el mismo ángulo
excepto el punto más alejado de P0. Añade dicho punto al stack de tamaño m.
4) Si el tamaño del array es menor que 3, devolver.
5) Crear una pila vacía 'S' y empujar los puntos[0], puntos[1] y puntos[2] a S.
6) Procesa los m-3 puntos restantes uno a uno. Hacer lo siguiente para cada punto 'points[i]'
6.1) Seguir quitando puntos de la pila mientras la orientación de los 3 puntos siguientes no
sea antihoraria (o no giren a la izquierda).
a) Punto situado junto al superior de la pila
b) Punto en la parte superior de la pila
c) puntos[i]
6.2) Empuja puntos[i] a S
