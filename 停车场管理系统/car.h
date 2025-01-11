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

	//获取车牌号
	string getNumber() { return carnumber; }
	//获取到达时间总分钟数
	double getAtimesum() { return arrive_min_sum; }
	//获取离开时间总分钟数
	double getDtimesum() { return depart_min_sum; }
	//返回金额
	double getAmount() { return amount; }
	//返回车位号
	int getSpace() { return spacenum; }

	void setcarnum(string num) { carnumber = num; }

	void setcarspace(int space) { spacenum = space; }
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
	void setspace(int space) { spacenum = space; }
private:
	int spacenum;//车位号
	string carnumber; //车牌号	
	int parkingtime; //停车时间
	double amount; //总金额
	int arrive_min_sum;//总分钟数
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
	int emptyspace[Max_Size + 1];

public:
	Manager()
	{
		initparkinglot();
		initsideway();
		initspace();
		loadfile();
	}

	//初始化顺序表停车场
	void initparkinglot();

	//初始化队列便道
	void initsideway();

	//停车场相关函数
	void arrive();
	void depart();

	//查找函数(顺序查找和二分查找)
	car* sqfindcar(string carnum);
	car* binarysearch(int space);
	void findcar();

	//排序函数
	void bininsertsort();
	void heapsort();
	void sift(int low, int high);
	void sort();

	//便道相关函数
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();

	//文件相关函数
	void savecarinfo(bool mode);
	void loadfile();

	//其他函数
	static void drawmenu();
	void printonecar(car* tem);
	void parkinginfo();
	void initspace();
	void modifyinfo();
};