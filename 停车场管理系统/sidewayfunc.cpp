#include"car.h"

void initsideway(sideway*& s)
{
	s = new sideway;
	s->front = s->rear = 0;
}

void ensideway(sideway* s, car* c)
{
	if ((s->rear + 1) % Max_Size == s->front) {
		cout << "��������ȴ�����������\n";
		return;
	}

	s->rear = (s->rear + 1) % Max_Size;
	s->sideway[s->rear] = c;
	cout << "ͣ������λ������" << c->getNumber() << "�޷�����ͣ��������ͣ���ڱ����\n";
}

car* desideway(sideway* s)
{
	/*if (s->front == s->rear)
		return;*/

	s->front++;
	return s->sideway[s->front];

}