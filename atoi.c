#include <stdio.h>
#include <string.h>

int change(char *str);

void main() {
	int num;
	char buf[100];
	printf("Input number string : ");
	scanf_s("%s", buf, 100);
	num = change(buf);
	printf("Num is %d\n", num);
}

//���ڿ��� ������ ��ȯ�Ѵ�. 
int change(char *str)
{
	int i, j, strnum, num = 0, num_10 = 1;
	//���ڿ��� ���� ���� ���� 
	int size = strlen(str);
	for (i = 0; i < size; i++)
	{
		//'0'�� �ƽ�Ű�ڵ�ǥ ���ڰ��� 48. '1'�� 29. ���ڿ��� ����� ���� �ƽ�Ű�ڵ�ǥ�� ���ڰ����� �����.
		//str[i]�� 48�� ���� �ش� �ڸ����� ������ ����. 
		strnum = str[i] - '0';
		//�ڸ���. ���� �ڸ����� *10
		for (j = size - 1 - i; j > 0; j--)
		{
			num_10 *= 10;
		}
		num = num + (strnum * num_10);
		num_10 = 1;
	}
	return num;
}