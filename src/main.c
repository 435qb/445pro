#include <stdio.h>
//#include "list.h"
#include "game.h"

int main()
{
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
            while(getchar() != '\n') continue;
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