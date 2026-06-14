#include "../include/CargaDatos.h"
#include "../include/UsuarioController.h"
#include "../include/ManejadorUsuarios.h" //borrar
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
    
    Fabrica* f = Fabrica::getInstance();
    IUsuarioController* uc = f->getIUsuarioController();
    IGestionViajeController* gv = f->getIGestionViajeController();
    IControladorFechaActual* fa = f->getIControladorFechaActual();

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

        uc->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa28", "ignacio.figueroa@fing.edu.uy", "38471125");

        uc-> altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "29564030");

        uc->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin.rivero@hotmail.com", "50217843");

    } catch (std::exception& e){
        std::cout << "Error en carga de usuarios: " << e.what() << "\n";
    }

    //Carga de Vehiculos
    try{
        uc->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
        uc->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);
        uc->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto);
        uc->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);
        uc->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", TipoVehiculo::Moto);
        uc->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Moto);
        uc->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
        uc->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Moto);

    } catch(std::exception& e){
        std::cout << "Error en carga de vehiculos: " << e.what() << "\n";
    }
    
    //Carga de Viajes
    try{
        DTFecha f1(21,10,2026);
        gv->altaViaje("ABJ4586", f1, "montevideo", "mercedes", 4, 200);
        DTFecha f2(20,10,2026);
        gv->altaViaje("ACM4455", f2, "young", "montevideo", 5, 250);
        DTFecha f3(20,10,2026);
        gv->altaViaje("BAS7895", f3, "young", "montevideo", 4, 200);
        DTFecha f4(21,10,2026);
        gv->altaViaje("BCS4105", f4, "montevideo", "mercedes", 9, 200);
        DTFecha f5(21,10,2026);
        gv->altaViaje("LDA4875", f5, "montevideo", "mercedes", 1, 300);
        DTFecha f6(21,10,2026);
        gv->altaViaje("PDB1205", f6, "montevideo", "mercedes", 1, 350);
        DTFecha f7(21,10,2026);
        gv->altaViaje("SBJ4874", f7, "montevideo", "mercedes", 4, 260);
        DTFecha f8(20,10,2026);
        gv->altaViaje("SCF2469", f8, "montevideo", "cerro chato", 1, 150);
        DTFecha f9(15,3,2026);
        gv->altaViaje("ABJ4586", f9, "montevideo", "colonia", 4, 140);
        DTFecha f10(15,3,2026);
        gv->altaViaje("BCS4105", f10, "montevideo", "colonia", 9, 180);
        DTFecha f11(15,3,2026);
        gv->altaViaje("SBJ4874", f11, "montevideo", "colonia", 1, 100);
        DTFecha f12(14,3,2026);
        gv->altaViaje("SBJ4874", f12, "montevideo", "colonia", 4, 600);
        DTFecha f13(20,10,2026);
        gv->altaViaje("LDA4875", f13, "young", "montevideo", 1, 250);

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
        uc->setNicknameRecordad("santi_90");
        uc->setCodigoRecordado(9);
        uc->calificarUsuario("matil92", 4);

        uc->setNicknameRecordad("mari_b");
        uc->setCodigoRecordado(9);
        uc->calificarUsuario("matil92", 4);

        uc->setNicknameRecordad("matil92");
        uc->setCodigoRecordado(9);
        uc->calificarUsuario("mari_b", 3);

        uc->setNicknameRecordad("ana_silva");
        uc->setCodigoRecordado(10);
        uc->calificarUsuario("valen_uy", 5);

        uc->setNicknameRecordad("ana_silva");
        uc->setCodigoRecordado(10);
        uc->calificarUsuario("joaco_r", 5);

        uc->setNicknameRecordad("mari_b");
        uc->setCodigoRecordado(12);
        uc->calificarUsuario("carlos_r", 5);

        uc->setNicknameRecordad("carlos_r");
        uc->setCodigoRecordado(12);
        uc->calificarUsuario("nacho_f", 5);

    } catch(std::exception& e){
        std::cout << "Error en carga de calificaciones: " << e.what() << "\n";
    }

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
