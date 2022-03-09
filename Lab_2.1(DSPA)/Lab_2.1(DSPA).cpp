#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

#define MAX_SIZE 5


int ListSize = 0;
int Array_based_list[MAX_SIZE];
int current = 0;

bool isFull()
{
	if (ListSize >= MAX_SIZE)
		return true;
	else
		return false;
}
bool isEmpty()
{
	if (ListSize == 0)
		return true;
	else
		return false;
}
void AddElementBefore(int index)
{
	if (index > 4 || index < 0)
	{
		std::cout << "Ошибка ввода!" << std::endl;
		return;
	}
	if (isFull())
	{
		cout << "Массив заполнен!" << endl;
		return;
	}
	if (isEmpty())
	{
		Array_based_list[0] = rand() % 101;
		ListSize++;
		return;
	}

	current = index;

	for (int i = MAX_SIZE-1; i != current; i--)
	{
		Array_based_list[i] = Array_based_list[i-1];
	}	
	Array_based_list[index] = rand() % 101;
	ListSize++;
	
}
void AddElementAfter(int index)
{
	if (index > 4 || index < 0)
	{
		std::cout << "Ошибка ввода!" << std::endl;
		return;
	}
	if (isFull())
	{
		cout << "Массив заполнен!" << endl;
		return;
	}
	if (isEmpty())
	{
		Array_based_list[0] = rand() % 101;
		ListSize++;
		return;
	}
	current = index;
	for (int i = MAX_SIZE - 1; i != current+1; i--)
	{
		Array_based_list[i] = Array_based_list[i-1];
	}
	Array_based_list[index+1] = rand() % 101;
	ListSize++;	
}

void Pop(int index)
{
	if (index > 4 || index < 0)
	{
		std::cout << "Ошибка ввода!" << std::endl;
		return;
	}
	if (isEmpty())
	{
		std::cout << "Лист пуст!" << std::endl;
		return;
	}
	current = index;
	Array_based_list[index] = NULL;
	
	for (int i = current; i < MAX_SIZE; i++)
	{
		Array_based_list[i] = Array_based_list[i + 1];
	}
	ListSize--;
	for (int i = MAX_SIZE-1; i >= ListSize; i--)
	{
		Array_based_list[i] = NULL;
	}
}
void ShowList()
{
	for (int i = 0; i < ListSize; i++)
	{
		std::cout << Array_based_list[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{	
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	char choice;
	int index;
	while (true)
	{
		std::cout << "Введите, что вы хотите сделать:\n"<<
		"1)Добавить перед\n2)Добавить после\n3)Удалить" << std::endl;
		while ((!(std::cin >> choice) || (std::cin.peek() != '\n')))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "ошибка!" << std::endl;
		}
		std::cout << "Введите индекс" << std::endl;

		while ((!(std::cin >> index) || (std::cin.peek() != '\n')))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "ошибка!" << std::endl;
		}
		if (choice == '1')
		{
			AddElementBefore(index);
			ShowList();
		}
		else if (choice == '2')
		{
			AddElementAfter(index);
			ShowList();
		}
		else if (choice == '3')
		{
			Pop(index);
			ShowList();
		}
		else
			break;
	}	
	return 0;
}