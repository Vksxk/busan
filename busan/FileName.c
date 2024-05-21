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


//��� ����
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
	int action;
	int mds_aggro = 1;

	while (1) {
		//<�̵�>������
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
			zombie--;
		}
		else if (turn % 2 == 0) {
			printf("zombie: stay %d (cannot move)\n\n", zombie);
		}
		//���
		map(train, citizen, zombie, madongseok);
		//�ù� ���
		if (citizen_chance < 100 - percentile) {
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", citizen + 1, citizen, citizen_aggro - 1, citizen_aggro);
		}
		else
			printf("citizen: stay %d\n", citizen);
		//���� ���
		if (zombie_chance > 100 - percentile) {
			printf("zombie: %d -> %d\n\n", zombie + 1, zombie);
		}
		else {
			printf("zombie: stay %d\n\n", zombie);
		}
		// ������ �̵�
		// ����� �����Ҷ� �̵� ����
		if (madongseok == zombie + 1) {
			while (1) {
				printf("madongseok move(0:stay)>>");
				scanf_s("%d", &move);
				if (move == 0) {
					madongseok_aggro--;
					printf("madongseok: stay %d(aggro: %d, stamina: %d\n", madongseok, madongseok_aggro, stamina);
					break;
				}
				else {
					printf("madongseok move(0:stay)>>");
					scanf_s("%d", &move);
				}
			}
		}
		//���� ���ϸ� �̵�����
		else {
			while (1) {
				printf("madongseok move(0:stay, 1:left)>>");
				scanf_s("%d", &move);
				if (move == 0) {
					madongseok_aggro--;
					printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d\n", madongseok, madongseok_aggro+1, madongseok_aggro, stamina);
					break;
				}
				else if (move == 1) {
					madongseok_aggro++;
					printf("madongseok: left %d(aggro: %d -> %d, stamina: %d\n", madongseok, madongseok_aggro-1, madongseok_aggro, stamina);
					madongseok--;
					break;
				}
				else {
					printf("madongseok move(0:stay, 1:left)>>");
					scanf_s("%d", &move);
				}
			}
		map(train, citizen, zombie, madongseok);
		}
		if (madongseok == zombie + 1) {
			printf("madongseok action(0.rest, 1.provoke, 2. pull)>>");
			scanf_s("%d", &action);
			if (action == 0) {
				printf("\nmadongseok rets...\n");
				madongseok_aggro--;
				stamina++;
				printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d\n", madongseok_aggro + 1, madongseok_aggro, stamina - 1, stamina);
			}
			else if (action == 1) {
				printf("madongseok provoked zombie...\n");
				mds_aggro = madongseok_aggro;
				madongseok_aggro = AGGRO_MAX;
				printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
			}
			else if (action == 2) {
				mds_aggro = madongseok_aggro;
				madongseok_aggro++;
				madongseok_aggro++;
				stamina--;
				if (madongseok_aggro > AGGRO_MAX) {
					madongseok_aggro = AGGRO_MAX;
					int madongseok_chance = rand() % 100;
					if (madongseok_chance < 100 - percentile) {
						printf("madongseok pulled zombie... Next turn, it can't move\n");
						printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
					}
					else {
						printf("madongseok failed to pull zombie\n");
						printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
					}
				}
				else {
					int madongseok_chance = rand() % 100;
					if (madongseok_chance < 100 - percentile) {
						printf("madongseok pulled zombie... Next turn, it can't move\n");
						printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
					}
					else {
						printf("madongseok failed to pull zombie\n");
						printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
					}
				}
		}
		else {
				printf("madongseok action(0.rest, 1.provoke)>>");
				scanf_s("%d", &action);
				if (action == 0) {
					printf("\nmadongseok rets...\n");
					madongseok_aggro++;
					stamina++;
					printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d\n", madongseok_aggro - 1, madongseok_aggro, stamina - 1, stamina);
				}
				else if (action == 1) {
					printf("madongseok provoked zombie...\n");
					mds_aggro = madongseok_aggro;
					madongseok_aggro = AGGRO_MAX;
					printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n", mds_aggro, madongseok_aggro, stamina);
				}
			}

		}
		//�ù� �¸�
		if (citizen == 1) {
			printf("SUCCESS!\ncitizen(s) escaped to the next train");
			break;
		}
		//���� �¸�
		if (zombie == citizen + 1 && zombie == madongseok - 1) {
			if (citizen_aggro > madongseok_aggro) {
				printf("GAME OVER! citizen dead...");
				break;
			}
			else
				stamina--;
				printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina : %d -> %d\n\n", citizen_aggro, madongseok_aggro, stamina + 1, stamina);
		}
		else if (zombie == madongseok - 1) {
			stamina--;
			if (stamina = STM_MIN) {
				printf("Game Over! Madongseok was hit by a zombie and his stamina was reduced to 0.");
				break;
			}else
			printf("zombie attacked madongseok madongseok stamina: %d -> %d\n\n", stamina + 1, stamina);
		}
		else
			printf("zombie attacked nobody.\n");

		//����������
		turn++;
	}
	return 0;
}