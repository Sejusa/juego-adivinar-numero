#include <thread>   // Para rand()
#include <iostream>

#define valorMaximo 20
#define valorMinimo 1

short numeroGenerado() {
	return (rand() % valorMaximo) + valorMinimo;
}

bool comprobarNumero(short numeroSeleccion, short numeroAAdivinar, bool condicionVictoria) {
	if (numeroSeleccion == numeroAAdivinar) { //Si el jugador ha acertado el número.
		std::cout << "\nHas acertado." << std::endl;

		condicionVictoria = true;
		return condicionVictoria; //Número acertado.
	}

	else if (numeroSeleccion < numeroAAdivinar) {
		std::cout << "\nTu número es menor al número que debes acertar." << std::endl;

		condicionVictoria = false;
		return condicionVictoria; //Número fallado.
	}

	else {
		std::cout << "\nTu número es mayor al número que debes acertar." << std::endl;

		condicionVictoria = false;
		return condicionVictoria = false; //Número fallado.
	}
}