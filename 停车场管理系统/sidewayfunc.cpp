#include"car.h"

void initsideway(sideway*& s)
{
	s = new sideway;
	s->front = s->rear = 0;
}

void ensideway(sideway* s, car* c)
{
	if ((s->rear + 1) % Max_Size == s->front) {
		cout << "便道车辆等待车辆已满！\n";
		return;
	}

	s->rear = (s->rear + 1) % Max_Size;
	s->sideway[s->rear] = c;
	cout << "停车场车位已满，" << c->getNumber() << "无法进入停车场，已停放在便道！\n";
}

car* desideway(sideway* s)
{
	/*if (s->front == s->rear)
		return;*/

	s->front++;
	return s->sideway[s->front];

}