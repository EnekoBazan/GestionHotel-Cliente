#ifndef MENUS_H_
#define MENUS_H_

#include <sqlite3.h>
#include <string>
class Menu {
public:
 //   Menu(sqlite3* db);
    void menuPrincipal();
    void iniciarSesionAdmin();
    void deustoBookingAdmin();
    void iniciarSesionUsuario();
    void registrarse();
    void deustoBooking();
    void reservar();
    void cancelarReserva();
    void cancelarHotel();
    void cancelarUsuario();

private:
 //   sqlite3* db;
    bool verificarAdmin(const std::string& nombreAdmin, const std::string& contrasena);
    bool verificarUsuario(const std::string& usuario, const std::string& contrasena);
    bool cargarHoteles();
    bool cargarUsuarios();
    bool cargarReservas();
    bool anadirUsuario(int id, const std::string& nombre, const std::string& apellido, const std::string& contrasena, const std::string& email);
    bool anadirReserva(int id, const std::string& nombreHotel, const std::string& fechaEntrada, const std::string& fechaSalida);
    void eliminarReserva(int codigoReserva);
    void eliminarHotel(int codigoHotel);
    void eliminarUsuario(int codigoUsuario);
};

#endif /* MENUS_H_ */
