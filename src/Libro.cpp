#include "../include/Libro.h"
#include <iostream>

Libro::Libro(std::string tit, std::string aut, std::string isbn) 
    : titulo(tit), autor(aut), ISBN(isbn), disponible(true) {}

void Libro::mostrarInfo() const {
    std::cout << "Título: " << titulo 
              << "\nAutor: " << autor 
              << "\nISBN: " << ISBN 
              << "\nDisponible: " << (disponible ? "Sí" : "No") 
              << "\n" << std::endl;
}

bool Libro::estaDisponible() const { return disponible; }

void Libro::prestar() { disponible = false; }

void Libro::devolver() { disponible = true; }

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getISBN() const { return ISBN; }
