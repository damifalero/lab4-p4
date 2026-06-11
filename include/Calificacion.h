#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include "Usuario.h"
#include "Reserva.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* uCalificado;
    Usuario* uCalificador;
    Reserva* res;

public:
    // Constructor y destructor
    Calificacion(DTFecha fecha, int puntaje, Reserva* res, Usuario* uCalificado,Usuario* uCalificador);
    ~Calificacion();

    //getters
    DTFecha getDTFecha();
    int getPuntaje();
    Usuario* getUCalificador();
    Usuario* getUCalificado();


    //setters
    void setDTFecha(DTFecha fecha);
    void setPuntaje(int puntaje);
    void setUCalificador(Usuario* usuario);
    void setUCalificado(Usuario* usuario);

    //operaciones
    void asociarUsuarioCalificado(Usuario* u);
    void desasociarUsuarioCalificado();
    void asociarUsuarioCalificador(Usuario* u);
    void desasociarUsuarioCalificador();
    void asociarReserva(Reserva* r);
    void desasociarReserva();
};

#endif 