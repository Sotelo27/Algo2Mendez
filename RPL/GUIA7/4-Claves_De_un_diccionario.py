"""

Luego de haber programado todos los TDA en C, llega la noticia de que en python ya fueron implementados y se pueden usar libremente!

Para conocer un poco mejor las primitivas, la idea es dado un diccionario o hash con materias y sus respectivas notas devolver una 
lista de todas las materias que comienzan con la letra 'A' y además tuvieron una nota mayor o igual a 4.

TIP: el diccionario es de la siguiente forma:

  {'materia': nota, 'otra materia': nota, ...}. 
"""
def materias_aprobadas_con_a(materias):
    materias_aprobadas = []

    for materia, nota in materias.items():
        if materia[0] == 'A' and nota >= 4:
            materias_aprobadas.append(materia)

    return materias_aprobadas