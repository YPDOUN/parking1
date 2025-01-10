#include"car.h"

void Manager::arrive()
{
	string carnumber, atime;
	cout << "�����������ĳ��ƺź͵���ʱ�䣺";
	cin >> carnumber >> atime;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber, atime);
		ensideway(tem);
		return;
	}

	p->parkinglot[p->length] = new car(carnumber, atime);
	p->length++;
	cout << "����:" << carnumber << "�ѽ���ͣ������\n";

	savecarinfo(append);
}

void Manager::depart()
{
	int pos;
	parkinginfo();
	cout << "��������뿪�����ĳ�λ�ţ�";
	cin >> pos;

	if (pos < 1 || pos > p->length) 
	{
		cout << pos << "�ų�λ��û�г�����";
		return;
	}
	
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "���뿪ͣ����\n";
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

		cout << "ͣ�����п�λ������е�" << temcar->getNumber()
			<< "�ѽ���ͣ������" << endl;
	}
}

void Manager::sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "��λ��λ��" << i << "��\n";
	}
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv", mode ? (ios::out | ios::trunc) : (ios::out));

	if (file.is_open()) {
		file << "���ƺ�,����ʱ��,�뿪ʱ��,��֧�����\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;

			file << p->parkinglot[i]->getNumber() << "," << p->parkinglot[i]->getAtime()
				<< "," << p->parkinglot[i]->getDtime() << "," << p->parkinglot[i]->getAmount()<<"\n";
		}
		file.close();
	}
	else {
		cerr << "�޷����ļ�!" << endl;
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
		cerr << "�޷����ļ���" << endl;
	}
}