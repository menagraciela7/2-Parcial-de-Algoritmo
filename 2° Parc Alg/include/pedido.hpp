#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "cliente.hpp"
#include "articulo.hpp"

/**
 * @class Pedido
 * @brief Relaciona un Cliente con un Articulo polimórfico mediante punteros simples.
 */
class Pedido
{
private:
    int idPedido;
    const Cliente* cliente;
    const Articulo* articulo;
    int cantidad;

public:
    Pedido();
    Pedido(int idPedido, const Cliente* cliente, const Articulo* articulo, int cantidad);
    ~Pedido();

    int getIdPedido() const;
    const Cliente* getCliente() const;
    const Articulo* getArticulo() const;
    int getCantidad() const;
    
    double calcularTotal() const;
};

#endif // PEDIDO_HPP
