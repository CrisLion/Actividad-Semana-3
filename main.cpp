#include "Controladora.hpp"

int main(){
    int opc;
    Controladora* objCon = new Controladora();

    while (true){
        std::cin>>opc; std::cin.ignore();
        switch (opc){
            case 0: objCon->registroAutomatico(); break;
            case 1: objCon->registrar(); break;
            case 2: objCon->mostrarPartcipantes(); break;
            case 3: objCon->GanadoresNumeroExacto(); break;
            case 4: objCon->Ganadores4Digitos(); break;
            case 5: objCon->GanadoresAnteriorSiguiente(); break;
        }
    }

    return 0;
}