#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define LEN_MIN 15             
#define LEN_MAX 50
#define PROB_MIN 10        
#define PROB_MAX 90

int main(void) {
	srand((unsigned int)time(NULL));
	printf("                                                  \n                            .,       ,,      ...  \n   !=.     !=,       ::     $#.     .#$    $*;#;  \n   =#-     =#-       $#     $#.  .***##*** #=;#;  \n   =#########-       $#     $#.  ,$$$$$$$$ #=;#;  \n   =#=*****##-       ##-    $#.     -;;-   #=;#;  \n   =#,     =#-      -##$    $#!;, .$####=..#=;#;  \n   =##$$$$$##-     .$#$#;   $###: ;#;  =####=;#;  \n   *$$$$$$$$$-    .=#! $#=. $#.   !#-  ;#!;#=;#;  \n                 ~##*   $#* $#.   -##=$##  #=;#;  \n =$$$$$$$$$$$$$~  *;     ~  $#.    ,=##*.  *!;#:  \n ##############:    -:,     $#.        ~=$#$*,    \n       $#.          !#~     $#.      ,###$$###$   \n       $#.          !#~              $#:     =#:  \n       $#.          !#~              $#,     !#;  \n       $#.          !#########:      ~##=!;!$##,  \n       $#.          ~!!!!!!!!!-       ,=#####!.   \n       ..                                ..       \n");
	int train, percentile;
	printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
	scanf_s("%d", &train);
	int zombie = train - 3;
	int citizen = train - 6;
	int turn = 1;
	if (train < LEN_MIN || train > LEN_MAX)
		return 0;
	printf("percentile probability 'p'(%d~%d)>>", PROB_MIN, PROB_MAX);
	scanf_s("%d", &percentile);
	if (percentile < PROB_MIN || percentile > PROB_MAX)
		return 0;
	for (int i = 1; i <= train; i++) {
		printf("#");
	}
	printf("\n#");
	for (int i = 1; i <= train; i++) {
		if (i == citizen)
			printf("C");
		else if (i == zombie)
			printf("Z");
		else if (i == train - 2)
			printf("M");
		else if (i == train - 1)
			printf("#");
		else 
			printf(" ");
	}
	printf("\n");
	for (int i = 1; i <= train; i++) {
		printf("#");
	}
	printf("\n");
	printf("\n");
	while (1) {
		int citizen_chance = rand() % 100;
		if (citizen_chance < 100 - percentile) {
			citizen = (citizen > 1) ? (citizen - 1) : 1;
		}
		int zombie_chance = rand() % 100;
		if (turn % 2 == 1) {
			if (zombie_chance > 100 - percentile) {
				zombie = (zombie > 1) ? (zombie - 1) : 1;
			}
		}
		printf("\n");
		for (int i = 1; i <= train; i++) {
			printf("#");
		}
		printf("\n#");
		for (int i = 1; i <= train; i++) {
			if (i == citizen)
				printf("C");
			else if (i == zombie)
				printf("Z");
			else if (i == train - 2)
				printf("M");
			else if (i == train - 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
		for (int i = 1; i <= train; i++) {
			printf("#");
		}
		printf("\n");
		printf("\n");
		if (citizen_chance < 100 - percentile) {
			printf("citizen: %d -> %d\n", citizen + 1, citizen);
		}
		else
			printf("citizen: stay %d\n", citizen);
		if (turn % 2 == 0) {
			printf("zombie: stay %d (cannot move)\n\n", zombie);
		}
		else if (zombie_chance > 100 - percentile) {
			printf("zombie: % d -> % d\n\n", zombie + 1, zombie);
		}
		else
			printf("zombie: stay %d\n\n", zombie);
		if (citizen == 1) {
			printf("SUCCESS!\ncitizen(s) escaped to the next train");
			break;
		}
		if (zombie == citizen + 1) {
			printf("GAME OVER!\nCitizen(s) has(have) been attacked by a zombie");
			break;
		}
		turn++;
		Sleep(4000);
	}
	return 0;
}