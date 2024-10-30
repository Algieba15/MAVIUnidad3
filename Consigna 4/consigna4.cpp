#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf; //Establecemos la textura y el sprite
Texture texture_platform;
Sprite sprite_platform;

int main() {

    Texture texturePlatform; //Cargamos la textura y le damos indicaciones a Visual sobre qué hacer si no puede cargarla
    if (!texturePlatform.loadFromFile("plataforma.jpg")) {
        std::cerr << "Error: No se pudo cargar el archivo plataforma.jpg" << std::endl;
        return -1;
    }

    RenderWindow App(VideoMode(800, 600, 32), "Escenario de Plataformas"); //Creamos la pantalla

    float height1 = 100, height2 = 150, height3 = 200, height4 = 250, height5 = 300, height6 = 350, height7 = 400;
    float barWidth = 50.0f;
    float gap = 20.0f;

    Sprite platform1, platform2, platform3, platform4, platform5, platform6, platform7; //Definimos los sprites de las plataformas

    // Cargamos el material del sprite. Escalamos y posicionamos las plataformas verticales

    platform1.setTexture(texturePlatform);
    platform1.setScale(barWidth / texturePlatform.getSize().x, height1 / texturePlatform.getSize().y);
    platform1.setPosition(0 * (barWidth + gap), 600 - height1);

    platform2.setTexture(texturePlatform);
    platform2.setScale(barWidth / texturePlatform.getSize().x, height2 / texturePlatform.getSize().y);
    platform2.setPosition(1 * (barWidth + gap), 600 - height2);

    platform3.setTexture(texturePlatform);
    platform3.setScale(barWidth / texturePlatform.getSize().x, height3 / texturePlatform.getSize().y);
    platform3.setPosition(2 * (barWidth + gap), 600 - height3);

    platform4.setTexture(texturePlatform);
    platform4.setScale(barWidth / texturePlatform.getSize().x, height4 / texturePlatform.getSize().y);
    platform4.setPosition(3 * (barWidth + gap), 600 - height4);

    platform5.setTexture(texturePlatform);
    platform5.setScale(barWidth / texturePlatform.getSize().x, height5 / texturePlatform.getSize().y);
    platform5.setPosition(4 * (barWidth + gap), 600 - height5);

    platform6.setTexture(texturePlatform);
    platform6.setScale(barWidth / texturePlatform.getSize().x, height6 / texturePlatform.getSize().y);
    platform6.setPosition(5 * (barWidth + gap), 600 - height6);

    platform7.setTexture(texturePlatform);
    platform7.setScale(barWidth / texturePlatform.getSize().x, height7 / texturePlatform.getSize().y);
    platform7.setPosition(6 * (barWidth + gap), 600 - height7);

    // Cargamos el material del sprite. Escalamos y posicionamos la plataforma horizontal

    Sprite horizontalPlatform;
    horizontalPlatform.setTexture(texturePlatform);
    horizontalPlatform.setScale(600.0f / texturePlatform.getSize().x, 20.0f / texturePlatform.getSize().y);
    horizontalPlatform.setPosition(500.0f, 200.0f);

    while (App.isOpen()) { //Bucle para el funcionamiento de la pantalla
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }
        App.clear(); //Limpiamos la pantalla

        //Dibujamos las plataformas

        App.draw(platform1);
        App.draw(platform2);
        App.draw(platform3);
        App.draw(platform4);
        App.draw(platform5);
        App.draw(platform6);
        App.draw(platform7);
        App.draw(horizontalPlatform);

        App.display();//Mostramos en pantalla lo dibujado en el backbuffer

    }

    return 0;
}
