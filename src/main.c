#include <stdio.h>
//#include "list.h"
#include "game.h"
#include "test.h"

void init_house()
{
	FILE* fp = fopen("houses.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("houses.txt", "w");
		fprintf(fp, "5.0 6.0");
		fclose(fp);
		fp = fopen("houses.txt", "r");
	}
	int num = 0;
	while (fscanf(fp, "%*lf") != EOF) { ++num; }
	fseek(fp, 0, SEEK_SET);
	double temp;
	while (fscanf(fp, "%lf", &temp) != EOF)
	{
		house* curr = createHouse();
		curr->_area = temp;
	}
}
void init_facil()
{
	FILE* fp = fopen("facils.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("facils.txt", "w");
		fprintf(fp, "5 6");
		fclose(fp);
		fp = fopen("facils.txt", "r");
	}
	int num = 0;
	while (fscanf(fp, "%*d") != EOF) { ++num; }
	fseek(fp, 0, SEEK_SET);
	int temp;
	while (fscanf(fp, "%d", &temp) != EOF)
	{
		facil* curr = createFacil();
		curr->_queue->_MAX = temp;
	}
}
int main()
{
	init();
	init_house();
	init_facil();
	while (1)
	{
		int choose;
		printf("1.会员管理\n");
		printf("2.房屋管理\n");
		printf("3.入住管理\n");
		printf("4.设施管理\n");
		printf("5.用户管理\n");
		printf("6.退出\n");
		if (scanf("%d", &choose) == 0)
		{
			while (getchar() != '\n') continue;
			printf("无效字符\n");
			continue;
		}
		switch (choose)
		{
		case 1:
			manage_vips();
			break;
		case 2:
			manage_houses();
			break;
		case 3:
			manage_lives();
			break;
		case 4:
			manage_facilities();
			break;
		case 5:
			manage_accounts();
			break;
		case 6:
			return 0;
		default:
			printf("无效字符\n");
			break;
		}
	}
}

//管理员登陆 账号密码
//预约
//时间 学号 姓名 地点 原因 解决状态
//2020
//预约查询
//
