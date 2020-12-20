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

void new_vip()
{
    printf("输入您的姓名:\n");
    vip *curr = createVip();

    //输错了怎么办
    scanf("%s", curr->_name);

    printf("创建成功\n您的id是%d\n", curr->_id);
    while (1)
    {
        printf("请输入要购买的房子的id\n");
        int id;
        ID_GET(id);
        house* new = searchHouse(id);
        if (new == NULL)
        {
            printf("没有那样的房屋\n");
            continue;
        }
        else if (new->_is_bought) {
            printf("房屋已被占用\n");
            continue;
        }
        printf("您要的是%.2lf的房子吗?[Y/n]\n", new->_area);
        while (getchar() != '\n')
            continue;

        char ch;
        if ((ch = getchar()) != 'n' || ch != 'N')
        {
        	if(ch != '\n')
				while (getchar() != '\n')
					continue;
            printf("请输入入住人的名字\n");
        	
            char name[NAME_MAX + 1];
            scanf("%s", name);
        	
            user* curr1 = createUser();
            strcpy(curr1->_name, name);
            curr1->_house = new;
            new->_user = curr1;
            new->_vip = curr;
        	
            printf("修改完成\n入住人的id是%d\n", curr1->_id);
            new->_is_bought = 1;
            if (strcmp(name, curr->_name) == 0)
            {
                new->_is_rent = 0;
            } else
        	{
                new->_is_rent = 1;
        	}
        }
        else {
            printf("未购买\n");
            continue;
        }
        while (getchar() != '\n')
            continue;

        break;
    }
}

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
}

void modify_vip()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        scanf("%d", &id);

        vip *curr = searchVip(id);
    	if(curr == NULL)
    	{
            printf("查无此人\n");
    		continue;
    	}
    	
        char name[NAME_MAX + 1], a[NAME_MAX + 1];
        printf("请输入现姓名:\n");
        scanf("%s", name);
        printf("请再次输入:\n");
        scanf("%s", a);
        if (strcmp(name, a) == 0) {
            strcpy(curr->_name, name);
            printf("修改成功\n");
        }
        else
            printf("输入错误，请重试\n");
        break;
    }
}

void delete_vip()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        printf("您真的要删除吗?[y/N]\n");
        char ch;
        while (getchar() != '\n')
            continue;
        if ((ch = getchar()) == 'y' || ch == 'Y')
        {
            deleteVip(id);
            printf("删除成功\n");
        }
        else
            printf("未删除\n");
        break;
    }
}

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

void new_house()
{
    while (1) {
        printf("请输入房屋大小\n");
        double area;
        if (scanf("%lf", &area) == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("无效字符\n");
            continue;
        }

        house* curr = createHouse();
        printf("房屋的id是%d\n", curr->_id);
        curr->_area = area;
        FILE* fp = fopen("houses.txt", "a");
        fprintf(fp, " %.2lf", area);
        fclose(fp);
        break;
    }
}

void watch_house()
{
    while (1)
    {
        printf("请输入房屋id\n");
        int id;
        ID_GET(id)
        house* curr = searchHouse(id);
    	if(curr == NULL)
    	{
            printf("无此房屋\n");
    		continue;
    	}
        printf("房子的大小为%.2lf\n", curr->_area);
        break;
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
        ID_GET(choose)
        switch (choose)
        {
        case 1:
            new_house();
        	break;
        case 2:
            watch_house();
        	break;
        case 3:
            return;
        default:
            printf("无效字符\n");
        }
    }
}

