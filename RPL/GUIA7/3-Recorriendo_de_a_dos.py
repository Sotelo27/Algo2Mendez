"""
En un laboratorio se tiene una lista de los elementos que se compraron para un experimento muy importante. El jefe tiene otra lista con los elementos que efectivamente se recibieron.

Ayudalo a ver si las listas son iguales o no, ya que si faltan elementos el experimento puede ser peligroso!
"""
def revisar_listas(comprados, recibidos):
    if len(comprados) != len(recibidos):
        return False  
    
    comprados.sort()
    recibidos.sort()
    

    for i in range(len(comprados)):
        if comprados[i] != recibidos[i]:
            return False  
    
    return True  