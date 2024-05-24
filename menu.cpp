#include "menu.h"
#include "string.h"
#include "Usuario.h"
#include <iostream>
#include <winsock2.h>
using namespace std;


void Menu::menuPrincipal() {
    int seleccion;

    do {
        std::cout << "\n== Menu Principal ==\n";
        std::cout << "1- Iniciar Sesion Administrador\n";
        std::cout << "2- Iniciar Sesion Usuario\n";
        std::cout << "3- Registrarse\n";
        std::cout << "4- Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> seleccion;

        switch (seleccion) {
            case 1:
                iniciarSesionAdmin();
                break;
            case 2:
                iniciarSesionUsuario();
                break;
            case 3:
                registrarse();
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
                break;
        }
    } while (seleccion != 4);
}

void Menu::iniciarSesionAdmin() {
    std::string nombreAdmin;
    std::string contrasena;

    std::cout << "\n== Iniciar Sesion administrador ==\n";
    std::cout << "Introduce el nombre de administrador: ";
    std::cin >> nombreAdmin;
    std::cout << "Introduce la contrasena: ";
    std::cin >> contrasena;

    if (verificarAdmin(nombreAdmin, contrasena)) {
        std::cout << "Inicio de sesion exitoso!\n";
        deustoBookingAdmin();
    } else {
        std::cout << "Nombre de administrador o contrasena incorrectos.\n";
    }
}

void Menu::deustoBookingAdmin() {
    int seleccion;

    do {
        std::cout << "\n== Deusto Booking==\n";
        std::cout << "1-Visualizar hoteles\n";
        std::cout << "2-Visualizar usuarios\n";
        std::cout << "3-Visualizar reservas\n";
        std::cout << "4-Cancelar una reserva\n";
        std::cout << "5-Cancelar un hotel\n";
        std::cout << "6-Eliminar un usuario\n";
        std::cout << "7-Cerrar Sesion\n";
        std::cin >> seleccion;

        switch (seleccion) {
            case 1:
                if (cargarHoteles()) {
                    std::cout << "Hoteles cargados correctamente\n";
                } else {
                    std::cout << "Error al cargar los hoteles\n";
                }
                break;
            case 2:
                if (cargarUsuarios()) {
                    std::cout << "Usuarios cargados correctamente\n";
                } else {
                    std::cout << "Error al cargar los usuarios\n";
                }
                break;
            case 3:
                if (cargarReservas()) {
                    std::cout << "Reservas cargadas correctamente\n";
                } else {
                    std::cout << "Error al cargar las reservas\n";
                }
                break;
            case 4:
                cancelarReserva();
                break;
            case 5:
                cancelarHotel();
                break;
            case 6:
                cancelarUsuario();
                break;
            case 7:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
                break;
        }
    } while (seleccion != 7);
}

void Menu::iniciarSesionUsuario() {
    std::string usuario;
    std::string contrasena;

    std::cout << "\n== Iniciar Sesión usuario ==\n";
    std::cout << "Introduce el nombre de usuario: ";
    std::cin >> usuario;
    std::cout << "Introduce la contraseña: ";
    std::cin >> contrasena;

    if (verificarUsuario(usuario, contrasena)) {
        std::cout << "Inicio de sesión exitoso!\n";
        deustoBooking();
    } else {
        std::cout << "Nombre de usuario o contraseña incorrectos.\n";
    }
}

void Menu::registrarse() {
    static int id = 5;
    std::string nombre, apellido, contrasena, email;

    std::cout << "\n== Registrarse==\n";
    std::cout << "Introduce el nombre : ";
    std::cin >> nombre;
    std::cout << "Introduce el apellido : ";
    std::cin >> apellido;
    std::cout << "Introduce la contrasena: ";
    std::cin >> contrasena;
    std::cout << "Introduce la direccion de residencia: ";
    std::cin >> email;

    if (anadirUsuario(id, nombre, apellido, contrasena, email)) {
        std::cout << "Registro exitoso!\n";
        id++;
    } else {
        std::cout << "Error al registrar el usuario.\n";
    }
}

void Menu::deustoBooking() {
    int seleccion;

    do {
        std::cout << "\n== Deusto Booking==\n";
        std::cout << "1-Buscar Hoteles\n";
        std::cout << "2-Hacer una reserva\n";
        std::cout << "3-Cancelar una reserva\n";
        std::cout << "4-Ver mis reservas\n";
        std::cout << "5-Cerrar Sesion\n";
        std::cin >> seleccion;

        switch (seleccion) {
            case 1:
                if (cargarHoteles()) {
                    std::cout << "Hoteles cargados correctamente\n";
                } else {
                    std::cout << "Error al cargar los hoteles\n";
                }
                break;
            case 2:
                reservar();
                break;
            case 3:
                cancelarReserva();
                break;
            case 4:
                if (cargarReservas()) {
                    std::cout << "Reservas cargadas correctamente\n";
                } else {
                    std::cout << "Error al cargar las reservas\n";
                }
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
                break;
        }
    } while (seleccion != 5);
}

void Menu::reservar() {
    int id;
    std::string nombreHotel, fechaEntrada, fechaSalida;

    std::cout << "== Reservar==\n";
    std::cout << "Introduce el id del hotel: ";
    std::cin >> id;
    std::cout << "Introduce el nombre del hotel: ";
    std::cin >> nombreHotel;
    std::cout << "Introduce la fecha de entrada: ";
    std::cin >> fechaEntrada;
    std::cout << "Introduce la fecha de salida: ";
    std::cin >> fechaSalida;

    if (anadirReserva(id, nombreHotel, fechaEntrada, fechaSalida)) {
        std::cout << "Reserva Realizada\n";
    } else {
        std::cout << "Error al realizar la reserva\n";
    }
}

void Menu::cancelarReserva() {
    int codigoReserva;

    std::cout << "== Cancelar Reservar==\n";
    std::cout << "Introduce el codigo de la reserva: ";
    std::cin >> codigoReserva;
    eliminarReserva(codigoReserva);
}

void Menu::cancelarHotel() {
    int codigoHotel;

    std::cout << "== Cancelar Hotel==\n";
    std::cout << "Introduce el codigo del hotel: ";
    std::cin >> codigoHotel;
    eliminarHotel(codigoHotel);
}

void Menu::cancelarUsuario() {
    int codigoUsuario;

    std::cout << "== Cancelar Usuario==\n";
    std::cout << "Introduce el codigo del usuario: ";
    std::cin >> codigoUsuario;
    eliminarUsuario(codigoUsuario);
}




