#include"car.h"


double car::rate_per_hour = 10.0;

int main()
{
	int input = 1;
	Manager manager;

	do
	{
		system("cls");
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
		case 6:manager.bubblesort();
			system("pause");
			break;
		case 7:cout << "��ǰ�Ʒѵ���Ϊ��" << car::getRate() << ",�������µļƷѵ��ۣ�";
			double rate;
			cin >> rate;
			car::setRate(rate);
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			break;
		case 0:cout << "�˳�ϵͳ\n"; break;
		default:cout << "����������������룡\n"; 
			system("pause");
			break;
		}
	} while (input);

	cin.get();
}