#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include "DTUsuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include <string>
#include <set>

class IUsuarioController {
public:
    virtual bool altaPasajero(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::string ci) = 0;
    virtual bool altaConductor(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::set<TipoLibreta> libretas) = 0;
    virtual std::set<DTUsuario> listarUsuarios() = 0;
    virtual bool calificarUsuario(std::string nicknameCalificado,int calificacion) = 0;
    virtual int registrarVehiculo(std::string nickname,std::string matricula,int capacidad,std::string marca,std::string modelo,TipoVehiculo tipo) = 0;
    virtual std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;

    virtual ~IUsuarioController(){};
};

#endif IUSUARIOCONTROLLER_H