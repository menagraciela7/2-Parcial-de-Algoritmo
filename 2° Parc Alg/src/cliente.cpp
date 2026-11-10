#include "cliente.hpp"

Cliente::Cliente() : id(0), nombre(""), telefono("")
{
}

Cliente::Cliente(int id, std::string nombre, std::string telefono) : id(id), nombre(nombre), telefono(telefono)
{
}

Cliente::~Cliente()
{
}

int Cliente::getId() const
{
    return id;
}

std::string Cliente::getNombre() const
{
    return nombre;
}

std::string Cliente::getTelefono() const
{
    return telefono;
}
