#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 11

int ship_pattern[2][5][5][2], last_turn_1 = 0,  a_kill = 0, b_kill = 0;

//char map[11][11];

/*
auto complete input map
1 A1 vertical down A2 vertical down A3 vertical down A4 vertical down A5 vertical down A1 vertical down A2 vertical down A3 vertical down A4 vertical down A5 vertical down
*/

/*
auto complete guessing game
A1 A0 B1 A0 C1 A0 D1 A0 E1 A0 
A2 A0 B2 A0 C2 A0 D2 A0 
A3 A0 B3 A0 C3 A0
A4 A0 B4 A0 C4 A0 
A5 A0 B5
*/

void print_menu(){
	printf("Battleship\n");
	printf("1. Play\n");
	printf("2. How to play\n");
	printf("3. Exit\n");
	printf(">> ");
}

void how_to_play(){
	printf("HOW TO PLAY\n");
	printf("-----------\n");
	printf("Battledzhip is a two player game based on 'BATTLESHIP' board game.\n\n");
	printf("There will be user : User A (first turn) and user B (second turn).\n");
	printf("Initially, each user will map his /  her ship coordinate in 10 x 10 map.\n");
	printf("There are 5 ship they are going to map :\n");
	printf("1. 5 blocks ship (1)\n");
	printf("2. 4 blocks ship (1)\n");
	printf("3. 3 blocks ship (2)\n");
	printf("4. 2 blocks ship (1)\n\n");
}

