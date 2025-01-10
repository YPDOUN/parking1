#include"car.h"

bool Manager::issidewayempty()
{
	return (s->front == s->rear);
}

//入队列
void Manager::ensideway(car* c)
{
	if ((s->rear + 1) % Max_Size == s->front) 
	{
		cout << "便道车辆等待车辆已满！\n";
		return;
	}
	else
	{
		s->rear = (s->rear + 1) % Max_Size;
		s->sideway[s->rear] = c;
	}
}

//出队列
car* Manager::desideway()
{
	if (s->front == s->rear)
	{
		cout << "便道为空！";
		return nullptr;
	}

	s->front = (s->front + 1) % Max_Size;
	car* tem = s->sideway[s->front];
	s->sideway[s->front] = nullptr;

	return tem;
}

void Manager::showsidewayinfo()
{
	if (s->front == s->rear)
	{
		cout << "便道为空，暂时没有车辆进入！" << endl;
		return;
	}
	else
	{
		int n = 1;

		cout << "车位号" << "	" << "车牌号" << endl;
		for (int i = (s->front + 1) % Max_Size; i != (s->rear + 1) % Max_Size; i = (i + 1) % Max_Size)
		{
			cout << n << "	" << s->sideway[i]->getNumber() << endl;
			n++;
		}
	}
}