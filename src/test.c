#include "test.h"
static vipList* vipHead;
static houseList* houseHead;
static facilList* facilHead;
static workerList* workerHead;


//初始化id，house=null
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
//通过id返回会员结构体地址
vip *searchVip(int id){
    return vipSearch(&vipHead,id);
}
//通过id删除会员
void deleteVip(int id){
    vipDelete(&vipHead,id); 
}

void createHouse(){
    static int houseId = 1;
    house x = {houseId, 0, 0, 0, NULL};
    houseId++;
    return  housePush(&houseHead,&x);
}
//通过房屋id返回房屋地址 找不到返回NULL
house *searchHouse(int id){
    return houseSearch(&houseHead,id);
}
//更改房屋数据为入住状态

//更改房屋数据为出租状态

//更改房屋数据为空置状态

//初始化facil的信息

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
//通过id返回服务人员结构体地址 找不到返回NULL
worker *searchWorker(int id){
        
}
//通过id删除服务人员
void deletework(int id){

}
//通过服务人员id返回入住人地址 找不到返回NULL
user *searchworker(int id){

}
//通过入住人id返回入住人地址 找不到返回NULL
user *searchuser(int id){

}
//通过场馆id返回：1成功 0等待
int is_queue_full(int id){

}
