/* Caroline Jesuíno Nunes da Silva*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE -1
#define BOARD_SIZE 9

int is_invalid(char * board) {
	int count_X = 0, count_0 = 0;

	for(int i = 0; i < BOARD_SIZE; i++) {
		if (board[i] == '0') count_0++; 
		if (board[i] == 'X') count_X++; 
	}
	
	if(abs(count_0 - count_X) > 1) return TRUE;

	return FALSE;
}
/* Cases where are winners: lines with the same character, rows with the same
 * character and diagonals with the same character*/
int is_won(char * board, int * winner) {
	int i, ret = FALSE;
	char winner_symbol;
		
	// check the lines
	for(i = 0; i < BOARD_SIZE; i+= 3) {	
		if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
			ret = TRUE;
			winner_symbol = board[i];
		}
	}
	for(i = 0; i < 3; i ++) {
		// check the rows
		if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
			ret = TRUE;
			winner_symbol = board[i];
		}
	}
	// check the first diagonal
	if (board[0] == board[4] && board[0] == board[8]) {
		ret = TRUE;
		winner_symbol = board[0];
	// check the other one		
	} else if (board[2] == board[4] && board[2] == board[6]) {
		ret = TRUE;
		winner_symbol = board[2];
	}
	
	if (winner_symbol == 'X') {
		*winner = 1;
	} else {
		*winner = 0;
	}
	return ret;
}

/*If there is still empty spaces, the player with less plays should be the next
 * one to play*/
int next_to_play(char * board, int * next) {
	int count_X = 0, count_0 = 0, count_dot = 0;
	for(int i = 0; i < BOARD_SIZE; i++) {
		if(board[i] == 'X') {
			count_X++;
		} else if (board[i] == '0') {
			count_0++;
		} else if (board[i] == '.') {
			count_dot++;
		}
	}

	// since X is the first to play, if the 0 count is the same as the X
	// count, its because 0 was the last one to play
	if(count_dot == 0) {
		return FALSE;
	}
	if(count_0 == count_X) {
		*next = 1;
		return TRUE;
	}
	*next = 2;
	return TRUE;
}

/* The order of strenght of the conditions of the board are: 1-invalid board, 
because if it is already invalid it should not have a winner nor play more, 
2-winner, because if there is a winner there is no need to keep playing, 3-next 
to play.*/
void analyze_board(char * board) {
	int ret, jogador;

	ret = is_invalid(board);
	if (ret == TRUE) {
		printf("Inválido\n");
		return;
	}
	ret = is_won(board, &jogador);
	if (ret == TRUE) {
		if (jogador == 1) {
			printf("O primeiro jogador venceu\n");
		} else {
			printf("O segundo jogador venceu\n");
		}
		return;
	}
	ret = next_to_play(board, &jogador);
	if (ret == TRUE) {
		if (jogador == 1) {
			printf("Primeiro\n");
		} else {
			printf("Segundo\n");
		}
		return;
	}

	// Se nenhuma das outras condições foi atendida, houve um empate
	printf("Empate\n");
}

int main(int argc, char ** argv) {
	char * board;
	scanf("%ms", &board);
	
	analyze_board(board);	

	free(board);
	return 0;
}
