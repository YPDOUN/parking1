#include"car.h"


double car::rate_per_hour = 5.0;

int main()
{
	int input = 1;
	Manager manager;

	do
	{
		Manager::drawmenu();
		cout << "��������Ž�����Ӧ����: ";
		cin >> input;
		switch (input)
		{
		case 1:system("cls");
			manager.parkinginfo();
			system("pause");
			break;
		case 2:manager.arrive();
			system("pause");
			break;
		case 3:manager.depart();
			system("pause");
			break;
		case 4:manager.showsidewayinfo();
			system("pause");
			break;
		case 5:manager.findcar();
			system("pause");
			break;
		case 6:manager.sort();
			system("pause");
			break;
		case 7:manager.modifyinfo();
			system("pause");
			break;
		case 8:cout << "��ǰ�Ʒѵ���Ϊ��" << car::getRate() << ",�������µļƷѵ��ۣ�";
			double rate;
			cin >> rate;
			if (rate > 0)
				car::setRate(rate);
			else
				cout << "�Ʒѵ���Ӧ�ô���0��" << endl;
			system("pause");
			break;
		case 0:cout << "�˳�ϵͳ\n"; break;
		default:cout << "����������������룡\n";
			system("pause");
			break;
		}
	} while (input);

	return 0;
}