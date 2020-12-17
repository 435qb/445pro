#include <stdio.h>
#include <string.h>
#include "game.h"
//初始化id，house=null
vip *createVip();
//通过id返回会员结构体地址
vip *searchVip(int);
//通过id删除会员
void deleteVip(int);
//初始化house的信息
house *createHouse();
//通过房屋id返回房屋地址
house *searchHouse(int);

void 购买房屋(){

};

void 新建会员()
{
    printf("输入您的姓名:\n");
    vip *curr = createVip();

    //输错了怎么办
    scanf("%s", curr->_name);

    printf("创建成功\n");
    购买房屋();
};
void 查询会员()
{
    printf("请输入你的id\n");
    int id;
    scanf("%d", &id);
    vip *pre = searchVip(id);
};

void 修改会员()
{
    printf("请输入您的id\n");
    int id;
    scanf("%d", &id);

    vip *curr = searchVip(id);
    char name[NAME_MAX + 1], a[NAME_MAX + 1];
    printf("请输入现姓名:\n");
    scanf("%s", name);
    printf("请再次输入:\n");
    scanf("%s", a);
    if (strcmp(name, a) == 0)
        strcpy(curr->_name, name);
    else
        printf("输入错误，请重试\n");
};

void 删除会员()
{
    printf("请输入您的id\n");
    int id;
    scanf("%d", &id);
    deleteVip(id);
    printf("删除成功");
};

void 新建房屋()
{
    house *createHouse();
};

void 查看房屋()
{
    printf("请输入房屋id\n");
    int id;
    scanf("%d", &id);
    house *searchHouse(id);
};

void manage_vips()
{
    while (1)
    {
        printf("1.新建会员\n");
        printf("2.查询会员\n");
        printf("3.修改会员\n");
        printf("4.删除会员\n");
        printf("5.返回\n");
        int choose;
        if (scanf("%d", &choose) == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("无效字符\n");
            continue;
        }

        switch (choose)
        {
        case 1:
            新建会员();
            break;
        case 2:
            查询会员();
            break;
        case 3:
            修改会员();
            break;
        case 4:
            删除会员();
            break;
        case 5:
            return;
        default:
            printf("无效字符\n");
        }
    }
}
void manage_houses()
{
    printf("1.新建房屋\n");
    printf("2.查看房屋\n");
    printf("3.返回\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        新建房屋();
    case 2:
        查看房屋();
    case 3:
        return;
    default:
        printf("无效字符\n");
    }
}
void manage_lives()
{
    printf("选择入住人\n");
    scanf("")
    
}
void manage_facilities()
{
}
void manage_accounts()
{
}