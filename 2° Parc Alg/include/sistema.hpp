#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "articulo.hpp"
#include "garrafa.hpp"
#include "accesorio.hpp"
#include "cliente.hpp"
#include "empleado.hpp"
#include "pedido.hpp"

/**
 * @class Sistema
 * @brief Controlador que administra las operaciones del negocio mediante arreglos estáticos de punteros de tamaño 100.
 */
class Sistema
{
private:
    static const int MAX = 100;

    Articulo* articulos[MAX];
    Cliente* clientes[MAX];
    Empleado* empleados[MAX];
    Pedido* pedidos[MAX];

    int contArticulos;
    int contClientes;
    int contEmpleados;
    int contPedidos;

public:
    Sistema();
    ~Sistema();

    // 2.1 Cargar Articulos
    bool cargarGarrafa(int id, std::string nombre, double precio, double capacidadKg);
    bool cargarAccesorio(int id, std::string nombre, double precio, std::string tipo);

    // 2.2 Cargar Clientes
    bool cargarCliente(int id, std::string nombre, std::string telefono);

    // 2.3 Cargar Empleados
    bool cargarEmpleado(int id, std::string nombre, std::string puesto);

    // 2.4 Cargar Pedidos de Artículos Asignados a los Clientes
    bool cargarPedido(int idPedido, int idCliente, int idArticulo, int cantidad);

    // Métodos de búsqueda eficientes mediante bucles while
    const Cliente* buscarClientePorId(int id) const;
    const Articulo* buscarArticuloPorId(int id) const;

    // 2.5 Mostrar los pedidos de los Clientes
    void mostrarPedidos() const;

    // Métodos independientes de visualización de listas bases en texto
    void mostrarArticulos() const;
    void mostrarClientes() const;
    void mostrarEmpleados() const;
};

#endif // SISTEMA_HPP
