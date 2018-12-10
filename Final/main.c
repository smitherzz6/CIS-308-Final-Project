#include <gb/gb.h>
#include <stdio.h>
#include "Export.c"
#include "Roger.c"
#include "map.c"
#include "Opener.c"
#include "Letters.c"
#include "Wrong.c"
#include "Blank.c"
#include "Blank_Letters.c"
#define advance(a) (a + 1);
//initialization
char *end;
void b();
void Roger_Roger();
void init();
void checkInput();
void updateSwitches();
int a;
int clues;
int choice;
int i;

// L I T E R A L   H O U R S   F O R   M E M O R Y   A L L O C A T I O N

//clue comparison
typedef struct {
	int num;
}Clue;
Clue c1 = { 1 }; // Blood x=90 y=77
Clue c2 = { 2 }; // Table x=15  y=53
Clue c3 = { 3 }; // Bra   x=71  y=23
Clue c4 = { 4 }; // Poem  x=119 y=101
Clue c5 = { 5 }; // Knife x=135 y=45
Clue c6 = { 6 };
UINT8 player[2];
//extern unsigned char Blood2[];
void main() {
	init();
	end = " THE END!           ";
	printf("\n \n \n \n \n ");
	printf("CIS 308 FINAL GAME \n");
	printf("\n \n \n \n \n \n");
	printf(" PRESS Z TO START! \n");
	a = 0;
	clues = 1;
	choice = 0;
	while(1){
		checkInput();
		updateSwitches();

		if (joypad() & J_A && a == 0) {
			b();
			a = 1;
		}
		else if (joypad() & J_A && a == 1) {
			set_bkg_data(0, 20, Table_Left);
			set_bkg_tiles(0, 0, 20, 18, Map);
			Roger_Roger();
			a=2;
		}
		// Blood
		if (player[0] <= 94 && player[0] >= 86 && player[1] >= 73 && player[1] <= 81 && joypad() & J_A) {
			set_sprite_data(0, 18, Roger_Hurt);
			if (clues == c1.num) {
				set_bkg_data(0, 32, LetterTLE0);
				set_bkg_tiles(0, 0, 20, 18, Blank_Text);
				clues = advance(clues);

				printf("MR. JENKIN'S BLOOD, ");
				printf("REPORTS SAY HE WAS \n");
				printf("SHOT. PERHAPS \n");
				printf("THERE WAS A FIGHT?");
			}
			else {
				set_bkg_data(0, 32, LetterTLE0);
				set_bkg_tiles(0,0, 20, 18, Wrong);
			}
			a = 1;
			delay(1000);
		}

		// Table
		if (player[0] <= 28 && player[0] >= 20 && player[1] >= 49 && player[1] <= 57 && joypad() & J_A) {

			set_sprite_data(0, 18, Roger_Hurt);
			if (clues == c2.num) {
				set_bkg_data(0, 32, Blank_Letters_Text);
				clues = advance(clues);
				set_bkg_tiles(0, 0, 20, 18, Blank_Text);
				printf("\nA BROKEN TABLE, \n");
				printf("SEEMS IT WAS       \n");
				printf("KNOCKED OVER.      \n");
				printf("REPORTS SAY HIM    \n");
				printf("AND HIS WIFE WERE  \n");
				printf("ARGUING, WHAT WAS  \n");
				printf("THE REASON?        ");
			}
			else {
				set_bkg_data(0, 32, LetterTLE0);
				set_bkg_tiles(0, 0, 20, 18, Wrong);
			}
			a = 1;
			delay(1000);
		}
		
		// Bra x=71  y=23
		if (player[0] >= 75 && player[0] <= 83 && player[1] >= 17 && player[1] <=26 && joypad() & J_A) {

			set_sprite_data(0, 18, Roger_Hurt);
			if (clues == c3.num) {
				clues = advance(clues);
				set_bkg_data(0, 32, Blank_Letters_Text);
				set_bkg_tiles(0, 0, 20, 18, Blank_Text);
				printf("\nTHE MAID'S BRA, MR.\n");
				printf("JENKINS WAS HAVING \n");
				printf("AN AFFAIR! WHAT    \n");
				printf("ELSE WAS HE HIDING?");

			}
			else {
				set_bkg_data(0, 32, LetterTLE0);
				set_bkg_tiles(0, 0, 20, 18, Wrong);
			}
			a = 1;
			delay(1000);
		}
		
		// Poem  x=119 y=101
		if (player[0] >= 124 && player[0] <= 132 && player[1] >= 97 && player[1] <= 105 && joypad() & J_A) {

			 set_sprite_data(0, 18, Roger_Hurt);
			if (clues == c4.num) {
				clues=advance(clues);
				set_bkg_data(0, 32, Blank_Letters_Text);
				set_bkg_tiles(0, 0, 20, 18, Blank_Text);
				printf("\nA LOVE POEM BY MR. \n");
				printf("JENKINS FOR HIS    \n");
				printf("MAID! HOW WOULD    \n");
				printf("HIS WIFE REACT?    ");
			}
			else {
				set_bkg_data(0, 32, LetterTLE0);
				 set_bkg_tiles(0, 0, 20, 18, Wrong);
			}
			a = 1;
			delay(1000);
		}
		//Knife x=145 y=45
		if (player[0] >= 140 && player[0] <= 148 && player[1] >= 41 && player[1] <= 49 && joypad() & J_A) {

			set_sprite_data(0, 18, Roger_Hurt);
			if (clues == c5.num) {
				clues = advance(clues);
				a = 1;
				set_bkg_data(0, 32, Blank_Letters_Text);
				set_bkg_tiles(0, 0, 20, 18, Blank_Text);
				printf("\nA KNIFE! THE SON   \n");
				printf("SAW HIS MOTHER RUN \n");
				printf("IN WITH IT!        ");
			}
			else {
				set_bkg_data(0, 32, LetterTLE0);
				set_bkg_tiles(0, 0, 20, 18, Wrong);
			}
			a = 10;
			delay(1000);
			while (a == 10) {
				if (joypad() & J_A) {
					a=1;
				}
			}
		}

		if (clues == c6.num && a == 1) {
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			Roger_Roger();
			printf("\n  WHO DO YOU THINK  ");
			printf("KILLED MR. JENKINS? \n \n ");
			printf("WIFE   SON   MAID\n \n \n");
			a++;
		}
		if (player[0] >= 10 && player[0] <= 48 && player[1] >= 120 && player[1] <= 128 && clues == 6 && joypad() & J_A) {
			choice = 1;
		}
		if (player[0] >= 70 && player[0] <= 96 && player[1] >= 120 && player[1] <= 128 && clues == 6 && joypad() & J_A) {
			choice = 2;
		}
		if (player[0] >= 114 && player[0] <= 152 && player[1] >= 120 && player[1] <= 128 && clues == 6 && joypad() & J_A) {
			choice = 3;
		}
		if (choice == 1) {
			set_sprite_data(0, 18, Roger_Hurt);
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf("INCORRECT!         \n");
			printf("Upon further       \ninvestigation, it  \nwas found that Mr. \n");
			printf("Jenkins had put his\nson on his will.   \n");
			printf("A gun was found in \nhis car missing    \n");
			printf("a single bullet.   ");
			while (choice == 1) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf(" The Wife           \ndid conspire       \n");
			printf("to kill, but       \n");
			printf("she had a knife.   \n");
			printf("When she ran in,   \nshe found only a   \n");
			printf("dead corpse with   \na bullet in it's   \nhead               \n");
			printf("IT WAS THE SON!    ");
			choice = 1;
			while (choice == 1) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			for (i = 0; i < 20; i++) {
				printf("%c", end[i]);
				delay(500);
			}
		}
		if (choice == 2) {
			set_sprite_data(0, 18, Roger_Hurt);
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf("CORRECT!           \n");
			printf("Upon further       \ninvestigation, it  \nwas found that Mr. \n");
			printf("Jenkins had put his\nson on his will.   \n");
			printf("A gun was found in \nhis car missing    \n");
			printf("a single bullet.   ");
			while (choice == 2) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf(" The Wife           \ndid conspire       \n");
			printf("to kill, but       \n");
			printf("she had a knife.   \n");
			printf("When she ran in,   \nshe found only a   \n");
			printf("dead corpse with   \na bullet in it's   \nhead               \n");
			printf("IT WAS THE SON!    ");
			choice = 2;
			while (choice == 2) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			for (i = 0; i < 20; i++) {
				printf("%c", end[i]);
				delay(500);
			}
		}
		if (choice == 3) {
			set_sprite_data(0, 18, Roger_Hurt);
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf("INCORRECT!         \n");
			printf("Upon further       \ninvestigation, it  \nwas found that Mr. \n");
			printf("Jenkins had put his\nson on his will.   \n");
			printf("A gun was found in \nhis car missing    \n");
			printf("a single bullet.   ");
			while (choice == 3) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			printf(" The Wife           \ndid conspire       \n");
			printf("to kill, but       \n");
			printf("she had a knife.   \n");
			printf("When she ran in,   \nshe found only a   \n");
			printf("dead corpse with   \na bullet in it's   \nhead               \n");
			printf("IT WAS THE SON!    ");
			choice = 3;
			while (choice == 3) {
				if (joypad() & J_A) {
					choice = choice + 10;
				}
			}
			set_bkg_data(0, 32, Blank_Letters_Text);
			set_bkg_tiles(0, 0, 20, 18, Blank_Text);
			for (i = 0; i <20; i++) {
				printf("%c", end[i]);
				delay(500);
			}
		}
			//come back to this just in case (check switches and the other were here)
			//wait_vb1_done();
			
		// Game code here
	}
	
}


