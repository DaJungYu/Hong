#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int a[5][5] = { 0 };
	int tanknum = 0;  
	int x, y;       //x는 가로 y는 세로 
	int hitnum_user = 0;
	int hitnum_com = 0;
	srand((unsigned int) time(NULL));

	////////////////////////////////////////////////
	// 사용자
	////////////////////////////////////////////////
	printf("탱크를 배치 하시오 :\n");
	while (1)
	{
		printf("탱크 %d 가로:", tanknum + 1);
		scanf("%d", &x);
		
		printf("탱크 %d 세로:", tanknum + 1);
		scanf("%d", &y);

		if (a[x][y] == 0)
		{
			a[x][y] = 1;
			tanknum += 1;
		}
		else
		{
			printf("탱크 2와 탱크1의 위치는 겹칠 수 없습니다. 다시 입력하시오.\n");		
		}

		if (tanknum == 2)
		{
			break;
		}
	}

	////////////////////////////////////////////////
	// 컴퓨터
	////////////////////////////////////////////////
	tanknum = 0;
	while (1)
	{
	
		x = rand() % 5;       //컴퓨터는 랜덤으로 배치 
		y = rand() % 5;
		if (a[x][y] == 0)
		{
			a[x][y] = 2;
			tanknum += 1;
		}

		if (tanknum == 2)
		{
			break;
		}
	}

	printf("\n");
	
	////////////////////////////////////////////////
	// 게임
	////////////////////////////////////////////////
	while (1)
	{
		////////////////////////////////////////////////
		// 사용자 차례
		////////////////////////////////////////////////
		printf("컴퓨터의 탱크가 어디에 있을까요?\n");
		printf("가로:");
		scanf("%d", &x);
		printf("세로:");
		scanf("%d", &y);
		if (a[x][y] == 2)
		{
			printf("사용자의 타격성공\n");
			hitnum_user++;
		}
		else
		{
			printf("사용자의 타격불발\n");
		}

		if (hitnum_user == 2)
		{
			printf("사용자의 승리\n");
			break;
		}

		////////////////////////////////////////////////
		// 컴퓨터 차례
		////////////////////////////////////////////////
		x = rand() % 5;
		y = rand() % 5;
		if (a[x][y] == 1)
		{
			printf("컴퓨터의 타격성공\n");
			hitnum_com++;
		}
		else
		{
			printf("컴퓨터의 타격불발\n");
		}

		if (hitnum_com == 2)
		{
			printf("컴퓨터의 승리\n");
			break;
		}
	}
	return 0;
}
