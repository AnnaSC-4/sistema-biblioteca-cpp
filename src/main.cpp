#include "../include/Biblioteca.h"
#include "../include/Usuario.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "\n=== SISTEMA DE BIBLIOTECA ===" << std::endl;
    std::cout << "1. Agregar libro" << std::endl;
    std::cout << "2. Mostrar libros disponibles" << std::endl;
    std::cout << "3. Buscar por título" << std::endl;
    std::cout << "4. Buscar por autor" << std::endl;
    std::cout << "5. Prestar libro" << std::endl;
    std::cout << "6. Devolver libro" << std::endl;
    std::cout << "7. Eliminar libro" << std::endl;
    std::cout << "8. Mostrar información de usuario" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    Biblioteca biblioteca;
    Professor prof("Dr. Garcia", "PROF001");
    
    // Agregar algunos libros de ejemplo
    biblioteca.agregarLibro(Libro("C++ Programming", "Bjarne Stroustrup", "123456"));
    biblioteca.agregarLibro(Libro("Clean Code", "Robert Martin", "789012"));
    
    int opcion;
    std::string input;
    
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar buffer
        
        switch(opcion) {
            case 1: {
                std::string titulo, autor, isbn;
                std::cout << "Título: "; std::getline(std::cin, titulo);
                std::cout << "Autor: "; std::getline(std::cin, autor);
                std::cout << "ISBN: "; std::getline(std::cin, isbn);
                biblioteca.agregarLibro(Libro(titulo, autor, isbn));
                break;
            }
            case 2:
                biblioteca.mostrarLibrosDisponibles();
                break;
            case 3: {
                std::cout << "Título a buscar: "; 
                std::getline(std::cin, input);
                auto resultados = biblioteca.buscarPorTitulo(input);
                std::cout << "\nResultados de búsqueda:" << std::endl;
                for (const auto& libro : resultados) {
                    libro.mostrarInfo();
                }
                break;
            }
            case 4: {
                std::cout << "Autor a buscar: "; 
                std::getline(std::cin, input);
                auto resultados = biblioteca.buscarPorAutor(input);
                std::cout << "\nResultados de búsqueda:" << std::endl;
                for (const auto& libro : resultados) {
                    libro.mostrarInfo();
                }
                break;
            }
            case 5: {
                std::cout << "ISBN del libro a prestar: "; 
                std::getline(std::cin, input);
                if (biblioteca.prestarLibro(input)) {
                    std::cout << "Libro prestado exitosamente.\n";
                } else {
                    std::cout << "No se pudo prestar el libro.\n";
                }
                break;
            }
            case 6: {
                std::cout << "ISBN del libro a devolver: "; 
                std::getline(std::cin, input);
                if (biblioteca.devolverLibro(input)) {
                    std::cout << "Libro devuelto exitosamente.\n";
                } else {
                    std::cout << "No se pudo devolver el libro.\n";
                }
                break;
            }
            case 7: {
                std::cout << "ISBN del libro a eliminar: "; 
                std::getline(std::cin, input);
                biblioteca.eliminarLibro(input);
                break;
            }
            case 8:
                prof.mostrarInfo();
                break;
            case 0:
                std::cout << "¡Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 0);
    
    return 0;
}
