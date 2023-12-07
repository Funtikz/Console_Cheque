#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>

struct Menu {
	std::string name;
	double cost;
	int amount;
	Menu(std::string name,  double cost, int amount) : name(name),  cost(cost), amount(amount) {}
};


void PrintMenu(const std::vector<Menu> menu) {
	double Sum = 0;
	std::cout << "Блюдо"<< std::setw(35)<<"Цена"<< std::setw(30) << "Количество" << std::setw(31) << "Сумма\n";
	for (size_t i = 0; i != menu.size(); ++i) {
		std::cout << i + 1 << ". " << menu[i].name << std::setw(37-menu[i].name.size()) << menu[i].cost << std::setw(27) << menu[i].amount << std::setw(33) << menu[i].cost * menu[i].amount << "\n";
		Sum += menu[i].cost * menu[i].amount;
	}
	
	std::cout << "\nИТОГ:" << std::setw(95) << Sum << std::endl;
}



void AddDish(std::vector<Menu> &menu) {
	std::string name;
	double cost;
	int amount;
	std::cin.clear();
	std::cin.ignore();
	std::cout << "Введите название блюда: ";
	std::getline(std::cin, name);
	std::cout << "Введите цену: ";
	std::cin>>cost;
	std::cout << "Введите количество: ";
	std::cin >> amount;
	std::cout << "Блюдо успешно добавлено!\n";
	menu.push_back(Menu(name, cost, amount));
}


void DeleteDish(std::vector<Menu>& menu) {
	std::cin.clear();
	std::cin.ignore();
	std::string name1;
	std::cout << "Введите название блюда: ";
	std::getline(std::cin, name1);
	for (auto it = menu.begin(); it != menu.end(); ++it) {
		if (it->name == name1) {
			menu.erase(it);
			std::cout << "Блюдо успешно удалено!\n";
			return;
		}
		else if (it == menu.end()) {
			std::cout << "Такого блюда нет! Или ошибка в названии\n";
			return;
		}
	}

}


void ChangeDish(std::vector<Menu>& menu) {
	std::string name1;
	std::cout << "Введите название блюда: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, name1);

	auto it = std::find_if(menu.begin(), menu.end(), [&name1](const Menu& dish) {
		return dish.name == name1;
		});

	if (it != menu.end()) {
		std::cout << "Блюдо успешно найдено!\n";

		int value;
		do {
			std::cout << "1 - изменить имя\n" << "2 - изменить цену\n" << "3 - изменить количество\n" << "0 - выход\n";
			std::cin >> value;

			switch (value) {
			case 1: {
				std::string name2;
				std::cout << "Введите новое имя\n";
				std::cin.clear();
				std::cin.ignore();
				std::getline(std::cin, name2);
				it->name = name2;
				std::cout << "Имя успешно изменено\n";
				break;
			}
			case 2: {
				double cost2;
				std::cout << "Введите новую цену\n";
				std::cin >> cost2;
				it->cost = cost2;
				std::cout << "Цена успешно изменена\n";
				break;
			}
			case 3: {
				int amount2;
				std::cout << "Введите новое количество \n";
				std::cin >> amount2;
				it->amount = amount2;
				std::cout << "Количество успешно изменено\n";
				break;
			}
			}
		} while (value != 0);
	}
	else {
		std::cout << "Такого блюда не найдено или ошибка в названии\n";
	}
}




void PrintMainMenu() {
	std::cout << "1. Добавление товара в меню\n";
	std::cout << "2. Удаление товара из меню\n";
	std::cout << "3. Изменение товара из меню\n";
	std::cout << "0. Выход\n";
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RU");
	std::vector<Menu> menu;
	int value;
	do
	{
		system("cls");
		PrintMainMenu();
		std::cout << "\n";
		PrintMenu(menu);
		std::cin >> value;
		switch (value) {
		case 1: 
		{
			AddDish(menu);
			break;
		}
		case 2: {
			DeleteDish(menu);
			break;
		}
		case 3: {
			ChangeDish(menu);
			break;
		}
		}
		

	} while (value != 0);
}