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
        printf("��Ч�ַ�\n");     \
        continue;                 \
    }

void new_vip()
{
    printf("������������:\n");
    vip *curr = createVip();

    //�������ô��
    scanf("%s", curr->_name);

    printf("�����ɹ�\n����id��%d\n", curr->_id);
    while (1)
    {
        printf("������Ҫ����ķ��ӵ�id\n");
        int id;
        ID_GET(id);
        house* new = searchHouse(id);
        if (new == NULL)
        {
            printf("û�������ķ���\n");
            continue;
        }
        else if (new->_is_bought) {
            printf("�����ѱ�ռ��\n");
            continue;
        }
        printf("��Ҫ����%.2lf�ķ�����?[Y/n]\n", new->_area);
        while (getchar() != '\n')
            continue;

        char ch;
        if ((ch = getchar()) != 'n' || ch != 'N')
        {
        	if(ch != '\n')
				while (getchar() != '\n')
					continue;
            printf("��������ס�˵�����\n");
        	
            char name[NAME_MAX + 1];
            scanf("%s", name);
        	
            user* curr1 = createUser();
            strcpy(curr1->_name, name);
            curr1->_house = new;
            new->_user = curr1;
            new->_vip = curr;
        	
            printf("�޸����\n��ס�˵�id��%d\n", curr1->_id);
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
            printf("δ����\n");
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
        printf("���������id\n");
        int id;
        ID_GET(id);
        vip *pre = searchVip(id);
        if (pre == NULL)
        {   
            printf("���޴���\n");
        }else{
            printf("���������%s\n", pre->_name);
        }
        break;
    }
}

void modify_vip()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        scanf("%d", &id);

        vip *curr = searchVip(id);
    	if(curr == NULL)
    	{
            printf("���޴���\n");
    		continue;
    	}
    	
        char name[NAME_MAX + 1], a[NAME_MAX + 1];
        printf("������������:\n");
        scanf("%s", name);
        printf("���ٴ�����:\n");
        scanf("%s", a);
        if (strcmp(name, a) == 0) {
            strcpy(curr->_name, name);
            printf("�޸ĳɹ�\n");
        }
        else
            printf("�������������\n");
        break;
    }
}

void delete_vip()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        printf("�����Ҫɾ����?[y/N]\n");
        char ch;
        while (getchar() != '\n')
            continue;
        if ((ch = getchar()) == 'y' || ch == 'Y')
        {
            deleteVip(id);
            printf("ɾ���ɹ�\n");
        }
        else
            printf("δɾ��\n");
        break;
    }
}

void manage_vips()
{
    while (1)
    {
        printf("1.�½���Ա\n");
        printf("2.��ѯ��Ա\n");
        printf("3.�޸Ļ�Ա\n");
        printf("4.ɾ����Ա\n");
        printf("5.����\n");
        int choose;
        if (scanf("%d", &choose) == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("��Ч�ַ�\n");
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
            printf("��Ч�ַ�\n");
        }
    }
}

void new_house()
{
    while (1) {
        printf("�����뷿�ݴ�С\n");
        double area;
        if (scanf("%lf", &area) == 0)
        {
            while (getchar() != '\n')
                continue;
            printf("��Ч�ַ�\n");
            continue;
        }

        house* curr = createHouse();
        printf("���ݵ�id��%d\n", curr->_id);
        curr->_area = area;
        break;
    }
}

void watch_house()
{
    while (1)
    {
        printf("�����뷿��id\n");
        int id;
        ID_GET(id)
        house* curr = searchHouse(id);
    	if(curr == NULL)
    	{
            printf("�޴˷���\n");
    		continue;
    	}
        printf("���ӵĴ�СΪ%.2lf\n", curr->_area);
        break;
    }
}

