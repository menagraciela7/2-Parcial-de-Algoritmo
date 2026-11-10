#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "articulo.hpp"

/**
 * @class Accesorio
 * @brief Clase derivada de Articulo que añade el tipo o categoría del accesorio.
 */
class Accesorio : public Articulo
{
private:
    std::string tipo;

public:
    Accesorio();
    Accesorio(int id, std::string nombre, double precio, std::string tipo);
    virtual ~Accesorio();

    virtual void mostrarDetalle() const override;
};

#endif // ACCESORIO_HPP
