#ifndef __CONTROLADORA__
#define __CONTROLADORA__

#include "Persona.hpp"
#include "Lista.hpp"
#include <string>
#include <math.h>
#define CONSUELO 20000
#define POZO 54343321

class Controladora {
private:
    Lista<Persona> participantes;
    int numGanador;

    bool Verificar4Digitos(const Nodo<Persona>* i){
        for(int j = pow(10,5); j > 0; j /= 10){
                if ((i->_dato.num_comprado / j) % 10 == (numGanador / j) % 10) return true;
        }
        return false;
    }

public:
    Controladora(){
        numGanador = rand() % (999999 - 100000 +1) + 100000;
    }

    void registroAutomatico(){
        for (int i = 0; i < 20; i++)
            participantes.push_back(Persona("Juan","Mi casa xd","993133234"));
    }

    void registrar(){
        string nombre, direccion, telefono;

        std::cout<<"Ingrese su nombre: "; getline(std::cin, nombre);
        std::cout<<"Ingrese su direccion: "; getline(std::cin, direccion);
        std::cout<<"Ingrese su telefono: "; getline(std::cin, telefono);

        participantes.push_back(Persona(nombre,direccion,telefono));
    }

    void mostrarPartcipantes(){
        participantes.displayList(Persona::mostrarDatos);
    }

    void GanadoresNumeroExacto(){
        int cont = 0;

        for(Nodo<Persona>* i = participantes.get_cabeza_Nodo(); i != nullptr; i = i->_siguiente){
            if (i->_dato.num_comprado == numGanador) cont++;
        }

        for(Nodo<Persona>* i = participantes.get_cabeza_Nodo(); i != nullptr; i = i->_siguiente){
            if (i->_dato.num_comprado == numGanador) {
                std::cout<<"\nFELICIADES GANO "<< (float)POZO/(float)cont <<"\n";
                i->_dato.mostrarDatos();
            }
        }
    }

    void Ganadores4Digitos(){
        
        for(Nodo<Persona>* i = participantes.get_cabeza_Nodo(); i != nullptr; i = i->_siguiente){
            int cont = 0;

            if (Verificar4Digitos(i)) cont++;

            if (cont >= 4 && i->_dato.num_comprado != numGanador){
                std::cout<<"\nFELICIADES GANO "<< CONSUELO <<"\n";
                i->_dato.mostrarDatos();
            }
        }
    }

    void GanadoresAnteriorSiguiente(){
        int cont = 0;
        float montoPorGanador;

        //Hallando la cantidad de personas
        for(Nodo<Persona>* i = participantes.get_cabeza_Nodo(); i != nullptr; i = i->_siguiente){
            if (i->_dato.num_comprado == numGanador) cont++;
        }
        //De esta manera calculamos el monto por ganador
        montoPorGanador = (float)POZO/(float)cont;

        for(Nodo<Persona>* i = participantes.get_cabeza_Nodo()->_siguiente; i != nullptr; i = i->_siguiente){
            
            //Verificando que no sea ganador numero exacto ni de 4 digitos
            if (i->_dato.num_comprado == numGanador || Verificar4Digitos(i)) continue;

            bool tiene4DigitosSiguiente = false;
            bool tiene4DigitosAnterior = false;
                          
            tiene4DigitosSiguiente = Verificar4Digitos(i->_siguiente);
            tiene4DigitosAnterior = Verificar4Digitos(i->_anterior);

            if (i->_anterior->_dato.num_comprado == numGanador && !tiene4DigitosSiguiente || 
                i->_siguiente->_dato.num_comprado == numGanador && tiene4DigitosAnterior){

                std::cout<<"\nFELICIADES GANO "<< montoPorGanador*0.1 <<"\n";
                i->_dato.mostrarDatos();

            }
            else if (i->_anterior->_dato.num_comprado == numGanador && tiene4DigitosSiguiente ||
                     i->_siguiente->_dato.num_comprado == numGanador && tiene4DigitosAnterior){

                std::cout<<"\nFELICIADES GANO "<< montoPorGanador*0.2 <<"\n";
                i->_dato.mostrarDatos();

            }
        }
    }
};


#endif