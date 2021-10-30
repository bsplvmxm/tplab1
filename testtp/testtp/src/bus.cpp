#include "bus.h"
#include <iostream>
#include <cstring>

using namespace std;

void buses::data()
{
	cout << "�����: " << markabus << endl;
	cout << "������: " << modelbus << endl;
	cout << "���-�� ������� ����: " << kolvosid << endl;
	cout << "����� ���-�� ����: " << kolvomest << endl;
	cout << "�������� �����: " << konpunkt << endl;
}

void buses::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ����� ��������: ";
		cin >> markabus;
		if (exception(markabus) == -2)
			continue;
		break;
	}
	while(1)
	{
		system("cls");
		cout << "������� ������ ��������: ";
		cin >> modelbus;
		if (exception(modelbus) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ���-�� ������� ����: ";
		cin >> kolvosid;
		if (exception(kolvosid) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� ���-�� ����: ";
		cin >> kolvomest;
		if (exception(kolvomest) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� ���������� ��������: ";
		cin >> konpunkt;
		if (exception(konpunkt) == -2)
			continue;
		break;
	}
}

void buses::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markabus = line;
			break;
		}
		case 1:
		{
			modelbus = line;
			break;
		}
		case 2:
		{
			kolvosid = line;
			break;
		}
		case 3:
		{
			kolvomest = line;
			break;
		}
		case 4:
		{
			konpunkt = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void buses::save(ofstream& out)
{
	out << 3 << endl;
	out << markabus << endl;
	out << modelbus << endl;
	out << kolvosid << endl;
	out << kolvomest << endl;
	out << konpunkt << endl;
}

buses::buses()
{
	markabus = "�����";
	modelbus = "�����";
	kolvosid = "�����";
	kolvomest = "�����";
	konpunkt = "�����";
}

buses::buses(string mb, string mob, string kos, string kom, string kop)
{
	this->markabus = mb;
	this->modelbus = mob;
	this->kolvosid = kos;
	this->kolvomest = kom;
	this->konpunkt = kop;

}

buses::buses(const buses& Buses) : markabus(Buses.markabus), modelbus(Buses.modelbus), kolvosid(Buses.kolvosid), kolvomest(Buses.kolvomest), konpunkt(Buses.konpunkt) {}

int buses::exception(string line)
{
	try
	{
		if (line.empty())
			throw -2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "������ ���� �� ������ ���� ������" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "error 404" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}

buses::~buses() {}


