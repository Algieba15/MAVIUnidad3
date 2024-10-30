#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow App(VideoMode(800, 600), "Rotar un Sprite"); //Creamos la pantalla 

    Texture texture;
    if (!texture.loadFromFile("cuad_yellow.png")) { //Cargamos la textura
        std::cerr << "Error: No se pudo cargar la textura." << std::endl;
        return -1;
    }

    Sprite sprite; //Cargamos el material del sprite. Definimos tamaño y posición de la textura
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(App.getSize().x / 2, App.getSize().y / 2);

    while (App.isOpen()) { //Bucle para funcionamiento de la pantalla
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

        sprite.rotate(1.0f); //Indicación para qué rote el sprite y cómo

        App.clear(); //Limpiamos la pantalla

        App.draw(sprite); //Dibujamos el sprite

        App.display(); //Mostramos en pantalla lo dibujado en el backbuffer
    }

    return 0;
}



