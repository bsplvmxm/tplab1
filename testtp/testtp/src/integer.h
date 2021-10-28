#pragma once

#include "bus.h"
#include "garage.h"
#include "car.h"
#include "moto.h"
#include "keeper.h"
#include <iostream>
using std::cout;
using std::cin;

short num;

bool check_input()
{
	if (!cin.good())
	{
		cout << "����������� ������� ������, ���������� ��� ���" << endl;
		system("pause");
		cin.clear();
		while (cin.get() != '\n');
		return false;
	}
	return true;
}

void menu()
{
	while (1)
	{
		system("cls");
		cout << "�������� �����:" << endl << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ��������� ������ � ����" << endl;
		cout << "4. ��������� ������ �� �����" << endl;
		cout << "5. ������� ������" << endl;
		cout << "0. �����" << endl;
		cout << "������� ����� ������: ";
		cin >> num;
		if (!check_input())
			continue;
		break;
	}
}

void dop_menu(Keeper* keeper)
{
	short num2;
	while (1)
	{
		system("cls");
		cout << "�������� ������ ��� ����������:" << endl;
		cout << "1. ����������" << endl;
		cout << "2. ��������" << endl;
		cout << "3. �������" << endl;
		cout << "4. �����" << endl;
		cout << "������� ����� ������: ";
		cin >> num2;
		if (!check_input())
			continue;
		switch (num2)
		{
		case 1:
		{
			garage* obj = new cars;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 2:
		{
			garage* obj = new motos;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 3:
		{
			garage* obj = new buses;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "������ �������� ����� ����, ���������� ��� ���" << endl;
			system("cls");
			continue;
		}
		}
		break;
	}
}

void LoadData()
{
	Keeper* keeper = new Keeper;
	while (1)
	{
		menu();
		switch (num)
		{
		case 1:
		{
			dop_menu(keeper);
			continue;
		}
		case 2:
		{
			if (!(keeper->pop()))
			{
				cout << "������ �������� ��������, ������� �����" << endl;
				system("pause");
			}
			continue;
		}
		case 3:
		{
			system("cls");
			int ans;
			if (keeper->get_size() == 0)
			{
				cout << "������� �����, ������ � ���� ����������" << endl;
				system("pause");
				continue;
			}
			cout << "�������� � ����(1) ��� ������������ ������(2)?" << endl;
			cin >> ans;
			if (!check_input())
			{
				cout << "������ ������� �������, ���������� ��� ���" << endl;
				system("pause");
				continue;
			}
			switch (ans)
			{
			case 1:
			{
				if (keeper->save_all())
				{
					cout << "���������" << endl;
					system("pause");
				}
				break;
			}
			case 2:
			{
				if (remove("garage.txt") != 0)
					cout << "������ ���������� ������";
				else
				{
					if (keeper->save_all())
						cout << "���������" << endl;
				}
				system("pause");
				break;
			}
			default:
			{
				cout << "error 404 :)" << endl;
				system("pause");
				break;
			}
			}
			continue;
		}
		case 4:
		{
			if ((keeper->recover_all()) != -1)
				cout << "�������������� ������ �������" << endl;
			else
				cout << "���� ����" << endl;
			system("pause");
			continue;
		}
		case 5:
		{
			system("cls");
			keeper->show();
			system("pause");
			continue;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "������ �������� ����� ����, ���������� ��� ���" << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}