#include <SFML/Window.hpp>   
#include <SFML/Graphics.hpp> 
#include <iostream>          

using namespace sf;

Texture textureBlack, textureWhite; // Declaramos las texturas para las casillas negras y blancas

Sprite board[8][8]; // Declaramos una matriz 8x8 de sprites para representar el tablero de ajedrez

int main() {

    sf::RenderWindow App(sf::VideoMode(800, 800), "Tablero de Ajedrez"); // Creamos una ventana de 800x800 píxeles 

    sf::Texture texturaBlanca, texturaNegra;// Declaramos dos texturas: una para casillas blancas y otra para casillas negras

    if (!texturaBlanca.loadFromFile("chessw.png") || !texturaNegra.loadFromFile("chessb.png")) { // Cargar las texturas desde archivos 
        return -1; // Indica a VS que si no se pueden cargar las texturas, devuelva un error y salga del programa
    }

    //Creamos los sprites para las casillas blancas y negras utilizando las texturas cargadas
    sf::Sprite casillaBlanca(texturaBlanca);
    sf::Sprite casillaNegra(texturaNegra);

    //Definimos el tamaño de cada casilla como 100x100 píxeles
    int tamanioCasilla = 100;

    //Bucle principal del programa: mantiene la ventana abierta mientras esté activa
    while (App.isOpen()) {
        sf::Event event;  //Variable para capturar eventos
        while (App.pollEvent(event)) {
            // Cierra la ventana cuando se hace clic en la X.
            if (event.type == sf::Event::Closed)
                App.close();
        }
        App.clear();//Limpiamos la ventana antes de dibujar el tablero

        // Este bucle recorre las filas y columnas del tablero para determinar el color de las casillas(8x8)

        for (int fila = 0; fila < 8; fila++) {  //Esta línea rcorre las filas (0 a 7)
            for (int col = 0; col < 8; col++) { //Esta línea recorre las columnas (0 a 7)

                if ((fila + col) % 2 == 0) { //Si la suma de fila y columna es par, la casilla es blanca

                    casillaBlanca.setPosition(col * tamanioCasilla, fila * tamanioCasilla); //Coloca la casilla blanca en la posición adecuada en la ventana

                    App.draw(casillaBlanca);//Dibuja la casilla blanca en la ventana
                }
                else {

                    casillaNegra.setPosition(col * tamanioCasilla, fila * tamanioCasilla); //Coloca la casilla negra en la posición adecuada en la ventana

                    App.draw(casillaNegra); // Dibuja la casilla negra en la ventana
                }
            }
        }

        // Mostramos en pantalla lo que se dibujó
        App.display();
    }

    return 0;
}
