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

house* createHouse(){
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

facil* createFacil(){
    static int facilId = 1;
    facil f;
    f._id = facilId;
    ++facilId;
    return facilPush(&facilHead, &f);
}

worker* createWorker(){
    static int workerId = 1;
    worker w;
    w._id = workerId;
    ++workerId;
    return  workerPush(&workerHead, &w);
}
//ͨ��id���ط�����Ա�ṹ���ַ �Ҳ�������NULL
worker *searchWorker(int id){
    return workerSearch(&workerHead,id);
}
//ͨ��idɾ��������Ա
void deleteWorker(int id){
    workerDelete(&workerHead,id);
}
//ͨ��������Աid������ס�˵�ַ �Ҳ�������NULL
user *searchUserofWorker(int id){
    worker *wk;
    wk = workerSearch(&workerHead,id);
    return wk->_user;
}
//ͨ����ס��id������ס�˵�ַ �Ҳ�������NULL
user *searchUser(int id){
     return userSearch(&userHead,id);
}
user* createUser(){
    static int userId = 1;
    user u ;
    u._id = userId;
    ++userId;
    return userPush(&userHead, &u);
}
void deleteUser(int id){
    userDelete(&userHead,id); 
}

facil* searchFacil(int id)
{
    return facilSearch(&facilHead, id);
}