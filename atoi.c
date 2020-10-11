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

//문자열을 정수로 변환한다. 
int change(char *str)
{
	int i, j, strnum, num = 0, num_10 = 1;
	//문자열로 받은 정수 길이 
	int size = strlen(str);
	for (i = 0; i < size; i++)
	{
		//'0'의 아스키코드표 숫자값은 48. '1'은 29. 문자열로 저장된 수는 아스키코드표의 숫자값으로 저장됨.
		//str[i]에 48을 빼면 해당 자리수의 정수가 나옴. 
		strnum = str[i] - '0';
		//자릿수. 십의 자리수는 *10
		for (j = size - 1 - i; j > 0; j--)
		{
			num_10 *= 10;
		}
		num = num + (strnum * num_10);
		num_10 = 1;
	}
	return num;
}