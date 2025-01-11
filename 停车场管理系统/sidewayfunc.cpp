#include"car.h"

void Manager::initsideway()
{
	s = new sideway;
	for (int i = 0; i < Max_Size; i++)
		s->sideway[i] = nullptr;
	s->front = s->rear = 0;
}

bool Manager::issidewayempty()
{
	return (s->front == s->rear);
}

//�����
void Manager::ensideway(car* c)
{
	if ((s->rear + 1) % Max_Size == s->front)
	{
		cout << "��������ȴ�����������\n";
		return;
	}
	else
	{
		s->rear = (s->rear + 1) % Max_Size;
		s->sideway[s->rear] = c;
	}
}

//������
car* Manager::desideway()
{
	if (s->front == s->rear)
	{
		cout << "���Ϊ�գ�";
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
		cout << "���Ϊ�գ���ʱû�г������룡" << endl;
		return;
	}
	else
	{
		int n = 1;

		cout << "��λ��" << "	" << "���ƺ�" << endl;
		for (int i = (s->front + 1) % Max_Size; i != (s->rear + 1) % Max_Size; i = (i + 1) % Max_Size)
		{
			cout << n << "	" << s->sideway[i]->getNumber() << endl;
			n++;
		}
	}
}
