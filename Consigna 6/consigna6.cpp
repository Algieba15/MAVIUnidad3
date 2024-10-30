#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

//Declaramos texturas y sprites
Texture texture_red, texture_blue, texture_yellow, texture_grey;
Sprite sprite_red, sprite_blue, sprite_yellow, sprite_grey;
const int tamaño_cuadrado = 400;  // Cada cuadrado ocupará 400x400 píxeles

int main() {
    //Cargamos las texturas desde la carpeta.
    if (!texture_red.loadFromFile("cuad_red.png") ||
        !texture_blue.loadFromFile("cuad_blue.png") ||
        !texture_yellow.loadFromFile("cuad_yellow.png") ||
        !texture_grey.loadFromFile("cuad_grey.png")) {
        std::cerr << "Error al cargar las texturas" << std::endl;
        return -1;
    }

    //Declaramos las variables de tamaño para cada textura.
    float height_red = (float)texture_red.getSize().y;
    float width_red = (float)texture_red.getSize().x;

    float height_blue = (float)texture_blue.getSize().y;
    float width_blue = (float)texture_blue.getSize().x;

    float height_yellow = (float)texture_yellow.getSize().y;
    float width_yellow = (float)texture_yellow.getSize().x;

    float height_grey = (float)texture_grey.getSize().y;
    float width_grey = (float)texture_grey.getSize().x;

    // Cargamos el material del sprite
    sprite_red.setTexture(texture_red);
    sprite_blue.setTexture(texture_blue);
    sprite_yellow.setTexture(texture_yellow);
    sprite_grey.setTexture(texture_grey);

    //Escalar las texturas utilizando las variables de tamaño
    sprite_red.setScale(
        tamaño_cuadrado / width_red,  // Escala en X
        tamaño_cuadrado / height_red  // Escala en Y
    );
    sprite_blue.setScale(
        tamaño_cuadrado / width_blue,
        tamaño_cuadrado / height_blue
    );
    sprite_yellow.setScale(
        tamaño_cuadrado / width_yellow,
        tamaño_cuadrado / height_yellow
    );
    sprite_grey.setScale(
        tamaño_cuadrado / width_grey,
        tamaño_cuadrado / height_grey
    );

    //Posicionamos los sprites en la cuadrícula
    sprite_red.setPosition(0, 0);
    sprite_blue.setPosition(400, 0);
    sprite_yellow.setPosition(0, 400);
    sprite_grey.setPosition(400, 400);

    //Creamos la ventana de 800x800 píxeles (tanto el ancho como el largo tienen la misma logitud para que la pantalla quede cuadrada)
    sf::RenderWindow App(sf::VideoMode(800, 800), "Cuadrícula de Colores");

    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();  // Cerrar la ventana si se recibe el evento de cierre
        }

        //Limpiamos la ventana
        App.clear();

        //Dibujamos los sprites en la ventana
        App.draw(sprite_red);
        App.draw(sprite_blue);
        App.draw(sprite_yellow);
        App.draw(sprite_grey);

        //Mostramos en pantalla lo dibujado en el backbuffer
        App.display();
    }

    return 0;
}



