#include "sistema.hpp"
#include <iostream>

Sistema::Sistema() : contArticulos(0), contClientes(0), contEmpleados(0), contPedidos(0)
{
    int i = 0;
    while (i < MAX)
    {
        articulos[i] = nullptr;
        clientes[i] = nullptr;
        empleados[i] = nullptr;
        pedidos[i] = nullptr;
        i++;
    }
}

Sistema::~Sistema()
{
    int i = 0;
    while (i < contArticulos)
    {
        delete articulos[i];
        i++;
    }
    i = 0;
    while (i < contClientes)
    {
        delete clientes[i];
        i++;
    }
    i = 0;
    while (i < contEmpleados)
    {
        delete empleados[i];
        i++;
    }
    i = 0;
    while (i < contPedidos)
    {
        delete pedidos[i];
        i++;
    }
}

bool Sistema::cargarGarrafa(int id, std::string nombre, double precio, double capacidadKg)
{
    if (contArticulos >= MAX)
    {
        return false;
    }
    articulos[contArticulos] = new Garrafa(id, nombre, precio, capacidadKg);
    contArticulos++;
    return true;
}

bool Sistema::cargarAccesorio(int id, std::string nombre, double precio, std::string tipo)
{
    if (contArticulos >= MAX)
    {
        return false;
    }
    articulos[contArticulos] = new Accesorio(id, nombre, precio, tipo);
    contArticulos++;
    return true;
}

bool Sistema::cargarCliente(int id, std::string nombre, std::string telefono)
{
    if (contClientes >= MAX)
    {
        return false;
    }
    clientes[contClientes] = new Cliente(id, nombre, telefono);
    contClientes++;
    return true;
}

bool Sistema::cargarEmpleado(int id, std::string nombre, std::string puesto)
{
    if (contEmpleados >= MAX)
    {
        return false;
    }
    empleados[contEmpleados] = new Empleado(id, nombre, puesto);
    contEmpleados++;
    return true;
}

const Cliente* Sistema::buscarClientePorId(int id) const
{
    int i = 0;
    while (i < contClientes)
    {
        if (clientes[i]->getId() == id)
        {
            return clientes[i];
        }
        i++;
    }
    return nullptr;
}

const Articulo* Sistema::buscarArticuloPorId(int id) const
{
    int i = 0;
    while (i < contArticulos)
    {
        if (articulos[i]->getId() == id)
        {
            return articulos[i];
        }
        i++;
    }
    return nullptr;
}

bool Sistema::cargarPedido(int idPedido, int idCliente, int idArticulo, int cantidad)
{
    if (contPedidos >= MAX)
    {
        return false;
    }

    const Cliente* cli = buscarClientePorId(idCliente);
    const Articulo* art = buscarArticuloPorId(idArticulo);

    if (cli != nullptr && art != nullptr)
    {
        pedidos[contPedidos] = new Pedido(idPedido, cli, art, cantidad);
        contPedidos++;
        return true;
    }
    return false;
}

void Sistema::mostrarPedidos() const
{
    std::cout << "=========================================================\n";
    std::cout << "               LISTADO DE PEDIDOS REGISTRADOS            \n";
    std::cout << "=========================================================\n";

    if (contPedidos == 0)
    {
        std::cout << " No hay pedidos registrados en el sistema.\n";
    }

    int i = 0;
    while (i < contPedidos)
    {
        const Pedido* p = pedidos[i];
        std::cout << "Pedido ID: " << p->getIdPedido() << "\n";
        std::cout << "  Cliente: " << p->getCliente()->getNombre() << " (Tel: " << p->getCliente()->getTelefono() << ")\n";
        std::cout << "  Articulo: ";
        p->getArticulo()->mostrarDetalle();
        std::cout << "\n  Cantidad: " << p->getCantidad() << "\n";
        std::cout << "  Total del Pedido: $" << p->calcularTotal() << "\n";
        std::cout << "---------------------------------------------------------\n";
        i++;
    }
}

void Sistema::mostrarArticulos() const
{
    std::cout << "=========================================================\n";
    std::cout << "               LISTADO DE ARTICULOS EN STOCK             \n";
    std::cout << "=========================================================\n";
    
    if (contArticulos == 0)
    {
        std::cout << " No hay articulos cargados en el sistema.\n";
    }
    
    int i = 0;
    while (i < contArticulos)
    {
        std::cout << "ID: " << articulos[i]->getId() << " -> ";
        articulos[i]->mostrarDetalle();
        std::cout << "\n";
        i++;
    }
    std::cout << "---------------------------------------------------------\n";
}

void Sistema::mostrarClientes() const
{
    std::cout << "=========================================================\n";
    std::cout << "               LISTADO DE CLIENTES REGISTRADOS           \n";
    std::cout << "=========================================================\n";
    
    if (contClientes == 0)
    {
        std::cout << " No hay clientes cargados en el sistema.\n";
    }
    
    int i = 0;
    while (i < contClientes)
    {
        std::cout << "ID: " << clientes[i]->getId() 
                  << " | Nombre: " << clientes[i]->getNombre() 
                  << " | Tel: " << clientes[i]->getTelefono() << "\n";
        i++;
    }
    std::cout << "---------------------------------------------------------\n";
}

void Sistema::mostrarEmpleados() const
{
    std::cout << "=========================================================\n";
    std::cout << "               LISTADO DE EMPLEADOS DE LA EMPRESA        \n";
    std::cout << "=========================================================\n";
    
    if (contEmpleados == 0)
    {
        std::cout << " No hay empleados cargados en el sistema.\n";
    }
    
    int i = 0;
    while (i < contEmpleados)
    {
        std::cout << "ID: " << empleados[i]->getId() 
                  << " | Nombre: " << empleados[i]->getNombre() 
                  << " | Puesto: " << empleados[i]->getPuesto() << "\n";
        i++;
    }
    std::cout << "---------------------------------------------------------\n";
}
