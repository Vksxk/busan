#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//2-2 파라미터 
#define LEN_MIN 15 // 기차 길이             
#define LEN_MAX 50
#define STM_MIN 0 // 마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 // 확률        
#define PROB_MAX 90
#define AGGRO_MIN 0 // 어그로 범위
#define AGGRO_MAX 5

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

//마동석 행동 입력
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
//마동석 이동 입력
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
//확률 계산
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
//턴 계산
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
//입력값 처리
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

//출력 변수
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
	//입력값 처리
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
	//출력
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
		//<이동>페이즈
		//시민 이동
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
		//좀비 이동(미완 붙잡혓을떄 안움직이는거)
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
		//출력
		map(train, citizen, zombie, madongseok);
		//시민 출력
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
		//좀비 출력
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

		// 마동석 이동
		// 좀비랑 인접할때 이동 못함
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
		//인접하지 않은 경우
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
		//맵 출력
		map(train, citizen, zombie, madongseok);
		//마동석 출력
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
		//행동페이지
		//시민 행동
		if (citizen == 1) {
			printf("SUCCESS! citizen(s) escaped to the next train");
			break;
		}
		else {
			printf("citizen does nothing.\n");
		}
		//좀비 행동
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



		//마동석이 좀비와 인접했을때
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
				//성공했을때
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
				//실패했을때
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
		//마동석이 좀비와 인접안했을때
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
		//다음턴으로
		turn++;
	}
	return 0;
}