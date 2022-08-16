#include <stdio.h>
#include <ctype.h>
#define SUB_NUM 4  //���� ���� 

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
//  ���� ���� Ȯ�� 
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
	printf("���� ��ϵ� �л� ���\n");
				
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
	double aver, kor_aver=0, eng_aver=0, math_aver=0, sci_aver=0; // ��� 
	
	printf("������ �л��� �� ���ΰ���? ");
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		printf("%d�� �л��� �й��� �Է����ּ���: ", i+1);
		scanf("%d", &stu[i].id);
		printf("%d�� �л��� �̸��� �Է����ּ���: ", i+1);
		scanf("%s", stu[i].name);
		printf("%d�� �л��� ���� ������ �Է����ּ���: ", i+1);
		scanf("%d", &stu[i].subject[KOR]);
		printf("%d�� �л��� ���� ������ �Է����ּ���: ", i+1);
		scanf("%d", &stu[i].subject[ENG]);
		printf("%d�� �л��� ���� ������ �Է����ּ���: ", i+1);
		scanf("%d", &stu[i].subject[MATH]);
		printf("%d�� �л��� ���� ������ �Է����ּ���: ", i+1);
		scanf("%d", &stu[i].subject[SCI]);
	}	

while (1)
	{
		printf("================================================================\n");
		printf("�л� ���� �ý��� �Դϴ�.\n");
		printf("1. �л� ���� ��ȸ\n");
		printf("2. ���� ��ȸ\n"); 
		printf("3. ���� ����\n");
		printf("����� 0�� �Է��ϼ���.\n\n");
		printf("������ ���� �帱���? ");
		scanf("%d", &sel_menu);
		if (sel_menu == 0) 
		{
			printf("****����****\n");
			break;
		}
		
		switch (sel_menu)
		{
			case 1:
				show_stu(num, stu);
				printf("� �л��� ������ ��ȸ �ϰڽ��ϱ�? ");
				scanf("%d", &sel_stu);
				
				printf("\n1. ��ü ���� ��ȸ\n");
				printf("2. ��ü ���� ���\n\n");
				printf("������ ���� �帱���? ");
				scanf("%d", &sel_menu);
				sel_stu--;
				
				switch (sel_menu)
				{
					case 1:
						printf("\n�̸�: %s, �й�: %d, ����: %d, ����: %d, ����: %d, ����: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
						
					case 2:
						aver = (stu[sel_stu].subject[KOR] + stu[sel_stu].subject[ENG] + stu[sel_stu].subject[MATH] + stu[sel_stu].subject[SCI]) / SUB_NUM;
						printf("\n%s�� ��ü ���� ���: %.1f\n\n", stu[sel_stu].name, aver);
						break;
				}
				break;
			
			case 2:
				printf("\n� ���� ������ ��ȸ �ϰڽ��ϱ�?\n");
				printf("1. ��ü �л��� ���� �� ��� ����\n");
				printf("2. Ư�� ������ 1���� �л��� �й�,�̸� �� ����\n");
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
						
						printf("\n����: %.1f, ����: %.1f ����: %.1f ����: %.1f\n", kor_aver, eng_aver, math_aver, sci_aver);
						break;
						
					case 2:
						printf("� ������ 1���� ��ȸ���� �����ϼ���.");
						printf("1. ����, 2. ����, 3. ����, 4. ����\n");
						scanf("%d", &sel_sub);
						sel_sub--; 
						
						switch (sel_sub)
						{
							case 0:
								bubble_sort(num, stu, KOR);
								printf("%s���� 1�� : %d %s %d��\n\n", "����", stu[0].id, stu[0].name, stu[0].subject[KOR]);
								break;
							case 1:
								bubble_sort(num, stu, ENG);
								printf("%s���� 1�� : %d %s %d��\n\n", "����", stu[0].id, stu[0].name, stu[0].subject[ENG]);
								break;
							case 2:
								bubble_sort(num, stu, MATH);
								printf("%s���� 1�� : %d %s %d��\n\n", "����", stu[0].id, stu[0].name, stu[0].subject[MATH]);
								break;
							case 3:
								bubble_sort(num, stu, SCI);
								printf("%s���� 1�� : %d %s %d��\n\n", "����", stu[0].id, stu[0].name, stu[0].subject[SCI]);
								break;
						}
						break;
				}
				break; 
			
			case 3:
				show_stu(num, stu);
				
				printf("\n� �л��� ������ �����Ͻðڽ��ϱ�?");
				scanf("%d", &sel_stu);
				sel_stu--; 
				
				printf("\n� ������ �����Ͻðڽ��ϱ�?\n");
				printf("1. ���� 2. ���� 3. ���� 4. ����\n");
				scanf("%d", &sub);
				
				switch (sub)
				{
					case 1:
						printf("\n������ �Է��ϼ���: ");
						scanf("%d", &stu[sel_stu].subject[KOR]);
						printf("������ ���\n");
						printf("�̸�: %s, �й�: %d, ����: %d, ����: %d, ����: %d, ����: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 2:
						printf("\n������ �Է��ϼ���: ");
						scanf("%d", &stu[sel_stu].subject[ENG]);
						printf("������ ���\n");
						printf("�̸�: %s, �й�: %d, ����: %d, ����: %d, ����: %d, ����: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 3:
						printf("\n������ �Է��ϼ���: ");
						scanf("%d", &stu[sel_stu].subject[MATH]);
						printf("������ ���\n");
						printf("�̸�: %s, �й�: %d, ����: %d, ����: %d, ����: %d, ����: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
					case 4:
						printf("\n������ �Է��ϼ���: ");
						scanf("%d", &stu[sel_stu].subject[SCI]);
						printf("������ ���\n");
						printf("�̸�: %s, �й�: %d, ����: %d, ����: %d, ����: %d, ����: %d\n\n", stu[sel_stu].name, stu[sel_stu].id, stu[sel_stu].subject[KOR], stu[sel_stu].subject[ENG], stu[sel_stu].subject[MATH], stu[sel_stu].subject[SCI]);
						break;
				}
				break;
		}
	} 

	return 0;
}
