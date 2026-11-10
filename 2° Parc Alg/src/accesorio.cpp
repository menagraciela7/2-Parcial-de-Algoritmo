#include "accesorio.hpp"
#include <iostream>

Accesorio::Accesorio() : Articulo(), tipo("")
{
}

Accesorio::Accesorio(int id, std::string nombre, double precio, std::string tipo)
    : Articulo(id, nombre, precio), tipo(tipo)
{
}

Accesorio::~Accesorio()
{
}

void Accesorio::mostrarDetalle() const
{
    std::cout << "ACCESORIO (" << tipo << ") - " << getNombre() << " ($" << getPrecio() << ")";
}
