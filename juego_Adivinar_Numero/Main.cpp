#include <iostream>
#include "InputControl.h"
#include <locale.h> //Para el setlocale();
#include <thread>   // Para std::this_thread
#include <conio.h> // Necesaria para _getch()
#include "GuessNumber.h"

int main() {
	int numeroJugador = 0; //La inicializo como 0 para evitar errores.
	bool estadoPartida; //Para manejar si el jugador ha ganado o perdido.
	short continuar;

	setlocale(LC_ALL, ""); //Para texto según el idioma del dispositivo.
	srand(time(NULL)); //Genera una semilla aleatoria. Solo lo ejecutamos al inicio del programa para evitar bugs.

	do
	{
		estadoPartida = false;

		std::cout << "Bienvenido al juego de adivinar un número. Pulse cualquier botón para continuar." << std::endl;

		_getch(); // Espera a que se detecte una pulsación

		short numero = numeroGenerado(); //Este función generará un número aleatorio entre 1 y 20 y lo devolverá. Este será el número a adivinar.

		while (estadoPartida == false) { //Se ejecutará mientras no se haya adivinado el número.
			std::cout << "\n¿Cuál crees que es el número generado?" << std::endl;
			numeroJugador = controladorInput(0);
			estadoPartida = comprobarNumero(numeroJugador, numero, estadoPartida); //Ejecutamos comprobarNumero y depende del resultado asignamos a estadoPartida.
		}

		std::cout << "\n¿Quieres hacer otra partida? Escriba s(sí) o n(no)." << std::endl;
		continuar = controladorInput(1);
	} while (continuar != 0);

	return 0;
}