#include <stdio.h>

int main(void){

	char number[10];
	char major;
	int gender, age;



	printf("�й��� �Է��Ͻÿ� : ");
	scanf("%s", &number);

	printf("������ ��ǻ�Ͱ��а��Դϱ�? ������ o, Ʋ���� x �Է��Ͻÿ� : ");
	scanf(" %c", &major);

	printf("������ �Է��Ͻÿ� (���� ��� 1, ���� ��� 2): ");
	scanf("%d", &gender);

	printf("���̸� �Է��Ͻÿ� : ");
	scanf("%d", &age);

	printf("����� �й��� %s, ", number);

	switch (major){

	case 'o':

		printf("������ ��ǻ�Ͱ��а��̸�, ");

		break;

	case 'x':

		printf("������ ��ǻ�Ͱ��а��� �ƴϸ�, ");

		break;

	default:

		printf("error");

		break;

	}

	int mok = age / 10;

	switch (mok){

	case 0:
		printf("�Ƶ� �̻��� ");
		break;

	case 1:
		printf("10�� �̻��� ");
		break;

	case 2:
		printf("20�� �̻��� ");
		break;

	case 3:
		printf("30�� �̻��� ");
		break;

	case 4:
		printf("40�� �̻��� ");
		break;

	case 5:
		printf("50�� �̻��� ");
		break;

	default:
		printf("����� �̻��� ");
		break;

	}

	switch (gender){

	case 1:
		printf("���л��Դϴ�.");
		break;

	case 2:
		printf("���л��Դϴ�.");
		break;

	default:
		printf("error");
		break;

	}

}
