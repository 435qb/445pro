#include "test.h"
static vipList* viphead;
static houseList* houseHead;
static facilList* facilHead;
static workerList* workerHead;


//初始化id，house=null

 void Vipinit(){
     vip x;
     x._id = 0;
     vipCreate(&viphead, &x);
 }

vip *createVip(){
    static int vipId = 1;
    vip v;
    v._id = vipId;
    vipPush(&viphead, &v);
    ++vipId;
    return &v;
}
//通过id返回会员结构体地址
vip *searchVip(int id){
    return vipSearch(&viphead,id);
}
//通过id删除会员
void deleteVip(int id){
    vipDelete(&viphead,id); 
}
//初始化house的信息
void houseinit(){
    house t;
    t._id = 0;
    houseCreate(&houseHead, &t);
}

void createHouse(){
    static int houseId = 1;
    house x = {houseId, 0, 0, 0, NULL};
    housePush(&houseHead,&x);
    houseId++;
}
//通过房屋id返回房屋地址 找不到返回NULL
house *searchHouse(int id){
    return houseSearch(&houseHead,id);
}
//更改房屋数据为入住状态

//更改房屋数据为出租状态

//更改房屋数据为空置状态

//初始化facil的信息

 void facilinit(){
     facil x;
     x._id = 0;
     facilCreate(&facilHead, &x);
 }

void createFacil(){
     static int facilId = 1;
    facil f;
    f._id = facilId;
    vipPush(&facilHead, &f);
    ++facilId;
    return &f;
}
//初始化worker的信息
 void workerinit(){
     worker x;
     x._id = 0;
     workerCreate(&workerHead, &x);
 }

void createWorker(){
    static int workerId = 1;
    worker w;
    workerPush(&workerHead, &w);
    ++workerId;
    return &w;
}
//通过id返回服务人员结构体地址 找不到返回NULL
worker *searchWorker(int id){}
//通过id删除服务人员
void deletework(int id){}
//通过服务人员id返回入住人地址 找不到返回NULL
user *searchworker(int id){}
//通过入住人id返回入住人地址 找不到返回NULL
user *searchuser(int id){}
//通过场馆id返回：1成功 0等待
int is_queue_full(int id){

}
