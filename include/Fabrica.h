#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IGestionViajeController.h"
#include "IUsuarioController.h"

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
