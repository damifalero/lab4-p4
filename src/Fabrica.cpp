#include "../include/Fabrica.h"


Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IGestionViajeController* Fabrica::getIGestionViajeController() {
    return GestionViajeController::getInstance();
}

IUsuarioController* Fabrica::getIUsuarioController() {
    return UsuarioController::getInstancia();
}
