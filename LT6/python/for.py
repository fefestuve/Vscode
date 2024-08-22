import pygame
#La sentencia for en python itera sobre los items de cualquier secuencia(una lista o cadena de texto),
#en el orden de la secuencia.
#puedo usar break para salir del for y break para ir al siguiente ciclo

palabras=['gato','ventana','defenestrado']
for p in palabras:
    print(p, len(p))

#tambien puedo usar in range (algo)

for i in range(5):
    print('hola', i)

palabras2=palabras
palabras[0]='perro'

#al ser una lista, se hace como un pointer al otro entonces no es que 
# copia por valor, va a modificarse tambien palabras 2
print(palabras)
print(palabras2)