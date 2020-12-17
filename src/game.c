#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
//初始化id，house=null
vip *createVip(){};
//通过id返回会员结构体地址
vip *searchVip(int id){};
//通过id删除会员
void deleteVip(int id){};
//初始化house的信息
house *createHouse(){};
//通过房屋id返回房屋地址
house *searchHouse(int id){};
//通过入住人id返回房屋地址
house *searchhouse(int id){};
//更改房屋数据为入住状态
void 入住(){};
//更改房屋数据为出租状态
void 出租(){};
//更改房屋数据为空置状态
void 空置(){};
//初始化facil的信息
facil *createFacil(){};
//初始化worker的信息
worker *createWorker(){};
//通过id返回服务人员结构体地址
worker *searchWorker(int id){};
//通过id删除服务人员
void deletework(int id){};
//通过服务人员id返回入住人地址
user *searchworker(int id){};
//通过入住人id返回入住人地址
user *searchuser(int id){};
//通过场馆id返回：1成功 0等待
int queue(int id);
void 购买房屋(){
    printf("请输入购买房子的id\n");
    int id;
    scanf("%d",&id);
    house *new = searchhouse(id);
    vip_* house = new;
    printf("修改完成\n");
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
    printf("删除成功\n");
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

void 新建娱乐设施()
{
    facil *createFacil();
};

void 申请娱乐设施()
{
    printf("请输入场馆id\n");
    int id;
    scanf("%d",&id);
    int queue(id);
    if (queue == 1)
    printf("申请成功\n");
    if (queue == 0)
    printf("等待中\n");
};
void 新增服务人员()
{
    worker *createWorker();
};

void 修改服务人员()
{
    printf("请输入您的id\n");
    int id;
    scanf("%d", &id);
    worker *curr = searchWorker(id);
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
void 删除服务人员()
{
    printf("请输入您的id\n");
    int id;
    scanf("%d", &id);
    deleteVip(id);
    printf("删除成功\n");
};
void 查看服务对象()
{
    printf("请输入您的id\n");
    int id;
    scanf("%d", &id);
    user *searchworker(id);
    printf("查看成功\n");
};
void 设置服务对象()
{
    printf("请输入服务人员的id\n");
    int id;
    scanf("%d", &id);
    user *pre = searchworker(id);
    printf("请输入服务对象的id\n");
    int id2;
    scanf("%d", &id2);
    user *curr = searchuser(id);
    pre = curr;
    printf("设置成功\n");
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
    int id;
    scanf("%d", &id);
    house *searchhouse(id);
    printf("1.处理房屋\n");
    printf("2.申请娱乐设施\n");
    printf("3.返回\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
    {
        printf("1.入住\n");
        printf("2.出租\n");
        printf("3.空置\n");
        printf("4.返回\n");
        int choose2;
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
            入住();
        case 2:
            出租();
        case 3:
            空置();
        case 4:
            return;
        default:
            printf("无效字符\n");
        }
    }
    case 2:
    申请娱乐设施();
    case 3:
        return;
    default:
        printf("无效字符\n");
    }
}
void manage_facilities()
{
    printf("1.新建娱乐设施\n");
    printf("2.返回\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        新建娱乐设施();
    case 2:
        return;
    default:
        printf("无效字符\n");
    }
}
void manage_accounts()
{
    printf("1.新增服务人员\n");
    printf("2.已有人员\n");
    printf("3.返回\n");
    int choose1;
    scanf("%d", &choose1);
    switch (choose1)
    {
    case 1:
        新增服务人员();
    case 2:
        printf("1.修改服务人员\n");
        printf("2.删除服务人员\n");
        printf("3.查看服务对象\n");
        printf("4.设置服务对象\n");
        printf("5.返回\n");
        int choose2;
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
            修改服务人员();
        case 2:
            删除服务人员();
        case 3:
            查看服务对象();
        case 4:
            设置服务对象();
        case 5:
            return;
        default:
            printf("无效字符\n");
        }
    case 3:
        return;
    default:
        printf("无效字符\n");
    }
}