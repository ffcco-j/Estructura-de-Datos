//Autor: Francisco Jeria Guerra, EDD sección 412.
//Tema: LLS de clase Fracción.
//Profesor: Diego Hernandez García.

#include <iostream>
#include <limits>
#include <vector>

#include "Fraccion.h"

using namespace std;

//Declaración de cada nodo.
struct Nodo{
    Fraccion fraccion;
    struct Nodo *link;
};

typedef Nodo *Lista;

//Declaración de funciones del menú.
void agregarFraccion(Lista&);
void mostrarFracciones(Lista);
void contarFracciones(Lista);
void mostrarMayor(Lista);
void promedioPrimos(Lista);

//Declaración de funciones auxiliares.
bool esPrimo(int);
int mcd(int, int);

int main(){
    setlocale(LC_CTYPE,"Spanish");
    
    //Declaración variables del menú.
    int opcion_menu;
    bool repetir;
    
    //Creamos la lista F, que conteendrá las fracciones.
    Lista F;
    F = NULL;
    
    do{
        system("clear");
        
        cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
        cout << "|----      Agregar una fracción           [1]       Promedio fracciones             ----|" << endl;
        cout << "|----      Mostrar todas las fracciones   [2]       con numerador primo      [5]    ----|" << endl;
        cout << "|----      Contar fracciones menores a 1  [3]       Salir                    [0]    ----|" << endl;
        cout << "|----      Mostrar fracción mayor         [4]                                       ----|" << endl << endl;
     
        cout << "   Seleccione una opción => ";
        
        cin >> opcion_menu;
        
        //Limpieza buffer.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        system("clear");
        
        //Menu switch principal
        switch(opcion_menu){
        
        case 1:
            agregarFraccion(F);
            break;
        
        case 2:
            mostrarFracciones(F);
            break;
        
        case 3:
            contarFracciones(F);
            break;
            
        case 4:
            mostrarMayor(F);
            break;
            
        case 5:
            promedioPrimos(F);
            break;
        
        case 0:
            repetir = false;
            break;
    
        default:
            cout << "¡¡Ingrese una opción válida!!" << endl << endl;
        }
    }
    while(repetir);
    return 0;
}

//Función para saber si un número es primo.
bool esPrimo(int numero){
    if(numero == 0 || numero == 1 || numero == 4){ 
        return false;
    }
    for(int x = 2; x < numero / 2; x++){
        if (numero % x == 0){ 
            return false;
        }
  }
  return true;
}

//Función para calcular el maximo común divisor.
int mcd(int a, int b){
    if (b == 0){
        return a;
    }
    return mcd(b, a % b);
}

//Función para agregar fracción a la lsta F.
void agregarFraccion(Lista &F){
    //Declaración de variables.
    int num, denom;
    Fraccion newFraccion;
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    cout << "    Este programa sólo permite ingresar números enteros y positivos." << endl << endl << endl;
    
    cout << "    Ingrese el numerador:    ";
    
    cin >> num;
    
    //Limpiea buffer.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    //Verificar si un número es válido para una fracción.
    if(num <= 0){
        
        system("clear");
        
        cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
        
        cout << "    El numerador ingresado no puede ser negativo o igual a 0." << endl << endl;
        cout << "    Ingrese una fracción nuevamente." << endl << endl;
        
        system("read -p 'Presione enter para volver al menú...' var");
        return;
    }
    
    cout << "                            ---" << endl;
    cout << "    Ingrese el denominador:  ";
    
    cin >> denom;
    
    //Limpieza buffer.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(denom <= 0){
        
        system("clear");
        
        cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
        
        cout << "    El denominador ingresado no puede ser negativo o igual a 0." << endl << endl;
        cout << "    Ingrese una fracción nuevamente." << endl << endl;
        
        system("read -p 'Presione enter para volver al menú...' var");
        return;
    }
    
    system("clear");
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    //Asignar numerador y denominador a una clase Fraccion.
    newFraccion.setNumerador(num);
    newFraccion.setDenominador(denom);
    newFraccion.setResultado();
    
    //Mostrar la fracción.
    newFraccion.verFraccionResultado();
    
    cout << "-Fracción agregada correctamente." << endl << endl;
    
    //Se agrega la clase Fraccion a la lista.
    Lista nuevo = new (Nodo);
    nuevo->fraccion = newFraccion;
    nuevo->link = F;
    F = nuevo;
    
    
    system("read -p 'Presione enter para volver al menú...' var");
}

//Función para mostrar las fracciones contenidas en la lista.
void mostrarFracciones(Lista F){
    //Declaración de contador.
    int i=1;
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    //Se recorre la lista.
    while(F != NULL){
        cout << " ~Fracción N° " << i << ":" << endl;
        //Se ve cada fracción.
        F -> fraccion.verFraccion(); 
        F = F -> link;
        
        //Se aumenta el contador.
        i++;
        
        cout << "------------------" << endl;
    }
    system("read -p 'Presione enter para volver al menú...' var");
}

//Función para contar fracciones.
void contarFracciones(Lista F){
    //Declaración de contador.
    int i=0;
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    //Se recorre la lista.
    while(F != NULL){
        if(F->fraccion.getNumerador() < F->fraccion.getDenominador()){
            //Se aumenta el contador cada vez que el numerador sea menor que el denominador.
            i++;
        }
    F = F -> link;
    }
    
    cout << "    Hay " << i << " fraccion(es) que su numerador es" << endl;
    cout << "    menor que su denominador (o es menor a 1)." << endl << endl;
    
    system("read -p 'Presione enter para volver al menú...' var");
}

//Función para mostrar la fracción mayor de una lista.
void mostrarMayor(Lista F){
    //Declaración de clase Fraccion auxiliar.
    Fraccion aux;
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    //Se recorre la lista.
    while(F != NULL){
        if(F->fraccion.getResultado() > aux.getResultado()){
            //Si la fraccion actual es mayor a la auxiliar, se reemplaza en esta.
            aux.setNumerador(F->fraccion.getNumerador());
            aux.setDenominador(F->fraccion.getDenominador());
            aux.setResultado();
        }
    F = F -> link;
    }
    
    cout << "La fracción mayor en la lista es : " << endl << endl;
    
    //Se muestra la lista mayor contenida en la fracción auxiliar.
    aux.verFraccionResultado();
    
    system("read -p 'Presione enter para volver al menú...' var");
}

//Función para calcular el promedio de las fracciones de una lista.
void promedioPrimos(Lista F){
    //Variable para guardar el resultado
    float resultado = 0;
    int i = 0;
    
    cout << "|----------                       LLS de fracciones                           ----------|" << endl << endl;
    
    //Se recorre la lista.
    while(F != NULL){
        if(esPrimo(F->fraccion.getNumerador()) == true){
            //Se suman las fracciones
            resultado = resultado + F->fraccion.getResultado();
            //Se cuentan la cantidad de fracciones
            i++;
        }
        F = F->link;
    }
    
    if(i == 0){
        //Si no se encuentran fracciones primas, se devuelve al menú.
        
        cout << "No se han encontrado fracciones con numerador primo." << endl << endl;
        
        system("read -p 'Presione enter para volver al menú...' var");
        return;
    }
    
    //Se divide en la cantidad de datos para sacar el promedio
    resultado = resultado / i;
    
    cout << "El promedio de fracciones con numerador primo es :  "<< resultado << endl << endl;
    
    system("read -p 'Presione enter para volver al menú...' var");
}