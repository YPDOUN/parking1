#include"car.h"

void Manager::drawmenu()
{
	system("cls");
	cout << "****************************************\n";
	cout << "**           停车场管理系统           **\n";
	cout << "****************************************\n";
	cout << "**          请选择您需要的操作        **\n";
	cout << "**          1.查看停车场车辆信息      **\n";
	cout << "**          2.进入停车场              **\n";
	cout << "**          3.离开停车场              **\n";
	cout << "**          4.查看便道内车辆信息      **\n";
	cout << "**          5.查找停车场车辆信息      **\n";
	cout << "**          6.排序信息                **\n";
	cout << "**          7.修改车辆信息            **\n";
	cout << "**          8.修改计费单价            **\n";
	cout << "**          0.退出停车场系统          **\n";
	cout << "**                                    **\n";
	cout << "**   本停车场计费单价为: "
		<< setw(5) << setfill(' ') << fixed << setprecision(2) << car::getRate() << "元/h    **\n";
	cout << "****************************************\n";
}

void Manager::parkinginfo()
{
	if (p->length == 0)
	{
		cout << "停车场内无车辆！" << endl;
		return;
	}

	cout << "********停车场内车辆信息********\n\n";

	cout << "车位号" << "	" << "车牌号" << "		" << "到达时间" << endl;
	for (int i = 0; i < p->length; i++)
	{
		int hour = p->parkinglot[i]->gethour();
		int min = p->parkinglot[i]->getmin();

		cout << p->parkinglot[i]->getSpace() << "	" << p->parkinglot[i]->getNumber() << "	"
			<< setw(2) << setfill('0') << hour << ":"
			<< setw(2) << setfill('0') << min << "\n";
	}
}

void Manager::printonecar(car* tem)
{
	int hour = tem->gethour();
	int min = tem->getmin();
	cout << "车位号" << "	" << "车牌号" << "		" << "到达时间" << endl;
	cout << tem->getSpace() << "	" << tem->getNumber() << "	"
		<< setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << min << "\n";
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv", mode ? (ios::out | ios::trunc) : (ios::out));

	if (file.is_open()) {
		file << "车位号,车牌号,到达时间\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;

			int hour = p->parkinglot[i]->gethour();
			int min = p->parkinglot[i]->getmin();

			file << p->parkinglot[i]->getSpace() << ","
				<< p->parkinglot[i]->getNumber() << ","
				<< setw(2) << setfill('0') << hour << ":"
				<< setw(2) << setfill('0') << min << "\n";
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
	getline(file, line);
	while (getline(file, line))
	{
		stringstream ss(line);
		int space;
		string carnumber;
		int arrivehour, arriveminute;
		char delimiter;

		if (ss >> space >> delimiter && getline(ss, carnumber, ',') && ss >> arrivehour >> delimiter >> arriveminute)
		{
			car* tem = new car(carnumber, arrivehour, arriveminute, space);
			emptyspace[space] = -1;
			p->parkinglot[p->length] = tem;
			p->length++;
		}
	}
	file.close();
}
