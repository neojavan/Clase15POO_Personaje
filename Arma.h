#ifndef ARMA_H
#define ARMA_H

#include <string>

/**
 * @class Arma
 * @brief DECLARACIÓN de la clase Arma.
 * Representa un arma simple con un nombre y un valor de daño.
 */
class Arma {
private:
    std::string nombre;
    int danio;

public:
    // Constructor para crear un arma.
    Arma(std::string nombre, int danio);

    // Getters para acceder a sus atributos.
    std::string getNombre() const;
    int getDanio() const;
};

#endif //ARMA_H
