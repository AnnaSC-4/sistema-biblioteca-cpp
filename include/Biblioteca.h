#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    void eliminarLibro(const std::string& ISBN);
    void mostrarLibrosDisponibles() const;
    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;
    bool prestarLibro(const std::string& ISBN);
    bool devolverLibro(const std::string& ISBN);
};

#endif
