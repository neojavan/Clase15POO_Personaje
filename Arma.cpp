#include "Arma.h"
#include <iostream>

/**
 * @file Arma.cpp
 * @brief IMPLEMENTACIÓN de los métodos de la clase Arma.
 */

// Implementación del constructor.
Arma::Arma(std::string nombre, int danio)
    : nombre(nombre), danio(danio) {
    std::cout << "CONSTRUCTOR ARMA: Se ha forjado el arma '" << this->nombre << "'." << std::endl;
}

std::string Arma::getNombre() const {
    return this->nombre;
}

int Arma::getDanio() const {
    return this->danio;
}
