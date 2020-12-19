#include "test.h"
static vipList* vipHead;
static houseList* houseHead;
static facilList* facilHead;
static workerList* workerHead;
static userList* userHead;


//初始化id，house=null
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
//通过id返回会员结构体地址
vip *searchVip(int id){
    return vipSearch(&vipHead,id);
}
//通过id删除会员
void deleteVip(int id){
    vipDelete(&vipHead,id); 
}

house* createHouse(){
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

facil* createFacil(){
    static int facilId = 1;
    facil f;
    f._id = facilId;
    ++facilId;
    return vipPush(&facilHead, &f);
}

worker* createWorker(){
    static int workerId = 1;
    worker w;
    ++workerId;
    return  workerPush(&workerHead, &w);
}
//通过id返回服务人员结构体地址 找不到返回NULL
worker *searchWorker(int id){
        return houseSearch(&houseHead,id);
}
//通过id删除服务人员
void deleteWork(int id){
    workerDelete(&workerHead,id);
}
//通过服务人员id返回入住人地址 找不到返回NULL
user *searchUserofWorker(int id){
    worker *wk;
    wk=workerSearch(&workerHead,id);
    return wk->_user;
}
//通过入住人id返回入住人地址 找不到返回NULL
user *searchUser(int id){
     userSearch(&userHead,id);
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

//通过场馆id返回：1成功 0等待
int is_queue_full(int id){

}
