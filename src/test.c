#include "test.h"
static vipList* vipHead;
static houseList* houseHead;
static facilList* facilHead;
static workerList* workerHead;
static userList* userHead;


//��ʼ��id��house=null
void init()
{
    vip v;
    house h;
    worker w;
    facil f;
    user u;
    vipCreate(&vipHead, &v);
    houseCreate(&houseHead, &h);
    workerCreate(&workerHead, &w);
    facilCreate(&facilHead, &f);
    userCreate(&userHead,&u);
}

vip *createVip(){
    static int vipId = 1;
    vip v;
    v._id = vipId;
    ++vipId;
    return vipPush(&vipHead, &v);
}
//ͨ��id���ػ�Ա�ṹ���ַ
vip *searchVip(int id){
    return vipSearch(&vipHead,id);
}
//ͨ��idɾ����Ա
void deleteVip(int id){
    vipDelete(&vipHead,id); 
}

void createHouse(){
    static int houseId = 1;
    house x = {houseId, 0, 0, 0, NULL};
    houseId++;
    return  housePush(&houseHead,&x);
}
//ͨ������id���ط��ݵ�ַ �Ҳ�������NULL
house *searchHouse(int id){
    return houseSearch(&houseHead,id);
}
//���ķ�������Ϊ��ס״̬

//���ķ�������Ϊ����״̬

//���ķ�������Ϊ����״̬

//��ʼ��facil����Ϣ

void createFacil(){
     static int facilId = 1;
    facil f;
    f._id = facilId;
    ++facilId;
    return vipPush(&facilHead, &f);
}

void createWorker(){
    static int workerId = 1;
    worker w;
    ++workerId;
    return  workerPush(&workerHead, &w);
}
//ͨ��id���ط�����Ա�ṹ���ַ �Ҳ�������NULL
worker *searchWorker(int id){
        return houseSearch(&houseHead,id);
}
//ͨ��idɾ��������Ա
void deleteWork(int id){
    workerDelete(&workerHead,id);
}
//ͨ��������Աid������ס�˵�ַ �Ҳ�������NULL
user *searchWorker(int id){
    worker *wk;
    wk=workerSearch(&workerHead,id);
    return wk->_user;
}
//ͨ����ס��id������ס�˵�ַ �Ҳ�������NULL
user *searchUser(int id){
     userSearch(&userHead,id);
}
void createUser(){
    static int userId = 1;
    user *u ;
    u->_id=userId;
    ++userId;
    return  userPush(&userHead, &u);
}
void deleteUser(int id){
    userDelete(&userHead,id); 
}

//ͨ������id���أ�1�ɹ� 0�ȴ�
int is_queue_full(int id){

}
