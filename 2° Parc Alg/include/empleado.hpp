#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

/**
 * @class Empleado
 * @brief Clase que representa a un empleado de la empresa.
 */
class Empleado
{
private:
    int id;
    std::string nombre;
    std::string puesto;

public:
    Empleado();
    Empleado(int id, std::string nombre, std::string puesto);
    ~Empleado();

    int getId() const;
    std::string getNombre() const;
    std::string getPuesto() const;
};

#endif // EMPLEADO_HPP
