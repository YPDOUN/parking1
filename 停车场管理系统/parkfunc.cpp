#include"car.h"

void Manager::arrive()
{
	string carnumber, atime;
	cout << "请输入汽车的车牌号和到达时间：";
	cin >> carnumber >> atime;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber, atime);
		ensideway(tem);
		return;
	}

	p->parkinglot[p->length] = new car(carnumber, atime);
	p->length++;
	cout << "车辆:" << carnumber << "已进入停车场！\n";

	savecarinfo(append);
}

void Manager::depart()
{
	int pos;
	parkinginfo();
	cout << "请输入待离开车辆的车位号：";
	cin >> pos;

	if (pos < 1 || pos > p->length) 
	{
		cout << pos << "号车位上没有车辆！";
		return;
	}
	
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "已离开停车场\n";
	delete q;

	for (int i = pos - 1; i < p->length - 1; i++) {
		p->parkinglot[i] = p->parkinglot[i + 1];
	}
	p->parkinglot[p->length - 1] = nullptr;
	p->length--;
	
	if (!issidewayempty())
	{
		car* temcar = desideway();
		p->parkinglot[p->length] = temcar;
		p->length++;

		cout << "停车场有空位，便道中的" << temcar->getNumber()
			<< "已进入停车场中" << endl;
	}
}

void Manager::sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "的位置位于" << i << "号\n";
	}
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv", mode ? (ios::out | ios::trunc) : (ios::out));

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

void Manager::loadfile()
{
	ifstream file("parkinglot.csv");
	string line;
	int n = 0;


	if (file.is_open()) {
		getline(file, line);

		while (getline(file, line))
		{
			stringstream ss(line);
			string carnumber, atime, dtime, amount;

			getline(ss, carnumber, ',');
			getline(ss, atime, ',');
			getline(ss, dtime, ',');
			getline(ss, amount, ',');

			car* tem = new car(carnumber, atime, dtime);
			p->parkinglot[n] = tem;
			p->length++;
			n++;
		}
		file.close();
	}
	else {
		cerr << "无法打开文件！" << endl;
	}
}