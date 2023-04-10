// Hangman.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstring>
using namespace std;

const int IGNORE_CHARS = 256;
const char* INPUT_ERROR_STRING = "Input error, Please try again!";

void PlayGame();
bool WantToPlayAgain();
int GetSecretPhrase(char secretPhrase[], int maxLength);
char * MakeHiddenPhrase(char secretPhrase[], int secretPhraseLength);
void DrawBoard(int numberOfGuessesLeft, char* hiddenPhrase);
char GetGuess();
bool IsGameOver(int numberOfGuessesLeft, const char* hiddenPhrase, int secretPhraseLength);
void DisplayResult(const char *secretPhrase, int numberOfGuessesLeft);
void UpdateBoard(char guess, char* hiddenPhrase,const char secretPhrase[], const int secretPhraseLength, int &numberOfGuessesLeft);
char GetCharacter(const char* prompt, const char* error);
char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength);
void ClearScreen();
void WaitForKeyPress();

int main()
{

	do
	{
		PlayGame();
	} while (WantToPlayAgain());

    return 0;
}

void PlayGame()
{
	const int MAX_LENGTH_OF_SECRET_PHRASE = 256;
	const int MAX_NUMBER_OF_GUESSES = 6;

	char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];
	char* hiddenPhrase = nullptr;
	int numberOfGuessesLeft = MAX_NUMBER_OF_GUESSES;

	int secretPhraseLength = GetSecretPhrase(secretPhrase, MAX_LENGTH_OF_SECRET_PHRASE);
	ClearScreen();
	hiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);

	DrawBoard(numberOfGuessesLeft, hiddenPhrase);
	char guess;

	do
	{
		guess = GetGuess();
		//WaitForKeyPress();
		UpdateBoard(guess, hiddenPhrase, secretPhrase, secretPhraseLength, numberOfGuessesLeft);
		DrawBoard(numberOfGuessesLeft, hiddenPhrase);

	} while (!IsGameOver(numberOfGuessesLeft, hiddenPhrase, secretPhraseLength));

	DisplayResult(secretPhrase, numberOfGuessesLeft);

	delete[] hiddenPhrase;
}

void DisplayResult(const char* secretPhrase, int numberOfGuessesLeft)
{
	if (numberOfGuessesLeft > 0)
	{
		cout << "You got it! The phrase was: " << secretPhrase << endl;
	}
	else
	{
		cout << "You didn't get it! The phrase was: " << secretPhrase << endl;
	}
}

bool IsGameOver(int numberOfGuessesLeft, const char* hiddenPhrase, int secretPhraseLength)
{
	bool hasDash = false;
	for (int i = 0; i < secretPhraseLength; i++)
	{
		if (hiddenPhrase[i] == '_')
		{
			hasDash = true;
			break;
		}
	}

	return numberOfGuessesLeft == 0 || !hasDash;
}

void UpdateBoard(char guess, char* hiddenPhrase, const char secretPhrase[], const int secretPhraseLength, int& numberOfGuessesLeft)
{
	bool found = false;

	for (int i = 0; i < secretPhraseLength; i++)
	{
		if (tolower(secretPhrase[i]) == guess) {
			hiddenPhrase[i] = secretPhrase[i];
			found = true;
		}
	}

	if (!found)
	{
		numberOfGuessesLeft--;
	}
}

char GetGuess()
{
	return GetCharacter("Please input your guess: ", INPUT_ERROR_STRING);
}

int GetSecretPhrase(char secretPhrase[], int maxLength)
{
	bool failure;
	int length;

	do
	{
		failure = false;

		cout << "Please enter the secret phrase: ";
		cin.get(secretPhrase, maxLength);

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			failure = true;
			cout << INPUT_ERROR_STRING << endl;
		}
		else
		{
			length = strlen(secretPhrase);

			if (length == 0)
			{
				cout << "You must enter a word that's longer than zero";
				failure = true;
			}
		}


	} while (failure);

	return length;
}

char* MakeHiddenPhrase(char secretPhrase[], int secretPhraseLength)
{
	char* hiddenPhrase = new char[secretPhraseLength + 1];
	
	for (int i = 0; i < secretPhraseLength; i++)
	{
		if (secretPhrase[i] != ' ') {
			hiddenPhrase[i] = '_';
		}
		else
		{
			hiddenPhrase[i] = ' ';
		}
	}

	hiddenPhrase[secretPhraseLength] = '\0';

	return hiddenPhrase;
}

void DrawBoard(int numberOfGuessesLeft, char* hiddenPhrase)
{
	switch (numberOfGuessesLeft)
	{
	case 0:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|  /|\\" << endl;
		cout << "|  / \\" << endl;
		cout << "-+-" << endl;
		break;
	}
	case 1: 
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|  /|\\" << endl;
		cout << "|  /" << endl;
		cout << "-+-" << endl;
		break;
	}
	case 2:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|  /|\\" << endl;
		cout << "|  " << endl;
		cout << "-+-" << endl;
		break;
	}
	case 3:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|  /|" << endl;
		cout << "|  " << endl;
		cout << "-+-" << endl;
		break;
	}
	case 4:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|   |" << endl;
		cout << "|  " << endl;
		cout << "-+-" << endl;
		break;
	}
	case 5:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|   O" << endl;
		cout << "|   " << endl;
		cout << "|  " << endl;
		cout << "-+-" << endl;
		break;
	}
	case 6:
	{
		cout << "+---+" << endl;
		cout << "|   |" << endl;
		cout << "|  " << endl;
		cout << "|  " << endl;
		cout << "|  " << endl;
		cout << "-+-" << endl;
		break;
	}
	default:
		break;
	}

	cout << "Secret phrase: " << hiddenPhrase << endl;
}

bool WantToPlayAgain()
{
	const char validInputs[] = { 'y', 'n' };
	char response = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInputs, 2);

	return response == 'y';
}

char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength)
{
	char input;
	bool inputFailure = false;

	do {

		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.ignore(256, '\n');
			std::cin.clear();
			std::cout << error << std::endl;
			inputFailure = true;
		}
		else
		{
			std::cin.ignore(256, '\n');

			input = std::tolower(input);

			for (int i = 0; i < validInputLength; ++i)
			{
				if (input == validInput[i])
				{
					return input;
				}
			}

			std::cout << error << std::endl;
			inputFailure = true;
		}

	} while (inputFailure);

	return ' ';
}

char GetCharacter(const char* prompt, const char* error)
{
	char input;
	bool inputFailure;

	do {

		inputFailure = false;
		std::cout << prompt;

		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.ignore(256, '\n');
			std::cin.clear();
			std::cout << error << std::endl;
			inputFailure = true;
		}
		else
		{
			std::cin.ignore(256, '\n');
			if (std::isalpha(input))
			{
				input = std::tolower(input);
			}
			else
			{
				std::cout << error << std::endl;
				inputFailure = true;
			}
		}

	} while (inputFailure);

	return input;
}

void ClearScreen()
{
	system("cls");
}

void WaitForKeyPress()
{
	system("pause");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
