#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct product{
	char code[10];
	char name[30];
	int quantity;
	int quantitySell;
	int price;
	int priceSell;
}product[100];
int numOfpro=0;

void nhaphanghoa();
void edithanghoa();
void viewhanghoa();
int menu_quanlymathang();

void banhanghoa();
void viewketqua();
int menu_quanlybanhang();

void menu_baocao();
int menu_main();

void viewhanghoa(){
	printf("================Danh muc hang hoa hien co================\n");
	printf("=========================================================\n");
	printf("|STT|Ma hang     |Ten hang    |So luong ban|Gia ban(VND)|\n");
	for(int j=0;j<=numOfpro;j++){
		printf("|%-3d|%-12s|%-12s|%-12d|%-12d|\n",j+1, product[j].code, product[j].name, product[j].quantity-product[j].quantitySell, product[j].price);
	}
	printf("=========================================================\n");
}

void nhaphanghoa()
{
	char next;
	do
	{
		system("cls");
		printf("=======1.1 Nhap hang hoa=======\n");
		printf("- Cho biet ma hang: ");
		fflush(stdin);
		gets(product[numOfpro].code);
		printf("- Cho biet ten hang: ");
		fflush(stdin);
		gets(product[numOfpro].name);
		printf("- Cho biet so luong: ");
		scanf("%d",&product[numOfpro].quantity);
		printf("- Cho biet don gia: ");
		scanf("%d",&product[numOfpro].price);
		product[numOfpro].quantitySell=0;
		printf("- Ban co muon tiep tuc 1.1 khong? (Y/N)"); fflush(stdin);scanf("%c",&next);
		if (next=='y')
		{
			numOfpro++;
		}
		else break;
	}while(1);
}

void edithanghoa()
{
	char codeedit[10];char next;
	do
	{
		system("cls");
		printf("=======1.2 Sua hang hoa=======\n");
		printf("- Cho biet ma hang: ");fflush(stdin); gets(codeedit);
		int i;
		for (i=0;i<=numOfpro;i++)
		{
			if (strcmp(codeedit,product[i].code)==0) break;
		}
		
		char choose;
		printf("- Sua ten: ten cu: %s (co sua khong? (y/n)):",product[i].name); scanf("%s",&choose);
		if (choose=='y')
		{
			printf("- Ten moi: ");fflush(stdin); gets(product[i].name);
		}
		
		printf("- Sua so luong: %d (co sua khong? (y/n)):",product[i].quantity); scanf("%s",&choose);
		if (choose=='y')
		{
			printf("- So luong moi: ");scanf("%d",&product[i].quantity);
		}
		
		printf("- Sua don gia: %d (co sua khong? (y/n)):",product[i].price); scanf("%s",&choose);
		if (choose=='y')
		{
			printf("- Gia moi: ");scanf("%d",&product[i].price);
		}
		
		printf("- Ban co muon tiep tuc 1.2 khong? (y/n)"); fflush(stdin);scanf("%c",&next);
	}while(next=='y');
}

int menu_quanlymathang()
{
	int choose; char next;
	do
	{
		system("cls");
		printf("==========1. Quan ly mat hang==========\n");
		printf("=======================================\n");
		printf("- 1.1 Nhap hang hoa.\n");
		printf("- 1.2 Chinh sua danh muc hang hoa.\n");
		printf("- 1.3 Xem danh muc hang hoa.\n");
		printf("- 1.0 Ve menu chinh.\n");
		do
		{
			printf("#Chon: ");scanf("%d",&choose);
			(choose<0||choose>3)? printf("Nhap sai, vui long nhap lai: (0-3).\n"):0;
		} while(choose<0||choose>3);
		
		switch(choose)
		{
			case 0: return 0; break;
			case 1: nhaphanghoa();break;
			case 2: edithanghoa();break;
			case 3: viewhanghoa();break;
		}
		
		printf("Tiep tuc? (y/n) ");
		fflush(stdin);
		scanf("%c",&next);
	}while(next=='y');
}

