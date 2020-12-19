#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "test.h"

#define ID_GET(id)                \
    if (scanf("%d", &id) == 0)    \
    {                             \
        while (getchar() != '\n') \
            continue;             \
        printf("无效字符\n");     \
        continue;                 \
    }

void buy_house()
{
    while (1)
    {
        printf("请输入要购买的房子的id\n");
        int id;
        ID_GET(id);
        house *new = searchHouse(id);
        if (new == NULL)
        {
            printf("没有那样的房屋\n");
            continue;
        }else if (new->_is_bought){
            printf("房屋已被占用\n");
            continue;
        }
        printf("修改完成\n");
        break;
    }
};

void new_vip()
{
    printf("输入您的姓名:\n");
    vip *curr = createVip();

    //输错了怎么办
    scanf("%s", curr->_name);

    printf("创建成功\n");
    buy_house();
};
void search_vip()
{
    while (1)
    {
        printf("请输入你的id\n");
        int id;
        ID_GET(id);
        vip *pre = searchVip(id);
        if (pre == NULL)
        {   
            printf("查无此人\n");
        }else{
            printf("你的名字是%s\n", pre->_name);
        }
        break;
    }
};

void modify_vip()
{
    while (1)
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
        break;
    }
};

void delete_vip()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        printf("您真的要删除吗?[Y/n]\n");
        char ch;
        if ((ch = getchar()) == 'y' || ch == 'Y')
        {
            deleteVip(id);
            printf("删除成功\n");
        }
        else
            printf("未删除\n");
        while (getchar() != '\n')
            continue;
        break;
    }
};

void new_house()
{
    createHouse();
};

void watch_house()
{
    while (1)
    {
        printf("请输入房屋id\n");
        int id;
        ID_GET(id);
        //house *searchHouse(id);
        break;
    }
};

void new_facility()
{
    createFacil();
};

void apply_facility()
{
    while (1)
    {
        printf("请输入场馆id\n");
        int id;
        ID_GET(id);
        int queue = id;///
        if (queue == 1)
            printf("申请成功\n");
        if (queue == 0)
            printf("等待中\n");
        break;
    }
};
void add_worker()
{
    createWorker();
};

void modify_worker()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
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
        break;
    }
};
void delete_worker()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        deleteVip(id);
        printf("删除成功\n");
        break;
    }
};
void watch_user()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
    //user *searchworker(id);
        printf("查看成功\n");
        break;
    }
};
void set_user()
{
    while (1)
    {
        printf("请输入服务人员的id\n");
        int id;
        ID_GET(id);
        user *pre = searchworker(id);
        printf("请输入服务对象的id\n");
        int id2;
        ID_GET(id2);
        user *curr = searchuser(id);
        pre = curr;
        printf("设置成功\n");
        break;
    }
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
            new_vip();
            break;
        case 2:
            search_vip();
            break;
        case 3:
            modify_vip();
            break;
        case 4:
            delete_vip();
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
    while (1)
    {
        printf("1.新建房屋\n");
        printf("2.查看房屋\n");
        printf("3.返回\n");
        int choose;
        ID_GET(choose);
        switch (choose)
        {
        case 1:
            new_house();
        case 2:
            watch_house();
        case 3:
            return;
        default:
            printf("无效字符\n");
        }
    }
}
void manage_lives()
{
    while (1)
    {
        printf("选择入住人\n");
        int id;
        scanf("%d", &id);
        //house *searchhouse(id);
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
                //入住();
            case 2:
                //出租();
            case 3:
                //空置();
            case 4:
                return;
            default:
                printf("无效字符\n");
            }
        }
        case 2:
            apply_facility();
        case 3:
            return;
        default:
            printf("无效字符\n");
        }
    }
}
void manage_facilities()
{
    while (1)
    {
        printf("1.新建娱乐设施\n");
        printf("2.返回\n");
        int choose;
        ID_GET(choose);
        switch (choose)
        {
        case 1:
            new_facility();
        case 2:
            return;
        default:
            printf("无效字符\n");
        }
    }
}

void manage_accounts()
{
    while (1)
    {
        printf("1.新增服务人员\n");
        printf("2.修改服务人员\n");
        printf("3.删除服务人员\n");
        printf("4.查看服务对象\n");
        printf("5.设置服务对象\n");
        printf("6.返回\n");
        int choose;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            add_worker();
        case 2:
            modify_worker();
        case 3:
            delete_worker();
        case 4:
            watch_user();
        case 5:
            set_user();
        case 6:
            return;
        default:
            printf("无效字符\n");
        }
    }
}