void print_map(int map[max][max]){
	printf("  ");
	for(int i=0; i<10; i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int i=0; i<10; i++){
		printf("%c ", 65+i);
		for(int j=0; j<10; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

int input_map(char turn, int loop, int map[max][max]){
	int player;
	if(turn == 'A') player = 0;
	else if(turn == 'B') player = 1;
	
	printf("MAPPING SHIPS COORDINATE [%c]\n", turn);
	printf("----------------------------\n\n");
	print_map(map);
	printf("\n[%d] four blocks ship\n", loop);
	printf("-----------------------\n");
	char cordinate[3];
	char flow[12];
	char direction[6];
	do{
		printf("Coordinate [A - J][0 - 9] (case sensitive) : ");
		scanf("%s", cordinate);
		if(strlen(cordinate) < 3 && cordinate[0] <= 'J' && cordinate[0] >= 'A' && cordinate[1] >= '0' && cordinate[1] <= '9'){
			break;
		}
	}while(1);
	
	do{
		printf("Flow [vertical | horizontal] (case sensitive) :");
		scanf("%s", flow);
		if(strcmp(flow, "vertical") == 0 || strcmp(flow, "horizontal") == 0){
			break;
		}
	}while(1);
	
	do{
		if(strcmp(flow, "vertical") == 0){
			printf("Direction [up | down] (case sensitive) : ");
			scanf("%s", direction);
			if(strcmp(direction, "up") == 0 || strcmp(direction, "down") == 0){
				break;
			}
		}
		else if(strcmp(flow, "horizontal") == 0){
			printf("Direction [left | right] (case sensitive) : ");
			scanf("%s", direction);
			if(strcmp(direction, "left") == 0 || strcmp(direction, "right") == 0){
				break;
			}
		}
	}while(1);
	
	
	
	if(strcmp(flow, "vertical") == 0 && strcmp(direction, "down") == 0){
		for(int x=0; x<loop; x++){
			if( (cordinate[0] - 'A' + x) < 0 || (cordinate[0] - 'A' + x) > 9 || map[cordinate[0] - 'A' + x][cordinate[1] - '0'] == turn) return 0;
//			if( (cordinate[1] - '0') < 0 || (cordinate[1] - '0') > 9) return 0;
		}
	}
	else if(strcmp(flow, "vertical") == 0 && strcmp(direction, "up") == 0){
		for(int x=0; x<loop; x++){
			if( (cordinate[0] - 'A' - x) < 0 || (cordinate[0] - 'A' - x) > 9 || map[cordinate[0] - 'A' - x][cordinate[1] - '0'] == turn) return 0;
//			if( (cordinate[1] - '0') < 0 || (cordinate[1] - '0') > 9) return 0;
		}
	}
	else if(strcmp(flow, "horizontal") == 0 && strcmp(direction, "right") == 0){
		for(int x=0; x<loop; x++){
//			if( (cordinate[0] - 'A') < 0 || (cordinate[0] - 'A') > 9 ) return 0;
			if( (cordinate[1] - '0' + x) < 0 || (cordinate[1] - '0' + x) > 9 || map[cordinate[0] - 'A'][cordinate[1] - '0' + x] == turn) return 0;
		}
	}
	else if(strcmp(flow, "horizontal") == 0 && strcmp(direction, "left") == 0){
		for(int x=0; x<loop; x++){
//			if( (cordinate[0] - 'A') < 0 || (cordinate[0] - 'A') > 9 ) return 0;
			if( (cordinate[1] - '0' - x) < 0 || (cordinate[1] - '0' - x) > 9 || map[cordinate[0] - 'A' + x][cordinate[1] - '0'] == turn) return 0;

		}
	}		
	
	
	if(strcmp(flow, "vertical") == 0 && strcmp(direction, "down") == 0){
		for(int x=0; x<loop; x++){
			map[cordinate[0] - 'A' + x][cordinate[1] - '0'] = turn;
			
			ship_pattern[player][last_turn_1][x][0] = cordinate[0] - 'A' + x;
			ship_pattern[player][last_turn_1][x][1] = cordinate[1] - '0';
//			printf("--%d--\n", ship_pattern[player][last_turn_1][0]);
//			printf("**%d--\n", ship_pattern[player][last_turn_1][1]);
			
//			last_turn_1++;
//			last_turn_2++;
		}
	}
	else if(strcmp(flow, "vertical") == 0 && strcmp(direction, "up") == 0){
		for(int x=0; x<loop; x++){
			map[cordinate[0] - 'A' - x][cordinate[1] - '0'] = turn;
			
			ship_pattern[player][last_turn_1][x][0] = cordinate[0] - 'A' - x;
			ship_pattern[player][last_turn_1][x][1] = cordinate[1] - '0';

//			last_turn_1++;
//			last_turn_2++;
		}
	}
	else if(strcmp(flow, "horizontal") == 0 && strcmp(direction, "right") == 0){
		for(int x=0; x<loop; x++){
			map[cordinate[0] - 'A'][cordinate[1] - '0' + x] = turn;
			ship_pattern[player][last_turn_1][x][0] = cordinate[0] - 'A';
			ship_pattern[player][last_turn_1][x][1] = cordinate[1] - '0' + x;
			
//			last_turn_1++;
//			last_turn_2++;
		}
	}
	else if(strcmp(flow, "horizontal") == 0 && strcmp(direction, "left") == 0){
		for(int x=0; x<loop; x++){
			map[cordinate[0] - 'A'][cordinate[1] - '0' - x] = turn;
			ship_pattern[player][last_turn_1][x][0] = cordinate[0] - 'A';
			ship_pattern[player][last_turn_1][x][1] = cordinate[1] - '0' - x;
			
//			last_turn_1++;
//			last_turn_2++;
		}
	}	
	
	last_turn_1++;
	
	return 1;
}

void reset(int map[max][max]){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			map[i][j] = '.';
			map[i][j] = '.';
		}
	}
}

void input_map_loop(char turn, int loop, int map[max][max]){
	do{
		if(input_map(turn, loop, map) == 1){
//			system("pause");
			system("cls");
			break;
		}
		printf("\nYour inputed cordinate is either out of range or already filled by another ship!\n");
		system("pause");
		system("cls");
	}while(true);
}

void guessing_game(char turn, int turn_2, int map[max][max], int map_en[max][max]){
	printf("Its's player [%c]'s turn\n'", turn);
	printf("-----------------------\n'");
	if(turn == 'A') printf("Ship destroyed : %d\n\n", a_kill);
	if(turn == 'B') printf("Ship destroyed : %d\n\n", b_kill);
	
	print_map(map);
	
	printf("\nInput coordinate [A - J][0 - 9] : ");
	char input_2[3];
	do{
		printf("Input coordinate [A - J][0 - 9] : ");
		scanf("%s", input_2);
		if(strlen(input_2) < 3 && input_2[0] <= 'J' && input_2[0] >= 'A' && input_2[1] >= '0' && input_2[1] <= '9'){
			break;
		}
	}while(1);
	
	if(map_en[input_2[0] - 'A'][input_2[1] - '0'] == turn_2) {
		map[input_2[0] - 'A'][input_2[1] - '0'] = '!';
		if(turn == 'A') a_kill++;
		else if(turn == 'B') b_kill++;
		
//		for(int a=0; a<2; a++){
//			for(int b=0; b<5; b++){
//				for(int c=0; c<5; c++){
//					
//					if(ship_pattern[a][b][c][0] = input_2[0] - 'A' &&
//					ship_pattern[a][b][c][1] = input_2[1] - '0'){
//						
//					}
//				}
//			}
//		}

	}
	else map[input_2[0] - 'A'][input_2[1] - '0'] = '~';
}

int main(){
	int menu, map_a[11][11], map_b[11][11];
	
	reset(map_a);
	reset(map_b);
		
	do{
		print_menu();
		scanf("%d", &menu);
		
		if(menu == 1){
		
			system("cls");
			printf("A's turn to map his / her ship!\n");
			system("pause");
			system("cls");
			last_turn_1 = 0;
			input_map_loop('A', 5, map_a);
			input_map_loop('A', 4, map_a);
			input_map_loop('A', 3, map_a);
			input_map_loop('A', 3, map_a);
			input_map_loop('A', 2, map_a);
			
			system("cls");
			printf("B's turn to map his / her ship!\n");
			system("pause");
			system("cls");
			last_turn_1 = 0; 
			input_map_loop('B', 5, map_b);
			input_map_loop('B', 4, map_b);
			input_map_loop('B', 3, map_b);
			input_map_loop('B', 3, map_b);
			input_map_loop('B', 2, map_b);

			
//			for(int a=0; a<2; a++){
//				for(int b=0; b<5; b++){
//					for(int c=0; c<5; c++){
//						printf("[%d][%d]\n", ship_pattern[a][b][c][0], ship_pattern[a][b][c][1]);
//					}
//				}
//			}
			
			int map_a_2[max][max], map_b_2[max][max];
			
			reset(map_a_2);
			reset(map_b_2);

			do{
				if(a_kill > 16 ){
					system("cls");
					printf("A Win!\n");
					break;
				}
				if(b_kill > 16){
					system("cls");
					printf("B Win!\n");
					break;
				}
				guessing_game('A', 'B', map_a_2, map_b);
//				system("pause");
				system("cls");
				if(a_kill > 16 ){
					system("cls");
					printf("A Win!\n");
					break;
				}
				guessing_game('B', 'A', map_b_2, map_a);
//				system("pause");
				system("cls");
			}while(true);
			
		}
		else if (menu == 2){
			how_to_play();
		}
		else if(menu == 3){
			printf("Thank you for playing the game!\n");
			break;
		}
		else {
			printf("You should input 1-3!\n");
		}
		
		system("pause");
		system("cls");
	}while(1);
	
	return 0;
}
