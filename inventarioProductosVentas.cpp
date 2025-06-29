#include <iostream>
#include <windows.h>
using namespace std;

struct Producto{
    string nombre;
    float precio;
};

struct Venta{
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

void registrarProducto(){

}
void listarProductos(){

}

void buscarProducto(){

}

void actualizarProducto(){

}

void eliminarProducto(){

}

void registrarVenta(){

}

void listarVentas(){

}

void calcularTotalVentas(){

}

void menu(){
    SetConsoleOutputCP(CP_UTF8);
    int opcion;
    do{
        cout << "===== MENÚ PRINCIPAL =====";
        cout << "A: Registrar un nuevo producto\n";
        cout << "B: Listar los productos registrados\n";
        cout << "C: Buscar un producto por nombre\n";
        cout << "D: Actualizar los datos de un producto\n";
        cout << "E: Eliminar un producto\n";
        cout << "F: Registrar una venta\n";
        cout << "G: Listar las ventas realizadas\n";
        cout << "H: Calcular el total de ventas realizadas\n";
        cout << "S: Salir del programa\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion){
        case 'A':
            registrarProducto();
            break;
        case 'B':
            listarProductos();
            break;
        case 'C':
            buscarProducto();
            break;
        case 'D':
            actualizarProducto();
            break;
        case 'E':
            eliminarProducto();
            break;
        case 'F':
            registrarVenta();
            break;
        case 'G':
            listarVentas();
            break;
        case 'H':
            calcularTotalVentas();
            break;
        case 'S':
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Error, ingresa una opción válida..." << endl;
            break;
        }
    }while (opcion != 'S');
}

int main (){
    menu();
    
    return 0;
}