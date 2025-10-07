#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

// Forward declaration de la clase Arma.
// Le decimos al compilador que "Arma" es una clase sin necesidad de incluir el .h completo.
// Esto es útil para evitar dependencias circulares y acelerar la compilación.
class Arma;

/**
 * @class Personaje
 * @brief DECLARACIÓN MODIFICADA de la clase Personaje.
 * Ahora puede gestionar un puntero a un objeto Arma.
 */
class Personaje {
private:
    std::string nombre;
    int puntosDeVida;
    // Puntero para almacenar la dirección de memoria de un objeto Arma creado en el Heap.
    Arma* armaEquipada;

public:
    Personaje(std::string nombre);
    ~Personaje(); // El destructor ahora es crucial para liberar memoria.

    // Método para equipar un arma creada dinámicamente.
    void equiparArma(Arma* ptrArma);

    // El método atacar ahora usará el arma si está equipada.
    void atacar(Personaje& objetivo);

    // Métodos existentes.
    void recibirDanio(int danio);
    int getPuntosDeVida() const;
    std::string getNombre() const;
};

#endif //PERSONAJE_H

