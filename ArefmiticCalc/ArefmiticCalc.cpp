#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> p;

void math()
{
    for (int i = 0; i<p.size(); i++)
    {
        if (p.at(i).compare("*") == 0)
        {
            string s1 = p.at(i - 1);
            string s2 = p.at(i + 1);
            double p1 = atof(s1.c_str());
            double p2 = atof(s2.c_str());
            double mul = p1 * p2;
            string ms = to_string(mul);
            p.erase(p.begin() + i - 1);
            p.erase(p.begin() + i - 1);
            p.insert(p.begin() + i - 1, ms);
            p.erase(p.begin() + i);
            return;
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (p.at(i).compare("/") == 0)
        {
            string s1 = p.at(i - 1);
            string s2 = p.at(i + 1);
            double p1 = atof(s1.c_str());
            double p2 = atof(s2.c_str());
            double mul = p1 / p2;
            string ms = to_string(mul);
            p.erase(p.begin() + i - 1);
            p.erase(p.begin() + i - 1);
            p.insert(p.begin() + i - 1, ms);
            p.erase(p.begin() + i);
            return;
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (p.at(i).compare("+") == 0)
        {
            string s1 = p.at(i - 1);
            string s2 = p.at(i + 1);
            double p1 = atof(s1.c_str());
            double p2 = atof(s2.c_str());
            double mul = p1 + p2;
            string ms = to_string(mul);
            p.erase(p.begin() + i - 1);
            p.erase(p.begin() + i - 1);
            p.insert(p.begin() + i - 1, ms);
            p.erase(p.begin() + i);
            return;
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (p.at(i).compare("-") == 0)
        {
            string s1 = p.at(i - 1);
            string s2 = p.at(i + 1);
            double p1 = atof(s1.c_str());
            double p2 = atof(s2.c_str());
            double mul = p1 - p2;
            string ms = to_string(mul);
            p.erase(p.begin() + i - 1);
            p.erase(p.begin() + i - 1);
            p.insert(p.begin() + i - 1, ms);
            p.erase(p.begin() + i);
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
    while (p.size()>1)
        math();

    cout << "Ответ: " << p.at(0);
}