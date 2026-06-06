#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

public:
    // Constructor y destructor
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    //getters
    DTFecha getDTFecha();
    int getPuntaje();

    //setters
    void setDTFecha(DTFecha fecha);
    void setPuntaje(int puntaje);
};

#endif
