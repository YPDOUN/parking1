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
		cout << "请输入序号进入相应功能: ";
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
		case 7:cout << "当前计费单价为：" << car::getRate() << ",请输入新的计费单价：";
			double rate;
			cin >> rate;
			car::setRate(rate);
			cout << "修改成功！" << endl;
			system("pause");
			break;
		case 0:cout << "退出系统\n"; break;
		default:cout << "输入错误，请重新输入！\n"; 
			system("pause");
			break;
		}
	} while (input);

	cin.get();
}