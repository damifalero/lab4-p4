#ifndef USUARIO_H
#define USUARIO_H

#include "../include/DTUsuario.h"
#include "../include/Calificacion.h"
#include "../include/TipoUsuario.h"
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
    /*TipoUsuario* tipo;*/

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    //Getters
    std::string getNickname();
    std::string getNombre();
    std::string getContrasenia();
    std::string getEmail();
    float getPromedio();
    /*TipoUsuario* getTipo();*/

    //Funciones
    virtual bool esPasajero() = 0;

    DTUsuario getDTUsuario();
    void asociarCalificacion(Calificacion);
    void desasociarCalificaion(Calificacion);
    void actualizarPromedio();
};

#endif
