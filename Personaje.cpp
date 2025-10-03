#include "Personaje.h"
#include <iostream>

/**
 * @file Personaje.cpp
 * @brief IMPLEMENTACIÓN de los métodos de la clase Personaje.
 */

// Implementación del Constructor.
// Inicializa el nombre y establece la vida inicial en 100, como se requiere.
Personaje::Personaje(std::string nombre) : nombre(nombre), puntosDeVida(100) {
    std::cout << "CONSTRUCTOR: ¡El personaje '" << this->nombre << "' ha entrado en combate con " << this->puntosDeVida << " PV!" << std::endl;
}

// Implementación del Destructor.
Personaje::~Personaje() {
    std::cout << "DESTRUCTOR: El personaje '" << this->nombre << "' ha sido derrotado." << std::endl;
}

// Implementación del Getter para los puntos de vida.
int Personaje::getPuntosDeVida() const {
    return this->puntosDeVida;
}

// Implementación del Setter para recibir daño, con validación.
void Personaje::recibirDanio(int danio) {
    std::cout << ">> " << this->nombre << " recibe " << danio << " puntos de dano." << std::endl;
    this->puntosDeVida -= danio;

    // REGLA: La vida no puede ser negativa.
    if (this->puntosDeVida < 0) {
        this->puntosDeVida = 0;
    }
    std::cout << "   Vida restante: " << this->puntosDeVida << "/100" << std::endl;
}

// Implementación del Setter para curar, con validación.
void Personaje::curar(int cantidadCuracion) {
    std::cout << ">> " << this->nombre << " se cura " << cantidadCuracion << " puntos de vida." << std::endl;
    this->puntosDeVida += cantidadCuracion;

    // REGLA: La vida no puede superar el máximo de 100.
    if (this->puntosDeVida > 100) {
        this->puntosDeVida = 100;
    }
    std::cout << "   Vida restante: " << this->puntosDeVida << "/100" << std::endl;
}
