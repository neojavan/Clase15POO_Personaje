#include "Personaje.h"
#include "Arma.h" // Se incluye el header completo aquí para poder usar los métodos de Arma.
#include <iostream>

/**
 * @file Personaje.cpp
 * @brief IMPLEMENTACIÓN MODIFICADA de los métodos de la clase Personaje.
 */

// Constructor modificado: inicializa el puntero del arma a nullptr.
// nullptr indica que el personaje no tiene ningún arma equipada al ser creado.
Personaje::Personaje(std::string nombre)
    : nombre(nombre), puntosDeVida(100), armaEquipada(nullptr) {
    std::cout << "CONSTRUCTOR: Ha aparecido '" << this->nombre << "'." << std::endl;
}

// Destructor modificado: AHORA TIENE UNA RESPONSABILIDAD CRÍTICA.
Personaje::~Personaje() {
    std::cout << "DESTRUCTOR: '" << this->nombre << "' esta siendo eliminado." << std::endl;
    // Antes de que el personaje desaparezca, debemos liberar la memoria del arma que él "posee".
    // Si no hacemos esto, la memoria del arma se pierde para siempre (Memory Leak).
    if (this->armaEquipada != nullptr) {
        std::cout << "   -> Liberando la memoria del arma '" << this->armaEquipada->getNombre() << "'..." << std::endl;
        delete this->armaEquipada; // Se llama al destructor del Arma y se libera la memoria.
        this->armaEquipada = nullptr; // Buena práctica.
    }
}

void Personaje::equiparArma(Arma* ptrArma) {
    // Si el personaje ya tenía un arma, primero la libera para evitar una fuga de memoria.
    if (this->armaEquipada != nullptr) {
        delete this->armaEquipada;
    }
    this->armaEquipada = ptrArma;
    std::cout << ">> " << this->nombre << " ha equipado el arma: '" << this->armaEquipada->getNombre() << "'." << std::endl;
}

void Personaje::atacar(Personaje& objetivo) {
    int danioTotal = 10; // Daño base con los puños.

    // Si el personaje tiene un arma equipada, el daño aumenta.
    if (this->armaEquipada != nullptr) {
        danioTotal = this->armaEquipada->getDanio();
        std::cout << ">> " << this->nombre << " ataca a " << objetivo.getNombre() << " con " << this->armaEquipada->getNombre() << "!" << std::endl;
    } else {
        std::cout << ">> " << this->nombre << " ataca a " << objetivo.getNombre() << " con sus punos!" << std::endl;
    }

    objetivo.recibirDanio(danioTotal);
}

// Métodos que no cambian
void Personaje::recibirDanio(int danio) {
    this->puntosDeVida -= danio;
    // Uso del operador ternario para mostrar el estado.
    std::string estado = (this->puntosDeVida > 0) ? std::to_string(this->puntosDeVida) : "Derrotado";
    std::cout << "   -> " << this->nombre << " recibe " << danio << " de dano. Vida restante: " << estado << std::endl;
    if (this->puntosDeVida < 0) this->puntosDeVida = 0;
}

int Personaje::getPuntosDeVida() const {
    return this->puntosDeVida;
}

std::string Personaje::getNombre() const {
    return this->nombre;
}

