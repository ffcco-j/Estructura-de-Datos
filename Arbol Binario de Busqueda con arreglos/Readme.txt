Objetivos del Taller: Utilizar TAD de ABB que permite simular un diccionario y realizar diversas operaciones con ellos.

Enunciado: Se desea simular un diccionario de palabras, organizado por cada letra del abecedario y ordenado alfabéticamente. El diccionario
           se representa informáticamente, mediante un arreglo con 27 casillas, una por cada letra del abecedario. En cada casilla se
           almacena una estructura conformada por:

                      1. Letra del abecedario, por medio de la cual se agrupan todas las palabras que comienzan con dicha letra,
                      2. Un ABB que contiene todas las palabras que comienzan por la letra especificada.
                      3. Cantidad de palabras contenidas en el ABB.
                      
Nota 1: El arreglo contiene elementos de tipo DATO
Nota 2: El tipo DATO es una estructura que contiene: letra, un ABB y la cantidad de palabras en el ABB. En el ejemplo, DATO
        contiene la letra ‘E’ y el ABB contiene 5 palabras, donde cada palabra se organiza según su código ASCII, además cada nodo del
        ABB contiene la palabra y su frecuencia, es decir, la cantidad de veces que se repite.

Implementar un menú que permita:
           (a) Inicializar diccionario: permite generar un diccionario vacío.
           (b) Agregar una palabra en el diccionario: permite ingresar por teclado una palabra al interior del diccionario, si ya existe
               se debe aumentar su indicador de frecuencia.
           (c) Eliminar una palabra contenida en el diccionario: permite eliminar una palabra al interior del diccionario.
           (d) Mostrar toda la información del diccionario: permite mostrar de manera organizada (orden según ASCII) las palabras
               contenidas en el diccionario.
           (e) Buscar la información de una palabra: a partir de una palabra ingresada por teclado, muestra cuántas veces está
               repetida.
           (f) Mostrar todas las palabras repetidas: muestra de manera organizada todas las palabras repetidas con su frecuencia
               respectiva encontradas. Donde la Frecuencia, corresponde a la cantidad de veces que se repite la palabra en el árbol.
               
               Por ejemplo:
                      1) Casa se repite 3 veces
                      2) Perro se repite 2 veces
           (g) Salir
           
Cada opción del menú debe llamar a una función externa que involucra la manipulación del diccionario.
