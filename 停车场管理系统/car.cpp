#include"car.h"

int main()
{
	int input = 1;
	Manager manager;

	do
	{
		system("cls");
		drawmenu();
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
		case 3:manager.depart(); break;
		default:cout << "输入错误，请重新输入！\n"; 
			system("pause");
			break;
		}
	} while (input);

	cin.get();
}