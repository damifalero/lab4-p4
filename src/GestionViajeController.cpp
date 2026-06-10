#include "../include/GestionViajeController.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorViajes.h"

/**********NO ESTOY SEGURO SI VAN O NO *********/
#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"

GestionViajeController* GestionViajeController::instancia = NULL;

GestionViajeController::GestionViajeController() {
    ultimoViaje = 0;
    codigoRecordado = 0;
}

GestionViajeController::~GestionViajeController() {
}

GestionViajeController* GestionViajeController::getInstance() {
    if (instancia == NULL)
        instancia = new GestionViajeController();

    return instancia;
}

/**********CASO DE USO GENERAR RESERVA**********/
std::set<std::string> GestionViajeController::listarPasajeros() {
    std::set<std::string> pasajeros;

    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    std::map<std::string, Usuario*> usuarios = mu->getUsuarios();

    std::map<std::string, Usuario*>::iterator it;

    for (it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* usuario = it->second;

        if (usuario->esPasajero()) {
            pasajeros.insert(usuario->getNickname());
        }
    }

    return pasajeros;
}

std::set<DTConsultaViaje> GestionViajeController::consultarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    std::map<int, Viaje*> viajes = mv->getViajes();

    std::set<DTConsultaViaje> consulta;

    std::map<int, Viaje*>::iterator it;

    for (it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* viaje = it->second;
        if (viaje->esBuscado(fecha, origen, destino, asientos)) {
            consulta.insert(viaje->getDataViaje());
        }
    }

    return consulta;
}

bool GestionViajeController::generarReserva(std::string nickname, int codigo, int asientos) {

    return false;
}

bool GestionViajeController::altaViaje(
    std::string matricula,
    DTFecha fecha,
    std::string origen,
    std::string destino,
    int asientos,
    float precio) {

    return false;
}

DTDetalleViaje GestionViajeController::detalleViaje(int codigo) {
    return DTDetalleViaje(
        0,
        DTFecha(1,1,2000),
        "",
        "",
        0,
        0,
        DTDetalleVehiculo("", "", 0),
        std::vector<DTDetalleReserva>()
    );
}

/**********CASO DE USO CALIFICAR USUARIO**********/
std::set<DTListarViaje> GestionViajeController::listarViajes(std::string nick) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    Usuario* usuario = mu->obtenerUsuario(nick);

    //guardo nick en memoria
    this->nicknameRecordado = nick;

    std::set<DTListarViaje> resultado;

    if(usuario->esPasajero()){
        Pasajero* pas = dynamic_cast<Pasajero*>(usuario);
        std::set<Reserva*> reservas = pas->getReservas();
        std::set<Reserva*>::iterator it;
        for (it = reservas.begin(); it != reservas.end(); ++it) {
            resultado.insert((*it)->getDTListarViaje());
        }
    }else{
        Conductor* cond = dynamic_cast<Conductor*>(usuario);
        std::set<Vehiculo*> vehiculos = cond->getVehiculos();
        std::set<Vehiculo*>::iterator it;
        for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
            std::set<DTListarViaje> viajes = (*it)->getSetDTListarViaje();
            resultado.insert(viajes.begin(), viajes.end());
        }
    }

    return resultado;
}

std::set<DTUsuarioViaje> GestionViajeController::listarUsuariosViaje(int codigo) {
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    Viaje* viaje = mv->obtenerViaje(codigo);
    //guardo codigo en memoria
    this->codigoRecordado = codigo;

    std::set<DTUsuarioViaje> resultado;

    std::set<Reserva*> reservas = viaje->getReservas();
    std::set<Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it) {
        //hay que castear???
        Pasajero* pas = (*it)->getPasajero();
        if(pas->getNickname() != this->nicknameRecordado){
            DTUsuarioViaje dtuv(pas->getNickname(), TipoUsuario::Tipo_Pasajero);
            resultado.insert(dtuv);
        }
    }

    std::string cond = viaje->getConductor();
    if(cond != this->nicknameRecordado){
        DTUsuarioViaje dtuv(cond, TipoUsuario::Tipo_Conductor);
        resultado.insert(dtuv);
    }

    return resultado;
}

std::set<DTListarViaje> GestionViajeController::listarViajes() {
    return std::set<DTListarViaje>();
}

void GestionViajeController::eliminarViaje() {
    
}

void GestionViajeController::cancelarEliminarViaje() {
}

