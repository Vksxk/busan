#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//2-2 �Ķ���� 
#define LEN_MIN 15 // ���� ����             
#define LEN_MAX 50
#define STM_MIN 0 // ������ ü��
#define STM_MAX 5
#define PROB_MIN 10 // Ȯ��        
#define PROB_MAX 90
#define AGGRO_MIN 0 // ��׷� ����
#define AGGRO_MAX 5

// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// ������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

int main(void) {
	srand((unsigned int)time(NULL));
	printf("                                                  \n                            .,       ,,      ...  \n   !=.     !=,       ::     $#.     .#$    $*;#;  \n   =#-     =#-       $#     $#.  .***##*** #=;#;  \n   =#########-       $#     $#.  ,$$$$$$$$ #=;#;  \n   =#=*****##-       ##-    $#.     -;;-   #=;#;  \n   =#,     =#-      -##$    $#!;, .$####=..#=;#;  \n   =##$$$$$##-     .$#$#;   $###: ;#;  =####=;#;  \n   *$$$$$$$$$-    .=#! $#=. $#.   !#-  ;#!;#=;#;  \n                 ~##*   $#* $#.   -##=$##  #=;#;  \n =$$$$$$$$$$$$$~  *;     ~  $#.    ,=##*.  *!;#:  \n ##############:    -:,     $#.        ~=$#$*,    \n       $#.          !#~     $#.      ,###$$###$   \n       $#.          !#~              $#:     =#:  \n       $#.          !#~              $#,     !#;  \n       $#.          !#########:      ~##=!;!$##,  \n       $#.          ~!!!!!!!!!-       ,=#####!.   \n       ..                                ..       \n");
	int train, percentile, stamina;
	// 2-2 ���� �Է°� ó��
	while (1) {
		printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
		scanf_s("%d", &train);
		if (train >= LEN_MIN && train <= LEN_MAX) {
			break;
		}
		else {
		}
	}
	// 2-2 ������ �Է°� ó��
	while (1) {
		printf("madongseok stamina(%d~%d)>>", STM_MIN, STM_MAX);
		scanf_s("%d", &stamina);
		if (stamina >= STM_MIN && stamina <= STM_MAX) {
			break;
		}
		else {
		}
	}
	// 2-2 Ȯ�� �Է°� ó��
	while (1) {
		printf("percentile probability 'p'(%d~%d)>>", PROB_MIN, PROB_MAX);
		scanf_s("%d", &percentile);
		if (percentile >= PROB_MIN && percentile <= PROB_MAX) {
			break;
		}
		else {
		}
	}
	
	int zombie = train - 3;
	int citizen = train - 6;
	int turn = 1;
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