"""
La idea ahora es investigar sobre las primitivas de las listas, aprovechando que muchas ya fueron implementadas.

Dada una lista de elementos y otra de posiciones, se pide quitar de la lista original los elementos de las posiciones recibidas y devolverla.
"""
def sacar_elementos(lista, posiciones):
    posiciones.sort(reverse=True)
    
    for pos in posiciones:
        if 0 <= pos < len(lista):
            lista.pop(pos)
    
    return lista
