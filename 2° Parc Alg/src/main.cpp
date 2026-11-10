#include "sistema.hpp"
#include <iostream>
#include <string>

int main()
{
    Sistema empresaGas;
    int opcion = 0;

    int id = 0;
    int idCliente = 0;
    int idArticulo = 0;
    int idPedido = 0;
    int cantidad = 0;
    double precio = 0.0;
    double capacidadKg = 0.0;
    std::string nombre = "";
    std::string telefono = "";
    std::string puesto = "";
    std::string tipoAccesorio = "";
    int tipoArticulo = 0;

    while (opcion != 9)
    {
        std::cout << "\n=========================================================\n";
        std::cout << "               SISTEMA DE GESTION DE GAS                 \n";
        std::cout << "=========================================================\n";
        std::cout << "1. Cargar Articulo (Garrafa / Accesorio)\n";
        std::cout << "2. Cargar Cliente\n";
        std::cout << "3. Cargar Empleado\n";
        std::cout << "4. Cargar Pedido de Articulo Asignado a Cliente\n";
        std::cout << "5. Mostrar los Pedidos de los Clientes\n";
        std::cout << "6. Ver texto con los Articulos\n";
        std::cout << "7. Ver texto con los Clientes\n";
        std::cout << "8. Ver texto con los Empleados\n";
        std::cout << "9. Salir\n";
        std::cout << "---------------------------------------------------------\n";
        std::cout << "Seleccione una opcion (1-9): ";
        std::cin >> opcion;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n') 
            {
            }
            std::cout << "\n>> Error: Debe ingresar un numero entero.\n";
            opcion = 0;
            continue;
        }
        std::cin.ignore();

        if (opcion == 1)
        {
          std::cout << "\n--- CARGAR ARTICULO ---\n";

        tipoArticulo = 0;
        while (tipoArticulo != 1 && tipoArticulo != 2)
        {
            std::cout << "Tipo de Articulo (1: Garrafa, 2: Accesorio): ";
            std::cin >> tipoArticulo;

            if (std::cin.fail())
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                {
                }
                std::cout << ">> Error: Entrada invalida. Debe ingresar el numero 1 o 2.\n\n";
                tipoArticulo = 0;
                continue;
            }

            if (tipoArticulo != 1 && tipoArticulo != 2)
            {
                std::cout << ">> Error: Opcion fuera de rango. Seleccione 1 para Garrafa o 2 para Accesorio.\n\n";
            }
        }
            std::cout << "Ingrese ID del Articulo: ";
            std::cout << "\n--- CARGAR ARTICULO ---\n";
            std::cout << "Tipo de Articulo (1: Garrafa, 2: Accesorio): ";
            
            std::cin >> tipoArticulo;
            std::cout << "Ingrese ID del Articulo: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese Nombre/Descripcion: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Precio Unitario: ";
            std::cin >> precio;

            if (tipoArticulo == 1)
            {
                std::cout << "Ingrese Capacidad en Kg: ";
                std::cin >> capacidadKg;
                if (empresaGas.cargarGarrafa(id, nombre, precio, capacidadKg))
                {
                    std::cout << ">> Garrafa cargada con exito.\n";
                }
            }
            else if (tipoArticulo == 2)
            {
                std::cin.ignore();
                std::cout << "Ingrese Tipo de Accesorio: ";
                std::getline(std::cin, tipoAccesorio);
                if (empresaGas.cargarAccesorio(id, nombre, precio, tipoAccesorio))
                {
                    std::cout << ">> Accesorio cargado con exito.\n";
                }
            }
        }
        else if (opcion == 2)
        {
            std::cout << "\n--- CARGAR CLIENTE ---\n";
            std::cout << "Ingrese ID del Cliente: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese Nombre Completo: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Telefono: ";
            std::getline(std::cin, telefono);

            if (empresaGas.cargarCliente(id, nombre, telefono))
            {
                std::cout << ">> Cliente cargado con exito.\n";
            }
        }
        else if (opcion == 3)
        {
            std::cout << "\n--- CARGAR EMPLEADO ---\n";
            std::cout << "Ingrese ID del Empleado: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese Nombre Completo: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Puesto/Cargo: ";
            std::getline(std::cin, puesto);

            if (empresaGas.cargarEmpleado(id, nombre, puesto))
            {
                std::cout << ">> Empleado cargado con exito.\n";
            }
        }
        else if (opcion == 4)
        {
            std::cout << "\n--- CARGAR PEDIDO ASIGNADO ---\n";
            std::cout << "Ingrese ID del Pedido: ";
            std::cin >> idPedido;
            std::cout << "Ingrese ID del Cliente que solicita: ";
            std::cin >> idCliente;
            std::cout << "Ingrese ID del Articulo solicitado: ";
            std::cin >> idArticulo;
            std::cout << "Ingrese Cantidad: ";
            std::cin >> cantidad;

            if (empresaGas.cargarPedido(idPedido, idCliente, idArticulo, cantidad))
            {
                std::cout << ">> Pedido registrado correctamente.\n";
            }
            else
            {
                std::cout << ">> Error: No se encontro el Cliente/Articulo o limite alcanzado.\n";
            }
        }
        else if (opcion == 5)
        {
            empresaGas.mostrarPedidos();
        }
        else if (opcion == 6)
        {
            empresaGas.mostrarArticulos();
        }
        else if (opcion == 7)
        {
            empresaGas.mostrarClientes();
        }
        else if (opcion == 8)
        {
            empresaGas.mostrarEmpleados();
        }
        else if (opcion == 9)
        {
            std::cout << "\nSaliendo del programa de gestion...\n";
        }
        else
        {
            std::cout << "\n>> Opcion invalida.\n";
        }
    }

    return 0;
}
