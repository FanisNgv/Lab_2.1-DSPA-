#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

#define MAX_SIZE 5

int ListSize = 0;
int Array_based_list[MAX_SIZE];
int current = 0;
int random_number;

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

	for (int i = ListSize; i != current; i--)
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
	for (int i = ListSize; i != current+1; i--)
	{
		Array_based_list[i] = Array_based_list[i-1];
	}
	Array_based_list[index+1] = rand() % 101;
	ListSize++;	
}
void AddSortedElement()
{	
	random_number = rand() % 101;

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
	for (int i = 0; i <= ListSize; i++)
	{
		if (Array_based_list[i] > random_number)
		{
			for (int j = ListSize; j > i; j--)
			{
				Array_based_list[j] = Array_based_list[j - 1];
			}
			Array_based_list[i] = random_number;
			ListSize++;
			break;
		}
		if (i == ListSize)
		{
			Array_based_list[ListSize] = random_number;
			ListSize++;
			break;
		}
	}
}
void AddSortedChar()
{
	random_number = rand() % 26+65;

	if (isFull())
	{
		cout << "Массив заполнен!" << endl;
		return;
	}
	if (isEmpty())
	{
		Array_based_list[0] = random_number;
		ListSize++;
		return;
	}
	for (int i = 0; i <= ListSize; i++)
	{
		if (Array_based_list[i] > random_number)
		{
			for (int j = ListSize; j > i; j--)
			{
				Array_based_list[j] = Array_based_list[j - 1];
			}
			Array_based_list[i] = random_number;
			ListSize++;
			break;
		}
		if (i == ListSize)
		{
			Array_based_list[ListSize] = random_number;
			ListSize++;
			break;
		}
	}
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
	
	for (int i = current; i < ListSize-1; i++)
	{
		Array_based_list[i] = Array_based_list[i + 1];
	}
	ListSize--;
}
void ShowList()
{
	for (int i = 0; i < ListSize; i++)
	{
		std::cout << Array_based_list[i] << " ";
	}
	std::cout << std::endl;
}

char chariput()
{
	char iput;
	while ((!(std::cin >> iput) || (std::cin.peek() != '\n')))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "ошибка!" << std::endl;
	}
	return iput;
}
int intiput()
{
	int iput;
	while ((!(std::cin >> iput) || (std::cin.peek() != '\n')))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "ошибка!" << std::endl;
	}
	return iput;
}
int main()
{	
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	char choice;
	int index;
	bool working = true;

	while (working)
	{
		std::cout 
		<< "Введите, что вы хотите сделать:\n"
		<< "1)Добавить перед\n2)Добавить после\n3)Удалить\n"
		<< "4)Добавить с сортировкой"
		<<
		std::endl;

		choice = chariput();

		switch (choice)
		{
		case '1':
			std::cout << "Введите индекс\n";
			index = intiput();
			AddElementBefore(index);
			ShowList();
			break;
		case '2':
			std::cout << "Введите индекс\n";
			index = intiput();
			AddElementAfter(index);
			ShowList();
			break;
		case '3':
			index = intiput();
			Pop(index);
			ShowList();
			break;
		case '4':
			AddSortedElement();
			ShowList();
			break;
		default:
			std::cout << "Работа цикла завершена!\n";
			working = false;
			break;
		}		
	}	
	return 0;
}


