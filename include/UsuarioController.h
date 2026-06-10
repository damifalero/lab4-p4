<<<<<<< HEAD
#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include <string>
#include <set>
#include "TipoVehiculo.h"
#include "DTUsuario.h"
#include "TipoLibreta.h"
#include "DTVehiculosConductor.h"

class UsuarioController{
private:
    std::string nicknameRecordado;
    int codigoRecordado;
public:
    //Destructor
    ~UsuarioController();
    //el controlador tiene constructor o lo pongo en la interfaz?

    //getters
    std::string getNicknameRecordado();
    int getCodigoRecordado();

    //setters
    void setNicknameRecordad(std::string nickname);
    void setCodigoRecordado(int codigo);


    //operaciones
    bool altaPasajero(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::string ci);
    bool altaConductor(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::set<TipoLibreta> libretas);
    std::set<DTUsuario> listarUsuarios();
    bool calificarUsuario(std::string nicknameCalificado,int calificacion);
    int registrarVehiculo(std::string nickname,std::string matricula,int capacidad,std::string marca,std::string modelo,TipoVehiculo tipo);
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
};

#endif

=======
#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include <string>
#include <set>
#include "DTUsuario.h"
#include "DTVehiculosConductor.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class UsuarioController {
    private:
        std::string nicknameRecordado;
        int codigoRecordado;
    public:
        UsuarioController();
        bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
        bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
        std::set<DTUsuario> listarUsuarios();
        bool calificarUsuario(std::string nicknameCalificado, int calificacion);
        int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
        std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
};

#endif // USUARIO_CONTROLLER_H
>>>>>>> 30cc190797d3cd0c6e0bfac1402ba36d0a369787
