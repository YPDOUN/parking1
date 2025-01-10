#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
#define Max_Size 5
#define refresh true
#define append false

class car
{
public:
	car() {};
	car(const string carn, string atime, string dtime)
		:carnumber(carn),arrivetime(atime), departtime(dtime) 
	{
		calculateAmount();
	}
	car(const string carn, string atime)
		:carnumber(carn), arrivetime(atime) {
		amount = 0.0;
	};

	string getNumber() { return carnumber; }
	string getAtime()	{ return arrivetime; }
	string getDtime() { return departtime; }
	double getAmount() { return amount; }
	
	void calculateAmount()   //��ȡ�ַ����е�Сʱ���Ӽ�����
	{
		int arrivehour, departhour, arrivemin, departmin;

		stringstream atimestream(arrivetime);
		stringstream dtimestream(departtime);
		char ch;

		atimestream >> arrivehour >> ch >> arrivemin;
		dtimestream >> departhour >> ch >> departmin;

		double arrive_min_sum = arrivehour * 60 + arrivemin;
		double depart_min_sum = departhour * 60 + departmin;
		parkingtime = (depart_min_sum - arrive_min_sum) / 60.0;
		amount = parkingtime * 10.0;
	}

private:
	string carnumber; //���ƺ�
	string arrivetime; //����ʱ��
	string departtime; //�뿪ʱ��
	double parkingtime; //ͣ��ʱ��
	double amount; //�ܽ��
};

//ͣ�����ṹ
typedef struct
{
	car* parkinglot[Max_Size];
	int length;
}parkinglot;

//����ṹ
typedef struct
{
	car* sideway[Max_Size];
	int front, rear;
}sideway;

typedef struct
{
	car* stack[Max_Size];
	int top;
}temstack;

//����Ա��
class Manager
{
private:
	
	parkinglot* p;
	sideway* s;
	temstack* t;

public:
	Manager()
	{
		initparkinglot();
		initsideway();
		loadfile();
	}

	//��ʼ��˳���ͣ����
	void initparkinglot()
	{
		p = new parkinglot;
		p->length = 0;

		for (int i = 0; i < Max_Size; i++)
			p->parkinglot[i] = nullptr;
	}

	//��ʼ�����б��
	void initsideway()
	{
		s = new sideway;
		for (int i = 0; i < Max_Size; i++)
			s->sideway[i] = nullptr;
		s->front = s->rear = 0;
	}

	//��ʼ��ջ���ڴ�ű������
	void initstack()
	{
		t = new temstack;
		for (int i = 0; i < Max_Size; i++)
			t->stack[i] = nullptr;
		t->top = -1;
	}

	//ͣ������غ���
	void arrive();
	void depart();
	void sqfindcar(parkinglot* p, string carname);
	void parkinginfo();

	//�����غ���
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();
	bool isstackempty();
	void push(car* c);
	bool pop(car*& c);
	void departsideway();

	//�ļ���غ���
    void savecarinfo(bool mode);
	void loadfile();
 };

void drawmenu();