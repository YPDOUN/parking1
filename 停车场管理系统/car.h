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
		:carnumber(carn),arrivetime(atime), departtime(dtime)  //初始化成员，计算停车时间
	{
		calculateAmount();
	}

	string getNumber() { return carnumber; }
	string getAtime()	{ return arrivetime; }
	string getDtime() { return departtime; }
	double getAmount() { return amount; }
	
	void calculateAmount()   //提取字符串中的小时分钟计算金额
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
	string carnumber; //车牌号
	string arrivetime; //到达时间
	string departtime; //离开时间
	double parkingtime; //停车时间
	double amount; //总金额
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


//停车场相关函数
void initparkinglot(parkinglot*& p);
void arrive(parkinglot* p, sideway* s, const char* carnumber, string atime, string dtime);
void depart(parkinglot* p, int pos);
void sqfindcar(parkinglot* p, string carname);
void savecarinfo(parkinglot* p);

//便道相关函数
void initsideway(sideway*& s);
void ensideway(sideway* s, car* c);
car* desideway(sideway* s);

void draw();