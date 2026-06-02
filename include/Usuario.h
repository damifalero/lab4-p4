#ifndef USUARIO_H
#define USUARIO_H

#include "../include/DTUsuario.h"
#include "../include/Calificacion.h"
#include <string>
#include <set>

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float caliPromedio;
    std::set<Calificacion> calificaciones;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    //Getters
    std::string getNickname();
    std::string getNombre();
    std::string getContrasenia();
    std::string getEmail();
    float getPromedio();

    //Funciones
    bool esPasajero();
    DTUsuario getDTUsuario();
    void asociarCalificacion(Calificacion);
    void actualizarPromedio();
};

#endif
