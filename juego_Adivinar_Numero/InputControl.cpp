#include <iostream>

#define valorMaximo 20
#define valorMinimo 1

short controladorInput(short opcion) {
	switch (opcion)
	{
	case 0:{
		short input;

		do
		{
			std::cout << "Escriba su respuesta (no decimal. Si escribe una respuesta no decimal, el programa truncará su input).:" << std::endl;
			std::cin >> input;

			while (!input) {
				std::cout << "Por favor, escriba un número." << std::endl;

				std::cin.clear(); //Limpiar el estado de error de std::cin.

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Descartar la entrada incorrecta del buffer.

				std::cin >> input; //Pido el input de nuevo.
			}

			if (input < valorMinimo || input > valorMaximo) {
				std::cout << "Entrada incorrecta, tiene que ser un número entre 1 y 20." << std::endl;
			}
		} while (input < valorMinimo || input > valorMaximo || !input); //Hasta que no se introduzca una número entre 1 y 20 o la entrada no sea un número.

		return input;
	}
		

	case 1: {
		char input;

		do
		{
			std::cout << "Escriba su respuesta:" << std::endl;
			std::cin >> input;

			input = toupper(input); //Aumentamos el tamaño del input a mayúsculas.

			if (input != 'S' && input != 'N') {
				std::cout << "Entrada incorrecta, tiene que ser (s/n)." << std::endl;
			}
		} while (input != 'S' && input != 'N'); //Hasta que no se introduzca una S o N.

		if (input == 'S') {
			return 1; //Seguir.
		}

		else {
			return 0; //Salir.
		}
	}
	}
}