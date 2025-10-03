#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

/**
 * @class Personaje
 * @brief DECLARACIÓN de la clase Personaje.
 * Define la interfaz pública y los atributos privados para un personaje de videojuego.
 */
class Personaje {
private:
    // Atributos privados para proteger el estado del personaje.
    std::string nombre;
    int puntosDeVida;

public:
    // --- Constructor ---
    // Se asegura de que cada personaje nazca en un estado válido.
    Personaje(std::string nombre);

    // --- Destructor ---
    // Se ejecuta cuando el personaje es eliminado.
    ~Personaje();

    // --- Getter ---
    // Permite consultar el estado (la vida) de forma segura.
    int getPuntosDeVida() const;

    // --- Setters con Reglas ---
    // Métodos que modifican el estado del personaje aplicando validaciones.
    void recibirDanio(int danio);
    void curar(int cantidadCuracion);
};

#endif //PERSONAJE_H