//#include <iostream>
//
//using namespace std;
//
//#define MAX_SIZE 5;
//
//struct ArrayList
//{
//    int ListSize;
//    int array[MAX_SIZE];
//};
//
//void InitList(ArrayList*& list)
//{
//    list->ListSize = 0;
//    for (int i = 0; i < MAX_SIZE; i++)
//    {
//        list->array[i] = 0;
//    }
//}
//
//int CheckedInput(int begin, int end) // Ввод целочисленного значения с проверкой
//{
//    int choice;
//    while (true)
//    {
//        cin >> choice;
//        if (cin.fail())
//        {
//            cin.clear();
//            cin.ignore(32767, '\n');
//            cout << "Вводите данные корректно: ";
//            continue;
//        }
//        cin.ignore(32767, '\n');
//        if (choice < begin || choice > end)
//        {
//            cout << "Вводите данные корректно: ";
//            continue;
//        }
//        break;
//    }
//    return choice;
//}
//
//int CheckedInput() // Ввод целочисленного значения с проверкой
//{
//    int choice;
//    while (true)
//    {
//        cin >> choice;
//        if (cin.fail())
//        {
//            cin.clear();
//            cin.ignore(32767, '\n');
//            cout << "Вводите данные корректно: ";
//            continue;
//        }
//        cin.ignore(32767, '\n');
//        break;
//    }
//    return choice;
//}
//
//bool isEmpty(ArrayList*& myList) // проверка списка на пустоту
//{
//    if (myList->ListSize == 0)
//    {
//        return true;
//    }
//    return false;
//}
//
//bool isFull(ArrayList* myList) // проверка списка на полноту
//{
//    if (myList->ListSize == MAX_SIZE)
//    {
//        return true;
//    }
//    return false;
//}
//
//void PrintList(ArrayList* myList) // вывод списка
//{
//    for (int i = 0; i < myList->ListSize; i++)
//    {
//        cout << myList->array[i] << " ";
//    }
//}
//
//int Search(ArrayList* myList, int number) // поиск значения в списке 
//{
//    for (int i = 0; i < (myList->ListSize); i++)
//    {
//        if (myList->array[i] == number)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void Add(ArrayList*& myList, int number) // добавление элемента в упорядоченный список
//{
//    if (isEmpty(myList))
//    {
//        myList->array[0] = number;
//    }
//    else if (number > myList->array[(myList->ListSize) - 1])
//    {
//        myList->array[myList->ListSize] = number;
//    }
//    else
//    {
//        int index = 0;
//        while (index + 1 <= myList->ListSize)
//        {
//            if (number < myList->array[index])
//            {
//                int indToMove = myList->ListSize;
//                while (indToMove > index)
//                {
//                    myList->array[indToMove] = myList->array[indToMove - 1];
//                    indToMove--;
//                }
//                myList->array[index] = number;
//                break;
//            }
//            index++;
//        }
//    }
//    (myList->ListSize)++;
//}
//
//void Delete(ArrayList* myList, int index) // удаление элемента списка по индексу
//{
//    for (int i = index; i < (myList->ListSize) - 1; i++)
//    {
//        myList->array[i] = myList->array[i + 1];
//    }
//    myList->array[(myList->ListSize) - 1] = 0;
//    (myList->ListSize)--;
//}
//
//void CallMenu(ArrayList*& myList) // вызов меню
//{
//    bool work = true;
//    int choice;
//    while (work)
//    {
//        cout << "Выбор действия:\n1 - Вывод списка\n2 - Поиск элемента с заданной информационной частью\n3 - Добавление элемента\n4 - Удаление заданного элемента\n5 - Завершить работу\n";
//        cout << "Действие: "; choice = CheckedInput(1, 5);
//        switch (choice)
//        {
//        case 1:
//            if (isEmpty(myList))
//            {
//                cout << "Список пустой.";
//            }
//            else
//            {
//                cout << "Список: "; PrintList(myList);
//            }
//            cout << "\n\n";
//            break;
//        case 2:
//            int elemsIndex;
//            cout << "Введите информационную часть, индекс которой надо найти: "; elemsIndex = Search(myList, CheckedInput());
//            if (elemsIndex == -1)
//            {
//                cout << "Такого элемента в списке нет.";
//            }
//            else
//            {
//                cout << "Элемент " << elemsIndex << "-ый по списку.";
//            }
//            cout << "\n\n";
//            break;
//        case 3:
//            if (isFull(myList))
//            {
//                cout << "Список заполнен";
//                break;
//            }
//            cout << "Введите число, которое хотите добавить: "; Add(myList, CheckedInput());
//            cout << "\n\n";
//            break;
//        case 4:
//            int indexToDelete;
//            if (isEmpty(myList))
//            {
//                cout << "Список пуст";
//                break;
//            }
//            cout << "Введите индекс: "; indexToDelete = CheckedInput(0, (myList->ListSize) - 1);
//            Delete(myList, indexToDelete);
//            cout << "\n\n";
//            break;
//        case 5:
//            work = false;
//            break;
//        default:
//            break;
//        }
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    ArrayList* myList = new ArrayList;
//    InitList(myList);
//    CallMenu(myList);
//    delete myList;
//    return 0;
//}