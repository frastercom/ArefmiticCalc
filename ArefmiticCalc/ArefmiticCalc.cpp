#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> p;

void math()
{
    for (int i = 0; i<p.size(); i++) // пробегаем по элементам вектора, ищем приоритетное действие
    {
        if (p.at(i).compare("*") == 0) //если нашли знак умножения
        {
            string s1 = p.at(i - 1); //необходимо для преоброзования типа
            string s2 = p.at(i + 1); //необходимо для преоброзования типа
            double p1 = atof(s1.c_str()); //необходимо для преоброзования типа
            double p2 = atof(s2.c_str()); //необходимо для преоброзования типа
            double mul = p1 * p2; //выполнение математической операции
            string ms = to_string(mul); //необходимо для преоброзования типа
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.insert(p.begin() + i - 1, ms); //вставка результата в вектор
            p.erase(p.begin() + i); //удаление элемента по индексу в векторе
            return;
        }
    }
    for (int i = 0; i < p.size(); i++) // пробегаем по элементам вектора, ищем приоритетное действие
    {
        if (p.at(i).compare("/") == 0) //если нашли знак деления
        {
            string s1 = p.at(i - 1); //необходимо для преоброзования типа
            string s2 = p.at(i + 1); //необходимо для преоброзования типа
            double p1 = atof(s1.c_str()); //необходимо для преоброзования типа
            double p2 = atof(s2.c_str()); //необходимо для преоброзования типа
            double mul = p1 / p2; //выполнение математической операции
            string ms = to_string(mul); //необходимо для преоброзования типа
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.insert(p.begin() + i - 1, ms); //вставка результата в вектор
            p.erase(p.begin() + i); //удаление элемента по индексу в векторе
            return;
        }
    }
    for (int i = 0; i < p.size(); i++) // пробегаем по элементам вектора, ищем приоритетное действие
    {
        if (p.at(i).compare("+") == 0) //если нашли знак сложения
        {
            string s1 = p.at(i - 1); //необходимо для преоброзования типа
            string s2 = p.at(i + 1); //необходимо для преоброзования типа
            double p1 = atof(s1.c_str()); //необходимо для преоброзования типа
            double p2 = atof(s2.c_str()); //необходимо для преоброзования типа
            double mul = p1 + p2; //выполнение математической операции
            string ms = to_string(mul); //необходимо для преоброзования типа
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.insert(p.begin() + i - 1, ms); //вставка результата в вектор
            p.erase(p.begin() + i); //удаление элемента по индексу в векторе
            return;
        }
    }
    for (int i = 0; i < p.size(); i++) // пробегаем по элементам вектора, ищем приоритетное действие
    {
        if (p.at(i).compare("-") == 0) //если нашли знак вычитания
        {
            string s1 = p.at(i - 1); //необходимо для преоброзования типа
            string s2 = p.at(i + 1); //необходимо для преоброзования типа
            double p1 = atof(s1.c_str()); //необходимо для преоброзования типа
            double p2 = atof(s2.c_str()); //необходимо для преоброзования типа
            double mul = p1 - p2; //выполнение математической операции
            string ms = to_string(mul); //необходимо для преоброзования типа
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.erase(p.begin() + i - 1); //удаление элемента по индексу в векторе
            p.insert(p.begin() + i - 1, ms); //вставка результата в вектор
            p.erase(p.begin() + i); //удаление элемента по индексу в векторе
            return;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("c:\\1.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        string s;
        while (in >> s)
        {
            p.push_back(s);
        }
    }
    in.close();
    while (p.size()>1) // цикл пока не закончаться все математические операции
        math();

    cout << "Ответ: " << p.at(0);
}