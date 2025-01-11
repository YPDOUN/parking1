#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;
#define Max_Size 50
#define refresh true
#define append false

class car
{
public:
	car(const string carn, int arrivehour, int arrivemin, int space)
		:carnumber(carn), arrive_min_sum(arrivehour * 60 + arrivemin), 
		depart_min_sum(0), amount(0),spacenum(space) 
	{
	};

	car(string carnumber1) :carnumber(carnumber1)
	{}

	car(string carnumber1, int space) :carnumber(carnumber1), spacenum(space)
	{
		parktime();
	}

	//��ȡ���ƺ�
	string getNumber() { return carnumber; }
	//��ȡ����ʱ���ܷ�����
	double getAtimesum() { return arrive_min_sum; }
	//��ȡ�뿪ʱ���ܷ�����
	double getDtimesum() { return depart_min_sum; }
	//���ؽ��
	double getAmount() { return amount; }
	//���س�λ��
	int getSpace() { return spacenum; }

	void setcarnum(string num) { carnumber = num; }

	void setcarspace(int space) { spacenum = space; }
	//���㵽��ʱ�䣬��ת��Ϊ������
	void parktime()
	{
		time_t atime;
		struct tm p;

		time(&atime);
		localtime_s(&p, &atime);
		int arrivehour = p.tm_hour;
		int arrivemin = p.tm_min;
		arrive_min_sum = arrivehour * 60 + arrivemin;
	}

	//��ȡ�뿪ʱ�䲢ת��Ϊ�����������ܼ�Ǯ
	void Getdeparttime()
	{
		time_t dime;
		struct tm q;
		time(&dime);
		localtime_s(&q, &dime);

		int departhour = q.tm_hour;
		int departmin = q.tm_min;
		depart_min_sum = departhour * 60 + departmin;

		parkingtime = (depart_min_sum - arrive_min_sum) / 60;
		amount = parkingtime * rate_per_hour;
	}

	//��Ʒѵ���
	static double getRate()
	{
		return rate_per_hour;
	}

	//���üƷѵ���
	static void setRate(double rate)
	{
		rate_per_hour = rate;
	}

	int gethour() { return arrive_min_sum / 60; }
	int getmin() { return arrive_min_sum % 60; }
	void setspace(int space) { spacenum = space; }
private:
	int spacenum;//��λ��
	string carnumber; //���ƺ�	
	int parkingtime; //ͣ��ʱ��
	double amount; //�ܽ��
	int arrive_min_sum;//�ܷ�����
	int depart_min_sum;
	static double rate_per_hour;
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

//����Ա��
class Manager
{
private:
	parkinglot* p;
	sideway* s;
	int emptyspace[Max_Size + 1];

public:
	Manager()
	{
		initparkinglot();
		initsideway();
		initspace();
		loadfile();
	}

	//��ʼ��˳���ͣ����
	void initparkinglot();

	//��ʼ�����б��
	void initsideway();

	//ͣ������غ���
	void arrive();
	void depart();

	//���Һ���(˳����ҺͶ��ֲ���)
	car* sqfindcar(string carnum);
	car* binarysearch(int space);
	void findcar();

	//������
	void bininsertsort();
	void heapsort();
	void sift(int low, int high);
	void sort();

	//�����غ���
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();

	//�ļ���غ���
	void savecarinfo(bool mode);
	void loadfile();

	//��������
	static void drawmenu();
	void printonecar(car* tem);
	void parkinginfo();
	void initspace();
	void modifyinfo();
};