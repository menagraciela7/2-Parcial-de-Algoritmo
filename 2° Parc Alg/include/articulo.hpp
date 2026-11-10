#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include <string>

/**
 * @class Articulo
 * @brief Clase base abstracta que representa un artículo general del negocio.
 * 
 * Implementa la Abstracción definiendo los atributos indispensables de cualquier artículo.
 */
class Articulo
{
private:
    int id;
    std::string nombre;
    double precio;

public:
    Articulo();
    Articulo(int id, std::string nombre, double precio);
    
    /**
     * @brief Destructor virtual obligatorio para liberar memoria dinámica en cascada.
     */
    virtual ~Articulo();

    int getId() const;
    std::string getNombre() const;
    double getPrecio() const;

    /**
     * @brief Método virtual puro que obliga a las subclases a identificarse de forma polimórfica.
     */
    virtual void mostrarDetalle() const = 0;
};

#endif // ARTICULO_HPP
