// TicTacToe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;
const char* INPUT_ERROR_STRING = "Input error, Please try again!";
void DrawBoard(int board[][BOARD_SIZE]);
void PlayGame();
void PlayTurn(int board[][BOARD_SIZE], int player);
bool IsGameOver(int board[][BOARD_SIZE], int &winner);
char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength);
bool WantToPlayAgain();

int main()
{
	/*
		Write the game of Tic Tac Toe. It's a game with a 3 by 3 grid played by 2 players. 
		One player places O markers and the other player places X markers. Each player takes turns placing his/her marker in order to get 3 of their markers to line up on the board. 
		A player wins when 3 or their markers line up either horizontally, vertically or diagonally. 
		If no player has their markers line up in that fashion, and the board is full, then the game is called a "Cat Game". 
		Your program should output the winner of the game or "Cat Game" if there was no winner. 
		The user should be prompted if they would like to play again when the game is over. 
		If they choose to play again, the player who started second last game should go first. 
	*/
	do
	{
		PlayGame();
	} while (WantToPlayAgain());

   

	return 0;
}

void PlayGame()
{
	// Initialize a clear board
	int board[BOARD_SIZE][BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
	DrawBoard(board);
	int winner = 0;
	bool isGameOver = false;
	while (!isGameOver)
	{
		int player = 1;
		PlayTurn(board, player);
		DrawBoard(board);
		isGameOver = IsGameOver(board, winner);
		cout << "is over "<< isGameOver << endl;
		if (isGameOver)
		{
			break;
		}

		player = 2;
		PlayTurn(board, player);
		DrawBoard(board);
		isGameOver = IsGameOver(board, winner);
		if (isGameOver)
		{
			break;
		}
	}
	

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

void PlayTurn(int board[][BOARD_SIZE], int player)
{
	bool failure;
	do
	{
		int x, y;
		failure = false;
		cout << "Player " << player << " turn" << endl;
		cout << "Where do you want to place the mark?: ";
		cin >> x >> y;

		if (cin.fail())
		{
			cin.ignore(256, '\n');
			cin.clear();
			cout << "Input error" << endl;
			failure = true;
		}
		else if (x < 0 || x > BOARD_SIZE - 1 || y < 0 || y > BOARD_SIZE - 1)
		{
			cout << "Input error" << endl;
			failure = true;
		}
		else {
			if (player == 1) {
				board[x][y] = 1;
			}
			else {
				board[x][y] = 2;
			}
		}

	} while (failure);
}

bool IsGameOver(int board[][BOARD_SIZE], int &winner)
{

	// Check horizontal
	// TODO: Only checks for int 1 or 2 on horizontal, diagonal and verticals
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i][0] == board[i][1] == board[i][2])
		{
			winner = board[i][0] == 1 ? 1 : 2;
			return true;
		}
	}

	// check columns
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		if (board[0][i] == board[1][i] == board[2][i])
		{
			winner = board[i][0] == 1 ? 1 : 2;
			return true;
		}
	}

	// check diagonals
	if (board[0][0] == board[1][1] == board[2][2])
	{
		winner = board[0][0] == 1 ? 1 : 2;
		return true;
	}
	else if (board[2][0] == board[1][1] == board[0][2])
	{
		winner = board[0][0] == 1 ? 1 : 2;
		return true;
	}

	// check cat game
	bool isCatGame = true;
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				isCatGame = false;
			}
		}
	}

	return isCatGame;
}

void DrawBoard(int board[][BOARD_SIZE])
{
	/*
		+---+---+---+
		|	|	|	|
		+---+---+---+
		|	|	|	|
		+---+---+---+
		|	|	|	|
		+---+---+---+
	*/


	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			int elem = board[i][j];
			if (elem == 0)
			{
				cout << "*";
			}
			else if (elem == 1)
			{
				cout << "O";
			}
			else if (elem == 2)
			{
				cout << "X";
			}
		}
		cout << endl;
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
