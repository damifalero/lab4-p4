#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Usuario* pasajero; 
    Viaje* viaje; //cuando se hace generarReserva hay que vincular el viaje acá para poder hacer getdtlistariviaje
    std::set<Calificacion*> calificaciones;

public:
    // constructor y destructor
    Reserva(int asientosReservados, DTFecha fecha,Usuario pasajero,Viaje viaje);    
    ~Reserva();

    // getters 
    int getAsientosReservados();
    DTFecha getDTFecha();
    DTListarViaje getDTListarViaje();
    std::set<Calificacion*> getCalificaciones();
    Usuario* getPasajero();
    Viaje* getViaje();

    //setters
    void setAsientosReservados(int cantAsientos);
    void setDTFecha(DTFecha fecha);
    void setViaje(Viaje viaje);
    void setCalificaciones(std::set<Calificacion*> calificaciones);
    void setPasajero(Usuario pasajero);

    //operaciones
    bool agregarCalificacion(Calificacion calificacion);
};

#endif