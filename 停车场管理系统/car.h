#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
#define Max_Size 3

class car
{
public:
	car() {};
	car(const string carn, string atime, string dtime)
		:carnumber(carn),arrivetime(atime), departtime(dtime)  //��ʼ����Ա������ͣ��ʱ��
	{
		calculateAmount();
	}

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


//ͣ������غ���
void initparkinglot(parkinglot*& p);
void arrive(parkinglot* p, sideway* s, const char* carnumber, string atime, string dtime);
void depart(parkinglot* p, int pos);
void sqfindcar(parkinglot* p, string carname);
void savecarinfo(parkinglot* p);

//�����غ���
void initsideway(sideway*& s);
void ensideway(sideway* s, car* c);
car* desideway(sideway* s);

void draw();