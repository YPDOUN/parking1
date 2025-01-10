#include"car.h"

void Manager::arrive()
{
	string carnumber;
	cout << "请输入汽车的车牌号：";
	cin >> carnumber;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);

		cout << "停车场车辆已满！车辆:" << carnumber << "已进入便道！\n";
		return;
	}
	else
	{
		p->parkinglot[p->length] = new car(carnumber);
		p->length++;
		cout << "车辆:" << carnumber << "已进入停车场！\n";
	}

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
	q->Getdeparttime();
	cout << q->getNumber() << "已离开停车场, 费用为：" << q->getAmount() << endl;
	delete q;

	for (int i = pos - 1; i < p->length - 1; i++) 
	{
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

void Manager::sqfindcar()
{
	/*int choose, pos;
	string carname;
	cout << "请选择功能 1).车牌号 2).车位号:";
	cin >> choose;
	if (choose == 1)
	{
		cout << "请输入车牌号:";
		cin >> carname;
		
		for (int i = 0; i < p->length; i++)
		{
			if (carname == p->parkinglot[i]->getNumber())
			{
				cout << carname << "的位置位于" << i + 1 << "号\n";
				cout << "车位号" << "	" << "车牌号" << "		" << "到达时间" << "	" << "离开时间" << endl;
				cout << i + 1 << "	" << p->parkinglot[i]->getNumber() << "	"
					<< p->parkinglot[i]->getAtime() << "	" << p->parkinglot[i]->getDtime() << "	"
					<< p->parkinglot[i]->getAmount() << endl;
			}
		}
	}
	else
	{
		cout << "请输入车位号：";
		cin >> pos;

		if(p->parkinglot[pos - 1] == nullptr)
		{
			cout << "该车位上不存在车辆！";
			return;
		}
		else
		{
			cout << carname << "的位置位于" << pos << "号\n";
			cout << "车位号" << "	" << "车牌号" << "		" << "到达时间" << "	" << "离开时间" << endl;
			cout << pos << "	" << p->parkinglot[pos - 1]->getNumber() << "	"
				<< p->parkinglot[pos - 1]->getAtime() << "	" << p->parkinglot[pos - 1]->getDtime() << "	"
				<< p->parkinglot[pos - 1]->getAmount() << endl;
		}
	}*/
}

car* Manager::findcar()
{
	int left = 0, right = p->length - 1, mid;
	string carname;
	cout << "请输入待查找车辆的车牌号：";
	cin >> carname;

	while (left <= right)
	{
		mid = (left + right) / 2;
		car* midcar= p->parkinglot[mid];
		if (midcar->getNumber() == carname)
		{
			return midcar;
		}
		else if (midcar->getNumber() > carname)
			left = mid + 1;
		else
			right = mid - 1;
	}

}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv", mode ? (ios::out | ios::trunc) : (ios::out));

	if (file.is_open()) {
		file << "车牌号,到达时间\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;
			
			int hour = p->parkinglot[i]->gethour();
			int min = p->parkinglot[i]->getmin();

			file << p->parkinglot[i]->getNumber() << ","
				<< setw(2) << setfill('0') << hour << ":"
				<< setw(2) << setfill('0') << min << "\n";
		}
		file.close();
	}
	else {
		cerr << "无法打开文件!" << endl;
	}
}

void Manager::bubblesort()
{
	for (int i = 0; i < p->length - 1; i++)
	{
		for (int j = 0; j < p->length - 1; j++)
		{
			double atimesum1 = p->parkinglot[j]->getAtimesum();
			double atimesum2 = p->parkinglot[j + 1]->getAtimesum();

			if (atimesum1 > atimesum2)
			{
				car* tem = p->parkinglot[j];
				p->parkinglot[j] = p->parkinglot[j + 1];
				p->parkinglot[j + 1] = tem;
			}
		}
	}
}

void Manager::loadfile()
{
	/*ifstream file("parkinglot.csv");
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
	}*/

	ifstream file("parkinglot.csv");
	string line;
	getline(file, line);
	while (getline(file, line))
	{
		stringstream ss(line);
		string carnumber;
		int arrivehour, arriveminute;
		char delimiter;
		int i;

		if (getline(ss, carnumber, ',') && ss >> arrivehour >> delimiter >> arriveminute)
		{
			car* tem = new car(carnumber, arrivehour, arriveminute);
			p->parkinglot[p->length] = tem;
			p->length++;
		}
	}
	file.close();
}