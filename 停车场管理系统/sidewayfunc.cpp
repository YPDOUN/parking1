#include"car.h"

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
		cout << "ͣ������λ������" << c->getNumber() << "�޷�����ͣ��������ͣ���ڱ����\n";
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

bool Manager::isstackempty()
{
	return t->top == -1;
}

void Manager::push(car* c)
{
	//ջ��
	if (t->top == Max_Size - 1)
	{
		cout << "ջ����";
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
	* �����������ƺ� ��λ��ɾ������
	* front������ջ
	*/

	car* tem = depar
	


	
}