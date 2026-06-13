#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H

#include "Viaje.h"
#include "Vehiculo.h"
#include <string>
#include <map>
#include <set>

class ManejadorViajes {
    private:
        static ManejadorViajes* instancia;
        std::map<int, Viaje*> viajes;
        std::map<std::string, Reserva*> reservas;
        int ultimoCodigo;
    
    public:
        //Constructores y Destructores
        ManejadorViajes();
        ~ManejadorViajes();

        //Getters
        static ManejadorViajes* getInstancia();
        const std::map<int, Viaje*>& getViajes() const;
        const std::map<std::string, Reserva*>& getReservas() const;

        //Funciones
        void agregarViaje(Viaje* v);
        Viaje* obtenerViaje(int codigo);
        void agregarReserva(Reserva* r);
        int generarCodigo();
        Viaje* crearViaje(Vehiculo v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, int asientosDisponibles, float precio);
        void eliminarViaje(int codigo);
    };

#endif