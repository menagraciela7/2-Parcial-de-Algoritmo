#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

/**
 * @class Cliente
 * @brief Clase que representa a un cliente de la empresa.
 */
class Cliente
{
private:
    int id;
    std::string nombre;
    std::string telefono;

public:
    Cliente();
    Cliente(int id, std::string nombre, std::string telefono);
    ~Cliente();

    int getId() const;
    std::string getNombre() const;
    std::string getTelefono() const;
};

#endif // CLIENTE_HPP
