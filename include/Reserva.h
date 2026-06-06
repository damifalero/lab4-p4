#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "Pasajero.h"
#include "Viaje.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    /*
    Este Pasajero no lo toma como clase pasajero sino como enumerado Pasajero de TipoUsuario.h, no entiendo cómo porque en 
    ningún momento incluyo TipoUsuario.h, ni siquiera indirectamente.
    Si borro Pasajero de TipoUsuario.h el error se va, lo mismo si borro el include
    de TipoUsuario.h en Usuario.h (aunque Usuario.h tampoco está incluido ni directa ni indirectamente))
    */

    Pasajero* pasajero; 

    Viaje* viaje; //cuando se hace generarReserva hay que vincular el viaje acá para poder hacer getdtlistariviaje

public:
    // constructor y destructor
    Reserva(int asientosReservados, DTFecha fecha);    
    ~Reserva();

    // getters 
    int getAsientosReservados();
    DTFecha getDTFecha();
    DTListarViaje getDTListarViaje();

    //setters
    void setAsientosReservados(int cantAsientos);
    void setDTFecha(DTFecha fecha);
    void setViaje(Viaje viaje);
};

#endif
