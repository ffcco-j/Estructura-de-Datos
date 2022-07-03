Objetivos del Taller: Utilizar TAD de Stack y Cola, para manipular expresiones matemáticas (postfija).

Enunciado:

Parte 1) A partir de un string donde se representa una expresión matemática, que incluye paréntesis (redondos, cuadrados o
         llaves), operadores aritméticos (suma, resta, multiplicación y división) y operandos (sólo considerar números enteros positivos)
         se pide generar su equivalente en notación postfija1.
         
         Entrada : ([(2 + 3) * (5 - 2)] + {16 / 2})
         Salida : 2 3 + 5 2 - * 16 2 / + (El carácter blanco, corresponde al separador de la expresión)

Parte 2) A partir de un string, que contiene una expresión matemática en notación postfija (usted elige el delimitador), se pide
         evaluar numéricamente dicha expresión.
          
         Entrada : 2 3 + 6 7 + *
         Salida : 65
         
Se deberá presentar un menú con las siguientes opciones:
         
         (a) Convertir expresión matemática a notación postfija: Se ingresa por teclado una expresión matemática (asuma que viene bien construida) y 
             debe mostrar string en notación postfija.
         (b) Evaluar expresión postfija: Permitir ingresar expresión en notación postfija ya sea por teclado o utilizar salida de la opción (a) para 
             evaluar según procedimiento.
         (c) Salir

Cada opción del menú debe llamar a una función externa que involucre a los TAD stack y cola.
