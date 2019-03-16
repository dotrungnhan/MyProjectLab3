#include<conio.h>
#include<stdio.h>
#define MAX 100
#define LinkFile "D:/File Test/Test_2A.txt"
#define LinkFile2 "C:/File Test/Test_2B.txt"

struct DOTHI {
	int n;
	int a[MAX][MAX];
};

struct STACK {
	int size;
	int b[MAX];
};

//==============================================================
int DocMaTranKe(const char* TenFile,DOTHI &g)
{	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
//==============================================================

void XuatMaTranKe(DOTHI g)
{	printf("So dinh cua do thi = %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for(int i=0;i<g.n;i++)
	{	for(int j=0;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//=======================================================
void KhoiTaoStack(STACK &s) {
	s.size = 0;
}
//=======================================================
void DayGiaTriVaoStack(STACK &s, int Value) {
	if(s.size + 1 >= MAX) {
		return;
	}	
	s.b[s.size] = Value;
	s.size++;
}
//=======================================================
void TimDuongDi(int i, DOTHI &g, STACK &s) {
	for(int j = 0 ; j < g.n ; j ++) {
		if(g.a[i][j] != 0) {
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j,g,s);
		}
	}
	DayGiaTriVaoStack(s,i);
}
//=======================================================
int CheckEuler(DOTHI g) {
	DOTHI Temp = g;
	STACK s;
	KhoiTaoStack(s);
	int x = Start_Point(Temp);
	if(x == -1)
		return 0;
	TimDuongDi(0, Temp, s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] != s.b[s.size-1]) {
		return 0;
	}
	
	printf("Euler is:\n");
	printf(" %2c ",s.b[s.size - 1] + 'A');	
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf("->%2c ",s.b[i] + 'A');
	}
return 1;
}
//=======================================================
int Start_Point(DOTHI g) {
	int Rank;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}
		}
		if(Rank%2 != 0) {
			return -1;
		}
	}
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				return i;
			}
		}
	}
return -1;	
}

int Start_EvenPoint(DOTHI g) {
	int Rank, Count = 0;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ;j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}	
		}
		if(Rank%2 != 0) {
			Count++;
		}
		if(Count == 2) {
			return i; 
		} 
	}
return -1;
}

//Kiem tra duong di EUler

int CheckEulerWay(DOTHI g) {
	DOTHI Temp = g;
	STACK s;
	KhoiTaoStack(s);
	int x = Start_EvenPoint(Temp);
	if(x == -1) 
		return 0;
	FindWay(0,Temp,s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] == s.b[s.size-1]) {
		return 0;
	}
	printf("Euler Way is:\n");
	printf("%3c ",s.b[s.size - 1]+'A');
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf(" ->%3c",s.b[i]+'A');
	}
return 1;
}

int main() {
	DOTHI g;
	char inputfile[100];
	char ch;
	do{
		printf("\n\nNhap ten file do thi: ");
		gets(inputfile);

		if(DocMaTranKe(inputfile, g)==1) //doc file duoc
		{
			printf("Da lay thong tin do thi tu file thanh cong.\n\n");
			XuatMaTranKe(g);
		}
		if(CheckEuler(g) != 1) {
			printf("Not Euler!\n");
			if(CheckEulerWay(g)!=1) {
				printf("Not Euler Way");
			}
		}
		printf("\n\n--------------------------------------\n");
		printf("Ban co muon tiep tuc khong[Y/N]: ");
		ch=getche();
		}while(ch=='Y'||ch=='y');	
	return 0;
}

