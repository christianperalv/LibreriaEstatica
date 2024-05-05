#include <iostream>
#include <fstream>
#include <map>
#include <algorithm> // Para convertir a minúsculas
using namespace std;

// Función para convertir una cadena a minúsculas
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    map<string, int> listaCompra;

    // Cargar datos de lista de la compra desde un archivo si existe
    ifstream archivo_lectura("lista_compra.txt");
    if (archivo_lectura.is_open()) {
        string producto;
        int cantidad;
        while (archivo_lectura >> producto >> cantidad) {
            listaCompra[toLowerCase(producto)] = cantidad;
        }
        archivo_lectura.close();
    }

    while (true) {
        cout << "\n1. Insertar producto\n2. Ver lista\n3. Salir\nElija una opción: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string producto;
            cout << "Ingrese el nombre del producto: ";
            cin >> producto;

            int cantidad;
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;

            // Convertir a minúsculas para la comparación
            string productoLowerCase = toLowerCase(producto);

            // Verificar si el producto ya está en la lista
            auto it = listaCompra.find(productoLowerCase);
            if (it != listaCompra.end()) {
                cout << "El producto ya está en la lista. Se modificará la cantidad." << endl;
                it->second = cantidad; // Modificar la cantidad
            }
            else {
                listaCompra[productoLowerCase] = cantidad; // Insertar el nuevo producto
            }
            break;
        }
        case 2: {
            cout << "\nLista de la compra:" << endl;
            if (listaCompra.empty()) {
                cout << "La lista está vacía." << endl;
            }
            else {
                for (const auto& par : listaCompra) {
                    cout << par.first << " - Cantidad: " << par.second << endl;
                }
            }
            break;
        }
        case 3:
            // Guardar la lista de la compra en un archivo antes de salir
            ofstream archivo_escritura("lista_compra.txt");
            if (archivo_escritura.is_open()) {
                for (const auto& par : listaCompra) {
                    archivo_escritura << par.first << " " << par.second << endl;
                }
                archivo_escritura.close();
            }
            else {
                cerr << "Error al guardar la lista de la compra en el archivo." << endl;
            }
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            cout << "Opción no válida. Por favor, elija de nuevo." << endl;
        }
    }

    return 0;
}
