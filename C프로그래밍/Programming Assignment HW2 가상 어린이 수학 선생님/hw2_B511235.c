#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int temp;
	int a, b, x;
	int result_counter = 0; //0�̸� false, 1�̸� true
	char *result[4] = { NULL, NULL, NULL, NULL }; //result�� ���ڿ��� �迭�� ���ڿ��� ����.. 
												  //���� Ʋ�������� result_counter�� 1�� �����Ѵ�. result[]="����"�� ����Ѵ�.
	srand((unsigned int)time(NULL)); //random �Լ��� ������ srand�� �ѹ��ϰ� rand�� ��� �������� ������ �ȴ�.

	//******** ���� ********//
	a = rand() % 100 + 1;     //1���� 100���� �����Լ� 
	b = rand() % 100 + 1;
	if (a > b)
	{
		temp = a;     //b�� �׻� a���� Ŀ���ϹǷ� a�� b���� ũ�� a�� b�� �ٲ۴�.
		a = b;
		b = temp;
	}
	printf("%d���� �󸶸� ���ϸ� %d�� �ɱ��?", a, b);
	scanf("%d", &x);
	if ((b - a) != x)
	{
		result[result_counter] = "����";   // ���� Ʋ����� ����Ѵ�.
		result_counter++;
	}
	//********* ���� ********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	if (a < b)
	{
		temp = a;   //a�� �׻� b���� Ŀ���ϹǷ� a�� b���� ������ a�� b�� �ٲ۴�.
		a = b;
		b = temp;
	}
	printf("%d���� �󸶸� ���� %d�� �ɱ��?", a, b);
	scanf("%d", &x);
	if ((a - b) != x)
	{
		result[result_counter] = "����";
		result_counter++;
	}
	//********** ������**********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	while ((a%b) != 0)
	{
		//a�� b�� ����������� ������ ��������������� ��� ������Ų��.
		b = rand() % 100 + 1;
	}
	printf("%d���� �󸶸� ������ %d�� �ɱ��?", a, b);
	scanf("%d", &x);
	if ((a / b) != x)
	{
		result[result_counter] = "������";
		result_counter++;
	}
	//********* ����**********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	while ((b%a) != 0)
	{
		//b�� a�� ����������� ������ ��������������� ��� ������Ų��.
		a = rand() % 100 + 1;
	}
	printf("%d���� �󸶸� ���ϸ� %d�� �ɱ��?", a, b);
	scanf("%d", &x);
	if ((b / a) != x)
	{
		result[result_counter] = "����";
		result_counter++;
	}
	//���������� result_counter�� ����� ����.
	//��� ���
	if (result_counter == 0)
	{
		printf("������ �� �дϴ�.\n");
		printf("������ �� �дϴ�.\n");
		printf("�������� �� �дϴ�.\n");
		printf("������ �� �дϴ�.\n");
	}
	else
	{
		for (x = 0; x < result_counter - 1; x++)  // x�� ���� �ʿ䰡 �����Ƿ� for���� ī���ͷ� ����Ѵ�.
			                                      //'~��'�� �Ǹ������� ������ �ȵǹǷ� result_counter-1������ ���
	
		//result_counter-1������ �ݺ��ϹǷ� �� ������ �ϳ��� ���� ����Ѵ�.
		{
			printf("%s�Ƿ��� �÷��߰ڽ��ϴ�.\n", result[x]);
	}
			printf("%s �Ƿ��� �÷��߰ڽ��ϴ�.\n", result[x]);
		
		
	}
	return 0;  //main�� void main(void)�� �ƴ϶� main(void)�̹Ƿ� �Լ��� �������� ������ ��ȯ�ϴ� return 0;�� �־�� �Ѵ�.
}


