#include"car.h"

void drawmenu()
{
	cout << "***********************************\n";
	cout << "**         ͣ��������ϵͳ        **\n";
	cout << "***********************************\n";
	cout << "**       ��ѡ������Ҫ�Ĳ���      **\n";
	cout << "*        1.�鿴ͣ�����������     *\n";
	cout << "*        2.����ͣ����             *\n";
	cout << "*        3.�뿪ͣ����             *\n";
	cout << "*        0.�˳�ͣ����ϵͳ         *\n";
	cout << "***********************************\n";
}

void Manager::parkinginfo()
{
	if (p->length == 0)
		cout << "ͣ�������޳�����" << endl;

	cout << "********ͣ�����ڳ�����Ϣ********\n\n";

	cout << "��λ��" << "	" << "���ƺ�" << "		" << "����ʱ��" << endl;
	for (int i = 0; i < p->length; i++)
	{
		cout << i + 1 << "	" << p->parkinglot[i]->getNumber() << "	"
			<< p->parkinglot[i]->getAtime() << endl;
	}
}