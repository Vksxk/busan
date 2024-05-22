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

//������ �ൿ �Է�
int madongseok_P(int a) {
	int percentile;
	if (a == 1) {
		printf("madongseok action(0.rest, 1.provoke, 2. pull)>>");
		scanf_s("%d", &percentile);
		while (1) {
			if (percentile == 0) {
				return percentile;
			}
			else if (percentile == 1) {
				return percentile;
			}
			else if (percentile == 2) {
				return percentile;
			}
			else {
				printf("madongseok action(0.rest, 1.provoke, 2. pull)>>");
				scanf_s("%d", &percentile);
			}
		}
	}
	else {
		printf("madongseok action(0.rest, 1.provoke)>>");
		scanf_s("%d", &percentile);
		while (1) {
			if (percentile == 0) {
				return percentile;
			}
			else if (percentile == 1) {
				return percentile;
			}
			else {
				printf("madongseok action(0.rest, 1.provoke)>>");
				scanf_s("%d", &percentile);
			}
		}
	}
}
//������ �̵� �Է�
int madong(int a) {
	int percentile;
	if (a == 1) {
		printf("madongseok move(0:stay)>>");
		scanf_s("%d", &percentile);
		while (1) {
			if (percentile == 0) {
				return percentile;
			}
			else {
				printf("madongseok move(0:stay)>>");
				scanf_s("%d", &percentile);
			}
		}
	}
	else {
		printf("madongseok move(0:stay, 1:left)>>");
		scanf_s("%d", &percentile);
		while (1) {
			if (percentile == 0) {
				return percentile;
			}
			else if(percentile == 1) {
				return percentile;
			}
			else {
				printf("madongseok move(0:stay, 1:left)>>");
				scanf_s("%d", &percentile);
			}
		}
	}
}
//Ȯ�� ���
int random(int percentile) {
	int ran = rand() % 100;
	if (ran < 100 - percentile) {
		ran = 1;
		return ran;
	}
	else {
		ran = 0;
		return ran;
	}
}
//�� ���
int tur(int turn) {
	int tu;
	if (turn % 2 == 1) {
		tu = 1;
		return tu;
	}
	else {
		tu = 0;
		return tu;
	}
}
//�Է°� ó��
int percentileI(int a, int b) {
	int percentile;
	printf("percentile probability 'p'(%d~%d)>>", PROB_MIN, PROB_MAX);
	scanf_s("%d", &percentile);
	while (1) {
		if (percentile >= PROB_MIN && percentile <= PROB_MAX) {
			return percentile;
		}
		else {
			printf("percentile probability 'p'(%d~%d)>>", PROB_MIN, PROB_MAX);
			scanf_s("%d", &percentile);
		}
	}
}
int trainI(int a, int b) {
	int train;
	printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
	scanf_s("%d", &train);
	while (1) {
		if (train >= LEN_MIN && train <= LEN_MAX) {
			return train;
		}
		else {
			printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
			scanf_s("%d", &train);
		}
	}
}
int staminaI(int a, int b) {
	int stamina;
	printf("madongseok stamina(%d~%d)>>", STM_MIN, STM_MAX);
	scanf_s("%d", &stamina);
	while (1) {
		if (stamina >= STM_MIN && stamina <= STM_MAX) {
			return stamina;
		}
		else {
			printf("madongseok stamina(%d~%d)>>", STM_MIN, STM_MAX);
			scanf_s("%d", &stamina);
		}
	}
}

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
	printf("                                                  \n                            .,       ,,      ...  \n   !=.     !=,       ::     $#.     .#$    $*;#;  \n   =#-     =#-       $#     $#.  .***##*** #=;#;  \n   =#########-       $#     $#.  ,$$$$$$$$ #=;#;  \n   =#=*****##-       ##-    $#.     -;;-   #=;#;  \n   =#,     =#-      -##$    $#!;, .$####=..#=;#;  \n   =##$$$$$##-     .$#$#;   $###: ;#;  =####=;#;  \n   *$$$$$$$$$-    .=#! $#=. $#.   !#-  ;#!;#=;#;  \n                 ~##*   $#* $#.   -##=$##  #=;#;  \n =$$$$$$$$$$$$$~  *;     ~  $#.    ,=##*.  *!;#:  \n ##############:    -:,     $#.        ~=$#$*,    \n       $#.          !#~     $#.      ,###$$###$   \n       $#.          !#~              $#:     =#:  \n       $#.          !#~              $#,     !#;  \n       $#.          !#########:      ~##=!;!$##,  \n       $#.          ~!!!!!!!!!-       ,=#####!.   \n       ..                                ..       \n");
	//�Է°� ó��
	int train = trainI(LEN_MIN, LEN_MAX);
	int stamina = staminaI(STM_MIN, STM_MAX);
	int percentile = percentileI(PROB_MIN, PROB_MAX);
	int pull;
	int zombie = train - 3;
	int madongseok = train - 2;
	int citizen = train - 6;
	int turn = 1;
	int zombie_P = 0;
	int madongseok_A = 0;
	int citizen_A = 0;
	//���
	printf("\n");
	map(train, citizen, zombie,madongseok);
	printf("\n\n");
	int citizen_aggro = 1;
	int madongseok_aggro = 1;
	int action;
	int mds_aggro = madongseok_aggro;
	int citizen_chance;
	int madongseok_chance;
	while (1) {
		int zombie_C = 0;
		//<�̵�>������
		//�ù� �̵�
		citizen_chance = random(percentile);
		if (citizen_chance == 1) {
			citizen--;
			if (citizen_aggro + 1 == AGGRO_MIN) {
				citizen_A--;
			}
			else {
				citizen_aggro++;
			}
		}
		else {
			if (citizen_aggro - 1 == AGGRO_MIN) {
				citizen_A++;
			}
			else {
				citizen_aggro--;
			}
		}
		//���� �̵�(�̿� ���������� �ȿ����̴°�)
		int zombie_chance = tur(turn);
		if (pull = 1) {
			pull--;
			zombie_P++;
		}
		else if (zombie_chance == 1) {
				if (zombie == citizen + 1) {
				}
				else if (citizen_aggro > madongseok_aggro) {
					zombie--;
					zombie_C--;
				}
				else if (madongseok_aggro >= citizen_aggro) {
					if (zombie == madongseok - 1) {
					}
					else {
						zombie++;
						zombie_C--;
					}
				}
			}
		//���
		map(train, citizen, zombie, madongseok);
		//�ù� ���
		if (citizen_A == 1) {
			citizen_A--;
			printf("citizen: stay %d (aggro: %d)\n", citizen, citizen_aggro);
		}
		else if (citizen_A == -1) {
			citizen_A++;
			printf("citizen: stay %d (aggro: %d)\n", citizen, citizen_aggro);
		}
		else if (citizen_chance == 1) {
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", citizen + 1, citizen, citizen_aggro - 1, citizen_aggro);
		}
		else
			printf("citizen: stay %d (aggro: %d -> %d)\n", citizen, citizen_aggro+1, citizen_aggro);
		//���� ���
		if (zombie_P == 0) {
			zombie_P--;
			printf("zombie: I can't move %d\n\n", zombie);
		}
		else if (zombie_C == -1) {
			printf("zombie: %d -> %d\n\n", zombie + 1, zombie);
		}
		else if(zombie_C == 1) {
			printf("zombie: %d -> %d\n\n", zombie - 1, zombie);
		}
		else
			printf("zombie: stay %d\n\n", zombie);

		// ������ �̵�
		// ����� �����Ҷ� �̵� ����
		if (madongseok == zombie + 1) {
			madongseok_chance = madong(1);
			if (madongseok_chance == 0) {
				if (madongseok_aggro - 1 == AGGRO_MIN) {
					madongseok_A++;
				}
				else
					madongseok_aggro--;
			}
		}
		//�������� ���� ���
		else {
			madongseok_chance = madong(2);
			if (madongseok_chance == 0) {
				if (madongseok_aggro - 1 == AGGRO_MIN) {
				}
				else
					madongseok_aggro--;
			}
			else if (madongseok_chance == 1) {
				madongseok--;
				if (madongseok_aggro + 1 == AGGRO_MAX) {
				}
				else {
					madongseok_aggro++;
				}
			}
		}
		//�� ���
		map(train, citizen, zombie, madongseok);
		//������ ���
		if (madongseok_A == 1) {
			madongseok_A--;
			printf("madongseok: stay %d(aggro: %d, stamina: %d)\n\n", madongseok, madongseok_aggro, stamina);
		}
		else if (madongseok_A == -1) {
			madongseok_A++;
			printf("madongseok: stay %d(aggro: %d, stamina: %d)\n\n", madongseok, madongseok_aggro, stamina);
		}
		else if (madongseok_chance == 0) {
			printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro - 1, madongseok_aggro, stamina);
		}
		else if (madongseok_chance == 1) {
			printf("madongseok: left %d(aggro: %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro + 1, madongseok_aggro, stamina);
		}
		//�ൿ������
		//�ù� �ൿ
		if (citizen == 1) {
			printf("SUCCESS! citizen(s) escaped to the next train");
			break;
		}
		else {
			printf("citizen does nothing.\n");
		}
		//���� �ൿ
		if (zombie == citizen + 1 && zombie == madongseok - 1) {
			if (citizen_aggro > madongseok_aggro) {
				printf("GAME OVER! citizen dead...");
				break;
			}
			else {
				stamina--;
				if (stamina == STM_MIN) {
					printf("GAME OVER! madongseok dead...");
					break;
				}
				printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina : %d -> %d)\n", citizen_aggro, madongseok_aggro, stamina + 1, stamina);
			}
		}
		else if (zombie == madongseok - 1) {
			stamina--;
			if (stamina == STM_MIN) {
				printf("GAME OVER! madongseok dead...");
				break;
			}
			else
				printf("zombie attacked madongseok madongseok stamina: %d -> %d)\n", stamina + 1, stamina);
		}
		else
			printf("zombie attacked nobody.\n");



		//�������� ����� ����������
		if (madongseok == zombie + 1) {
			action = madongseok_P(1);
			if (action == 0) {
				printf("madongseok rets...\n");
				if (madongseok_aggro - 1 == AGGRO_MIN) {
					if (stamina + 1 == STM_MAX) {
						printf("madongseok: %d (aggro: %d, stamina: %d)\n\n\n", madongseok, madongseok_aggro, stamina);
					}
					else {
						stamina++;
						printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n\n", madongseok, madongseok_aggro, stamina-1, stamina);
					}
				}
				else if (stamina + 1 == STM_MAX) {
					madongseok_aggro++;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n\n", madongseok, madongseok_aggro - 1, madongseok_aggro, stamina);
				}
				else
					stamina++;
					madongseok_aggro++;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, madongseok_aggro - 1, madongseok_aggro, stamina-1, stamina);
			}
			else if (action == 1) {
				printf("madongseok provoked zombie...\n");
				if (madongseok_aggro == AGGRO_MAX) {
					printf("madongseok: %d (aggro: %d, stamina: %d)\n\n\n",madongseok, madongseok_aggro, stamina);
				}
				else {
					mds_aggro = madongseok_aggro;
					madongseok_aggro = AGGRO_MAX;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n\n",madongseok, mds_aggro, madongseok_aggro, stamina);
				}
			}
			else {
				int madongseok_pull = random(percentile);
				//����������
				if (madongseok_pull == 1) {
					pull = 1;
					printf("madongseok pulled zombie... Next turn, it can't move\n");
					mds_aggro = madongseok_aggro;
					madongseok_aggro++;
					madongseok_aggro++;
					if (madongseok_aggro > AGGRO_MAX) {
						madongseok_aggro = AGGRO_MAX;
						if (stamina - 1 == STM_MIN) {
							printf("GAME OVER! madongseok dead...");
							break;
						}
						else {
							stamina--;
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, mds_aggro, madongseok_aggro, stamina + 1, stamina);
						}
					}
					else if (stamina -1 == STM_MIN){
						printf("GAME OVER! madongseok dead...");
						break;
					}
					else {
						stamina--;
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, mds_aggro, madongseok_aggro, stamina + 1, stamina);
					}
				}
				//����������
				else {
					printf("madongseok failed to pull zombie\n");
					mds_aggro = madongseok_aggro;
					madongseok_aggro++;
					madongseok_aggro++;
					if (madongseok_aggro > AGGRO_MAX) {
						madongseok_aggro = AGGRO_MAX;
						if (stamina - 1 == STM_MIN) {
							printf("GAME OVER! madongseok dead...");
							break;
						}
						else {
							stamina--;
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, mds_aggro, madongseok_aggro, stamina + 1, stamina);
						}
					}
					else if (stamina - 1 == STM_MIN) {
						printf("GAME OVER! madongseok dead...");
						break;
					}
					else {
						stamina--;
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, mds_aggro, madongseok_aggro, stamina + 1, stamina);
					}
				}
			}
		}
		//�������� ����� ������������
		else {
			action = madongseok_P(2);
			if (action == 0) {
				printf("madongseok rets...\n");
				if (madongseok_aggro - 1 == AGGRO_MIN) {
					if (stamina + 1 == STM_MAX) {
						printf("madongseok: %d (aggro: %d, stamina: %d)\n\n\n", madongseok, madongseok_aggro, stamina);
					}
					else {
						stamina++;
						printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n\n", madongseok, madongseok_aggro, stamina - 1, stamina);
					}
				}
				else if (stamina + 1 == STM_MAX) {
					madongseok_aggro++;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n\n", madongseok, madongseok_aggro - 1, madongseok_aggro, stamina);
				}
				else
					stamina++;
				madongseok_aggro++;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n\n", madongseok, madongseok_aggro - 1, madongseok_aggro, stamina - 1, stamina);
			}
			else if (action == 1) {
				printf("madongseok provoked zombie...\n");
				printf("madongseok provoked zombie...\n");
				if (madongseok_aggro == AGGRO_MAX) {
					printf("madongseok: %d (aggro: %d, stamina: %d)\n\n\n", madongseok, madongseok_aggro, stamina);
				}
				else {
					mds_aggro = madongseok_aggro;
					madongseok_aggro = AGGRO_MAX;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n\n", madongseok, mds_aggro, madongseok_aggro, stamina);
				}
			}
		}
		//����������
		turn++;
	}
	return 0;
}