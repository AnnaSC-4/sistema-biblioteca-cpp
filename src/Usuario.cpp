#include "../include/Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nom, std::string identificacion) 
    : nombre(nom), id(identificacion), maxLibros(3) {}

void Usuario::mostrarInfo() const {
    std::cout << "Nombre: " << nombre 
              << "\nID: " << id 
              << "\nLímite de libros: " << maxLibros 
              << std::endl;
}

int Usuario::getMaxLibros() const { return maxLibros; }

Estudiante::Estudiante(std::string nom, std::string id) 
    : Usuario(nom, id) {
    maxLibros = 3;
}

Professor::Professor(std::string nom, std::string id) 
    : Usuario(nom, id) {
    maxLibros = 10;
}
