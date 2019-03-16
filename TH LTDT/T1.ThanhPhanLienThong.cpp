#include<conio.h>
#include<stdio.h>

#define MAX 10


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
void XetTinhLienThong(DOTHI g) {
	int Nhan[MAX];
	int SoThanhPhanLT = 0;
	for(int i = 0; i < g.n ; i++) {
		Nhan[i] = 0;
	}
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(Nhan[i] == 0) {
				SoThanhPhanLT++;
				Nhan[i] = SoThanhPhanLT;
				DiTimCacDinhLienThong(g,Nhan,i);
			}
		}
	}
	printf("So Thanh Phan Lien Thong La: %d", SoThanhPhanLT);
	for(int i = 1 ; i <= SoThanhPhanLT ; i++) {
		printf("\nThanh Phan Lien Thong %d Gom Cac Dinh:",i);
		for(int j = 0 ; j < g.n ; j++) {
			if(Nhan[j] == i)
				printf("%3c", j + 'A');
		}
	}
}
//==============================================================
//==============================================================
int main()
{
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
		if(CheckDoThi(g)==1)
		{
			if(CheckDoThiVoHuong(g)==1)
			{
				if(DoThiCoTrongSo(g)==1)
				{
					printf("Do thi hop le.\n");
					printf("Do Thi Vo Huong Co Trong So\n");
				
				}else
				{
					printf("Do thi hop le.\n");
					printf("Do Thi Vo Huong Khong Trong So\n");
				}
				
			}else
			{
				if(DoThiCoTrongSo(g)==1)
				{
					printf("Do thi hop le.\n");
					printf("Do thi Co huong Co Trong So.\n");
				}else
				{
					printf("Do thi hop le.\n");
					printf("Do thi Co huong Khong Trong So.\n");
				}
			}
			
		}else
		{
			printf("Do thi khong hop le.\n");
		}
		XetTinhLienThong(g);
		printf("\n\n--------------------------------------\n");
		printf("Ban co muon tiep tuc khong[Y/N]: ");
		ch=getche();
	}while(ch=='Y'||ch=='y');
	getch();
	
	
	return 0;
}


























