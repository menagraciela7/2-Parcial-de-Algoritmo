#ifndef GARRAFA_HPP
#define GARRAFA_HPP

#include "articulo.hpp"

/**
 * @class Garrafa
 * @brief Clase derivada de Articulo que añade el tamaño o capacidad en Kg.
 */
class Garrafa : public Articulo
{
private:
    double capacidadKg;

public:
    Garrafa();
    Garrafa(int id, std::string nombre, double precio, double capacidadKg);
    virtual ~Garrafa();

    virtual void mostrarDetalle() const override;
};

#endif // GARRAFA_HPP
