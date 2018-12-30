#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define STUDENT 40
typedef struct
{
 int num; //�й��ֱ� 
 int mid; //�߰������ֱ� 
 int fin; //�⸻�����ֱ� 
 int total;  //����
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
  fprintf(stderr, "������ �� �� �����ϴ�.");
  return 0;
 }
fprintf(fp, "==========================\n");
fprintf(fp, "NUM    MID    FIN   TOTAL\n");

 for (i = 0; i < STUDENT; i++)
 {
 	/////////////40�� ���� ������ �Է� �ޱ� ///////////////
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
  fprintf(stderr, "������ �� �� �����ϴ�.");
  return 0;
 }
 for (i = 0; i < STUDENT; i++)
 {
  fscanf(fp, "%d, %d ,%d, %d\n", s[i].num, s[i].mid, s[i].fin, s[i].total);
 }
 fclose(fp);

 printf("� ������ �������� �����ұ��? (1) �߰���� (2) �⸻��� (3) ���� \n");
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
   fprintf(stderr, "������ �� �� �����ϴ�.");
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
  

void sort_mid(student arr[]){ ///////////�߰���� ����///////////// 
 int y;
 printf("������ �����ϼ��� : (1) ���� (2) ���� \n");
 scanf("%d", &y); 
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("�߰���� �������� ����");
  for (i = 0; i <STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
  
    if (arr[j].mid < arr[up].mid) // ��������
    up=j;

     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
   
    printf("�߰���� �������� ����");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid > arr[down].mid) // ��������
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
    	}
	}
 
}

void sort_fin(student arr[]){ /////////////////�⸻��� ����//////////// 
 int y;
 printf("������ �����ϼ��� : (1) ���� (2) ���� \n");
 scanf("%d", &y);
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("�⸻��� �������� ����");
  for (i = 0; i < STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].fin < arr[up].fin) // ��������
    up=j;
	}
    
     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
    printf("�⸻��� �������� ����");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].fin > arr[down].fin) // ��������
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
    	}
	}
}
void sort_total(student arr[]){ //////////////��������////////////// 
 int y;
 printf("������ �����ϼ��� : (1) ���� (2) ���� \n");
 scanf("%d", &y);
 student temp;
 int i, j,up,down;
 if (y == 1)
 {
  printf("���� �������� ����");
  for (i = 0; i < STUDENT-1; i++)
  {
  	up=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid+arr[j].fin < arr[up].mid+arr[up].fin) // ��������
    up=j;
	}
    
     temp = arr[i];
     arr[i] = arr[up];
     arr[up] = temp;
    }
   }
   else if(y==2)
   {
   
    printf("���� �������� ����");
   for (i = 0; i < STUDENT-1; i++)
  {
  	down=i;
   for (j = i+1; j < STUDENT; j++)
   {
    if (arr[j].mid+arr[j].fin > arr[up].mid+arr[up].fin) // ��������
    down=j;
	}
    
     temp = arr[i];
     arr[i] = arr[down];
     arr[down] = temp;
		 }
    }
}

   
  
   

