/*Se dispone de un archivo denominado stock.dat correspondiente a la
existencia de artículos de un almacén. Se desea señalar aquellos artículos cuyo nivel de
existencia está por debajo del mínimo y que visualicen un mensaje: "Alerta: Hacer
Pedido". Cada artículo contiene un registro con los siguientes campos*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar los datos de un artículo
struct Articulo {
    string codigo;
    int nivel_minimo;
    int nivel_actual;
    string proveedor;
    double precio;
};

int main() {
    ifstream archivo("stock.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    Articulo articulo;
    while (archivo.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) {
        if (articulo.nivel_actual < articulo.nivel_minimo) {
            cout << "Código: " << articulo.codigo << endl;
            cout << "Proveedor: " << articulo.proveedor << endl;
            cout << "Precio: $" << articulo.precio << endl;
            cout << "Alerta: Hacer Pedido" << endl;
            cout << "-------------------------" << endl;
        }
    }

    archivo.close();

    return 0;
}