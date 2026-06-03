#include "../include/Usuario.h"

//Constructor y Destructor
Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->caliPromedio = 0;
}

Usuario::~Usuario() {}

//Getters
std::string Usuario::getNickname(){ return this->nickname; }
std::string Usuario::getNombre(){ return this->nombre; }
std::string Usuario::getContrasenia(){ return this->contrasena; }
std::string Usuario::getEmail(){ return this->email; }
float Usuario::getPromedio(){ return this->caliPromedio; }

//Funciones
bool Usuario::esPasajero(){} //¿Como se si el usuario es conductor o pasajero?(solo se me ocurre poner un atributo booleano)

DTUsuario Usuario::getDTUsuario(){
    DTUsuario datos(this->nickname, this->nombre);
    return datos;
}

void Usuario::asociarCalificacion(Calificacion cal){
    this->calificaciones.insert(cal);
}

void Usuario::actualizarPromedio(){
    int promedio = 0;
    std::set<Calificacion>::iterator it;
    for(it = this->calificaciones.begin(); it != this->calificaciones.end(); ++it){
        Calificacion current = *it;
        promedio = promedio + current.getPuntaje();
    }
    this->caliPromedio = promedio / calificaciones.size();
}