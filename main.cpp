//Autor: Francisco Jeria Guerra, EDD sección 412.
//Tema: Convertidor notacion postfija o polaca inversa.
//Profesor: Diego Hernandez García.
//Fecha inicio: 15/05/2022.
//Fecha término: 27/05/2022.

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

//Funciones menu principal.
void convertirNotacion(queue<string>&, stack<string>&, string&);
void evaluarExpresion(queue<string>&, stack<string>&, string&);

//Funciones menu evaluar expresión.
void nuevaExpresionPostfija(queue<string>&, stack<string>&);
void antiguaExpresionPostfija(queue<string>&, stack<string>&, string&);

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    
    //Declaración variables.
    int opcion_menu;
    bool repetir;
    string expresionPostfija; //Se modifica mediante puntero.
    
    
    //Queue y stack a utilizar mediante punteros.
    queue<string> numeros;
    stack<string> operadores;
    
    //Menú principal.
    do{
        system("clear");
        
        cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
        cout << "|----      Convertir a notación postfija  [1]       Salir            [0]          ----|" << endl;
        cout << "|----      Evaluar expresión postfija     [2]                                     ----|" << endl << endl;
     
        cout << "   Seleccione una opción => ";

        cin >> opcion_menu;
        
        //Limpieza buffer.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << endl;
        system("clear");
        
        //Menu switch principal
        switch(opcion_menu){
        
        case 1:
            convertirNotacion(numeros, operadores, expresionPostfija);
            break;
        
        case 2:
            evaluarExpresion(numeros, operadores, expresionPostfija);
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

//Función para ver si un string es un número.
bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

//Funcion para separar un string en un vector string por delimitador.
vector<string> split(string lineaAseparar, char delimitador){
    
    vector<string> vector_interno;
    stringstream linea(lineaAseparar);
    string parteDelString;
    
    while(getline(linea, parteDelString, delimitador)){
    vector_interno.push_back(parteDelString);
    }
    
    return vector_interno;
}

//Funcion para convertir una expresion matemática en expresion postfija.
void convertirNotacion(queue<string> &numeros, stack<string> &operadores, string &expresionPostfija){
    
    //Inicializar variables.
    string caracteres = "";
    expresionPostfija = "";
    
    cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
    cout << "    Ingrese una operación matemática                     [EJEMPLO]" << endl;
    cout << "    para convertirla en una notación" << endl;
    cout << "    postfija (con cada carácter        ''( [ ( 2 + 3 ) * ( 5 - 2 ) ] + { 16 / 2 } )''" << endl;
    cout << "    separado por un espacio, y solo" << endl;
    cout << "    enteros positivos)." << endl << endl;
    
    cout << "    => ";
    
    getline(cin, caracteres);
    
    //Separar string expresión matemática.
    vector<string> posicion = split(caracteres, ' ');
    
    //Llenado de queue numeros y stack operadores, recorriendo vector posicion que contiene la expresión matemática.
    for(int i = 0; i < posicion.size() + 1; i++){
        //Si es numero, se agrega a queue numeros.
        if(isNumber(posicion[i])){
            numeros.push(posicion[i]);
        }
        //Si no, es un operador o paréntesis.
        else{
            operadores.push(posicion[i]);
            //Si es cierre de paréntesis, se agrega el operador a la queue numeros.
            if(operadores.top() == ")" || operadores.top() == "]" || operadores.top() == "}"){
                operadores.pop();
                numeros.push(operadores.top());
                operadores.pop();
                operadores.pop();
            }
        }
    }
    //Llenado de string con resultado de la notación.
    while(numeros.empty() == false){
        expresionPostfija.append(numeros.front()).append(" ");
        numeros.pop();
    }
    //Se eliminan espacios en blanco del string.
    expresionPostfija.pop_back();
    expresionPostfija.pop_back();
    
    system("clear");
    
    //Mostrar resultado.
    cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
    cout << "                    [RESULTADO]                                                        " << endl << endl;
    cout << "    Expresión antes de convertir: ''" << caracteres << "''"                              << endl << endl;
    cout << "    Resultado en notación postfija: ''" << expresionPostfija << "''"                     << endl << endl;
    
    system("read -p 'Presione enter para volver al menú...' var");
}

void evaluarExpresion(queue<string> &numeros, stack<string> &operadores, string &expresionPostfija){
    
    //Declaración variables.
    int opcion_menu;
    bool repetir;
    
    cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
    cout << "|----  Ingresar nueva notación postfija    [1]      Salir                   [0]   ----|" << endl;
    cout << "|----  Usar notación postfija de opción 1  [2]                                    ----|" << endl << endl;
    
    cout << "   Seleccione una opción => ";
    
    cin >> opcion_menu;
    
    //Limpieza buffer.
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    //Menu switch función evaluar expresión.
    switch(opcion_menu){
        
        case 1:
            nuevaExpresionPostfija(numeros, operadores);
            repetir = false;
            break;
        
        case 2:
            antiguaExpresionPostfija(numeros, operadores, expresionPostfija);
            repetir = false;
            break;

        case 0:
            repetir = false;
            break;
    
        default:
            cout << "¡¡Ingrese una opción válida!!" << endl << endl;
        }
    while(repetir);
    system("read -p 'Presione enter para volver al menú...' var");
}

void nuevaExpresionPostfija(queue<string> &numeros, stack<string> &operadores){
    
    system("clear");
    
    //Declaración variables.
    string newNotacionPostfija;
    int a, b, resultado;
    
    cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
    cout << "    Ingrese una operación matemática                    [EJEMPLO]            " << endl;
    cout << "    en formato notación postfija                                             " << endl;
    cout << "    (con cada caracter separado por             ''2 3 + 5 2 - * 16 2 / +''   " << endl;
    cout << "    un espacio)."                                                              << endl << endl;
    
    cout << "    => ";
    
    getline(cin, newNotacionPostfija);
    
    //Separar nueva expresión postfija.
    vector<string> posicion = split(newNotacionPostfija, ' ');
    
    for(int i = 0; i < posicion.size() + 1; i++){
        
        //Se ingresa el dato en operadores.
        operadores.push(posicion[i]);
        
        //Si es [ + , - , * , / ], operar según corresponda.
        if(operadores.top() == "+"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a + b;
            
            //Pasar resultado int a resultado string.
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            //Se envia resultado string de vuelta a operadores.
            operadores.push(resultadoString);
        }
        if(operadores.top() == "-"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a - b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
        if(operadores.top() == "*"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a * b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
        if(operadores.top() == "/"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a / b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
    }
    
    //Se saca espacios en blanco de operadores.
    operadores.pop();
    
    //Mostrar resultado.
    cout << endl;
    cout << "    Resultado redondeado de la notación postfija: ''" << operadores.top() << "''"                   << endl << endl;
    
    //Vaciar operadores.
    operadores.pop();
}

void antiguaExpresionPostfija(queue<string> &numeros, stack<string> &operadores, string &expresionPostfija){
    
    system("clear");
    
    //Declaración variables.
    int a, b, resultado;
    
    cout << "|----------                Convertidor notación postfija                    ----------|" << endl << endl;
    
    cout << "    Usando antigua expresión: ''"<< expresionPostfija << "''" << endl;
    
    //Separar expresión postfija de opción 1.
    vector<string> posicion = split(expresionPostfija, ' ');
    
    for(int i = 0; i < posicion.size() + 1; i++){
        
        //Se ingresa el dato en operadores.
        operadores.push(posicion[i]);
        
        //Si es [ + , - , * , / ], operar según corresponda.
        if(operadores.top() == "+"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a + b;
            
            //Pasar resultado int a resultado string.
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            //Se envia resultado string de vuelta a operadores.
            operadores.push(resultadoString);
        }
        if(operadores.top() == "-"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a - b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
        if(operadores.top() == "*"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a * b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
        if(operadores.top() == "/"){
            operadores.pop();
            b = atoi(operadores.top().c_str());
            operadores.pop();
            a = atoi(operadores.top().c_str());
            operadores.pop();
            resultado = a / b;
            
            stringstream ss;
            ss << resultado;
            string resultadoString = ss.str();
            
            operadores.push(resultadoString);
        }
    }
    //Se saca espacios en blanco de operadores.
    operadores.pop();
    
    //Mostrar resultado.
    cout << endl;
    cout << "    Resultado de la notación postfija: ''" << operadores.top() << "''"                   << endl << endl;
    
    //Vaciar operadores.
    operadores.pop();
}
