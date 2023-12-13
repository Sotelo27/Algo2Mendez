class Figura:
        def __init__(self,color):
                self.color = color
        def mostrarColor(self):
                print("MI color es " + self.color)
class Cuadrado(Figura):
        def __init__(self,ancho,color):
                super().__init__(color)
                self.ancho = ancho
        def area(self):
                return self.ancho*self.ancho
class Rectangulo(Figura):
        def __init__(self,ancho,alto,color):
                super().__init__(color)
                self.ancho = ancho
                self.alto = alto
        def area(self):
                return self.ancho*self.alto
class Circulo(Figura):
        def __init__(self,radio,color):
                super().__init__(color)
                self.radio = radio
        def area(self):
                return math.pi * self.radio*self.radio
figuras = [Cuadrado(4,'rojo'),Rectangulo(4,5,'verde'),Circulo(3,'azul')]
for figura in figuras:
        print(figura.area())