void manage_houses()
{
    while (1)
    {
        printf("1.�½�����\n");
        printf("2.�鿴����\n");
        printf("3.����\n");
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
            printf("��Ч�ַ�\n");
        }
    }
}
/// <summary>
/// 
/// </summary>
void handle_house(user* curr)
{
    while (1) {
        printf("1.��ס\n");
        printf("2.����\n");
        printf("3.����\n");
        printf("4.����\n");
        int choose;
        ID_GET(choose)
        house* h = curr->_house;
        switch (choose)
        {
        case 1:
            while (1) {
                printf("��ѡ����Ҫס�ķ���id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
            	if(now == NULL)
            	{
                    printf("û�и÷���\n");
            	} else if(now->_is_bought == 0)
            	{
                    printf("��û�й���÷���\n");
            	} else if(now->_is_rent)
            	{
                    printf("�Ѿ����ȥ��\n");
            	} else if(strcmp(now->_vip->_name, curr->_name) != 0)
            	{
                    printf("�˷��ѱ����˹���\n");
            	} else if(now->_user != NULL)
            	{
                    printf("��ס�ľ���������ӣ������ٴ���ס\n");
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
                    printf("��ס�ɹ�\n");
            	}
            	break;
            }
            break;
        case 2:
	        while (1)
	        {
                printf("��ѡ����Ҫ��ķ���id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
                if (now == NULL)
                {
                    printf("û�и÷���\n");
                }
                else if (now->_is_bought == 0)
                {
                    printf("��û���˹���÷���\n");
                }
                else if (now->_is_rent)
                {
                    printf("�Ѿ����ȥ��\n");
                }
                else if (strcmp(now->_vip->_name, curr->_name) == 0)
                {
                    printf("�˷��������ķ��䲻��Ҫ��\n");
                }
                else if(now->_user != NULL)
                {
                    printf("���仹����ס\n");
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
                    printf("�ⷿ�ɹ�\n");
                }
                break;
	        }
            break;
        case 3:
            while (1)
            {
                printf("��ѡ����Ҫ���õķ���id\n");
                int id;
                ID_GET(id)
                house* now = searchHouse(id);
                if (now == NULL)
                {
                    printf("û�и÷���\n");
                }
                else if (now->_is_bought == 0)
                {
                    printf("��û���˹���÷���\n");
                }
                else if (now->_is_rent)
                {
                    printf("�Ѿ����ȥ��\n");
                }
                else if (strcmp(now->_vip->_name, curr->_name) != 0)
                {
                    printf("�˷��������ķ��䲻�ܿ���\n");
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
                    printf("�ⷿ�ɹ�\n");
                }
                break;

            }
            break;
        case 4:
            return;
        default:
            printf("��Ч�ַ�\n");
        }
    }
}

void apply_facility(user* curr)
{
    while (1)
    {
        printf("�����볡��id\n");
        int id;
        ID_GET(id);
        int queue = id;///
        if (queue == 1)
            printf("����ɹ�\n");
        if (queue == 0)
            printf("�ȴ���\n");
        break;
    }
};
void manage_lives()
{
    while (1)
    {
        printf("��������ס�˵�id\n");
        int id;
        ID_GET(id)
        user * curr = searchUser(id);
    	if(curr == NULL)
    	{
            printf("û�ҵ�����ס��\n");
    		continue;
    	}
    	
        printf("1.������\n");
        printf("2.����������ʩ\n");
        printf("3.����\n");
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
            printf("��Ч�ַ�\n");
        }
    }
}

void new_facility()
{
    createFacil();
};

void manage_facilities()
{
    while (1)
    {
        printf("1.�½�������ʩ\n");
        printf("2.����\n");
        int choose;
        ID_GET(choose)
        switch (choose)
        {
        case 1:
            new_facility();
        case 2:
            return;
        default:
            printf("��Ч�ַ�\n");
        }
    }
}

void add_worker()
{
    createWorker();
}

void modify_worker()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        worker* curr = searchWorker(id);
    	if(curr == NULL)
    	{
            printf("���޴���\n");
    		continue;
    	}
        char name[NAME_MAX + 1], a[NAME_MAX + 1];
        printf("������������:\n");
        scanf("%s", name);
        printf("���ٴ�����:\n");
        scanf("%s", a);
        if (strcmp(name, a) == 0)
            strcpy(curr->_name, name);
        else
            printf("�������������\n");
        break;
    }
}
void delete_worker()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        deleteVip(id);
        printf("ɾ���ɹ�\n");
        break;
    }
}

void watch_user()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        //user *searchworker(id);
        printf("�鿴�ɹ�\n");
        break;
    }
}
void set_user()
{
    while (1)
    {
        printf("�����������Ա��id\n");
        int id;
        ID_GET(id);
        user* pre = searchWorker(id);//currΪnull
        printf("�������������id\n");
        int id2;
        ID_GET(id2);
        user* curr = searchUser(id);//currΪnull
        pre = curr;
        printf("���óɹ�\n");
        break;
    }
}
void manage_accounts()
{
    while (1)
    {
        printf("1.����������Ա\n");
        printf("2.�޸ķ�����Ա\n");
        printf("3.ɾ��������Ա\n");
        printf("4.�鿴�������\n");
        printf("5.���÷������\n");
        printf("6.����\n");
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
            printf("��Ч�ַ�\n");
        }
    }
}