#include <iostream>      
#include <stdio.h>                      
#include <string.h>
#include <windows.h>
using namespace std;

struct sklad  //объявляем шаблон структуры
{
    char name[30];      //Наименование
    char ed[5];         //Единица измерения 
    float cena;         //Цена
    int kol;            //Количество
    int date;           //Дата последнего завоза
    int type;           //тип накладной (приход или отгрузка)
};
struct sklad mas[30]; //объвляем глобальный массив структур
struct sklad tmp; //объявляем временую переменную структ. типа
int sch = 0;        //Счетчик полных записей
int er;           //Переключатель

void enter_new(); //Прототипы функций
int menu();
void out();
void del();
void change();
void find();

int main()
{
    //setlocale(LC_ALL, "Russian");
    while (1)
    {
        switch (menu())
        {
        case 1: del(); break;
        case 2: enter_new(); break;
        case 3: change(); break;
        case 4: out(); break;
        case 5: find(); break;
        case 6: return 0;
        default: cout << "Неверный выбор/n";
        }
    }
}

void enter_new()  //ф-ция ввода новой структуры
{
    if (sch < 30) //вводим новую запись только, если счетчик полных 
        //записей меньше максимального количества записей
    {
        cout << "Запись номер" << sch + 1; //выводим номер записи
        cout << "\nВыберите тип накладной (1 - приход, 2 - отгрузка)\n";
        cin >> mas[sch].type;
        cout << "\nВведите наименование\n";
        cin >> mas[sch].name;
        cout << "Введите ед.измерения \n";
        cin >> mas[sch].ed;
        cout << "Введите цену\n";
        cin >> mas[sch].cena;
        cout << "Введите кол-во\n";
        cin >> mas[sch].kol;
        cout << "Введите дату последнего поступления\n";
        cin >> mas[sch].date;
        sch++; //увеличиваем счетчик полных записей на единицу
    }
    else
        cout << "Введено максимальное кол-во записей";
}

int menu()
{
    int er;
    cout << "Введите:\n";
    cout << "1-для удаления записи\n";
    cout << "2-для ввода новой записи\n";
    cout << "3-для изменения записи\n";
    cout << "4-для вывода записи(ей)\n";
    cout << "5-для поиска \n";
    cout << "6-для выхода\n";
    cin >> er;
    return er;
}

void out()  //ф-ция вывода записей
{
    int sw; //переключатель для выбора: выводить все записи или одну
    int k;  //номер структуры, кот. надо вывести
    if (sch == 0) //если счетчик количества структур равен 0, то 
        //выводим сообщение, что нет записей
        cout << "\nНет записей: \n";
    else
    {
        cout << "\nВведите: \n";
        cout << "1-если хотите вывести какую-либо запись\n";
        cout << "2-если хотите вывести все записи\n";
        cin >> sw;
        if (sw == 1)
        {
            cout << "Введите номер записи, которую нужно вывести\n";
            cin >> k;
            cout << endl;
            if (mas[k - 1].type == 1)
                cout << "Приход" << endl;
            else
                cout << "Отгрузка" << endl;
            cout << "Наименование:" << mas[k - 1].name << endl;
            cout << "Ед.измер.:" << mas[k - 1].ed << endl;
            cout << "Цена:" << mas[k - 1].cena << endl;
            cout << "Кол-во:" << mas[k - 1].kol << endl;
            cout << "Дата:" << mas[k - 1].date << endl;
            cout << "____________" << endl;
        }
        if (sw == 2)
        {
            for (int i = 0;i < sch;i++) //выводим в цикле все записи
            {
                if (mas[i].type == 1)
                    cout << "Приход" << endl;
                else
                    cout << "Отгрузка" << endl;
                cout << "Наименование:" << mas[i].name << endl;
                //выводим на экран значение name i-ой структуры 
                cout << "Ед.измер.:" << mas[i].ed << endl;
                cout << "Цена:" << mas[i].cena << endl;
                cout << "Кол-во:" << mas[i].kol << endl;
                cout << "Дата:" << mas[i].date << endl;
                cout << "____________" << endl;
            }
        }
    }
}

void del() //ф-ция удаления записи
{
    int d;  //номер записи, которую нужно удалить
    cout << "\nВведите номер записи, которую необходимо удалить\n";
    cout << "Если необходимо удалить все записи,нажмите '99'\n";
    cin >> d;
    if (d != 99)
    {
        for (int i = (d - 1);i < sch;i++) //цикл для удаления заданной 
            //записи, начинаем цикл с удаляемой записи
            mas[i] = mas[i + 1]; //замещаем текущую запись следующей за 
        //ней
        sch = sch - 1; //уменьшаем счетчик полных записей на 1
    }
    if (d == 99)
    {
        for (int i = 0;i < 30;i++) //цикл по всем зап. от первой до 30-ой
            mas[i] = tmp; //замещаем каждую структуру в массиве пустой 
        //структурой
        sch = 0; //счетчик структур обнуляем, т.к. все записи удалены
    }
}

void change() //функция для изменения записи
{
    int c; //номер записи, которую нужно изменить
    int per;
    cout << "\nВведите номер записи\n";
    cin >> c;
    do
    {
        cout << "Введите: \n";
        cout << "1-для изменения типа накладной\n";
        cout << "2-для изменения наименования\n";
        cout << "3-для изменения ед.измерения\n";
        cout << "4-для изменения цены\n";
        cout << "5-для изменения количества\n";
        cout << "6-для изменения даты\n";
        cout << "7-для прекращения\n";
        cin >> per;
        switch (per)
        {
        case 1: cout << "\nВведите новый тип накладной (1 - приход, 2 - отгрузка)\n";
            cin >> mas[c - 1].type; break;
        case 2: cout << "\nВведите новое наименование\n";
            cin >> mas[c - 1].name; break;
        case 3: cout << "Введите новые ед.измерения \n";
            cin >> mas[c - 1].ed; break;
        case 4: cout << "Введите новую цену\n";
            cin >> mas[c - 1].cena; break;
        case 5: cout << "Введите новое кол-во\n";
            cin >> mas[c - 1].kol; break;
        case 6: cout << "Введите новую дату последнего поступления\n";
            cin >> mas[c - 1].date; break;
        case 7: return;
        }
    } while (1);
}

void find()  //ф-ция поиска записей
{
    int sw;     // переключатель
    if (sch == 0)
        cout << "\nНет запиcей: \n";
    else
    {
        cout << "\nВведите: \n";
        cout << "1-все накладные прихода\n";
        cout << "2-все накладные отгрузки\n";
        cin >> sw;
        for (int i = 0;i < sch;i++) //в цикле просматриваем все структуры 
            //из массива структур
            if (mas[i].type == sw)
            {
                if (mas[i].type == 1)
                    cout << "Приход" << endl;
                else
                    cout << "Отгрузка" << endl;
                cout << "Наименование:" << mas[i].name << endl;
                cout << "Ед.измер.:" << mas[i].ed << endl;
                cout << "Цена:" << mas[i].cena << endl;
                cout << "Кол-во:" << mas[i].kol << endl;
                cout << "Дата:" << mas[i].date << endl;
                cout << "____________" << endl;
            }
    }
}


