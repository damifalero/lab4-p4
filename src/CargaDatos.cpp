#include "../include/CargaDatos.h"
#include "../include/UsuarioController.h"
#include "../include/GestionViajeController.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Fabrica.h"
#include <iostream>

class Fabrica;

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    // Aquí iría la lógica de carga de datos harcodeados
    std::cout << "Cargando datos harcodeados del sistema...\n";
    // ... (inserción de usuarios, vehículos, viajes, reservas) ...
    
    IUsuarioController* uc = Fabrica::getInstance()->getIUsuarioController();
    IGestionViajeController* gv = Fabrica::getInstance()->getIGestionViajeController();
    IControladorFechaActual* fa = Fabrica::getInstance()->getIControladorFechaActual();

    //no estoy muy segura peeero

    //Carga de Usuarios
    try{
        //Cargar conductores
        std::set<TipoLibreta> libs_matias;
        libs_matias.insert(TipoLibreta::AutoAmateur);
        uc->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libs_matias);
        
        std::set<TipoLibreta> libs_ana;
        libs_ana.insert(TipoLibreta::AutoProfesional);
        uc->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libs_ana);

        std::set<TipoLibreta> libs_diego;
        libs_diego.insert(TipoLibreta::MotoAmateur);
        uc->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", libs_diego);
        
        std::set<TipoLibreta> libs_laura;
        libs_laura.insert(TipoLibreta::MotoProfesional);
        uc->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libs_laura);

        std::set<TipoLibreta> libs_carlos;
        libs_carlos.insert(TipoLibreta::AutoProfesional);
        libs_carlos.insert(TipoLibreta::MotoAmateur);
        uc->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libs_carlos);

        //Cargar pasajeros
        uc->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiao.acosta@gmail.com", "14923042");

        uc->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "41038591");

        uc->altaPasajero("nacho_f", "Igancio Figueroa", "ifigueroa28", "ignacio.figueroa@fing.edu.uy", "38471125");

        uc-> altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "29564030");

        uc->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin.rivero@hotmail.com", "50217843");

    } catch (std::exception& e){
        std::cout << "Error en carga de usuarios: " << e.what() << "\n";
    }

    //Carga de Vehiculos
    try{
        uc->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
        //faltan agregar los demas

    } catch(std::exception& e){
        std::cout << "Error en carga de vehiculos: " << e.what() << "\n";
    }
    
    //Carga de Viajes
    try{
        fa->setFecha(DTFecha(/*21, 10, 2026*/));
        //no falta agregar el codigo?
        gv->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
        //faltan agregar los demas
    } catch(std::exception& e){
        std::cout << "Error en carga de viajes: " << e.what() << "\n";
    }

    //Carga de Reservas
    try{
        fa->setFecha(DTFecha(14, 3, 2026));
        gv->generarReserva("santi_90", 9, 2);
        gv->generarReserva("mari_b", 9, 1);
        gv->generarReserva("nacho_f", 10, 5);
        gv->generarReserva("valen_uy", 10, 3);
        gv->generarReserva("joaco_r", 10, 1);
        fa->setFecha(DTFecha(13, 3, 2026));
        gv->generarReserva("mari_b", 12, 1);
        gv->generarReserva("nacho_f", 12, 1);
        gv->generarReserva("nacho_f", 9, 1);
        fa->setFecha(DTFecha(1, 6, 2026));
        gv->generarReserva("mari_b", 1, 2);
    } catch(std::exception& e){
        std::cout << "Error en carga de reservas: " << e.what() << "\n";
    }

    //Carga de Claificaciones
    try{
        //donde se agrega el nickname y el codigo?
        uc->calificarUsuario("matil92", 4);
    } catch(std::exception& e){
        std::cout << "Error en carga de calificaciones: " << e.what() << "\n";
    }

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
