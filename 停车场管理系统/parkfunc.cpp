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
	cout << "�����������ĳ��ƺźͳ�λ�ţ�";
	cin >> carnumber >> space;

	if (emptyspace[space] == -1)
	{
		cout << "�ó�λ�����Ѿ��г���" << endl;
		return;
	}

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);

		cout << "ͣ������������������:" << carnumber << "�ѽ�������\n";
		return;
	}
	else
	{
		p->parkinglot[p->length] = new car(carnumber, space);
		emptyspace[space] = -1;
		p->length++;
		cout << "����:" << carnumber << "�ѽ���ͣ������" << space << "�ų�λ��\n";
	}

	savecarinfo(append);
}

void Manager::depart()
{
	system("cls");
	int space;

	parkinginfo();
	cout << "��������뿪�����ĳ�λ�ţ�";
	cin >> space;

	if (space < 1 || space > p->length)
	{
		cout << space << "�ų�λ��û�г�����";
		return;
	}

	for(int i = 0; i < p->length; i++)
	{
		if (p->parkinglot[i]->getSpace() == space)
		{
			car* q = p->parkinglot[i];
			q->Getdeparttime();
			cout << q->getNumber() << "���뿪ͣ����, ����Ϊ��" << q->getAmount() << endl;
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
			cout << space << "�ų�λ��û�г�����" << endl;
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

		cout << "ͣ�����п�λ������е�" << temcar->getNumber()
			<< "�ѽ���ͣ������" << endl;
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
	cout << "**     ��ѯ����������Ϣ  **\n";
	cout << "**     1.���ƺŲ�ѯ      **\n";
	cout << "**     2.��λ�Ų�ѯ      **\n";
	cout << "**     0.�˳���ѯ        **\n";
	cout << "***************************\n";

	int choose, space;
	string carnum;

	cout << "�����빦�����: ";
	cin >> choose;

	if (choose == 1)
	{
		cout << "�����복�ƺţ�";
		cin >> carnum;

		car* tem = sqfindcar(carnum);
		if (tem != nullptr)
			printonecar(tem);
		else
		{
			cout << "���޴˳�����" << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "�����복λ�ţ�";
		cin >> space;

		car* tem = binarysearch(space);
		if (tem != nullptr)
			printonecar(tem);
		else
		{
			cout << "���޴˳�����" << endl;
		}
	}
	else if (choose == 0)
	{
		cout << "�˳���ѯ!" << endl;
		return;
	}
	else
		cout << "�������" << endl;
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
	cout << "**     ��ѯ����������Ϣ  **\n";
	cout << "**     1.���ƺŲ�ѯ�޸�  **\n";
	cout << "**     2.��λ�Ų�ѯ�޸�  **\n";
	cout << "**     0.�˳��޸�        **\n";
	cout << "***************************\n";

	int choose, space;
	string carnum;

	cout << "�����빦����ţ�";
	cin >> choose;

	if (choose == 1)
	{
		cout << "�����복�ƺţ�";
		cin >> carnum;
		car* tem = sqfindcar(carnum);

		if (tem != nullptr)
		{
			printonecar(tem);
			cout << "�������µĳ��ƺţ�" << endl;
			cin >> carnum;
			tem->setcarnum(carnum);
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "���޳�����" << endl;
			return;
		}
	}

	else if (choose == 2)
	{
		cout << "�����복λ�ţ�";
		cin >> space;
		car* tem = binarysearch(space);

		if (tem != nullptr)
		{
			printonecar(tem);
			cout << "�������µĳ�λ�ţ�" << endl;
			cin >> space;
			tem->setcarspace(space);
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "���޳�����" << endl;
			return;
		}
	}
	else if (choose == 0)
	{
		cout << "�˳��޸�!" << endl;
		return;
	}
	else
		cout << "�������" << endl;
}

void Manager::sort()
{
	system("cls");
	cout << "***************************\n";
	cout << "**     ��������Ϣ      **\n";
	cout << "**     1.��λ������      **\n";
	cout << "**     2.�볡ʱ������    **\n";
	cout << "**     3.���ƺ�����      **\n";
	cout << "**     0.�˳��޸�        **\n";
	cout << "***************************\n";

	int choose;
	cout << "��������Ӧ�Ĺ�����ţ�";
	cin >> choose;

	switch (choose)
	{
	case 1:
		bininsertsort();
		cout << "�����ĳ�����Ϣ����: " << endl;
		parkinginfo();
		break;
	case 2:
		heapsort();
		cout << "�����ĳ�����Ϣ����: " << endl;
		parkinginfo();
		break;
	case 3:
		cout << "�����ĳ�����Ϣ����: " << endl;
		parkinginfo();
		break;
	case 0:
		cout << "�˳�����" << endl;
		break;
	default:
		cout << "�������" << endl;
		break;
	}
}