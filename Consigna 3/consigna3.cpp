#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600), "Fondo de Pantalla"); //Creamos la pantalla

    sf::Texture texturaFondo;

    if (!texturaFondo.loadFromFile("fondo.jpg")) { //Cargamos la textura
        std::cerr << "Error al cargar la imagen fondo.jpg" << std::endl;
        return -1; //Le indicamos a Visual qué hacer si no carga la textura
    }

    sf::Sprite spriteFondo;
    spriteFondo.setTexture(texturaFondo); //Cargamos el material del sprite

    //Escalamos la textura y el sprite
    spriteFondo.setScale(
        800.0f / texturaFondo.getSize().x,
        600.0f / texturaFondo.getSize().y
    );

    //Loop principal
    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        App.clear(); //Limpiamos la pantalla
        App.draw(spriteFondo); //Dibujamos el sprite
        App.display(); //Mostramos lo dibujado en el backbuffer

        //Espera para que la ventana no se cierre inmediatamente
        sf::sleep(sf::seconds(10));
    }

    return 0;
}