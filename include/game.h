#ifndef _game_h
#define _game_h

#define NAME_MAX 100
#include <stdlib.h>
struct HOUSE;
typedef struct USER
{
    struct HOUSE* _house;
    int _id;
    char _name[NAME_MAX + 1];
} user;
struct VIP;
typedef struct HOUSE
{
    int _id;
    double _area;
    int _is_bought;
    int _is_rent;
    user *_user; //��ס��
    struct VIP* _vip;
} house;

typedef struct VIP
{
    int _id;
    char _name[NAME_MAX + 1];
    house *_house;
} vip;



// _is_bought 1 _is_rent 0 _human 0 ����
// _is_bought 0 δ����
// _is_bought 1 _is_rent 1 ���
// _is_bought 1 _is_rent 0 _human !0 ��ס
typedef struct QUEUE
{
    int _MAX;
    user *_data;
} queue;

typedef struct Facilities
{
    int _id;
    queue *_queue;
} facil;

typedef struct WORKER
{
    int _id;
    char _name[NAME_MAX + 1];
    user *_user;
} worker;
#include "list.h"
INIT(vip);
INIT(user);
INIT(house);
INIT(facil);
INIT(worker);
//�������Ĳ�һ��
INIT(queue);
queue queuePop(queueList **wl);
#undef INIT

void manage_vips();
void manage_houses();
void manage_lives();
void manage_facilities();
void manage_accounts();

#endif
