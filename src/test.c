#include "test.h"
static vipList* vipHead;
static houseList* houseHead;
static facilList* facilHead;
static workerList* workerHead;


//��ʼ��id��house=null
void init()
{
    vip v;
    house h;
    worker w;
    facil f;
    vipCreate(&vipHead, &v);
    houseCreate(&houseHead, &h);
    workerCreate(&workerHead, &w);
    facilCreate(&facilHead, &f);
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
        
}
//ͨ��idɾ��������Ա
void deletework(int id){

}
//ͨ��������Աid������ס�˵�ַ �Ҳ�������NULL
user *searchworker(int id){

}
//ͨ����ס��id������ס�˵�ַ �Ҳ�������NULL
user *searchuser(int id){

}
//ͨ������id���أ�1�ɹ� 0�ȴ�
int is_queue_full(int id){

}
