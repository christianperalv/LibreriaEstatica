#pragma once
#ifndef GESTION_LISTA_COMPRA_H
#define GESTION_LISTA_COMPRA_H

#include <string>
#include <map>

class ListaCompra {
public:
    // Constructor
    ListaCompra();

    // M�todos
    void insertarProducto(const std::string& producto, int cantidad);
    void verLista() const;
    void guardarLista() const;

private:
    // Funci�n privada para convertir una cadena a min�sculas
    std::string toLowerCase(const std::string& str) const;

    // Miembro de datos
    std::map<std::string, int> listaCompra;
};

#endif // GESTION_LISTA_COMPRA_H
