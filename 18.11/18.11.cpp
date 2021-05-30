#include <iostream>
#include <iterator>
#include <list>
#include "List.h"
#include "Pair.h"
#include <queue>
#include "Pair.cpp"
using namespace std;

// === PRINT ===
template<typename T>
void Print(list<T> l)
{
    typename list<T>::iterator i = l.begin();
    for (; i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T>
void Print(List<T> l)
{
    for (int i = 0; i < l.Size(); i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Print(priority_queue<T> qu)
{
    cout << "Вывод очереди с конца" << endl;
    for (int i = qu.size(); i > 0; i--)
    {
        cout << qu.top() << " ";
        qu.pop();
    }
    cout << endl;
}

// === OTHER METHODS ===
template<typename T>
priority_queue<T> DeleteRange(priority_queue<T> qu, double key, int a, int b)
{
    priority_queue<T> res;
    for (int i = qu.size() - 1; i >= 0; i--)
    {
        // transfer element if its situated between a and b and equal key
        if (i < a || i > b || qu.top() != key) res.push(qu.top());
        qu.pop();
    }
    return res;
}

template<typename T>
T GetSum(priority_queue<T> qu)
{
    T sum = qu.top();
    for (int i = qu.size() - 1; i > 0; i--)
        qu.pop();
    sum += qu.top();
    return sum;
}

template<typename T>
priority_queue<T> AddToAllElements(priority_queue<T> qu, T inc)
{
    priority_queue<T> res;
    for (int i = qu.size() - 1; i >= 0; i--)
    {
        res.push(qu.top() + inc);
        qu.pop();
    }
    return res;
}

// === TASKS ===
void Task1()
{
    cout << endl << "Task 1" << endl;
    list<double> l;

    for (int i = 0; i < 10; i++)
        l.push_back(rand() % 10000 / 100.0);

    Print(l);
}

void Task2()
{
    cout << endl << "Task 2" << endl;
    list<Pair> l;

    for (int i = 0; i < 10; i++)
        l.push_back(Pair());

    Print(l);
}

void Task3()
{
    cout << endl << "Task 3" << endl;
    List<double> l;

    for (int i = 0; i < 10; i++)
        l.Insert(rand() % 10000 / 100.0, i);

    Print(l);
    cout << l.Average() << endl;
}

void Task4()
{
    cout << endl << "Task 4" << endl;
    priority_queue<double> qu;

    for (int i = 0; i < 10; i++)
        qu.push(rand() % 10000 / 100.0);

    Print(qu);

    int a = -1, b = -1;
    while (a < 0 || a > 10)
    {
        cout << "Введите начало диапазона ";
        cin >> a;
    }

    while (b < 0 || b < a)
    {
        cout << "Введите конец диапазона ";
        cin >> b;
    }

    double key;
    cout << "Введите ключ ";
    cin >> key;

    qu = DeleteRange(qu, key, a, b);

    Print(qu);
}

void Task5()
{
    cout << endl << "Task 5" << endl;
    priority_queue<double> qu;

    for (int i = 0; i < 10; i++)
        qu.push(rand() % 10000 / 100.0);

    Print(qu);

    qu = AddToAllElements(qu, GetSum(qu));

    Print(qu);
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
}