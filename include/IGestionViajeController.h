#ifndef IGESTIONVIAJECONTROLLER_H
#define IGESTIONVIAJECONTROLLER_H

#include "DTConsultaViaje.h"
#include "DTDetalleViaje.h"
#include "DTUsuarioViaje.h"
#include "DTListarViaje.h"
#include "DTFecha.h"
#include "Calificacion.h"

#include <set>
#include <string>

class IGestionViajeController {
    public:
        virtual ~IGestionViajeController() {}
        virtual std::set<std::string> listarPasajeros()= 0;
        virtual std::set<DTConsultaViaje> consultarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos)= 0;
        virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio)= 0;
        virtual DTDetalleViaje detalleViaje(int codigo)= 0;
        virtual std::set<DTUsuarioViaje> listarUsuariosViaje(int codigo)= 0;
        virtual std::set<DTListarViaje> listarViajes(std::string nickname)= 0;
        virtual std::set<DTListarViaje> listarViajes()= 0;
        virtual void eliminarViaje()= 0;
        virtual void cancelarEliminarViaje()= 0;
        virtual bool generarReserva(std::string nickname, int codigo, int asientos)= 0;

};

#endif