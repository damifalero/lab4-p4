#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include "Usuario.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    //
    Usuario* uCalificado;
    Usuario* uCalificador;
    //

public:
    // Constructor y destructor
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    //getters
    DTFecha getDTFecha();
    int getPuntaje();
    Usuario* getUCalificador();
    Usuario* getUCalificado();


    //setters
    void setDTFecha(DTFecha fecha);
    void setPuntaje(int puntaje);
    void setUCalificador(Usuario usuario);
    void setUCalificado(Usuario usuario);
};

#endif
