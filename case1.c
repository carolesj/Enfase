/* Caroline Jesuino Nunes da Silva
Since this case is simple and little, I opted to not overmodularize it
*/

#include <stdio.h>
#include <stdlib.h>
#define forever 1

int walk_torwards_each_other(int first_initial_position, int
	second_initial_position) {
	
	int position_difference, tiredness = 0, 
		first_tiredness_coeficient = 1, second_tiredness_coeficient = 1;
	
	// to make sure the orientation is right, the first friend will always
	// be in the smallest position
	if (first_initial_position > second_initial_position) {
		int aux = second_initial_position;
		second_initial_position = first_initial_position;
		first_initial_position = aux;
	}
	
	// at every iteration we have a scenario where at least one of the
	// initial positions are changed. The idea is that, everytime a friend
	// moves, we have almost the same situation, but only the tirednesses
	// are different
	while(forever) {
		first_initial_position++;
		tiredness += first_tiredness_coeficient;
		first_tiredness_coeficient++;
		if (first_initial_position == second_initial_position) {
			break;
		}
		second_initial_position--;
		tiredness += second_tiredness_coeficient;
		second_tiredness_coeficient++;
		if (first_initial_position == second_initial_position) {
			break;
		}	
	}
	return tiredness;
}

int main (int argc, char ** argv) {
	int first_initial_position, second_initial_position, tiredness;
	scanf("%d%d", &first_initial_position, &second_initial_position);
	
	tiredness = walk_torwards_each_other(first_initial_position,
		second_initial_position);
	printf("%d", tiredness);	
	
	return 0;
}
