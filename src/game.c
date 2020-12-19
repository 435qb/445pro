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

void buy_house()
{
    while (1)
    {
        printf("������Ҫ����ķ��ӵ�id\n");
        int id;
        ID_GET(id);
        house *new = searchHouse(id);
        if (new == NULL)
        {
            printf("û�������ķ���\n");
            continue;
        }else if (new->_is_bought){
            printf("�����ѱ�ռ��\n");
            continue;
        }
        printf("�޸����\n");
        break;
    }
};

void new_vip()
{
    printf("������������:\n");
    vip *curr = createVip();

    //�������ô��
    scanf("%s", curr->_name);

    printf("�����ɹ�\n");
    buy_house();
};
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
};

void modify_vip()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        scanf("%d", &id);

        vip *curr = searchVip(id);
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
};

void delete_vip()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        printf("�����Ҫɾ����?[Y/n]\n");
        char ch;
        if ((ch = getchar()) == 'y' || ch == 'Y')
        {
            deleteVip(id);
            printf("ɾ���ɹ�\n");
        }
        else
            printf("δɾ��\n");
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
        printf("�����뷿��id\n");
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
void add_worker()
{
    createWorker();
};

void modify_worker()
{
    while (1)
    {
        printf("����������id\n");
        int id;
        ID_GET(id);
        worker *curr = searchWorker(id);
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
};
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
};
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
};
void set_user()
{
    while (1)
    {
        printf("�����������Ա��id\n");
        int id;
        ID_GET(id);
        user *pre = searchworker(id);
        printf("�������������id\n");
        int id2;
        ID_GET(id2);
        user *curr = searchuser(id);
        pre = curr;
        printf("���óɹ�\n");
        break;
    }
};
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
void manage_houses()
{
    while (1)
    {
        printf("1.�½�����\n");
        printf("2.�鿴����\n");
        printf("3.����\n");
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
            printf("��Ч�ַ�\n");
        }
    }
}
void manage_lives()
{
    while (1)
    {
        printf("ѡ����ס��\n");
        int id;
        scanf("%d", &id);
        //house *searchhouse(id);
        printf("1.������\n");
        printf("2.����������ʩ\n");
        printf("3.����\n");
        int choose;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            printf("1.��ס\n");
            printf("2.����\n");
            printf("3.����\n");
            printf("4.����\n");
            int choose2;
            scanf("%d", &choose2);
            switch (choose2)
            {
            case 1:
                //��ס();
            case 2:
                //����();
            case 3:
                //����();
            case 4:
                return;
            default:
                printf("��Ч�ַ�\n");
            }
        }
        case 2:
            apply_facility();
        case 3:
            return;
        default:
            printf("��Ч�ַ�\n");
        }
    }
}
void manage_facilities()
{
    while (1)
    {
        printf("1.�½�������ʩ\n");
        printf("2.����\n");
        int choose;
        ID_GET(choose);
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