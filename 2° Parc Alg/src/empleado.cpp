#include "empleado.hpp"

Empleado::Empleado() : id(0), nombre(""), puesto("")
{
}

Empleado::Empleado(int id, std::string nombre, std::string puesto) : id(id), nombre(nombre), puesto(puesto)
{
}

Empleado::~Empleado()
{
}

int Empleado::getId() const
{
    return id;
}

std::string Empleado::getNombre() const
{
    return nombre;
}

std::string Empleado::getPuesto() const
{
    return puesto;
}
