#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pc = NULL;
	int i = 0;
	pc = (char *)malloc(100 * sizeof(char));
	if(pc == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	 } 
	 
	 /* pc�� ����Ű�� �����͸� 1�� ������Ű�鼭 */
	for (i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
	
	 /* �ƽ�Ű �ڵ忡�� 0�� NULL�� �ǹ��Ѵ�. */
	*(pc + i) = 0;
	
	printf("���ĺ� : %s\n", pc);
	
	free(pc); 
	return 0;
}
