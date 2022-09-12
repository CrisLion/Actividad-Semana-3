#ifndef __PERSONA__
#define __PERSONA__
#include <iostream>
#include <functional>
using std::function;
using std::string;

struct Persona{
    string nombre;
    string direccion;
    string telefono;
    unsigned short edad;
    unsigned short num_comprado;

    Persona(const string& nombre, const string& direccion, const string& telef) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telef;
        this->edad = rand() % (70 - 18 + 1) + 18;
        this->num_comprado = rand() % (999999 - 100000 +1) + 100000;
    }

    void mostrarDatos(){
        std::cout<<"Nombre: "<<this->nombre<<"\nDireccion: "<<this->direccion<<"\nTelefono: "<<this->telefono<<
        "\nEdad: "<<std::to_string(this->edad)<<"\nNumero comprado: "<<std::to_string(this->num_comprado)<<
        "\n*************************************\n";
    }

};

#endif