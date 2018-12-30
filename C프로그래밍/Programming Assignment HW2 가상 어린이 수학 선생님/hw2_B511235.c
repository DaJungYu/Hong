#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int temp;
	int a, b, x;
	int result_counter = 0; //0이면 false, 1이면 true
	char *result[4] = { NULL, NULL, NULL, NULL }; //result는 문자열의 배열로 문자열이 담긴다.. 
												  //답이 틀릴때마다 result_counter가 1씩 증가한다. result[]="문자"를 출력한다.
	srand((unsigned int)time(NULL)); //random 함수를 쓸때는 srand를 한번하고 rand를 써야 실직적인 랜덤이 된다.

	//******** 덧셈 ********//
	a = rand() % 100 + 1;     //1부터 100까지 랜덤함수 
	b = rand() % 100 + 1;
	if (a > b)
	{
		temp = a;     //b는 항상 a보다 커야하므로 a가 b보다 크면 a와 b를 바꾼다.
		a = b;
		b = temp;
	}
	printf("%d에서 얼마를 더하면 %d이 될까요?", a, b);
	scanf("%d", &x);
	if ((b - a) != x)
	{
		result[result_counter] = "덧셈";   // 답이 틀린경우 출력한다.
		result_counter++;
	}
	//********* 뺄셈 ********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	if (a < b)
	{
		temp = a;   //a는 항상 b보다 커야하므로 a가 b보다 작으면 a와 b를 바꾼다.
		a = b;
		b = temp;
	}
	printf("%d에서 얼마를 빼면 %d이 될까요?", a, b);
	scanf("%d", &x);
	if ((a - b) != x)
	{
		result[result_counter] = "뺄셈";
		result_counter++;
	}
	//********** 나눗셈**********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	while ((a%b) != 0)
	{
		//a가 b로 나누어떨어지지 않으면 나누어떨어질때까지 계속 랜덤시킨다.
		b = rand() % 100 + 1;
	}
	printf("%d에서 얼마를 나누면 %d이 될까요?", a, b);
	scanf("%d", &x);
	if ((a / b) != x)
	{
		result[result_counter] = "나눗셈";
		result_counter++;
	}
	//********* 곱셈**********//
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	while ((b%a) != 0)
	{
		//b가 a로 나누어떨어지지 않으면 나누어떨어질때까지 계속 랜덤시킨다.
		a = rand() % 100 + 1;
	}
	printf("%d에서 얼마를 곱하면 %d이 될까요?", a, b);
	scanf("%d", &x);
	if ((b / a) != x)
	{
		result[result_counter] = "곱셈";
		result_counter++;
	}
	//최종적으로 result_counter에 결과가 담긴다.
	//결과 출력
	if (result_counter == 0)
	{
		printf("덧셈을 잘 압니다.\n");
		printf("뺄셈을 잘 압니다.\n");
		printf("나눗셈을 잘 압니다.\n");
		printf("곱셈을 잘 압니다.\n");
	}
	else
	{
		for (x = 0; x < result_counter - 1; x++)  // x는 이제 필요가 없으므로 for문의 카운터로 사용한다.
			                                      //'~과'는 맨마지막에 붙으면 안되므로 result_counter-1까지만 출력
	
		//result_counter-1까지만 반복하므로 맨 마지막 하나를 따로 출력한다.
		{
			printf("%s실력을 늘려야겠습니다.\n", result[x]);
	}
			printf("%s 실력을 늘려야겠습니다.\n", result[x]);
		
		
	}
	return 0;  //main이 void main(void)가 아니라 main(void)이므로 함수가 끝났을때 정수를 반환하는 return 0;이 있어야 한다.
}


