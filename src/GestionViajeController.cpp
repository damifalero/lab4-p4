#include "../include/GestionViajeController.h"

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

std::set<DTConsultaViaje> GestionViajeController::consultarViaje(DTFecha fecha, std::string origen,
    std::string destino,
    int asientos) {

    return std::set<DTConsultaViaje>();
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

std::set<DTUsuarioViaje> GestionViajeController::listarUsuariosViaje(int codigo) {
    return std::set<DTUsuarioViaje>();
}

std::set<DTListarViaje> GestionViajeController::listarViajes(std::string nick) {
    return std::set<DTListarViaje>();
}

std::set<DTListarViaje> GestionViajeController::listarViaje() {
    return std::set<DTListarViaje>();
}

void GestionViajeController::eliminarViaje() {
    
}

void GestionViajeController::cancelarEliminarViaje() {
}

bool GestionViajeController::generarReserva(
    std::string nickname,
    int codigo,
    int asientos) {

    return false;
}