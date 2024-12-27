#include"car.h"

//初始化停车场并将指针置null
void initparkinglot(parkinglot*& p)
{
	p = new parkinglot;
	p->length = 0;

	for (int i = 0; i < Max_Size; i++)
		p->parkinglot[i] = nullptr;
}

void arrive(parkinglot* p, sideway* s, const char* carnumber, string atime, string dtime)
{
	if (p->length >= Max_Size) {
		car* tem = new car(carnumber, atime, dtime);
		ensideway(s, tem);
		return;
	}

	p->parkinglot[p->length] = new car(carnumber, atime, dtime);
	p->length++;
	cout << "车辆:" << carnumber << "已进入停车场！\n";
}

void depart(parkinglot* p, int pos)
{
	if (pos < 1 || pos > p->length) {
		cout << "无效的位置: " << pos << "无法移除车辆！";
		return;
	}
	
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "已离开停车场\n";
	for (int i = pos - 1; i < p->length - 1; i++) {
		p->parkinglot[i] = p->parkinglot[i + 1];
	}

	delete q;
	p->length--;
	p->parkinglot[p->length] = nullptr;
}

void sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "的位置位于" << i << "号\n";
	}
}

void savecarinfo(parkinglot* p) {
	ofstream file("parkinglot.csv");

	if (file.is_open()) {
		file << "车牌号,到达时间,离开时间,待支付金额\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;
			file << p->parkinglot[i]->getNumber() << "," << p->parkinglot[i]->getAtime()
				<< "," << p->parkinglot[i]->getDtime() << "," << p->parkinglot[i]->getAmount()<<"\n";
		}
		file.close();
	}
	else {
		cerr << "无法打开文件!" << endl;
	}
}

void loadfile()
{

}