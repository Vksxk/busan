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

int main(void) {
	srand((unsigned int)time(NULL));
	printf("                                                  \n                            .,       ,,      ...  \n   !=.     !=,       ::     $#.     .#$    $*;#;  \n   =#-     =#-       $#     $#.  .***##*** #=;#;  \n   =#########-       $#     $#.  ,$$$$$$$$ #=;#;  \n   =#=*****##-       ##-    $#.     -;;-   #=;#;  \n   =#,     =#-      -##$    $#!;, .$####=..#=;#;  \n   =##$$$$$##-     .$#$#;   $###: ;#;  =####=;#;  \n   *$$$$$$$$$-    .=#! $#=. $#.   !#-  ;#!;#=;#;  \n                 ~##*   $#* $#.   -##=$##  #=;#;  \n =$$$$$$$$$$$$$~  *;     ~  $#.    ,=##*.  *!;#:  \n ##############:    -:,     $#.        ~=$#$*,    \n       $#.          !#~     $#.      ,###$$###$   \n       $#.          !#~              $#:     =#:  \n       $#.          !#~              $#,     !#;  \n       $#.          !#########:      ~##=!;!$##,  \n       $#.          ~!!!!!!!!!-       ,=#####!.   \n       ..                                ..       \n");
	int train, percentile, stamina;
	// 2-2 기차 입력값 처리
	while (1) {
		printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
		scanf_s("%d", &train);
		if (train >= LEN_MIN && train <= LEN_MAX) {
			break;
		}
		else {
		}
	}
	// 2-2 마동석 입력값 처리
	while (1) {
		printf("madongseok stamina(%d~%d)>>", STM_MIN, STM_MAX);
		scanf_s("%d", &stamina);
		if (stamina >= STM_MIN && stamina <= STM_MAX) {
			break;
		}
		else {
		}
	}
	// 2-2 확률 입력값 처리
	while (1) {
		printf("percentile probability 'p'(%d~%d)>>", PROB_MIN, PROB_MAX);	
		scanf_s("%d", &percentile);
		if (percentile >= PROB_MIN && percentile <= PROB_MAX) {
			break;
		}
		else {
		}
	}
	// 출력
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

	// 2 - 3 이동
	int move;
	int citizen_aggro = 1;
	int madongseok_aggro = 1;

	while (1) {
		//시민 이동
		int citizen_chance = rand() % 100;
		if (citizen_chance < 100 - percentile) {
			citizen--;
			citizen_aggro++;
		}
		else
			citizen_aggro--;
			
		//좀비 이동
		int zombie_chance = rand() % 100;
		if (turn % 2 == 1) {
			if (zombie_chance > 100 - percentile) {
				zombie = (zombie > 1) ? (zombie - 1) : 1;
			}
		}
		//마동석 이동
		printf("madongseok move(0:stay, 1:left)>>");
		scanf_s("%d", &move);
		if (move == 0) {
			madongseok_aggro--;
		}
		else if (move == 1) {
			madongseok_aggro++;
		}
		//출력
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
		// 출력
		if (citizen_chance < 100 - percentile) {
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", citizen + 1, citizen, citizen_aggro - 1, citizen_aggro);
		}
		else
			printf("citizen: stay %d\n", citizen);
		// 좀비 턴 계산
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
	}
	return 0;
}