"""
Para empezar con Python la idea es recorrer los elementos en una lista (siendo las listas los vectores de Python) y aplicarles una función.

Al igual que en C, para iterar sobre una lista se pueden utilizar las funciones for y while, pero existen otras formas que hacen uso de funciones de Python.

Por ejemplo, la función range devuelve una secuencia de números, por lo que se puede hacer algo del estilo:

for i in range(5) 

que va a iterar con i = 0 hasta i = 4.

También está la función enumerate, que cuando se utiliza con el for permite tener una lista con el contador y el valor correspondiente.

Otra estructura muy utilizada es la comprensión de listas, que permite crear una lista a partir de otra de la siguiente forma:

lista_1 = [i for i in lista if i > 3]

Crea una lista_1 que contiene los mismos elementos que lista, si son mayores a 3.

En este caso, dada una lista de notas de alumnos de algoritmos 2 se pide calcular el promedio de la materia y devolverlo. 
"""

def promedio(notas_alumnos):
    if not notas_alumnos:  
        return 0  
    
    suma_notas = sum(notas_alumnos)  
    cantidad_notas = len(notas_alumnos)  
    promedio = suma_notas / cantidad_notas 
    
    return promedio