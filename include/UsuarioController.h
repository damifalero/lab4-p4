#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include <string>
#include <set>
#include "GestionViajeController.h"
#include "IUsuarioController.h"
#include "TipoVehiculo.h"
#include "DTUsuario.h"
#include "TipoLibreta.h"
#include "DTVehiculosConductor.h"

class UsuarioController : public IUsuarioController{
private:
    static UsuarioController* instancia;
    std::string nicknameRecordado;
    int codigoRecordado;

public:
    //Constructor y destructor
    UsuarioController();
    virtual ~UsuarioController();
    

    //getters
    static UsuarioController* getInstancia();
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
