// NumberGuesser.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

const int IGNORE_CHARS = 256;
const int MAX_RANGE = 100;

bool WantToPlayAgain();
bool IsGameOver(int maxGuesses, int secretNumber, int guess);
void PlayGame();
void DisplayResults(int maxGuesses, int secretNumber);
int GetGuess(int maxGuesses);

// maxGuesses == 0

int main()
{
	do
	{
		PlayGame();
	} while (WantToPlayAgain());
}

void PlayGame()
{
	int secretNumber = 65;
	int maxGuesses = ceil(log2(MAX_RANGE));
	int guess = 0;
	cout << "Guess a number between 0 and " << MAX_RANGE << endl;

	do
	{
		guess = GetGuess(maxGuesses);
		
		if (guess != secretNumber) {
			maxGuesses--;
			if (guess > secretNumber)
			{
				cout << "The guess is too hight\n";
			}
			else
			{
				cout << "The guess is too low\n";
			}
		}

	} while (!IsGameOver(maxGuesses, secretNumber, guess));
	DisplayResults(maxGuesses, secretNumber);
}

void DisplayResults(int maxGuesses, int secretNumber)
{
	if (maxGuesses > 0)
	{
		cout << "You guessed it, the secret number was: " << secretNumber << endl;
	}
	else {
		cout << "You didn't get it, the secret number was: " << secretNumber << endl;
	}
}

int GetGuess(int maxGuesses)
{
	int n;
	bool failure;
	do
	{
		failure = false;
		cout << "Please enter a guess ( " << maxGuesses << " guesses left): ";
		cin >> n;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Please enter an integer between 0 and " << MAX_RANGE << endl;
			failure = true;
		}
	} while (failure);

	return n;
}

bool IsGameOver(int maxGuesses, int secretNumber, int guess)
{
	return maxGuesses == 0 || secretNumber == guess;
}

bool WantToPlayAgain()
{
	char c;
	bool failure;
	do
	{
		failure = false;
		cout << "Would you like to play again? (y/n): ";
		cin >> c;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Please enter y or n";
			failure = true;
		}
	} while (failure);

	return c == 'y';
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
