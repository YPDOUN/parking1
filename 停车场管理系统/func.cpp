#include"car.h"

void Manager::drawmenu()
{
	cout << "****************************************\n";
	cout << "**           停车场管理系统           **\n";
	cout << "****************************************\n";
	cout << "**          请选择您需要的操作        **\n";
	cout << "**          1.查看停车场车辆信息      **\n";
	cout << "**          2.进入停车场              **\n";
	cout << "**          3.离开停车场              **\n";
	cout << "**          4.查看便道内车辆信息      **\n";
	cout << "**          5.查找停车场车辆信息      **\n";
	cout << "**          6.排序停车场车辆信息      **\n";
	cout << "**          7.修改计费单价            **\n";
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
	for (int i = 0; i < Max_Size; i++)
	{
		if (p->parkinglot[i] != nullptr)
		{
			int hour = p->parkinglot[i]->gethour();
			int min = p->parkinglot[i]->getmin();

			cout << i + 1 << "	" << p->parkinglot[i]->getNumber() << "	"
				<< setw(2) << setfill('0') << hour << ":"
				<< setw(2) << setfill('0') << min << "\n";
		}
		else
		{
			cout << i + 1 << "	" << "null\n";
		}
	}
}