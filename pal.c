
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub){
	//1. We create the output variable with an initial value.
	int res = 0;

	//2. We assign num to a random value in the desired range
	res = (rand() % (ub - lb)) + lb;

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {

		dummy_char = getchar();

		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// initialise_array
//--------------------------------------------------
void initialise_array(int a[6], int num) {

	int index = 5;
	int digit;


	while (num)
	{	
		digit = num % 10;

		a[index] = (digit);

		num /= 10;
		--index;
	}
}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {

	boolean b = False;

	if (a[0] == a[5] && a[1] == a[4] && a[2] == a[3]) {

		b = True;
	}

	return b;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {

	char res = ' ';
	
	boolean validChar = False;

	do{

		printf("\n\nNEW MOVEMENT: Enter a valid command by keyword:\nValid commands: a       d       w       x \n\n");

		res = my_get_char();


		if (res == 'a' || res == 'd' || res == 'w' || res == 'x') {

			validChar = True;
		}

	} while(validChar == False);

	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){


	if (c == 'a') {

		if (*p_p > &a[0]) {

			(*p_p) = (*p_p) - 1;

			++(*p_nm);
		}	
	}

	if (c == 'd') {

		if (*p_p < &a[5]) {
			
			(*p_p) = (*p_p) + 1;

			++(*p_nm);
		}
	}

	if (c == 'w') {



		if ((**p_p) < 9) {
		
			(**p_p) = (**p_p) + 1;
			
			++(*p_nm);
		}
	}

	if (c == 'x') {


		if ((**p_p) > 0) {
			
			(**p_p) = (**p_p) - 1;

			++(*p_nm);
		}
	}

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int * nm) {



	printf("\n\n------ Game Status -------\nNumber = { ");
								   
	for (int i = 0; i < 6; i++) {

		printf("%d ", a[i]);
	}


	printf("}\n           ");

	if (p == &a[0]) {

		printf("^");
	}

	if (p == &a[1]) {

		printf("  ^");
	}

	if (p == &a[2]) {

		printf("    ^");
	}

	if (p == &a[3]) {

		printf("      ^");
	}

	if (p == &a[4]) {

		printf("        ^");
	}

	if (p == &a[5]) {

		printf("          ^");
	}
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {


	int a[6];
	initialise_array(a, pal_num);

	int* p = &a[gen_num(0, 6)];
	
	int nm = 0;

	
	boolean b = is_pal(a);

	while (b == False) {



		print_status(a, p, nm);
		printf("\n\n-------------");
		printf("\nNum mov = %d ", nm);
		char c = ask_for_command();
		
		

		process_movement(a,  &p, &nm, c);

		

		b = is_pal(a);
	}   

	
		print_status(a, p, nm);

		printf("\n\n-------------------------");
		printf("\n------- SOLVED! ---------");
		printf("\n-------------------------");

	

}

