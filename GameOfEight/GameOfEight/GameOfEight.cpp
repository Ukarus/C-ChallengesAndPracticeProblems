// GameOfEight.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

bool WantToPlayAgain();
void PlayGame();
int GetChoice(int previousChoice);
const int IGNORE_CHARS = 256;

int main()
{
	do
	{
		PlayGame();
	} while (WantToPlayAgain());
}

bool WantToPlayAgain()
{
	char c;
	bool failure;
	do
	{
		failure = false;
		cout << "Do you want to play again? (y/n): ";
		cin >> c;
		c = tolower(c);

		if (cin.fail() || (c != 'y' && c != 'n'))
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Please enter y or n";
			failure = true;
		}

	} while (failure);

	return c == 'y';
}

void PlayGame()
{
	int initialNumber = 8;
	int previousChoice = 0;
	int playerTurn = 1;
	int lastPlayer = 0;

	do
	{
		cout << "Number is currently " << initialNumber << endl;
		cout << "Player " << playerTurn << " turn" << endl;
		int choice = GetChoice(previousChoice);
		previousChoice = choice;
		initialNumber -= choice;
		lastPlayer = playerTurn;
		playerTurn++;

		if (playerTurn > 2) {
			playerTurn = 1;
		}
	} while (initialNumber > 0);

	cout << "Player " << lastPlayer << " won" << endl;
}

int GetChoice(int previousChoice)
{
	int choice;
	bool failure;
	do
	{
		failure = false;
		cout << "Choose a number (available options: ";
		for (int i = 1; i <= 3; i++)
		{
			if (i != previousChoice) {

				if (i < 3) {
					cout << i << ", ";
				}
				else {
					cout << i << "): ";
				}
			}
		}

		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 3)
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Please enter a number between 1 and 3\n";
			failure = true;
		}

		if (choice == previousChoice)
		{
			cout << "You can't enter the number your opponent inputted previously\n";
			failure = true;
		}

	} while (failure);

	return choice;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
