#include "pedido.hpp"

Pedido::Pedido() : idPedido(0), cliente(nullptr), articulo(nullptr), cantidad(0)
{
}

Pedido::Pedido(int idPedido, const Cliente* cliente, const Articulo* articulo, int cantidad) 
    : idPedido(idPedido), cliente(cliente), articulo(articulo), cantidad(cantidad)
{
}

Pedido::~Pedido()
{
}

int Pedido::getIdPedido() const
{
    return idPedido;
}

const Cliente* Pedido::getCliente() const
{
    return cliente;
}

const Articulo* Pedido::getArticulo() const
{
    return articulo;
}

int Pedido::getCantidad() const
{
    return cantidad;
}

double Pedido::calcularTotal() const
{
    if (articulo != nullptr)
    {
        return cantidad * articulo->getPrecio();
    }
    return 0.0;
}
