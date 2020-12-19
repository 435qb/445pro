#include "test.h"
static vipList *vipHead;
static houseList *houseHead;
static facilList *facilHead;
static workerList *workerHead;

//初始化id，house=null

void init()
{
    vip v;
    house h;
    facil f;
    worker w;
    vipCreate(&vipHead, &v);
    houseCreate(&houseHead, &h);
    facilCreate(&facilHead, &f);
    workerCreate(&workerHead, &w);
}

vip *createVip()
{
    static int vipId = 1;
    vip v, *curr;
    v._id = vipId;
    vipPush(&vipHead, &v);
    curr = vipSearch(&vipHead, vipId);
    ++vipId;
    return curr;
}
//通过id返回会员结构体地址
vip *searchVip(int id)
{
    return vipSearch(&vipHead, id);
}
//通过id删除会员
void deleteVip(int id)
{
    vipDelete(&vipHead, id);
}
vip* createHouse()
{
    static int houseId = 1;
    house x = {houseId, 0, 0, 0, NULL};
    housePush(&houseHead, &x);
    houseId++;
}
//通过房屋id返回房屋地址 找不到返回NULL
house *searchHouse(int id)
{
    return houseSearch(&houseHead, id);
}
//更改房屋数据为入住状态

//更改房屋数据为出租状态

//更改房屋数据为空置状态

//初始化facil的信息

void facilinit()
{
    facil x;
    x._id = 0;
    facilCreate(&facilHead, &x);
}

facil *createFacil()
{
    static int facilId = 1;
    facil f, *curr;
    f._id = facilId;
    facilPush(&facilHead, &f);
    curr =
        ++facilId;
    return &f;
}
//初始化worker的信息
void workerinit()
{
    worker x;
    x._id = 0;
    workerCreate(&workerHead, &x);
}

void createWorker()
{
    static int workerId = 1;
    worker w;
    workerPush(&workerHead, &w);
    ++workerId;
    return &w;
}
//通过id返回服务人员结构体地址 找不到返回NULL
worker *searchWorker(int id) {}
//通过id删除服务人员
void deletework(int id) {}
//通过服务人员id返回入住人地址 找不到返回NULL
user *searchworker(int id) {}
//通过入住人id返回入住人地址 找不到返回NULL
user *searchuser(int id) {}
//通过场馆id返回：1成功 0等待
int is_queue_full(int id)
{
}
