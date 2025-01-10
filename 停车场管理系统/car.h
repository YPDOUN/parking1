#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;
#define Max_Size 5
#define refresh true
#define append false

class car
{
public:
	car(const string carn, int arrivehour, int arrivemin)
		:carnumber(carn), arrive_min_sum(arrivehour * 60 + arrivemin),depart_min_sum(0),amount(0) {};

	car(string carnumber1) :carnumber(carnumber1)
	{
		parktime();
	}

	//获取车牌号
	string getNumber() { return carnumber; }
	//获取到达时间总分钟数
	double getAtimesum() { return arrive_min_sum; }
	//获取离开时间总分钟数
	double getDtimesum() { return depart_min_sum; }
	//返回金额
	double getAmount() { return amount; }

	//计算到达时间，并转换为分钟数
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

	//获取离开时间并转化为分钟数并求总价钱
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

	//求计费单价
	static double getRate()
	{
		return rate_per_hour;
	}

	//设置计费单价
	static void setRate(double rate)
	{
		rate_per_hour = rate;
	}

	int gethour() { return arrive_min_sum / 60; }
	int getmin() { return arrive_min_sum % 60; }

private:
	string carnumber; //车牌号	
	int parkingtime; //停车时间
	double amount; //总金额
	int arrive_min_sum;
	int depart_min_sum;
	static double rate_per_hour;
};

//停车场结构
typedef struct
{
	car* parkinglot[Max_Size];
	int length;
}parkinglot;

//便道结构
typedef struct
{
	car* sideway[Max_Size];
	int front, rear;
}sideway;

//管理员类
class Manager
{
private:
	parkinglot* p;
	sideway* s;
public:
	Manager()
	{
		initparkinglot();
		initsideway();
		loadfile();
	}

	//初始化顺序表停车场
	void initparkinglot()
	{
		p = new parkinglot;
		p->length = 0;

		for (int i = 0; i < Max_Size; i++)
			p->parkinglot[i] = nullptr;
	}

	//初始化队列便道
	void initsideway()
	{
		s = new sideway;
		for (int i = 0; i < Max_Size; i++)
			s->sideway[i] = nullptr;
		s->front = s->rear = 0;
	}

	//停车场相关函数
	void arrive();
	void depart();
	void sqfindcar();
	void parkinginfo();
	car* findcar();
	void bubblesort();

	//便道相关函数
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();

	//文件相关函数
    void savecarinfo(bool mode);
	void loadfile();

	static void drawmenu();
 };