#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <string>

using namespace std;

class Fraccion{
    //Datos privados.
    private:
        int numerador;
        int denominador;
        float resultado;
    //Datos públicos.
    public:
        //Constructores y destructor.
        Fraccion();
        Fraccion(int, int, float);
        ~Fraccion();
        
        //Setters y Getters.
        int getNumerador();
        void setNumerador(int);
        
        int getDenominador();
        void setDenominador(int);
        
        float getResultado();
        void setResultado();
        
        //Funcion miembro ver.
        void verFraccion();
        void verFraccionResultado();
};

#endif