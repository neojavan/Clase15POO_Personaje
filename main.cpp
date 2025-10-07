#include <iostream>
#include "Personaje.h"
#include "Arma.h"

int main() {
    std::cout << "===== GESTIoN DE MEMORIA DINaMICA =====" << std::endl;

    // 1. Creamos un héroe en la memoria ESTÁTICA (Stack).
    // Su vida está limitada al ámbito de la función main.
    Personaje heroe("Aragorn");

    // 2. Creamos un arma en la memoria DINÁMICA (Heap) usando 'new'.
    // Esta memoria PERSISTE hasta que la liberemos explícitamente con 'delete'.
    // 'ptrEspada' contiene la dirección de memoria del objeto Arma.
    Arma* ptrEspada = new Arma("Anduril", 50);

    // 3. El personaje equipa el arma.
    // Pasamos el puntero (la dirección de memoria) al método.
    heroe.equiparArma(ptrEspada);

    // 4. Creamos un enemigo para la simulación.
    Personaje orco("Lurtz");

    // 5. Simulación de combate.
    std::cout << "\n--- Comienza el combate ---" << std::endl;
    heroe.atacar(orco);
    orco.atacar(heroe);
    heroe.atacar(orco);
    std::cout << "-------------------------" << std::endl;

    std::cout << "\nEl programa 'main' esta a punto de terminar." << std::endl;
    std::cout << "Los objetos en el Stack ('heroe' y 'orco') seran destruidos automaticamente." << std::endl;
    std::cout << "El destructor de 'heroe' se encargará de liberar la memoria del Arma en el Heap." << std::endl;

    // Al final de main, se llamará a ~Personaje() para 'heroe' y 'orco'.
    // El destructor de 'heroe' ejecutará 'delete' sobre 'ptrEspada', previniendo una fuga de memoria.
    return 0;
}

