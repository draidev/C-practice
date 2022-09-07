#include <stdio.h>
#include <ctype.h>
#define SUB_NUM 4  //과목 개수 

enum {
	KOR,
	ENG,
	MATH,
	SCI
};
typedef struct Student {
	int id;
	char name[20];
	int subject[4];
	int kor, eng, math, sci;
}student;

void bubble_sort(int n, student *stu, int sub)
{
	student temp;
	int i, j, m;
	
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n - 1; j++)
			if(stu[j-1].subject[sub] > stu[j].subject[sub])
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
//  정렬 과정 확인 
//	for (m = 0; m < n; m++)
//	{
//		printf("%d%s ", stu[m].id, stu[m].name);
//	}
	printf("\n");
	}
}

int show_stu(int num, student *stu)
{
	int i;
	printf("현재 등록된 학생 목록\n");
				
	for (i = 0; i < num; i++)
	{
		printf("%d. %s ", i+1, stu[i].name);
	}
	printf("\n"); 
}

int main(void)
{
	student stu[100];
	int num, i, sel_menu, sel_stu, sel_sub, sub;
	double aver, kor_aver=0, eng_aver=0, math_aver=0, sci_aver=0; // 평균 
	
	printf("관리할 학생은 몇 명인가요? ");
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		printf("%d번 학생의 학번을 입력해주세요: ", i+1);
		scanf("%d", &stu[i].id);
		printf("%d번 학생의 이름을 입력해주세요: ", i+1);
		scanf("%s", stu[i].name);
		printf("%d번 학생의 국어 성적을 입력해주세요: ", i+1);
		scanf("%d", &stu[i].subject[KOR]);
		printf("%d번 학생의 영어 성적을 입력해주세요: ", i+1);
		scanf("%d", &stu[i].subject[ENG]);
		printf("%d번 학생의 수학 성적을 입력해주세요: ", i+1);
		scanf("%d", &stu[i].subject[MATH]);
		printf("%d번 학생의 과학 성적을 입력해주세요: ", i+1);
		scanf("%d", &stu[i].subject[SCI]);
	}	

while (1)
	{
		printf("================================================================\n");
		printf("학생 관리 시스템 입니다.\n");
		printf("1. 학생 정보 조회\n");
		printf("2. 성적 조회\n"); 
		printf("3. 성적 관리\n");
		printf("종료는 0을 입력하세요.\n\n");
		printf("무엇을 도와 드릴까요? ");
		scanf("%d", &sel_menu);
		if (sel_menu == 0) 
		{
			printf("****종료****\n");
			break;
		}
		
		switch (sel_menu)
		{
			case 1:
				show_stu(num, stu);
				printf("어떤 학생의 정보를 조회 하겠습니까? ");
				scanf("%d", &sel_stu);
				
				printf("\n1. 전체 정보 조회\n");
				printf("2. 전체 성적 평균\n\n");
				printf("무엇을 도와 드릴까요? ");
				scanf("%d", &sel_menu);
				sel_stu--;
				
				switch (sel_menu)
				{
					case 1:
						printf("\n이름: %s, 학번: %d, 국어: %d, 영어: %d, 수학: %d, 과학: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
						
					case 2:
						aver = (stu[sel_stu].subject[KOR] + stu[sel_stu].subject[ENG] + stu[sel_stu].subject[MATH] + stu[sel_stu].subject[SCI]) / SUB_NUM;
						printf("\n%s의 전체 성적 평균: %.1f\n\n", stu[sel_stu].name, aver);
						break;
				}
				break;
			
			case 2:
				printf("\n어떤 성적 정보를 조회 하겠습니까?\n");
				printf("1. 전체 학생의 과목 별 평균 점수\n");
				printf("2. 특정 과목의 1등인 학생의 학번,이름 및 성적\n");
				scanf("%d", &sel_menu);
				
				switch (sel_menu)
				{
					case 1:
						for(i = 0; i < num; i++)
						{
							kor_aver += stu[i].subject[KOR];
							eng_aver += stu[i].subject[ENG];
							math_aver += stu[i].subject[MATH];
							sci_aver += stu[i].subject[SCI];
						}
						kor_aver /= num;
						eng_aver /= num;
						math_aver /= num;
						sci_aver /= num;
						
						printf("\n국어: %.1f, 영어: %.1f 수학: %.1f 과학: %.1f\n", kor_aver, eng_aver, math_aver, sci_aver);
						break;
						
					case 2:
						printf("어떤 과목의 1등을 조회할지 선택하세요.");
						printf("1. 국어, 2. 영어, 3. 수학, 4. 과학\n");
						scanf("%d", &sel_sub);
						sel_sub--; 
						
						switch (sel_sub)
						{
							case 0:
								bubble_sort(num, stu, KOR);
								printf("%s과목 1등 : %d %s %d점\n\n", "국어", stu[0].id, stu[0].name, stu[0].subject[KOR]);
								break;
							case 1:
								bubble_sort(num, stu, ENG);
								printf("%s과목 1등 : %d %s %d점\n\n", "영어", stu[0].id, stu[0].name, stu[0].subject[ENG]);
								break;
							case 2:
								bubble_sort(num, stu, MATH);
								printf("%s과목 1등 : %d %s %d점\n\n", "수학", stu[0].id, stu[0].name, stu[0].subject[MATH]);
								break;
							case 3:
								bubble_sort(num, stu, SCI);
								printf("%s과목 1등 : %d %s %d점\n\n", "과학", stu[0].id, stu[0].name, stu[0].subject[SCI]);
								break;
						}
						break;
				}
				break; 
			
			case 3:
				show_stu(num, stu);
				
				printf("\n어떤 학생의 정보를 관리하시겠습니까?");
				scanf("%d", &sel_stu);
				sel_stu--; 
				
				printf("\n어떤 과목을 수정하시겠습니까?\n");
				printf("1. 국어 2. 영어 3. 수학 4. 과학\n");
				scanf("%d", &sub);
				
				switch (sub)
				{
					case 1:
						printf("\n점수를 입력하세요: ");
						scanf("%d", &stu[sel_stu].subject[KOR]);
						printf("수정된 결과\n");
						printf("이름: %s, 학번: %d, 국어: %d, 영어: %d, 수학: %d, 과학: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 2:
						printf("\n점수를 입력하세요: ");
						scanf("%d", &stu[sel_stu].subject[ENG]);
						printf("수정된 결과\n");
						printf("이름: %s, 학번: %d, 국어: %d, 영어: %d, 수학: %d, 과학: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 3:
						printf("\n점수를 입력하세요: ");
						scanf("%d", &stu[sel_stu].subject[MATH]);
						printf("수정된 결과\n");
						printf("이름: %s, 학번: %d, 국어: %d, 영어: %d, 수학: %d, 과학: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 4:
						printf("\n점수를 입력하세요: ");
						scanf("%d", &stu[sel_stu].subject[SCI]);
						printf("수정된 결과\n");
						printf("이름: %s, 학번: %d, 국어: %d, 영어: %d, 수학: %d, 과학: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
				}
				break;
		}
	} 

	return 0;
}
