#ifndef _TEST_H
#define _TEST_H
#include "game.h"
//初始化id，house=null
vip *createVip();
//通过id返回会员结构体地址
vip *searchVip(int id);
//通过id删除会员
void deleteVip(int id);
//初始化house的信息
void createHouse();
//通过房屋id返回房屋地址 找不到返回NULL
house *searchHouse(int id);
//通过入住人id返回房屋地址 找不到返回NULL
house *searchhouse(int id);
//初始化facil的信息
void createFacil();
//初始化worker的信息
void createWorker();
//通过id返回服务人员结构体地址 找不到返回NULL
worker *searchWorker(int id);
//通过id删除服务人员
void deletework(int id);
//通过服务人员id返回入住人地址 找不到返回NULL
user *searchworker(int id);
//通过入住人id返回入住人地址 找不到返回NULL
user *searchuser(int id);
//通过场馆id返回：1成功 0等待
int is_queue_full(int id);
#endif