#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H

#include "Usuario.h"
#include <string>
#include <map>


class ManejadorUsuarios {
    private:
        static ManejadorUsuarios* instancia;
        std::map<std::string, Usuario*> usuarios;
    
    public:
        //Constructores y Destructores
        ManejadorUsuarios();
        ~ManejadorUsuarios();

        //Getters
        static ManejadorUsuarios* getInstancia();
        std::map<std::string, Usuario*> getUsuarios();

        //Funciones
        void agregarUsuario(Usuario* u);
        bool existeUsuario(std::string nickname);
        Usuario* obtenerUsuario(std::string nickname);
        std::set<Usuario> listarUsuarios();
};

#endif