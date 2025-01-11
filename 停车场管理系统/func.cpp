#include"car.h"

void Manager::drawmenu()
{
	system("cls");
	cout << "****************************************\n";
	cout << "**           ͣ��������ϵͳ           **\n";
	cout << "****************************************\n";
	cout << "**          ��ѡ������Ҫ�Ĳ���        **\n";
	cout << "**          1.�鿴ͣ����������Ϣ      **\n";
	cout << "**          2.����ͣ����              **\n";
	cout << "**          3.�뿪ͣ����              **\n";
	cout << "**          4.�鿴����ڳ�����Ϣ      **\n";
	cout << "**          5.����ͣ����������Ϣ      **\n";
	cout << "**          6.������Ϣ                **\n";
	cout << "**          7.�޸ĳ�����Ϣ            **\n";
	cout << "**          8.�޸ļƷѵ���            **\n";
	cout << "**          0.�˳�ͣ����ϵͳ          **\n";
	cout << "**                                    **\n";
	cout << "**   ��ͣ�����Ʒѵ���Ϊ: "
		<< setw(5) << setfill(' ') << fixed << setprecision(2) << car::getRate() << "Ԫ/h    **\n";
	cout << "****************************************\n";
}

void Manager::parkinginfo()
{
	if (p->length == 0)
	{
		cout << "ͣ�������޳�����" << endl;
		return;
	}

	cout << "********ͣ�����ڳ�����Ϣ********\n\n";

	cout << "��λ��" << "	" << "���ƺ�" << "		" << "����ʱ��" << endl;
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
	cout << "��λ��" << "	" << "���ƺ�" << "		" << "����ʱ��" << endl;
	cout << tem->getSpace() << "	" << tem->getNumber() << "	"
		<< setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << min << "\n";
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv", mode ? (ios::out | ios::trunc) : (ios::out));

	if (file.is_open()) {
		file << "��λ��,���ƺ�,����ʱ��\n";
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
		cerr << "�޷����ļ�!" << endl;
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
