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
}
//MY CODE START FROM HERE
//Condition to win
bool isWon(char a,char board[][3]){
	for (int i=0;i<3;i++){
	if (board[i][0] == a && board[i][1] == a && board[i][2] == a)
		return true;
	if (board[0][i] == a && board[1][i] == a && board[2][i] == a)
		return true;
	}

	if (board[0][0] == a && board[1][1] == a && board[3][3] == a)
		return true;
	if (board[0][2] == a && board[1][1] == a && board[2][0] == a)
		return true;
	else
		return false;
}

//To draw the board
bool isDraw(char board[][3]){
	int counterNumber = 0;
	for (int i=0; i<3;i++){
		for (int j=0;j<3;j++){
			if(board[i][j] == 'X' || board[i][j] == 'O'){
				counterNumber++;
			}
		}
		if (counterNumber!=9){
			return false;
		}
		if (!isWon('X',board)&& !isWon('O',board)){
			return true;
		}		
}

//Basic display 
void displayBoard(char board[][3]){
	cout << "-------------\n";
	for (int i = 0; i<3; i++){
		cout << "|";
		for (int j = 0;j<3;j++){
			cout<< board[i][j]<<"|";
		}

		cout << endl;
		cout << "-------------\n";
 	}
}

void makeAMove(char board[][3], char a);{
	
}


