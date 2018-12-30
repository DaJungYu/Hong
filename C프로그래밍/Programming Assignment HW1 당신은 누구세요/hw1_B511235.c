#include <stdio.h>

int main(void){

	char number[10];
	char major;
	int gender, age;



	printf("학번을 입력하시오 : ");
	scanf("%s", &number);

	printf("전공이 컴퓨터공학과입니까? 맞으면 o, 틀리면 x 입력하시오 : ");
	scanf(" %c", &major);

	printf("성별을 입력하시오 (남인 경우 1, 여인 경우 2): ");
	scanf("%d", &gender);

	printf("나이를 입력하시오 : ");
	scanf("%d", &age);

	printf("당신의 학번은 %s, ", number);

	switch (major){

	case 'o':

		printf("전공은 컴퓨터공학과이며, ");

		break;

	case 'x':

		printf("전공은 컴퓨터공학과가 아니며, ");

		break;

	default:

		printf("error");

		break;

	}

	int mok = age / 10;

	switch (mok){

	case 0:
		printf("아동 이상의 ");
		break;

	case 1:
		printf("10대 이상의 ");
		break;

	case 2:
		printf("20대 이상의 ");
		break;

	case 3:
		printf("30대 이상의 ");
		break;

	case 4:
		printf("40대 이상의 ");
		break;

	case 5:
		printf("50대 이상의 ");
		break;

	default:
		printf("장년층 이상의 ");
		break;

	}

	switch (gender){

	case 1:
		printf("남학생입니다.");
		break;

	case 2:
		printf("여학생입니다.");
		break;

	default:
		printf("error");
		break;

	}

}
