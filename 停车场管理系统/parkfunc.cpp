#include"car.h"

void Manager::arrive()
{
	string carnumber;
	cout << "�����������ĳ��ƺţ�";
	cin >> carnumber;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);

		cout << "ͣ������������������:" << carnumber << "�ѽ�������\n";
		return;
	}
	else
	{
		p->parkinglot[p->length] = new car(carnumber);
		p->length++;
		cout << "����:" << carnumber << "�ѽ���ͣ������\n";
	}

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
	q->Getdeparttime();
	cout << q->getNumber() << "���뿪ͣ����, ����Ϊ��" << q->getAmount() << endl;
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

		cout << "ͣ�����п�λ������е�" << temcar->getNumber()
			<< "�ѽ���ͣ������" << endl;
	}
}

void Manager::sqfindcar()
{
	/*int choose, pos;
	string carname;
	cout << "��ѡ���� 1).���ƺ� 2).��λ��:";
	cin >> choose;
	if (choose == 1)
	{
		cout << "�����복�ƺ�:";
		cin >> carname;
		
		for (int i = 0; i < p->length; i++)
		{
			if (carname == p->parkinglot[i]->getNumber())
			{
				cout << carname << "��λ��λ��" << i + 1 << "��\n";
				cout << "��λ��" << "	" << "���ƺ�" << "		" << "����ʱ��" << "	" << "�뿪ʱ��" << endl;
				cout << i + 1 << "	" << p->parkinglot[i]->getNumber() << "	"
					<< p->parkinglot[i]->getAtime() << "	" << p->parkinglot[i]->getDtime() << "	"
					<< p->parkinglot[i]->getAmount() << endl;
			}
		}
	}
	else
	{
		cout << "�����복λ�ţ�";
		cin >> pos;

		if(p->parkinglot[pos - 1] == nullptr)
		{
			cout << "�ó�λ�ϲ����ڳ�����";
			return;
		}
		else
		{
			cout << carname << "��λ��λ��" << pos << "��\n";
			cout << "��λ��" << "	" << "���ƺ�" << "		" << "����ʱ��" << "	" << "�뿪ʱ��" << endl;
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
	cout << "����������ҳ����ĳ��ƺţ�";
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
		file << "���ƺ�,����ʱ��\n";
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
		cerr << "�޷����ļ�!" << endl;
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
		cerr << "�޷����ļ���" << endl;
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