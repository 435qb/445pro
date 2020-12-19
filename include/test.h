#ifndef _TEST_H
#define _TEST_H
#include "game.h"
void init();
//��ʼ��id��house=null
vip *createVip();

//ͨ��id���ػ�Ա�ṹ���ַ
vip *searchVip(int id);

//ͨ��idɾ����Ա
void deleteVip(int id);

//��ʼ��house����Ϣ
house* createHouse();

//ͨ������id���ط��ݵ�ַ �Ҳ�������NULL
house *searchHouse(int id);

//ͨ����ס��id������ס�˵�ַ �Ҳ�������NULL
user* searchUser(int id);

//ͨ��userid���ط��ݵ�ַ �Ҳ�������NULL
inline house* searchHouseofUser(int id)
{
	return searchUser(id)->_house;
}

//��ʼ��facil����Ϣ
facil* createFacil();


//��ʼ��worker����Ϣ
worker* createWorker();

//ͨ��id���ط�����Ա�ṹ���ַ �Ҳ�������NULL
worker *searchWorker(int id);///
//
//ͨ��idɾ��������Ա

void deleteWorker(int id);

//ͨ��������Աid������ס�˵�ַ �Ҳ�������NULL
user *searchUserofWorker(int id);


//ͨ������id���أ�1�ɹ� 0�ȴ�
int is_queue_full(int id);
user* createUser();

#endif