void b() {
	set_bkg_data(0, 32, LetterTLE0);
	set_bkg_tiles(0, 0, 20, 18, Opener);
	delay(1000);
}

void Roger_Roger() {
	set_sprite_data(0, 18, Roger);
	set_sprite_tile(0, 0);
	player[0] = 80;
	player[1] = 80;
	if (clues == 6) {
		player[0] = 82;
		player[1] = 124;
	}
	//player=[0] = 80;
	//player[1] = 80;
}

void init() {
	DISPLAY_ON;		// Turn on the display
	NR52_REG = 0x8F;	// Turn on the sound
	NR51_REG = 0x11;	// Enable the sound channels
	NR50_REG = 0x77;	// Increase the volume to its max

}

void updateSwitches() {
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
}

void checkInput() {

	// UP
	if (joypad() & J_UP && player[1] > 19) {

			player[1]--;
	}

	// DOWN
	if (joypad() & J_DOWN && player[1] < 149) {

		player[1]++;

	}

	// LEFT
	if (joypad() & J_LEFT && player[0] > 9) {

		player[0]--;

	}

	// RIGHT
	if (joypad() & J_RIGHT && player[0] < 159) {

		player[0]++;

	}
	//speed
	delay(20);
	move_sprite(0, player[0], player[1]);
}