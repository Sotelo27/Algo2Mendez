"""
Una empresa está haciendo recolección de datos y necesita saber cuánta gente de cada rango etario participó en su encuesta.

La división de grupos es la siguiente:

    18 a 30 años
    31 a 50 años
    51 a 70 años

A partir de una lista de tuplas que contiene la edad y qué voto el participante se pide crear una lista nueva que contenga cuántos votos 'si' hubo de cada rango.

TIP: una lista de tuplas se ve de la siguiente forma:

lista = [(18, 'si'), (34, 'no'), (55, 'si')]

Una tupla es similar a una lista, con la diferencia de que es inmutable. 
"""
def conteo_votos_afirmativos(respuestas):
    rango_18_30 = 0
    rango_31_50 = 0
    rango_51_70 = 0

    # Iterar sobre las respuestas
    for edad, voto in respuestas:
        if 18 <= edad <= 30 and voto == 'si':
            rango_18_30 += 1
        elif 31 <= edad <= 50 and voto == 'si':
            rango_31_50 += 1
        elif 51 <= edad <= 70 and voto == 'si':
            rango_51_70 += 1

    conteo_votos = [rango_18_30, rango_31_50, rango_51_70]

    return conteo_votos