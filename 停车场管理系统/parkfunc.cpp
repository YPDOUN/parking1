#include"car.h"

void Manager::initparkinglot()
{
	p = new parkinglot;
	p->length = 0;

	for (int i = 0; i < Max_Size; i++)
		p->parkinglot[i] = nullptr;
}


void Manager::initspace()
{
	for (int i = 1; i < Max_Size + 1; i++)
		emptyspace[i] = i;
}

void Manager::arrive()
{
	string carnumber;
	int space;
	cout << "请输入汽车的车牌号和车位号：";
	cin >> carnumber >> space;

	if (emptyspace[space] == -1)
	{
		cout << "该车位号上已经有车！" << endl;
		return;
	}

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);

		cout << "停车场车辆已满！车辆:" << carnumber << "已进入便道！\n";
		return;
	}
	else
	{
		p->parkinglot[p->length] = new car(carnumber, space);
		emptyspace[space] = -1;
		p->length++;
		cout << "车辆:" << carnumber << "已进入停车场的" << space << "号车位！\n";
	}

	savecarinfo(append);
}

void Manager::depart()
{
	system("cls");
	int space;

	parkinginfo();
	cout << "请输入待离开车辆的车位号：";
	cin >> space;

	if (space < 1 || space > p->length)
	{
		cout << space << "号车位上没有车辆！";
		return;
	}

	for(int i = 0; i < p->length; i++)
	{
		if (p->parkinglot[i]->getSpace() == space)
		{
			car* q = p->parkinglot[i];
			q->Getdeparttime();
			cout << q->getNumber() << "已离开停车场, 费用为：" << q->getAmount() << endl;
			delete q;

			for (int j = i; j < p->length - 1; j++)
			{
				p->parkinglot[j] = p->parkinglot[j + 1];
			}
			p->parkinglot[p->length - 1] = nullptr;
			p->length--;
		}
		else if(i >= p->length)
		{
			cout << space << "号车位上没有车辆！" << endl;
			return;
		}
	}

	if (!issidewayempty())
	{
		car* temcar = desideway();
		temcar->parktime();
		temcar->setspace(space);
		p->parkinglot[p->length] = temcar;
		p->length++;

		cout << "停车场有空位，便道中的" << temcar->getNumber()
			<< "已进入停车场中" << endl;
	}
}

car* Manager::sqfindcar(string carnum)
{
	for (int i = 0; i < p->length; i++)
	{
		if (carnum == p->parkinglot[i]->getNumber())
		{
			car* tem = p->parkinglot[i];
			return tem;
		}
		if (i >= p->length)
			return nullptr;
	}
}

car* Manager::binarysearch(int space)
{
	sort();
	int low = 0, high = p->length - 1, mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (p->parkinglot[mid]->getSpace() == space)
			return p->parkinglot[mid];
		else if (p->parkinglot[mid]->getSpace() > space)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return nullptr;
}

void Manager::findcar()
{
	system("cls");
	cout << "***************************\n";
	cout << "**     查询单辆汽车信息  **\n";
	cout << "**     1.车牌号查询      **\n";
	cout << "**     2.车位号查询      **\n";
	cout << "**     0.退出查询        **\n";
	cout << "***************************\n";

	int choose, space;
	string carnum;

	cout << "请输入功能序号: ";
	cin >> choose;

	if (choose == 1)
	{
		cout << "请输入车牌号：";
		cin >> carnum;

		car* tem = sqfindcar(carnum);
		if (tem != nullptr)
			printonecar(tem);
		else
		{
			cout << "查无此车辆！" << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "请输入车位号：";
		cin >> space;

		car* tem = binarysearch(space);
		if (tem != nullptr)
			printonecar(tem);
		else
		{
			cout << "查无此车辆！" << endl;
		}
	}
	else if (choose == 0)
	{
		cout << "退出查询!" << endl;
		return;
	}
	else
		cout << "输入错误！" << endl;
}

void Manager::bininsertsort()
{
	
}


void Manager::sift(int low, int high)
{
	int i = low, j = 2 * i + 1;
	
	car* tem = p->parkinglot[i];
	
	while (j <= high)
	{
		if (j < high && p->parkinglot[j]->getAtimesum() < p->parkinglot[j + 1]->getAtimesum())
			j++;

		if (tem->getAtimesum() < p->parkinglot[j]->getAtimesum())
		{
			p->parkinglot[i] = p->parkinglot[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	p->parkinglot[i] = tem;
}

void Manager::heapsort()
{
	int i;
	int n = p->length;

	for (i = n / 2; i >= 0; i--)
		sift(i, n - 1);
	for (i = p->length - 1; i > 0; i--)
	{
		car* tem = p->parkinglot[0];
		p->parkinglot[0] = p->parkinglot[i];
		p->parkinglot[i] = tem;

		sift(0, i - 1);
	}
}

void Manager::modifyinfo()
{
	system("cls");
	cout << "***************************\n";
	cout << "**     查询单辆汽车信息  **\n";
	cout << "**     1.车牌号查询修改  **\n";
	cout << "**     2.车位号查询修改  **\n";
	cout << "**     0.退出修改        **\n";
	cout << "***************************\n";

	int choose, space;
	string carnum;

	cout << "请输入功能序号：";
	cin >> choose;

	if (choose == 1)
	{
		cout << "请输入车牌号：";
		cin >> carnum;
		car* tem = sqfindcar(carnum);

		if (tem != nullptr)
		{
			printonecar(tem);
			cout << "请输入新的车牌号：" << endl;
			cin >> carnum;
			tem->setcarnum(carnum);
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "查无车辆！" << endl;
			return;
		}
	}

	else if (choose == 2)
	{
		cout << "请输入车位号：";
		cin >> space;
		car* tem = binarysearch(space);

		if (tem != nullptr)
		{
			printonecar(tem);
			cout << "请输入新的车位号：" << endl;
			cin >> space;
			tem->setcarspace(space);
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "查无车辆！" << endl;
			return;
		}
	}
	else if (choose == 0)
	{
		cout << "退出修改!" << endl;
		return;
	}
	else
		cout << "输入错误！" << endl;
}

void Manager::sort()
{
	system("cls");
	cout << "***************************\n";
	cout << "**     排序车辆信息      **\n";
	cout << "**     1.车位号排序      **\n";
	cout << "**     2.入场时间排序    **\n";
	cout << "**     3.车牌号排序      **\n";
	cout << "**     0.退出修改        **\n";
	cout << "***************************\n";

	int choose;
	cout << "请输入相应的功能序号：";
	cin >> choose;

	switch (choose)
	{
	case 1:
		bininsertsort();
		cout << "排序后的车场信息如下: " << endl;
		parkinginfo();
		break;
	case 2:
		heapsort();
		cout << "排序后的车场信息如下: " << endl;
		parkinginfo();
		break;
	case 3:
		cout << "排序后的车场信息如下: " << endl;
		parkinginfo();
		break;
	case 0:
		cout << "退出排序！" << endl;
		break;
	default:
		cout << "输入错误！" << endl;
		break;
	}
}