"""
El algoritmo babilónico para el cálculo de la raíz cuadrada de x es muy simple: consiste en seleccionar una estimación inicial de la raíz a calcular 
(por ejemplo, estimacion = x/2) e iterativamente verificar cuánto se parece el cuadrado de nuestra estimación calculada al número original.

Es decir, si la diferencia entre estimacion*estimacion y el número original x difieren menos de un valor arbitrario, una precisión dada, 
entonces consideramos que obtuvimos la raíz cuadrada del valor x original.
 A cada paso del algoritmo, la nueva estimación se calcula de la siguiente forma nueva_estimacion = (estimacion + x/estimacion) / 2.

Se pide escribir la función que obtenga la raíz cuadrada de un número pasado por parámetro, teniendo en cuenta que la raíz calculada tiene que tener una precisión de 0.000001.

En caso de no existir la raíz cuadrada real, devolver el valor -1.

Quizás suena conocido de la guía 0 ;)
"""
def raiz_cuadrada(valor):
    if valor < 0:
        return -1

    precision = 0.000001
    estimacion = valor / 2

    while estimacion * estimacion - valor >= precision or estimacion * estimacion - valor <= -precision:
        nueva_estimacion = (estimacion + valor / estimacion) / 2
        if nueva_estimacion == estimacion:
            return nueva_estimacion
        estimacion = nueva_estimacion

    return estimacion