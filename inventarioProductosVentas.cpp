#include <iostream>
#include <string>
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

void registrarProducto(Producto producto[], int &contProducto){
    cout << "\nIngrese el nombre del producto número " << contProducto + 1 << ":" << endl;
    cin.ignore();
    getline(cin, producto[contProducto].nombre);

    cout << "Ingrese el precio del producto:" << endl;
    cin >> producto[contProducto].precio;

    while (cin.fail()){
        cout << "Error: ingrese un número válido y mayor a 0:" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> producto[contProducto].precio;
    }
    contProducto++;
}

void listarProductos(Producto producto[], int contProducto){
    cout << "\nLos productos listados son:" << endl;
    for (int i = 0; i < contProducto; i++){
        cout << "\nProducto " << i + 1 << endl;
        cout << "Nombre: " << producto[i].nombre << endl;
        cout << "Precio: " << producto[i].precio << endl;
    }
}

void buscarProducto(Producto producto[], int contProducto){
    string nombreProducto;
    cout << "\nIngrese el nombre del producto a buscar:" << endl;
    cin.ignore();
    getline(cin, nombreProducto);

    for (int i = 0; i < contProducto; i++){
        if (producto[i].nombre == nombreProducto){
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << producto[i].nombre << endl;
            cout << "Precio: " << producto[i].precio << endl;
            return;
        }else{
            cout << "Producto no encontrado." << endl;
        }
    }
}

void actualizarProducto(Producto producto[], int contProducto){
    string nombreProducto;
    cout << "\nIngrese el nombre del producto a actualizar:" << endl;
    cin.ignore();
    getline(cin, nombreProducto);

    for (int i = 0; i < contProducto; i++){
        if (producto[i].nombre == nombreProducto){
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << producto[i].nombre << endl;
            cout << "Precio: " << producto[i].precio << endl;

            cout << "\nIngrese el nuevo nombre del producto:" << endl;
            getline(cin, producto[i].nombre);
            cout << "Ingrese el nuevo precio del producto:" << endl;
            cin >> producto[i].precio;

            while (cin.fail()){
                cout << "Error: ingrese un número válido y mayor a 0:" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> producto[i].precio;
            }
            cout << "\nProducto actualizado con éxito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
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
    const int MAX_PRODUCTOS = 100;
    const int MAX_VENTAS = 100;
    Producto producto[MAX_PRODUCTOS];
    Venta venta[MAX_VENTAS];
    int contadorProductos = 0;
    char opcion;
    string opcionString;

    do{
        cout << "===== MENÚ PRINCIPAL =====\n";
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
        cin >> opcionString;
        if(opcionString.length() != 1){
            opcion = 'X';
        }else{
            opcion = toupper(opcionString[0]);
        }

        switch (opcion){
        case 'A':
            registrarProducto(producto, contadorProductos);
            break;
        case 'B':
            listarProductos(producto, contadorProductos);
            break;
        case 'C':
            buscarProducto(producto, contadorProductos);
            break;
        case 'D':
            actualizarProducto(producto, contadorProductos);
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
            cout << "\nSaliendo del programa..." << endl;
            break;
        default:
            cout << "\nError, ingresa una opción válida..." << endl;
            break;
        }
        if (opcion != 'S'){
            system("PAUSE");
            system("cls");
        }
    }while (opcion != 'S');
}

int main (){
    menu();
    
    return 0;
}