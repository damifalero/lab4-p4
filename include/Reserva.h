#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero; 
    Viaje* viaje; //cuando se hace generarReserva hay que vincular el viaje acá para poder hacer getdtlistariviaje
    std::set<Calificacion*> calificaciones;

public:
    // constructor y destructor
    Reserva(int asientosReservados, DTFecha fecha,Pasajero pasajero,Viaje viaje);    
    ~Reserva();

    // getters 
    int getAsientosReservados();
    DTFecha getDTFecha();
    Viaje* getViaje();
    DTListarViaje getDTListarViaje();
    std::set<Calificacion*> getCalificaciones();
    Usuario* getPasajero(); 

    //setters
    void setAsientosReservados(int cantAsientos);
    void setDTFecha(DTFecha fecha);
    void setViaje(Viaje viaje);
    void setCalificaciones(std::set<Calificacion*> calificaciones);
    void setPasajero(Pasajero pasajero);

    //operaciones
    bool agregarCalificacion(Calificacion calificacion);
    void Reserva::asociarViaje(Viaje v);
    void Reserva::desasociarViaje();
    void Reserva::asociarPasajero(Pasajero p);
    void Reserva::desasociarPasajero();
    void Reserva::asociarCalificacion(Calificacion* c);
    void Reserva::desasociarCalificacion(Calificacion* c);
};

#endif RESERVA_H