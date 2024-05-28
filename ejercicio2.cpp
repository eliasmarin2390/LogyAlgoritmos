/*Desarrollar un programa que permita ingresar y almacenar 5 registros de
información en el archivo agenda.dat, luego abrir el archivo e imprimir a pantalla todos
los registros.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar la información
struct Registro {
    string nombre;
    int edad;
    string direccion;
    string telefono;
    string ciudad;
};

int main() {
    const int numRegistros = 5;
    Registro registros[numRegistros];

    // Ingresar los datos
    for (int i = 0; i < numRegistros; ++i) {
        cout << "Registro " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> registros[i].nombre;
        cout << "Edad: ";
        cin >> registros[i].edad;
        cout << "Dirección: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, registros[i].direccion);
        cout << "Teléfono: ";
        cin >> registros[i].telefono;
        cout << "Ciudad: ";
        cin >> registros[i].ciudad;
    }

    // Guardar los datos en el archivo
    ofstream archivo("agenda.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    archivo.write(reinterpret_cast<char*>(&registros), sizeof(registros));
    archivo.close();

    // Leer los datos del archivo y mostrarlos en pantalla
    ifstream archivoLectura("agenda.dat", ios::binary);
    if (!archivoLectura) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return 1;
    }

    Registro registroLeido;
    while (archivoLectura.read(reinterpret_cast<char*>(&registroLeido), sizeof(registroLeido))) {
        cout << "Nombre: " << registroLeido.nombre << endl;
        cout << "Edad: " << registroLeido.edad << endl;
        cout << "Dirección: " << registroLeido.direccion << endl;
        cout << "Teléfono: " << registroLeido.telefono << endl;
        cout << "Ciudad: " << registroLeido.ciudad << endl;
        cout << "-------------------------" << endl;
    }

    archivoLectura.close();

    return 0;
}
