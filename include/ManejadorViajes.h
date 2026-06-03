#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H

#include "Viaje.h"
#include "Vehiculo.h"
#include <string>
#include <map>


class ManejadorViajes {
    private:
        static ManejadorViajes* instancia;
        std::map<int, Viaje*> viajes;
        std::map<int, Reserva*> reservas;
        int ultimoCodigo; //No se que es(preguntar)
    
    public:
        //Constructores y Destructores
        ManejadorViajes();
        ~ManejadorViajes();

        //Getters
        static ManejadorViajes* getInstancia();
        std::map<int, Viaje*> getViajes();
        std::map<int, Reserva*> getReservas();

        //Funciones
        void agregarViaje(Viaje* v);
        Viaje* obtenerViaje(int codigo);
        void agregarReserva(Reserva* r);
        int generarCodigo();
        Viaje crearViaje(Vehiculo v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio)
};

#endif