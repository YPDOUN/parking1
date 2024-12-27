#include"car.h"

int main()
{
	char input = 1;
	do {
		draw();
		cout << "ÇëÊäÈëĞòºÅ£º";
		cin >> input;
		switch (input)
		{
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		default:cout << "ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë£¡\n";
		}
	} while (input!='0');

	cin.get();
	parkinglot *p;
	sideway* s;
	initparkinglot(p);
	initsideway(s);

    arrive(p, s, "ÔÁA123456", "12:50", "16:30");
	arrive(p, s, "ÔÁA888888", "11:58", "16:30");
	arrive(p, s, "ÔÁA888888", "11:58", "16:30");
	arrive(p, s, "ÔÁA888888", "11:58", "16:30");

	sqfindcar(p, "ÔÁA123456");

	depart(p, 1);
    savecarinfo(p);

	cin.get();
}