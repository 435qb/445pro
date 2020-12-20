#include "game.h"

void vipCreate(vipList** wl, const vip* w)
{
	wl[0] = (vipList*)malloc(sizeof(vipList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
}

vip* vipPush(vipList** wl, const vip* w)
{
	vipList *curr, *temp = wl[0];
	vipCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next)) continue;
	temp->next = curr;
	return &(curr->element);
}

vip* vipSearch(vipList** wl, int id)
{
	vipList* curr = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id) { return &(curr->element); }
		curr = curr->next;
	}
	return NULL;
}

void vipDelete(vipList** wl, int id)
{
	vipList *curr = wl[0], *pre = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id)
		{
			if (pre != curr)
			{
				vipList* temp = curr->next;
				pre->next = temp;
			}
			free(curr);
			return;
		}
		curr = curr->next;
	}
}

void vipFree(vipList** wl)
{
	vipList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]);
		wl[0] = next;
	}
}

void userCreate(userList** wl, const user* w)
{
	wl[0] = (userList*)malloc(sizeof(userList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
}

user* userPush(userList** wl, const user* w)
{
	userList *curr, *temp = wl[0];
	userCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next)) continue;
	temp->next = curr;
	return &(curr->element);
}

user* userSearch(userList** wl, int id)
{
	userList* curr = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id) { return &(curr->element); }
		curr = curr->next;
	}
	return NULL;
}

void userDelete(userList** wl, int id)
{
	userList *curr = wl[0], *pre = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id)
		{
			if (pre != curr)
			{
				userList* temp = curr->next;
				pre->next = temp;
			}
			free(curr);
			return;
		}
		curr = curr->next;
	}
}

void userFree(userList** wl)
{
	userList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]);
		wl[0] = next;
	}
}

void houseCreate(houseList** wl, const house* w)
{
	wl[0] = (houseList*)malloc(sizeof(houseList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
}

house* housePush(houseList** wl, const house* w)
{
	houseList *curr, *temp = wl[0];
	houseCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next)) continue;
	temp->next = curr;
	return &(curr->element);
}

house* houseSearch(houseList** wl, int id)
{
	houseList* curr = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id) { return &(curr->element); }
		curr = curr->next;
	}
	return NULL;
}

void houseDelete(houseList** wl, int id)
{
	houseList *curr = wl[0], *pre = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id)
		{
			if (pre != curr)
			{
				houseList* temp = curr->next;
				pre->next = temp;
			}
			free(curr);
			return;
		}
		curr = curr->next;
	}
}

void houseFree(houseList** wl)
{
	houseList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]);
		wl[0] = next;
	}
}

void facilCreate(facilList** wl, const facil* w)
{
	wl[0] = (facilList*)malloc(sizeof(facilList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
	wl[0]->element._queue = (queue*)malloc(sizeof(queue));
}

facil* facilPush(facilList** wl, const facil* w)
{
	facilList *curr, *temp = wl[0];
	facilCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next)) continue;
	temp->next = curr;
	return &(curr->element);
}

facil* facilSearch(facilList** wl, int id)
{
	facilList* curr = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id) { return &(curr->element); }
		curr = curr->next;
	}
	return NULL;
}

void facilDelete(facilList** wl, int id)
{
	facilList *curr = wl[0], *pre = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id)
		{
			if (pre != curr)
			{
				facilList* temp = curr->next;
				pre->next = temp;
			}
			free(curr->element._queue);
			free(curr);
			return;
		}
		curr = curr->next;
	}
}

void facilFree(facilList** wl)
{
	facilList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]->element._queue);
		free(wl[0]);
		wl[0] = next;
	}
}

void workerCreate(workerList** wl, const worker* w)
{
	wl[0] = (workerList*)malloc(sizeof(workerList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
}

worker* workerPush(workerList** wl, const worker* w)
{
	workerList *curr, *temp = wl[0];
	workerCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next)) continue;
	temp->next = curr;
	return &(curr->element);
}

worker* workerSearch(workerList** wl, int id)
{
	workerList* curr = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id) { return &(curr->element); }
		curr = curr->next;
	}
	return NULL;
}

void workerDelete(workerList** wl, int id)
{
	workerList *curr = wl[0], *pre = wl[0];
	while (curr != NULL)
	{
		if (curr->element._id == id)
		{
			if (pre != curr)
			{
				workerList* temp = curr->next;
				pre->next = temp;
			}
			free(curr);
			return;
		}
		curr = curr->next;
	}
}

void workerFree(workerList** wl)
{
	workerList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]);
		wl[0] = next;
	}
}

void queueCreate(queueList** wl, const queue* w)
{
	wl[0] = (queueList*)malloc(sizeof(queueList));
	wl[0]->element = *w;
	wl[0]->next = NULL;
}

queue* queuePush(queueList** wl, const queue* w)
{
	queueList *curr, *temp = wl[0];
	queueCreate(&curr, w);
	while (temp->next != NULL && (temp = temp->next))
		continue;
	temp->next = curr;
	return &curr->element;
}

//不能传入指向null的指针,必须是头节点
queue queuePop(queueList** wl)
{
	queue retn = wl[0]->element;
	queueList* curr = wl[0]->next;
	free(wl[0]);
	wl[0] = curr;
	return retn;
}

//被弃用的函数
queue* queueSearch(queueList** wl, int id) { return NULL; }
//同样被弃用
void queueDelete(queueList** wl, int id)
{
}

void queueFree(queueList** wl)
{
	queueList* next;
	while (wl[0] != NULL)
	{
		next = wl[0]->next;
		free(wl[0]);
		wl[0] = next;
	}
}
#undef INITFUNC
