#include "../include/GestionViajeController.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorViajes.h"
#include "../include/ManejadorVehiculo.h"

/**********NO ESTOY SEGURO SI VAN O NO *********/
#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"
#include "../include/Calificacion.h"
#include <ControladorFechaActual.h>



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
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    Usuario* usuario = mu->obtenerUsuario(nickname);

    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    Viaje* viaje = mv->obtenerViaje(codigo);

    if (usuario == NULL || viaje == NULL){
         return false;
    }

    if (!viaje->cantAsientosValida(viaje->cantAsientosRes(), asientos, viaje->getAsientosPublicados())){
         return false;
    }

    /*const std::map<int, Reserva*>& reservas = mv->getReservas();
    std::map<int, Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it) {       
        Reserva* reserva = it->second;
        if (reserva->getPasajero()->getNickname() == nickname && reserva->getViaje()->getCodigo() == codigo) {
            return false; // El pasajero ya tiene una reserva para ese viaje
        }
    }
    
    if (!usuario->esPasajero()){
         return false; // El usuario no es un pasajero
    }*/

    //Validación clave generada para reserva
    std::string claveBuscada = std::to_string(codigo) + "-" + nickname;
    const std::map<std::string, Reserva*>& reservas = mv->getReservas();

    if (reservas.find(claveBuscada) != reservas.end()){
        return false; //El pasajero ya tiene una reserva para este viaje
    }

    if (!usuario->esPasajero()){
        return false;
    }
    
    Pasajero* pas = dynamic_cast<Pasajero*>(usuario);
    if (pas == NULL){
        return false; //El dynamic_cast falló, el usuario no es pasajero real
    }

    ControladorFechaActual* cfa = ControladorFechaActual::getInstance();
    DTFecha fechaActual = cfa->getFecha();

    Reserva* reserva = new Reserva(asientos, fechaActual, *pas, *viaje);
    mv->agregarReserva(reserva);
    viaje->addReserva(reserva);
    pas->asociarReserva(reserva);
    return true;
}

/**********CASO DE USO ALTA VIAJE**********/
bool GestionViajeController::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    ManejadorVehiculo* mvh = ManejadorVehiculo::getInstancia();
    Vehiculo* vehiculo = mvh->obtenerVehiculo(matricula);

    if (vehiculo == NULL)
        return false;

    // Si se publican más asientos que la capacidad del vehículo
    if (asientos > vehiculo->getCapacidad())
        return false;

    // Obtener conductor asociado al vehículo
    Conductor* conductor = vehiculo->getConductor();

    // Si el conductor ya tiene un viaje ese día
    if (conductor != NULL && conductor->hayViajesFechaConductor(fecha)){
        return false;
    }

    // Crear el viaje
    Viaje* viaje = new Viaje(
        ultimoViaje + 1,
        fecha,
        origen,
        destino,
        asientos,
        asientos,   // asientos disponibles inicialmente
        precio,
        vehiculo
    );

    // Crear link entre Vehiculo y Viaje
    vehiculo->asociarViaje(viaje);

    // Registrar el viaje en el manejador
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    mv->agregarViaje(viaje);

    // Actualizar último código utilizado
    ultimoViaje = viaje->getCodigo();

    return true;
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
        Pasajero* pas = dynamic_cast<Pasajero*>((*it)->getPasajero());
        if(pas != NULL && pas->getNickname() != this->nicknameRecordado){
            DTUsuarioViaje dtuv(pas->getNickname(), TipoUsuario::Tipo_Pasajero);
            resultado.insert(dtuv);
        }
    }

    std::string cond = viaje->getConductor();
    if(!cond.empty() && cond != this->nicknameRecordado){
        DTUsuarioViaje dtuv(cond, TipoUsuario::Tipo_Conductor);
        resultado.insert(dtuv);
    }

    return resultado;
}

/**********CASO DE USO ELIMINAR VIAJE**********/

std::set<DTListarViaje> GestionViajeController::listarViajes() {
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    std::map<int, Viaje*> viajes = mv->getViajes();
    
    std::set<DTListarViaje> resultado;
    std::map<int, Viaje*>::iterator it;
    for (it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* viaje = it->second;
        resultado.insert(viaje->getDTListarViaje());
    }

    return resultado;
}

DTDetalleViaje GestionViajeController::detalleViaje(int codigo) {
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    Viaje* viaje = mv->obtenerViaje(codigo);
    //guardo codigo en memoria
    this->codigoRecordado = codigo;

    return viaje->getDTDetalleViaje();
}

void GestionViajeController::eliminarViaje() {
    ManejadorViajes* mv = ManejadorViajes::getInstancia();
    Viaje* viaje = mv->obtenerViaje(codigoRecordado);

    if (viaje == NULL){
        return;
    }

    Vehiculo* vehiculo = viaje->getVehiculo();
    if (vehiculo != NULL){
        // Desasociar el viaje del vehículo
        vehiculo->desasociarViaje(viaje);
        viaje->desasociarVehiculo();
    }
    

    std::set<Reserva*> reservas = viaje->getReservas();
    std::set<Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it) {
        Reserva* res = *it;
        if (res == NULL){
            return;
        }
        std::set<Calificacion*> calificaciones = res->getCalificaciones();    
        std::set<Calificacion*>::iterator itCal;
        for (itCal = calificaciones.begin(); itCal != calificaciones.end(); ++itCal) {
            Calificacion* calificacion = *itCal;
            if (calificacion != NULL){
                Usuario* uCalificado = calificacion->getUCalificado();
                Usuario* uCalificador = calificacion->getUCalificador();

                calificacion->desasociarReserva();
                res->desasociarCalificacion(calificacion);
                calificacion->desasociarUsuarioCalificado();
                calificacion->desasociarUsuarioCalificador();

                if (uCalificado!= NULL){
                    uCalificado->desasociarCalificacion(calificacion);
                }
                if (uCalificador != NULL){
                    uCalificador->desasociarCalificacion(calificacion);
                }

                delete calificacion;
            }
            
        }

        Pasajero* pas = dynamic_cast<Pasajero*>(res->getPasajero());
        if (pas != NULL){
            pas->desasociarReserva(res);
        }
        res->desasociarViaje();
        res->desasociarPasajero();
        viaje->desasociarReserva(res);
        delete (res);

        
    }
    delete viaje;
    this->codigoRecordado = -1;
}

void GestionViajeController::cancelarEliminarViaje() {
    this->codigoRecordado = -1;
}

