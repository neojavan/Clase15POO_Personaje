#include <iostream>
#include "Personaje.h"

/**
 * @file main.cpp
 * @brief Programa principal para simular el uso de la clase Personaje.
 */
int main() {
    std::cout << "===== SIMULADOR DE COMBATE BaSICO =====" << std::endl;

    // Se crea un objeto Personaje. Se invoca a su constructor.
    Personaje heroe("Aragorn");

    std::cout << "\n--- Comienza el combate ---" << std::endl;

    // Se usan los setters para modificar el estado del objeto.
    heroe.recibirDanio(30);  // Vida: 70
    heroe.recibirDanio(25);  // Vida: 45

    // Se usa el setter de curación.
    heroe.curar(20);         // Vida: 65

    // Se prueba la regla de que la vida no puede superar 100.
    heroe.curar(50);         // Vida debería ser 100, no 115.

    // Se prueba la regla de que la vida no puede ser menor a 0.
    heroe.recibirDanio(120); // Vida debería ser 0, no -20.

    std::cout << "\n--- Fin del combate ---" << std::endl;
    std::cout << "El programa 'main' está a punto de terminar." << std::endl;
    std::cout << "El destructor de 'heroe' se llamara automaticamente." << std::endl;

    return 0;
}
