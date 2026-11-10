#include "articulo.hpp"

Articulo::Articulo() : id(0), nombre(""), precio(0.0)
{
}

Articulo::Articulo(int id, std::string nombre, double precio) : id(id), nombre(nombre), precio(precio)
{
}

Articulo::~Articulo()
{
}

int Articulo::getId() const
{
    return id;
}

std::string Articulo::getNombre() const
{
    return nombre;
}

double Articulo::getPrecio() const
{
    return precio;
}