void banhanghoa()
{
	char codeedit[10];char next; int numOfbuy;
	do
	{
		system("cls");
		printf("==========2.1 Ban hang==========\n");
		printf("- Cho biet mat hang can ban: ");fflush(stdin); gets(codeedit);
		int i;
		for (i=0;i<=numOfpro;i++)
		{
			if (strcmp(codeedit,product[i].code)==0) break;
		}
		
		printf("Cho biet gia ban: (khong nho hon %d VND).\n",product[i].price);
		scanf("%d",&product[i].priceSell);
		printf("Cho biet so luong ban: "); scanf("%d",&numOfbuy);
		product[i].quantitySell+=numOfbuy;
		printf("OK, da xac nhan va cap nhat thong tin!\n");
		
		printf("- Ban co muon tiep tuc 2.1 khong? (Y/N)"); fflush(stdin);scanf("%c",&next);
	}while (next=='y');
}

void viewketqua()
{
	char next;
	int count=1;
	do
	{
		printf("==========2.2 Ket qua==========\n");
		printf("===================Cac mat hang da ban===================\n");
		printf("=========================================================\n");
			printf("|STT|Ma hang     |Ten hang    |So luong ban|Gia ban(VND)|Con |\n");
		for(int j=0;j<=numOfpro;j++)
		{
			if (product[j].quantitySell!=0)
			{
				printf("|%-3d|%-12s|%-12s|%-12d|%-12d|%-12d\n", count, product[j].code, product[j].name, product[j].quantitySell,product[j].priceSell, product[j].quantity-product[j].quantitySell);	
				count++;
			}
		}
		printf("=========================================================\n");
		
		printf("- Ban co muon tiep tuc 2.2 khong? (Y/N)"); fflush(stdin);scanf("%c",&next);
	}while (next=='y');
}


int menu_quanlybanhang()
{
	int choose; char next;
	do
	{
		system("cls");
		printf("==========2. Quan ly ban hang==========\n");
		printf("=======================================\n");
		printf("- 2.1 Ban hang.\n");
		printf("- 2.2 Xem ket qua.\n");
		printf("- 2.0. Ve menu chinh.\n");
		do
		{
			printf("#Chon: ");scanf("%d",&choose);
			(choose<0||choose>2)? printf("Nhap sai, vui long nhap lai: (0-3).\n"):0;
		} while(choose<0||choose>2);
		
		switch(choose)
		{
			case 0: return 0; break;
			case 1: banhanghoa(); break;
			case 2: viewketqua(); break;
		}
		
		printf("Tiep tuc? (y/n) ");
		fflush(stdin);
		scanf("%c",&next);
	}while(next=='y');
	
}

void menu_baocao()
{
		viewhanghoa();
		printf("Ban phim bat ky de tiep tuc...\n");
		getch();
		int count=1;
		printf("===================Cac mat hang da ban===================\n");
		printf("=========================================================\n");
		printf("|STT|Ma hang     |Ten hang    |So luong ban|Gia ban(VND)|Con |\n");
		double s=0;
		for(int j=0;j<=numOfpro;j++)
		{
			if (product[j].quantitySell!=0)
			{
				printf("|%-3d|%-12s|%-12s|%-12d|%-12d|%-12d\n", count, product[j].code, product[j].name, product[j].quantitySell,product[j].priceSell, product[j].quantity-product[j].quantitySell);
				s+=product[j].quantitySell*(product[j].priceSell-product[j].price);
				count++;
			}
		}
		printf("=========================================================\n");
		printf("Loi nhuan thu duoc: %lf\n",s);
}

int menu_main()
{
	int choose; char next;
	do
	{
		system("cls");
		printf("====Chuong trinh quan ly kinh doanh====\n");
		printf("=======================================\n");
		printf("- 1. Quan ly mat hang.\n");
		printf("- 2. Quan ly ban hang.\n");
		printf("- 3. Bao cao.\n");
		printf("- 0. Thoat.\n");
		do
		{
			printf("#Chon: ");scanf("%d",&choose);
			(choose<0||choose>3)? printf("Nhap sai, vui long nhap lai: (0-3).\n"):0;
		} while(choose<0||choose>3);
		
		switch(choose)
		{
			case 0: exit(1); break;
			case 1: menu_quanlymathang(); break;
			case 2: menu_quanlybanhang(); break;
			case 3: menu_baocao();break;
		}
		printf("Tiep tuc? (y/n) ");
		fflush(stdin);
		scanf("%c",&next);
	}while(next=='y');
}

int main()
{
	menu_main();
	system("pause");
	return 0;
}