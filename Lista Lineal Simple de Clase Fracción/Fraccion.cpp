#include "Fraccion.h"

Fraccion::Fraccion(){
    this->numerador = 0;
    this->denominador = 0;
    this->resultado = 0;
}

Fraccion::Fraccion(int numerador, int denominador, float resultado){
    this->numerador = numerador;
    this->denominador = denominador;
    this->resultado = resultado;
}

Fraccion::~Fraccion(){

} 

int Fraccion::getNumerador(){
    return this->numerador;
}

void Fraccion::setNumerador(int newNumerador){
    this->numerador = newNumerador;
}

int Fraccion::getDenominador(){
    return this->denominador;
}

void Fraccion::setDenominador(int newDenominador){
    this->denominador = newDenominador;
}

float Fraccion::getResultado(){
    return this->resultado;
}

void Fraccion::setResultado(){
    this->resultado = (float)numerador / denominador;
}

void Fraccion::verFraccion(){
    cout << "      " << this->numerador << endl;
    cout << "     --- " << endl;
    cout << "      " << this->denominador << endl;
}

void Fraccion::verFraccionResultado(){
    cout << "  [Fracción]       [Resultado]" << endl << endl;
    cout << "      " << this->numerador << endl;
    cout << "     ---            " << this-> resultado << endl;
    cout << "      " << this->denominador << endl << endl;
}