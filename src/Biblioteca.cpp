#include "../include/Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado exitosamente.\n";
}

void Biblioteca::eliminarLibro(const std::string& ISBN) {
    auto it = std::remove_if(libros.begin(), libros.end(),
        [&](const Libro& libro) { return libro.getISBN() == ISBN; });
    
    if (it != libros.end()) {
        libros.erase(it, libros.end());
        std::cout << "Libro eliminado exitosamente.\n";
    } else {
        std::cout << "Libro no encontrado.\n";
    }
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "\n=== LIBROS DISPONIBLES ===" << std::endl;
    for (const auto& libro : libros) {
        if (libro.estaDisponible()) {
            libro.mostrarInfo();
        }
    }
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::vector<Libro> resultados;
    for (const auto& libro : libros) {
        if (libro.getTitulo().find(titulo) != std::string::npos) {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultados;
    for (const auto& libro : libros) {
        if (libro.getAutor().find(autor) != std::string::npos) {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

bool Biblioteca::prestarLibro(const std::string& ISBN) {
    for (auto& libro : libros) {
        if (libro.getISBN() == ISBN && libro.estaDisponible()) {
            libro.prestar();
            return true;
        }
    }
    return false;
}

bool Biblioteca::devolverLibro(const std::string& ISBN) {
    for (auto& libro : libros) {
        if (libro.getISBN() == ISBN && !libro.estaDisponible()) {
            libro.devolver();
            return true;
        }
    }
    return false;
}
