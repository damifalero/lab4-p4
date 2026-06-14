#ifndef CONTROLADOR_FECHA_ACTUAL_H
#define CONTROLADOR_FECHA_ACTUAL_H

#include "IControladorFechaActual.h"

class ControladorFechaActual : public IControladorFechaActual {
private:
    static ControladorFechaActual* instancia;
    DTFecha fechaActual;

    //Constructor
    ControladorFechaActual();

public:

    //Getters
    static ControladorFechaActual* getInstance();
    DTFecha getFecha();

    //Setters
    void setFecha(DTFecha nuevaFecha);
};

#endif
