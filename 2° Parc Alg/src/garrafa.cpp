#include "garrafa.hpp"
#include <iostream>

Garrafa::Garrafa() : Articulo(), capacidadKg(0.0)
{
}

Garrafa::Garrafa(int id, std::string nombre, double precio, double capacidadKg)
    : Articulo(id, nombre, precio), capacidadKg(capacidadKg)
{
}

Garrafa::~Garrafa()
{
}

void Garrafa::mostrarDetalle() const
{
    std::cout << "GARRAFA [" << capacidadKg << " Kg] - " << getNombre() << " ($" << getPrecio() << ")";
}
