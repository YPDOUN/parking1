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
		cout << "停车场车位已满，" << c->getNumber() << "无法进入停车场，已停放在便道！\n";
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

bool Manager::isstackempty()
{
	return t->top == -1;
}

void Manager::push(car* c)
{
	//栈满
	if (t->top == Max_Size - 1)
	{
		cout << "栈满！";
		return;
	}
	else
	{
		t->top++;
		t->stack[t->top] = c;
	}
}

bool Manager::pop(car*& c)
{
	if (t->top == -1)
		return false;
	else
	{
		c = t->stack[t->top];
		t->top--;
		return true;
	}

}

void Manager::departsideway()
{
	/*
	* menu
	* 输入汽车车牌号 车位号删除车辆
	* front出放入栈
	*/

	car* tem = depar
	


	
}