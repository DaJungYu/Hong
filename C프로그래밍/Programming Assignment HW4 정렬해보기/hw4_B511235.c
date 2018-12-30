#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define STUDENT 40
typedef struct
{
 int num; //학번넣기 
 int mid; //중간성적넣기 
 int fin; //기말성적넣기 
 int total;  //총점
}student;

void sort_mid(student arr[]);
void sort_fin(student arr[]);
void sort_total(student arr[]);

int main()
{
	student s[40];
 	int i, x, y;
 	FILE *fp = NULL;
 	 FILE *fp1 = NULL;
 
 srand((unsigned)time(NULL));
 if ((fp = fopen("grades.txt", "w")) == NULL)
 {
  fprintf(stderr, "파일을 열 수 없습니다.");
  return 0;
 }
fprintf(fp, "==========================\n");
fprintf(fp, "NUM    MID    FIN   TOTAL\n");

 for (i = 0; i < STUDENT; i++)
 {
 	/////////////40명 성적 난수로 입력 받기 ///////////////
  s[i].num = rand() % 80 + 11; 
  s[i].mid = rand() % 101;
  s[i].fin = rand() % 101;
  s[i].total = s[i].mid + s[i].fin;
  fprintf(fp, "----------------------------------------\n");
  fprintf(fp, "B15%d, %5d, %5d, %5d\n", s[i].num, s[i].mid, s[i].fin, s[i].total);
 }
 fclose(fp);

 if ((fp = fopen("grades.txt", "r")) == NULL)
 {
  fprintf(stderr, "파일을 열 수 없습니다.");
  return 0;
 }
 for (i = 0; i < STUDENT; i++)
 {
  fscanf(fp, "%d, %d ,%d, %d\n", s[i].num, s[i].mid, s[i].fin, s[i].total);
 }
 fclose(fp);

 printf("어떤 성적을 기준으로 정렬할까요? (1) 중간고사 (2) 기말고사 (3) 총점 \n");
 scanf("%d", &x);
 switch (x)
 {
 		case 1:
  		sort_mid(s);
  		break;
  		case 2:
  		sort_fin(s);
  		break;
  		case 3:
  		sort_total(s);
  		break;
		default: 
 		break;
	}
	if ((fp1 = fopen("stats.txt", "w")) == NULL)
  {
   fprintf(stderr, "파일을 열 수 없습니다.");
   return 0;
  }
  fprintf(fp, "==========================\n");
  fprintf(fp, "NUM    MID    FIN   TOTAL\n");
  for (i = 0; i < STUDENT; i++)
  {
   fprintf(fp1, "-----------------------------------------\n");
   fprintf(fp1, "B15%d, %5d, %5d, %5d\n", s[i].num, s[i].mid, s[i].fin, s[i].total);
  }
  fclose(fp1);
   }
  

void sort_mid(student arr[]){ ///////////중간고사 정렬///////////// 
 int y;
 printf("차순을 선택하세요 : (1) 오름 (2) 내림 \n");
 scanf("%d", &y); 
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("중간고사 오름차순 정렬");
  for (i = 0; i <STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
  
    if (arr[j].mid < arr[up].mid) // 오름차순
    up=j;

     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
   
    printf("중간고사 내림차순 정렬");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid > arr[down].mid) // 내림차순
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
    	}
	}
 
}

void sort_fin(student arr[]){ /////////////////기말고사 정렬//////////// 
 int y;
 printf("차순을 선택하세요 : (1) 오름 (2) 내림 \n");
 scanf("%d", &y);
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("기말고사 오름차순 정렬");
  for (i = 0; i < STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].fin < arr[up].fin) // 오름차순
    up=j;
	}
    
     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
    printf("기말고사 내림차순 정렬");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].fin > arr[down].fin) // 내림차순
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
    	}
	}
}
void sort_total(student arr[]){ //////////////총점정렬////////////// 
 int y;
 printf("차순을 선택하세요 : (1) 오름 (2) 내림 \n");
 scanf("%d", &y);
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("총점 오름차순 정렬");
  for (i = 0; i < STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid+arr[j].fin < arr[up].mid+arr[up].fin) // 오름차순
    up=j;
	}
    
     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
   
    printf("총점 내림차순 정렬");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid+arr[j].fin > arr[up].mid+arr[up].fin) // 내림차순
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
		 }
    }
}

   
  
   

