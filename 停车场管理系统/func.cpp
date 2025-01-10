#include"car.h"

void drawmenu()
{
	cout << "***********************************\n";
	cout << "**         停车场管理系统        **\n";
	cout << "***********************************\n";
	cout << "**       请选择您需要的操作      **\n";
	cout << "*        1.查看停车场车辆信息     *\n";
	cout << "*        2.进入停车场             *\n";
	cout << "*        3.离开停车场             *\n";
	cout << "*        4.查看便道内车辆信息     *\n";
	cout << "*        0.退出停车场系统         *\n";
	cout << "***********************************\n";
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
	for (int i = 0; i < Max_Size; i++)
	{
		if (p->parkinglot[i] != nullptr)
			cout << i + 1 << "	" << p->parkinglot[i]->getNumber() << "	"
			<< p->parkinglot[i]->getAtime() << endl;
		else
		{
			cout << i + 1 << "	" << "null\n";
		}
	}
}