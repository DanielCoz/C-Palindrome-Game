
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"
#include <stdio.h>

//------------------------------------
//	main
//------------------------------------
int main() {
	//1. We generate the seed for the random number
	srand(time(NULL));

	//2. We select the number of 6 digits we want to play with
	int pal_num = 721174;

	printf("\n\n");
	


	//3. We perform the interactive session
	user_game_palindrome(pal_num);


	//4. We finish the program
	printf("\n\nPress enter to quit.");
	getchar();
	return 0;
}
