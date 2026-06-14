#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "Pasajero.h"
#include "Viaje.h"

//Dependencia circular 
class Viaje;
class Pasajero;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero; 
    Viaje* viaje; 
    std::set<Calificacion*> calificaciones;

public:
    //Constructor y Destructor
    Reserva(int asientosReservados, DTFecha fecha,Pasajero* pasajero,Viaje* viaje);    
    ~Reserva();

    //Getters 
    int getAsientosReservados();
    DTFecha getDTFecha();
    Viaje* getViaje();
    DTListarViaje getDTListarViaje();
    std::set<Calificacion*> getCalificaciones();
    Pasajero* getPasajero();

    //Setters
    void setAsientosReservados(int cantAsientos);
    void setDTFecha(DTFecha fecha);
    void setViaje(Viaje* viaje);
    void setCalificaciones(std::set<Calificacion*> calificaciones);
    void setPasajero(Pasajero* pasajero);

    //Operaciones
    void agregarCalificacion(Calificacion calificacion);
    void asociarViaje(Viaje v);
    void desasociarViaje();
    void asociarPasajero(Pasajero p);
    void desasociarPasajero();
    void asociarCalificacion(Calificacion* c);
    void desasociarCalificacion(Calificacion* c);
    DTDetalleReserva getDTDetalleReserva();
};

#endif 