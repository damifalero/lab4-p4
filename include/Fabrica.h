#ifndef FABRICA_H
#define FABRICA_H

#include "../include/ControladorFechaActual.h"
#include "../include/GestionViajeController.h"
#include "../include/UsuarioController.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IGestionViajeController.h"
#include "../include/IUsuarioController.h"

class Fabrica {
private:
    //Singleton
    static Fabrica* instancia;
    IControladorFechaActual* controladorFechaActual;
    IGestionViajeController* gestionViajeController;
    IUsuarioController* usuarioController;
    //Constructor y destructor
    Fabrica();
    ~Fabrica();
    //Bloquear copia y asignación
    Fabrica(const Fabrica&) = delete;
    Fabrica& operator=(const Fabrica&) = delete;
public:
    static Fabrica* getInstance();
    IControladorFechaActual* getIControladorFechaActual();
    IGestionViajeController* getIGestionViajeController();
    IUsuarioController* getIUsuarioController();
};

#endif
