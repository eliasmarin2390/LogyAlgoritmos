/* Desarrollar un programa que permita crear un archivo agenda.dat de
direcciones, cuyos registros constan de los siguientes campos*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct registro{
    string name;
    int age;
    string  country;
    string phone;
    string direcctions;
};

int main() {
    // Crear un arreglo de registros
    registros[] = {
        {"Juan Pérez", 30, "Managua", "123456789", "Calle Principal 123"},
        {"María López", 25, "León", "987654321", "Avenida Central 456"}
        // Agrega más registros aquí según tus necesidades
    };

    // Escribir los registros en el archivo agenda.dat
    ofstream archivo("agenda.dat");
    if (archivo.is_open()) {
        for (const auto& registro : registros) {
            archivo << registro.nombre << ", " << registro.edad << ", "
                    << registro.ciudad << ", " << registro.telefono << ", "
                    << registro.direccion << endl;
        }
        archivo.close();
        cout << "Archivo agenda.dat creado exitosamente." << std::endl;
    } else {
        cerr << "Error al abrir el archivo." << endl;
    }

    return 0;
}

 


