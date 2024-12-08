//1)	Ввод массива структур;
//2)	Сортировка массива структур по алфавиту по первому полю (название фильма)
//3)	Поиск в массиве структур по заданному параметру;
//4)	Изменение заданной структуры;
//5)	Удаление структуры из массива;
//6)	Вывод на экран массива структур;
//7)	Выход.
/*-------------------------------------------------------------------------------*/
//15.	Структура «Кинотеатр»: название кинофильма; 
//		сеанс; стоимость билета; количество зрителей.

//поиск по двум по букве и по полю

#include <iostream>      
#include <stdio.h>                      
#include <string.h>
#include <windows.h>
using namespace std;

int n = 0, i,j;
struct Film
{
	char title[100];
	float session;
	float price;
	int viewers_num;
};
struct Film films[20];

void in()
{
	if (n <= 20)
	{
		cout << "\nЗапіс нумар " << n + 1;

		cout << "\nНазва фільма: ";
		cin >> films[n].title;
		//getchar();

		cout << "\nПрацягласць сеансу (гадзін): ";
		cin >> films[n].session;
		//getchar();

		cout << "\nКошт квітка (рублёў): ";
		cin >> films[n].price;
		//getchar();

		cout << "\nКолькасць гледачоў: ";
		cin >> films[n].viewers_num;
		//getchar();

		n++;
	}
	else
	{
		cout << "\nНяма месца! Выдаліце нешта.";
	}
} 
void sort()
{
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((strcoll(films[i].title, films[j].title)) > 0)
			{
				Film temp = films[i];
				films[i] = films[j];
				films[j] = temp;
			} 
		}
	}
	cout << "Адсартыравана па назвах фільма у алфавітным парадку!" << endl;
}
void find()
{
	int k = 0;
	cout << "Нумар фільма, які Вы хочаце знайсці > ";
	cin >> k;
	if (k < 1 || k > n)
	{
		cout << "Фільма з такім нумарам няма!" << endl;
	}
	else
	{
		cout << "-----------------------------------" << endl;
		cout << "Фільм " << k << endl;
		cout << "Назва             : " << films[k-1].title << endl;
		cout << "Працягласць       : " << films[k - 1].session << " гадзін" << endl;
		cout << "Кошт              : " << films[k - 1].price << " рублёў" << endl;
		cout << "Колькасць гледачоў: " << films[k - 1].viewers_num << " чалавек" << endl;
		cout << "-----------------------------------" << endl;
	}
}
void change()
{
	if (n == 0)
	{
		cout << "Памылка: няма запісаў." << endl;
	}
	else
	{
		int k = 0;
		cout << "Нумар фільма, які Вы хочаце змяніць > ";
		cin >> k;
		if (k < 1 || k > n)
		{
			cout << "Фільма з такім нумарам няма!" << endl;
		}
		else
		{
			cout << "\nЗапіс нумар " << k;

			cout << "\nНазва фільма: ";
			cin >> films[k - 1].title;

			cout << "\nПрацягласць сеансу (гадзін): ";
			cin >> films[k - 1].session;

			cout << "\nКошт квітка (рублёў): ";
			cin >> films[k - 1].price;

			cout << "\nКолькасць гледачоў: ";
			cin >> films[k - 1].viewers_num;

			cout << "\nАдрэгавана!";
		}
	}
	
}
void del()
{
	if (n == 0)
	{
		cout << "Памылка: няма запісаў." << endl;
	}
	else
	{
		int k = 0;
		cout << "Нумар фільма, які Вы хочаце выдаліць > ";
		cin >> k;
		if (k < 1 || k > n)
		{
			cout << "Фільма з такім нумарам няма!" << endl;
		}
		else
		{
			for (i = (k - 1); i < n; i++)
			{
				films[i] = films[i + 1];
			}
			n--;
		}
		cout << "Фільм выдалены!" << endl;
	}
	
}
void out()
{
	if (n == 0)
	{
		cout << "Памылка: няма запісаў." << endl;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			cout << "-----------------------------------" << endl;
			cout << "Фільм " << i + 1 << endl;
			cout << "Назва             : " << films[i].title << endl;
			cout << "Працягласць       : " << films[i].session << " гадзін" << endl;
			cout << "Кошт              : " << films[i].price << " рублёў" << endl;
			cout << "Колькасць гледачоў: " << films[i].viewers_num << " чалавек" << endl;
			cout << "-----------------------------------" << endl;

		}
	}
	
}
void find2()
{
	if (n == 0)
	{
		cout << "Памылка: няма запісаў." << endl;
	}
	else
	{
		bool hasFound = false;
		char b;
		cout << "Сімвал, па якім будзем шукаць:\n> ";
		cin >> b;

		int viewers;
		cout << "Колькасць гледачоў:\n> ";
		cin >> viewers;

		for (i = 0; i < n; i++)
		{

			if ((films[i].title[0] == b) && (films[i].viewers_num == viewers))
			{
				cout << "Found" << endl;
				cout << "-----------------------------------" << endl;
				cout << "Фільм " << i + 1 << endl;
				cout << "Назва             : " << films[i].title << endl;
				cout << "Працягласць       : " << films[i].session << " гадзін" << endl;
				cout << "Кошт              : " << films[i].price << " рублёў" << endl;
				cout << "Колькасць гледачоў: " << films[i].viewers_num << " чалавек" << endl;
				cout << "-----------------------------------" << endl;
				hasFound = true;
			}
			if (!hasFound)
			{
				cout << "Па дадзеных параметрах нічога не знайшлося :(\n" << endl;
			}

		}
	}
	
}
void main()
{
	int choice = 0;
	cout << "Прывітанне!" << endl;
	while (choice != 7)
	{
		printf("\n1 - увесці\n2 - адсартыраваць\n3 - знайсці\n4 - змяніць\n5 - выдаліць\n6 - адлюстраваць\n7 - выйсці\n8 - дад. заданне");
		printf("\nВы абралі > ");
		//scanf_s("%d", choice);
		cin >> choice;
		switch (choice)
		{
		case 1:
			 in();
			break;
		case 2:
			sort();
			break;
		case 3:
			find();
			break;
		case 4:
			change();
			break;
		case 5:
			del();
			break;
		case 6:
			out();
			break;

		case 7:
			cout << "Завяршэнне праграмы.";
			break;
		case 8:
			find2();
			break;
		default:
			cout << "\nПамылка ўводу!";
			break;
		}
	}
}