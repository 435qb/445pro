#include <stdio.h>
//#include "list.h"
#include "game.h"

int main(){
    while(1){
        int choose;
        printf("1.会员管理\n");
        printf("2.房屋管理\n");
        printf("3.入住管理\n");
        printf("4.设施管理\n");
        printf("5.用户管理\n");
        scanf("%d",&choose);
        
        switch(choose){
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
        default:
            break;
        }
    }   

    return 0;
}