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
		printf("\n\n--------------------------------------\n");
		printf("Ban co muon tiep tuc khong[Y/N]: ");
		ch=getche();
		}while(ch=='Y'||ch=='y');
	return 0;
}
