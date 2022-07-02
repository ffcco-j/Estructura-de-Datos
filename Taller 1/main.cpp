//Autor: Francisco Jeria Guerra, EDD sección 412.
//Tema: ABB de diccionario.
//Profesor: Diego Hernandez García.

#include <iostream>
#include <limits>
#include <string>

using namespace std;

//Nodo del Arbol binario de búsqueda.
struct Nodo{
    string palabra;
    int frecuencia;
    struct Nodo *izq;
    struct Nodo *der;
};

typedef Nodo *ABB;

//Datos de cada letra.
struct Dato{
    char letra;
    ABB T;
    int cantidadPalabras;
};

//Funciones auxiliares.
void enOrden(ABB &T);
void Mayor(ABB &T, ABB &aux);
void insterarABB(ABB &T, string key);
void eliminarABB(ABB &T, string key);
int buscarABB(ABB &T, string key);
void buscarRepetidasABB(ABB &T, int &i);

//Funciones del menú.
void inicializarDiccionario(Dato letras[25]);
void agregarPalabra(Dato letras[25]);
void eliminarPalabra(Dato letras[25]);
void mostrarDiccionario(Dato letras[25]);
void buscarPalabra(Dato letras [25]);
void mostrarRepetidas(Dato letras [25]);

int main(){
    setlocale(LC_CTYPE,"Spanish");
    
    Dato letras[25];
    
    //Declaración variables del menú.
    int opcion_menu;
    bool repetir = true;
    
    do{
        system("clear");
        
        cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
    
        cout << "|----      Inicializar diccionario        [1]       Buscar palabra             [5]    ----|" << endl;
        cout << "|----      Agregar palabra                [2]       Mostrar palabras repetidas [6]    ----|" << endl;
        cout << "|----      Eliminar palabra               [3]       Salir                      [0]    ----|" << endl;
        cout << "|----      Mostrar todo el diccionario    [4]                                         ----|" << endl << endl;
     
        cout << "   Seleccione una opción => ";
        
        cin >> opcion_menu;
        
        //Limpieza buffer.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        system("clear");
        
        //Menu switch principal
        switch(opcion_menu){
        
        case 1:
            inicializarDiccionario(letras);
            break;
        
        case 2:
            agregarPalabra(letras);
            break;
        
        case 3:
            eliminarPalabra(letras);
            break;
            
        case 4:
            mostrarDiccionario(letras);
            break;
            
        case 5:
            buscarPalabra(letras);
            break;
        
        case 6:
            mostrarRepetidas(letras);
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

//Funciones auxuliares

//Muestra los datos de menor a mayor.
void enOrden(ABB &T){
    if(T != NULL){
        enOrden(T->izq);
        cout << T->palabra << " - ";
        enOrden(T->der);
    }
}

//Busca el dato mayor del arbol.
void Mayor(ABB &T, ABB &aux){
    //Buscar el dato mayor 
    if(T->der != NULL){
        return Mayor(T->der, aux);
    } else{
        aux = T;
        T = T->izq;
    }
}

//Inserta un nodo al ABB.
void insterarABB(ABB &T, string key){
    if(T==NULL){
        T = new Nodo;
        T->palabra = key;
        T->frecuencia = T->frecuencia + 1;
        T->izq = NULL;
        T->der = NULL;
    } else{
        if(key > T->palabra){
            insterarABB(T->der, key);
        }
        if(key < T->palabra){
            insterarABB(T->izq, key);
        }
        if(key == T->palabra){
            T->frecuencia++;
        }
    }
}

//Elimina una palabra en el ABB.
void eliminarABB(ABB &T, string key){
    ABB aux;
    if(T!=NULL){
        if(key == T->palabra){
           aux = T;
            if(T->der == NULL){
                T = T->izq;
            } else {
                if(T->izq == NULL){
                    T = T->der;
                } else {
                    Mayor(T->izq, aux);
                    T->palabra = aux->palabra;
                }
                delete aux;
                T->frecuencia = T->frecuencia - 1;
            }
            cout << "    Palabra eliminada exitosamente." << endl << endl;
        } else {
            if(key > T->palabra){
                eliminarABB(T->der, key);
            } else {
                eliminarABB(T->der, key);
            }
        }
    } else{
        cout << "    No se ha encontrado la palabra." << endl << endl;
    }
}

//Busca una palabra en el ABB.
int buscarABB(ABB &T, string key){
    if(T==NULL){
        return 0;
    } else {
        if(key > T->palabra){
            buscarABB(T->der, key);
        } else{
            if(key < T->palabra){
                buscarABB(T->izq, key);
            } else{
                if (key == T->palabra){
                    return T->frecuencia;
                }
            }
        }
    return 0;
    }
}

//Mostrar solo las palabras repetidas.
void buscarRepetidasABB(ABB &T, int &i){
    if(T != NULL){
        buscarRepetidasABB(T->izq, i);
        if(T->frecuencia >= 2){
            cout << "   " << T->palabra << " se repite ''" << T->frecuencia << "'' veces." << endl;
            i++;
        }
        buscarRepetidasABB(T->der, i);
    }
}

//Funciones del menú

//inicializar diccionario en default.
void inicializarDiccionario(Dato letras[25]){
    for(int i = 0 ; i <= 25; i++){
        letras[i].letra = char(97 + i);
        letras[i].cantidadPalabras = 0;
        letras[i].T = NULL;
    }
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
        
    cout << "     El diccionario fue inicializado correctamente" << endl << endl;
    system("read -p 'Presione enter para volver al menú...' var");
}

//Agrega una palabra al diccionario.
void agregarPalabra(Dato letras[25]){
    
    char i;
    int a;
    string newPalabra;
    
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
        
    cout << "     Ingrese una letra del diccionario para agregar una palabra: ";
    cin >> i;
        
    //Limpieza buffer.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    a = int(i) - 97;
    
    cout << "     Ingrese la palabra que empieze con la letra escogida (sólo minúsulas): ";
    getline(cin, newPalabra);
    cout << endl;
    
    insterarABB(letras[a].T, newPalabra);
    
    cout << "     Palabra: ''" << newPalabra << "'' agregada a la letra ''" << i << "'' correctamente." << endl << endl;
    
    letras[a].cantidadPalabras++;
    
    system("read -p 'Presione enter para volver al menú...' var");
}

//Elimina una palabra al diccionario.
void eliminarPalabra(Dato letras[25]){
    int i;
    string newPalabra;
    
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
        
    cout << "     Ingrese una letra del diccionario para eliminar una palabra: ";
    cin >> i;
        
    //Limpieza buffer.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    cout << "     Ingrese la palabra a eliminar (sólo minúsulas): ";
    getline(cin, newPalabra);
    cout << endl;
    
    eliminarABB(letras[i].T, newPalabra);
    
    letras[i].cantidadPalabras--;
    
    system("read -p 'Presione enter para volver al menú...' var");
}

//Muestra todo el diccionario.
void mostrarDiccionario(Dato letras[25]){
    
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
    
    for(int i = 0; i <= 25; i++){
        cout << "     Letra " << letras[i].letra << ":" << endl << endl;
        enOrden(letras[i].T);
        cout << endl;
        cout << " ----------------" << endl;
    }
    system("read -p 'Presione enter para volver al menú...' var");
}

//Busca una palabra en el diccionario.
void buscarPalabra(Dato letras[25]){
    string aux;
    int i;
    
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
    
    cout << "   Ingrese una letra del diccionario para buscar una palabra: ";
    cin >> i;
        
    //Limpieza buffer.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    cout << "   Ingrese una palabra para ver cuántas veces está repetida: ";
    getline(cin, aux);
    cout << endl;

    cout << "   La palabra " << aux << " esta repetida " << buscarABB(letras[i].T, aux) << " veces." << endl << endl;
    system("read -p 'Presione enter para volver al menú...' var");
}

//Muestra solo las palabras repetidas.
void mostrarRepetidas(Dato letras [25]){
    int aux = 0;
    cout << "|----------                        ABB de diccionario                           ----------|" << endl << endl;
    
    cout << "   Mostrando todas las palabras repetidas: " << endl << endl;
    for(int i = 0; i <= 25; i++){
        buscarRepetidasABB(letras[i].T, aux);
    }
    if(aux == 0){
        cout << "   No hay palabras repetidas." << endl;
    }
    cout << endl;
    system("read -p 'Presione enter para volver al menú...' var");
}

