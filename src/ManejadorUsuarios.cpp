#include "../include/ManejadorUsuarios.h"


ManejadorUsuarios* ManejadorUsuarios::instancia = NULL;

ManejadorUsuarios::ManejadorUsuarios(){}
ManejadorUsuarios::~ManejadorUsuarios() {}

ManejadorUsuarios* ManejadorUsuarios::getInstancia() {
    if (instancia == NULL) {
        instancia = new ManejadorUsuarios();
    }
    return instancia;
}
std::map<std::string, Usuario*> ManejadorUsuarios::getUsuarios(){ return this->usuarios; }

void ManejadorUsuarios::agregarUsuario(Usuario* u){ usuarios[u->getNickname()] = u;}

bool ManejadorUsuarios::existeUsuario(std::string nickname){
    return usuarios.find(nickname) != usuarios.end();
}

Usuario* ManejadorUsuarios::obtenerUsuario(std::string nickname){
    auto it = usuarios.find(nickname);

    if(it == usuarios.end())
        return nullptr;

    return it->second;
};

/*std::set<Usuario> ManejadorUsuarios::listarUsuarios(){
    std::set<Usuario> lista;
    //De donde sale esta funcion?(me refiero en el DCD)
}
*/