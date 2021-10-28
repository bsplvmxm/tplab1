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
		cout << "Неправильно введены данные, попробуйте еще раз" << endl;
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
		cout << "Выберите пункт:" << endl << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Сохранить данные в файл" << endl;
		cout << "4. Загрузить данные из файла" << endl;
		cout << "5. Вывести данные" << endl;
		cout << "0. Выход" << endl;
		cout << "Введите номер пункта: ";
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
		cout << "Выберите объект для добавления:" << endl;
		cout << "1. Автомобиль" << endl;
		cout << "2. Мотоцикл" << endl;
		cout << "3. Автобус" << endl;
		cout << "4. Выход" << endl;
		cout << "Введите номер пункта: ";
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
			cout << "Выбран неверный пункт меню, попробуйте еще раз" << endl;
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
				cout << "Ошибка удаления элемента, очередь пуста" << endl;
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
				cout << "Очередь пуста, запись в файл невозможна" << endl;
				system("pause");
				continue;
			}
			cout << "Добавить в файл(1) или перезаписать данные(2)?" << endl;
			cin >> ans;
			if (!check_input())
			{
				cout << "Данные введены неверно, попробуйте еще раз" << endl;
				system("pause");
				continue;
			}
			switch (ans)
			{
			case 1:
			{
				if (keeper->save_all())
				{
					cout << "Сохранено" << endl;
					system("pause");
				}
				break;
			}
			case 2:
			{
				if (remove("garage.txt") != 0)
					cout << "Ошибка перезаписи данных";
				else
				{
					if (keeper->save_all())
						cout << "Сохранено" << endl;
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
				cout << "Восстановление прошло успешно" << endl;
			else
				cout << "Файл пуст" << endl;
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
			cout << "Выбран неверный пункт меню, попробуйте еще раз" << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}