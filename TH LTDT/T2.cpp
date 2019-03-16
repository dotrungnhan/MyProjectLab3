#include<conio.h>
#include<stdio.h>

#define MAX 100


typedef struct GRAPH
{	int n;
	int a[MAX][MAX];
}DOTHI;

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
int CheckDoThi(DOTHI g)
	{
		int i;
		for(i=0;i<g.n;i++)
		{
			if(g.a[i][i]!=0)
				return 0;
		}
		return 1;
	}
int CheckDoThiVoHuong(DOTHI g)
{
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			if(g.a[i][j]!=g.a[j][i] )
				return 0;
		}
	}
	return 1;
}
int DoThiCoTrongSo(DOTHI g)
{
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			if(g.a[i][j]>1 || g.a[i][j]<0 )
				return 1;
		}
	}
	return 0;
}
//==============================================================
//di tim cac dinh lien thong
void DiTimCacDinhLienThong(DOTHI g, int Nhan[MAX],int i)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0 && Nhan[j]!=Nhan[i])
		{
			Nhan[j]=Nhan[i];
			DiTimCacDinhLienThong(g,Nhan,j);
		}
	}
}
//==============================================================
struct STACK {
	int size;
	int b[MAX];
};
//==============================================================
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
//==============================================================
int CheckEuler(int dxp,DOTHI g)
{
	DOTHI temp = g;
	STACK s;
	KhoiTaoStack(s);
	TimDuongDi(dxp,temp,s);
	for(int i = 0 ; i < temp.n ; i++) {
		for(int j = 0 ; j < temp.n ; j++) {
			if(temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] != s.b[s.size-1]) {
		return 0;
	}
	
	printf("\n Chu Trinh Euler: \n");
	for(int i=s.size-1;i>0;i--)
		printf("%d -> ",s.b[i]);
	printf("%d ",s.b[0]);
	

	
}
//==============================================================
int CheckDuongDi(int dxp,DOTHI g)
{
	DOTHI temp = g;
	STACK s;
	KhoiTaoStack(s);
	TimDuongDi(dxp,temp,s);
	for(int i = 0 ; i < temp.n ; i++) {
		for(int j = 0 ; j < temp.n ; j++) {
			if(temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] == s.b[s.size-1]) {
		return 0;
	}
	
	printf("\n Chu Trinh Euler: \n");
	for(int i=s.size-1;i>0;i--)
		printf("%d -> ",s.b[i]);
	printf("%d ",s.b[0]);
	

	
}
//==============================================================

int main()
{
	int dxp;
	DOTHI g;
	char inputfile[100]= "D:/Euler3.txt";
	char ch;
	do{
	//	printf("\n\nNhap ten file do thi: ");
	//	gets(inputfile);

		if(DocMaTranKe(inputfile, g)==1) //doc file duoc
		{
			printf("Da lay thong tin do thi tu file thanh cong.\n\n");
			XuatMaTranKe(g);
			printf("Nhap phim bat ki de hien Euler:");
			getch();
			printf("\nNhap diem xuat phat: ");
			scanf("%d",&dxp);
			if( ! CheckEuler(dxp,g))
			{
				printf("Khong co line go Euler");
				getch();
				if(CheckDuongDi(g)!=1) {
					printf("Khong Co Duong Di");
				}
			}
	}
	
		printf("\n\n--------------------------------------\n");
		printf("Ban co muon tiep tuc khong[Y/N]: ");
		ch=getche();
	}while(ch=='Y'||ch=='y');
	getch();
	
	
	return 0;
}


























