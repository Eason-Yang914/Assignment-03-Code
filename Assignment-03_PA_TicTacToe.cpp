#include <iostream>
#include <stdlib.h>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {

		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);

		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
};

//MY CODE START FROM HERE
//need to add current input character as variable, char current     
bool isWon(char current ,char board[][3]){
	for (int i = 0; i < 3; i++){
		// use if loop to decide in which condition, the player can win
		//column win condition
		if (board[i][0] == current && board[i][1] == current && board[i][2] == current){
			return true;
		}

		//row win condition
		if (board[0][i] == current && board[1][i] == current && board[2][i] == current){
			return true;
		}
		
		
	}

	//traverser win condition
		if (board[0][0] == current && board[1][1] == current && board[2][2] == current){
			return true;
		}
		
		//another traverser win condition
		if (board[2][0] == current && board[1][1] == current && board[0][2] == current){
			return true;
		}else{
			return false;
		}
	//return 0;
};

//Define the method isDraw()
bool isDraw(char board[][3]){
	for (int i = 0 ; i<3 ; i++){
		for (int k = 0; k<3 ; k++){
			if (board[i][k] == ' '){
				return false;
			}
		}		
	}
	return true;
};

//Define the function displayBoard
//using for loop to display basic TicTacToe board
void displayBoard(char board[][3]){
	cout << "-------------" << endl;

	for (int i = 0; i<3; i++){
		cout << "|";
		for (int k =0; k<3;k++){
			cout <<" "<< board[i][k]<< "|";
		}
		cout << endl;
	}
		cout << "-------------"<< endl;
	
};

//Define the method makeAMove()
void makeAMove(char board[][3], char current){
	//setup input window
	int row;
	int column;
	cout << "Enter a row (0,1,2) for player " << current << ":";
	cin >> row;
	cout << "Enter a column (0,1,2) for player" << current << ":"; 
	cin >> column;

	if (board[row][column] != ' '){
		cout << "This cell is already occupied. Try a different cell" << endl;
		cout << "Enter a row (0,1,2) for player " << current << ":";
		cin >> row;
		cout << "Enter a column (0,1,2) for player" << current << ":"; 
		cin >> column;
	}
	board[row][column] = current;
};