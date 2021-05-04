#include <iostream>
#include "Seguridad.h"

using namespace std;

int main()
{
    string nombre, codificado, textoarchivo, textobin, decodificado;
    int semilla, opcion;
    while (true) {
        cout << "Menu:";
        cout << "\n1. Codificar un archivo de texto";
        cout << "\n2. Decodificar un archico binario";
        cout << "\n3. Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        system("CLS");

        if(opcion==1){
            cout << "Ingrese en nombre del archivo a codificar: ";
            cin >> nombre;

            textoarchivo=Leer(nombre, 1);

            system("CLS");

            cout << "Ingrese la semilla de codificacion: ";
            cin >> semilla;

            system("CLS");

            codificado=Codificar1(Cabin(textoarchivo),semilla);
            Escribir("Bincodificado.bin", codificado);
            cout << "Archivo codificado exitosamente\n";
            cout << "Nota: El archivo codificado se guarda automaticamente como 'Bincodificado.bin'.\n\n\n";

            system("pause");
            system("CLS");

        }
        else if(opcion==2){
            cout << "Ingrese en nombre del archivo a decodificar: ";
            cin >> nombre;

            textobin=Leer(nombre,2);

            system("CLS");

            cout << "Ingrese la semilla de decodificacion: ";
            cin >> semilla;

            system("CLS");

            decodificado=Decodificar1(textobin,semilla);
            Escribir("Bindecodificado.bin", decodificado);
            cout << "Archivo decodificado exitosamente\n";
            cout << "Nota: El archivo decodificado se guarda automaticamente como 'Bindecodificado.bin'.\n\n\n";

            system("pause");
            system("CLS");
        }
        else{
            cout << "Proceso finalizado.\n\n\n";
            break;
        }
    }

    return 0;
}
