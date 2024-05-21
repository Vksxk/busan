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


int madongseok12(int a) {
	int action;
	if (a == 1) {
		printf("madongseok action(0.rest, 1.provoke)>>");
		scanf_s("%d", &action);
		if (action == 0) {
			printf("madongseok rets...");
			return 0;
		}
		else if (action == 2) {
			printf("madongseok provoked zombie...");
			return 0;
		}
		else if (action == 3) {
			//����� ���� ����
			printf("madongseok pulled zombie... Next turn, it can't move");
			printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d");

		}
	}
}

//2-1 ����
void map(int train, int citizen, int zombie, int madongseok) {
	for (int i = 1; i <= train; i++) {
		printf("#");
	}
	printf("\n#");
	for (int i = 1; i <= train; i++) {
		if (i == citizen)
			printf("C");
		else if (i == zombie)
			printf("Z");
		else if (i == madongseok)
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
	printf("\n\n");
}

int main(void) {
	srand((unsigned int)time(NULL));
	//��Ʈ�� printf("                                                  \n                            .,       ,,      ...  \n   !=.     !=,       ::     $#.     .#$    $*;#;  \n   =#-     =#-       $#     $#.  .***##*** #=;#;  \n   =#########-       $#     $#.  ,$$$$$$$$ #=;#;  \n   =#=*****##-       ##-    $#.     -;;-   #=;#;  \n   =#,     =#-      -##$    $#!;, .$####=..#=;#;  \n   =##$$$$$##-     .$#$#;   $###: ;#;  =####=;#;  \n   *$$$$$$$$$-    .=#! $#=. $#.   !#-  ;#!;#=;#;  \n                 ~##*   $#* $#.   -##=$##  #=;#;  \n =$$$$$$$$$$$$$~  *;     ~  $#.    ,=##*.  *!;#:  \n ##############:    -:,     $#.        ~=$#$*,    \n       $#.          !#~     $#.      ,###$$###$   \n       $#.          !#~              $#:     =#:  \n       $#.          !#~              $#,     !#;  \n       $#.          !#########:      ~##=!;!$##,  \n       $#.          ~!!!!!!!!!-       ,=#####!.   \n       ..                                ..       \n");
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
	int madongseok = train - 2;
	int citizen = train - 6;
	int turn = 1;
	//���
	printf("\n");
	map(train, citizen, zombie,madongseok);
	printf("\n\n");
	int move;
	int citizen_aggro = 1;
	int madongseok_aggro = 1;

	while (1) {
		//�ù� �̵�
		int citizen_chance = rand() % 100;
		if (citizen_chance < 100 - percentile) {
			citizen--;
			citizen_aggro++;
		}
		else
			citizen_aggro--;
			
		//���� �̵�
		int zombie_chance = rand() % 100;
		if (turn % 2 == 1) {
			if (zombie_chance > 100 - percentile) {
				if (citizen_aggro >= madongseok_aggro) {
					zombie--;
				}
				else
					zombie++;
			}
		}
		//���� ���
		map(train, citizen, zombie, madongseok);

		//�ù� �̵� 
		if (citizen_chance < 100 - percentile) {
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", citizen + 1, citizen, citizen_aggro - 1, citizen_aggro);
		}
		else
			printf("citizen: stay %d\n", citizen);
		// ���� ��
		if (turn % 2 == 0) {
			printf("zombie: stay %d (cannot move)\n\n", zombie);
		}
		//���� �̵�
		else if (zombie_chance > 100 - percentile) {
			if (citizen_aggro >= madongseok_aggro) {
				printf("zombie: %d -> %d\n\n", zombie + 1, zombie);
			}
			else
				printf("zombie: %d -> %d\n\n", zombie - 1, zombie);
		}
		else
			printf("zombie: stay %d\n\n", zombie);
		//���� ���
		if (citizen == 1) {
			printf("SUCCESS!\ncitizen(s) escaped to the next train");
			break;
		}
		if (zombie == citizen + 1) {
			printf("GAME OVER!\nCitizen(s) has(have) been attacked by a zombie");
			break;
		}
		// ������ �̵�
		if (madongseok == zombie + 1) {
			while (1) {
				printf("madongseok move(0:stay)>>");
				scanf_s("%d", &move);
				if (move == 0) {
					madongseok_aggro--;
					break;
				}
				else {
					printf("madongseok move(0:stay)>>");
					scanf_s("%d", &move);
				}
			}
		}
		else {
			while (1) {
				printf("madongseok move(0:stay, 1:left)>>");
				scanf_s("%d", &move);
				if (move == 0) {
					madongseok_aggro--;
					break;
				}
				else if (move == 1) {
					madongseok_aggro++;
					break;
				}
				else {
					printf("madongseok move(0:stay, 1:left)>>");
					scanf_s("%d", &move);
				}
			}
		}
		//���
		map(train, citizen, zombie, madongseok);

		//�ൿ ������
		

		//����������
		turn++;
	}
	return 0;
}