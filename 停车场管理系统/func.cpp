#include"car.h"

void Manager::drawmenu()
{
	cout << "****************************************\n";
	cout << "**           ͣ��������ϵͳ           **\n";
	cout << "****************************************\n";
	cout << "**          ��ѡ������Ҫ�Ĳ���        **\n";
	cout << "**          1.�鿴ͣ����������Ϣ      **\n";
	cout << "**          2.����ͣ����              **\n";
	cout << "**          3.�뿪ͣ����              **\n";
	cout << "**          4.�鿴����ڳ�����Ϣ      **\n";
	cout << "**          5.����ͣ����������Ϣ      **\n";
	cout << "**          6.����ͣ����������Ϣ      **\n";
	cout << "**          7.�޸ļƷѵ���            **\n";
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