void handle_house(user* curr)
{
    while (1) {
        printf("1.入住\n");
        printf("2.出租\n");
        printf("3.空置\n");
        printf("4.返回\n");
        int choose;
        ID_GET(choose)
        house* h = curr->_house;
        switch (choose)
        {
        case 1:
            while (1) {
                printf("请选择您要住的房间id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
            	if(now == NULL)
            	{
                    printf("没有该房间\n");
            	} else if(now->_is_bought == 0)
            	{
                    printf("还没有购买该房间\n");
            	} else if(now->_is_rent)
            	{
                    printf("已经租出去了\n");
            	} else if(strcmp(now->_vip->_name, curr->_name) != 0)
            	{
                    printf("此房已被他人购买\n");
            	} else if(now->_user != NULL)
            	{
                    printf("您住的就是这个房子，无需再次入住\n");
            	} else
            	{
            		//now clear
                    now->_is_rent = 0;
                    now->_user = curr;
            		//h clear
                    h->_is_rent = 0;
                    h->_user = NULL;
            		//user clear
                    curr->_house = now;
                    printf("入住成功\n");
            	}
            	break;
            }
            break;
        case 2:
	        while (1)
	        {
                printf("请选择您要租的房间id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
                if (now == NULL)
                {
                    printf("没有该房间\n");
                }
                else if (now->_is_bought == 0)
                {
                    printf("还没有人购买该房间\n");
                }
                else if (now->_is_rent)
                {
                    printf("已经租出去了\n");
                }
                else if (strcmp(now->_vip->_name, curr->_name) == 0)
                {
                    printf("此房就是您的房间不需要租\n");
                }
                else if(now->_user != NULL)
                {
                    printf("房间还有人住\n");
                }else
                {
                    //now clear
                    now->_is_rent = 1;
                    now->_user = curr;
                    //h clear
                    h->_is_rent = 0;
                    h->_user = NULL;
                    //user clear
                    curr->_house = now;
                    printf("租房成功\n");
                }
                break;
	        }
            break;
        case 3:
            while (1)
            {
                printf("请选择您要空置的房间id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
                if (now == NULL)
                {
                    printf("没有该房间\n");
                }
                else if (now->_is_bought == 0)
                {
                    printf("还没有人购买该房间\n");
                }
                else if (now->_is_rent)
                {
                    printf("已经租出去了\n");
                }
                else if (strcmp(now->_vip->_name, curr->_name) != 0)
                {
                    printf("此房不是您的房间不能空置\n");
                } else
                {
                    //now clear
                    now->_is_rent = 1;
                    now->_user = curr;
                    //h clear
                    h->_is_rent = 0;
                    h->_user = NULL;
                    //user clear
                    curr->_house = now;
                    printf("租房成功\n");
                }
                break;

            }
            break;
        case 4:
            return;
        default:
            printf("无效字符\n");
        }
    }
}

void apply_facility(user* curr)
{
    while (1)
    {
        printf("请输入场馆id\n");
        int id;
        ID_GET(id)
        facil* curr = searchFacil(id);///
        if (curr == NULL)
        {
            printf("查无此设施\n");
        	continue;
        }
        if (curr->_queue->_now < curr->_queue->_MAX)
        {
            ++curr->_queue->_now;
            printf("申请成功\n");
        }else
            printf("人已满\n");
        break;
    }
}
void manage_lives()
{
    while (1)
    {
        printf("请输入入住人的id\n");
        int id;
        ID_GET(id)
        user * curr = searchUser(id);
    	if(curr == NULL)
    	{
            printf("没找到该入住人\n");
    		continue;
    	}
    	
        printf("1.处理房屋\n");
        printf("2.申请娱乐设施\n");
        printf("3.返回\n");
        int choose;
        ID_GET(choose)
        switch (choose)
        {
        case 1:
            handle_house(curr);
        	break;
        case 2:
            apply_facility(curr);
        	break;
        case 3:
            return;
        default:
            printf("无效字符\n");
        }
    }
}

void new_facility()
{
    while (1) {
        printf("请输入设施大小\n");
        int max;
        if (scanf("%d", &max) == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("无效字符\n");
            continue;
        }

        facil* curr = createFacil();
        printf("设施的id是%d\n", curr->_id);
        curr->_queue->_MAX = max;
        FILE* fp = fopen("facils.txt", "a");
        fprintf(fp, " %d", max);
        fclose(fp);
        break;
    }

};

void manage_facilities()
{
    while (1)
    {
        printf("1.新建娱乐设施\n");
        printf("2.返回\n");
        int choose;
        ID_GET(choose)
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

void add_worker()
{
    printf("输入您的姓名:\n");
    worker* curr = createWorker();

    //输错了怎么办
    scanf("%s", curr->_name);
    printf("创建成功\n您的id是%d\n", curr->_id);
	
}
void modify_user(worker* curr)
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        worker* curr = searchWorker(id);
        if (curr == NULL)
        {
            printf("查无此人\n");
            continue;
        }
        else if (curr->_user == NULL)
        {
            printf("您还没有指定服务对象\n");
            return;
        }
        curr->_user == NULL;
        printf("删除服务对象成功\n");
        break;
    }

}
void modify_name(worker* curr)
{
    char name[NAME_MAX + 1], a[NAME_MAX + 1];
    printf("请输入现姓名:\n");
    scanf("%s", name);
    printf("请再次输入:\n");
    scanf("%s", a);
    if (strcmp(name, a) == 0) {
        strcpy(curr->_name, name);
        printf("修改成功");
    }
    else
        printf("输入错误，请重试\n");
}
void modify_worker()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        worker* curr = searchWorker(id);
    	if(curr == NULL)
    	{
            printf("查无此人\n");
    		continue;
    	}
        printf("1.修改服务对象\n");
        printf("2.修改名字\n");
        printf("3.退出\n");
        int choose;
    	ID_GET(choose)
        switch (choose)
        {
        case 1:
            modify_user(curr);
        	break;
        case 2:
            modify_name(curr);
        	break;
        case 3:
            return;
		default:
            printf("无效字符\n");
        }
    }
}
void delete_worker()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        printf("您真的要删除吗?[y/N]\n");
        char ch;
        while (getchar() != '\n')
            continue;
        if ((ch = getchar()) == 'y' || ch == 'Y')
        {
            deleteWorker(id);
            printf("删除成功\n");
        }
        else
            printf("未删除\n");
        break;
    }
}

void watch_user()
{
    while (1)
    {
        printf("请输入您的id\n");
        int id;
        ID_GET(id);
        worker * curr = searchWorker(id);
    	if(curr == NULL)
    	{
            printf("查无此人\n");
    		continue;
    	}else if(curr->_user == NULL)
    	{
            printf("您还没有指定服务对象\n");
    		return;
    	}
        printf("您的服务对象是id为%d的%s\n", curr->_user->_id, curr->_user->_name);
        break;
    }
}
void set_user()
{
    while (1)
    {
        printf("请输入服务人员的id\n");
        int id;
        ID_GET(id);
        worker* pre = searchWorker(id);//curr为null
    	if(pre == NULL)
    	{
            printf("查无此服务人员\n");
            continue;
        }
        printf("请输入服务对象的id\n");
        int id2;
        ID_GET(id2);
        user* curr = searchUser(id);//curr为null
        if(curr == NULL)
        {
            printf("查无此入住人\n");
            continue;
        }
        if (pre->_user != NULL)
        {
            printf("您已有服务对象\n");
            return;
        }
        pre->_user = curr;
        printf("设置成功\n");
        break;
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
        	break;
        case 2:
            modify_worker();
        	break;
        case 3:
            delete_worker();
        	break;
        case 4:
            watch_user();
        	break;
        case 5:
            set_user();
        	break;
        case 6:
            return;
        default:
            printf("无效字符\n");
        }
    }
}