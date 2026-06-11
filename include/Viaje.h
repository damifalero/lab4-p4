#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTConsultaViaje.h"
#include "DTDetalleViaje.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include <string>
#include <set>

class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    int asientosDisponibles;
    float precioPorAsiento;
    Vehiculo* vehiculo;
    std::set<Reserva*> reservas;

public:
    //Constructor y Destructor
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados,int asientosDisponibles, float precioPorAsiento, Vehiculo* vehiculo);
    ~Viaje();

    //Getters
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    int getAsientosDisponibles();
    float getPrecioPorAsiento();
    Vehiculo* getVehiculo();
    std::set<Reserva*> getReservas();
    

    //Setters
    void setCodigo(int codigo);
    void setFecha(DTFecha fecha);
    void setOrigen(std::string origen);
    void setDestino(std::string destino);
    void setAsientosPublicados(int asientosPublicados);
    void setAsientosDisponibles(int asientosDisponibles);
    void setPrecioPorAsiento(float precioPorAsiento);
    void setVehiculo(Vehiculo* vehiculo);
    void setReservas(std::set<Reserva*> reservas );

    //Operaciones de la clase Viaje
    std::string getConductor();
    bool esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados);
    bool cantAsientosValida(int asientosRes, int asientos, int asientosPublicados);
    DTListarViaje getDTListarViaje();  
    DTDetalleViaje getDTDetalleViaje();
    int cantAsientosRes();
    DTConsultaViaje getDataViaje();
    void addReserva(Reserva* r);
    int obtenerCodigo();
    
    /*Operaciones para asociar y desasociar el link entre Viaje y Vehiculo*/
    void asociarVehiculo(Vehiculo* v);
    void desasociarVehiculo();

    /*Operaciones para asociar y desasociar el link entre Viaje y Reserva*/
    void asociarReserva(Reserva* r);
    void desasociarReserva(Reserva* r);
    
};

#endif
