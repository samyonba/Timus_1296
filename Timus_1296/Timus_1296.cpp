// Timus_1296.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    list<int> data;


    int current = 0;
    for (size_t i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (current * value >= 0)
        {
            current += value;
        }
        else
        {
            data.push_back(current);
            current = value;
        }
    }
    if (current > 0)
        data.push_back(current);
    if (data.front() <= 0)
        data.erase(data.begin());


    cout << endl;
    for (auto c : data)
    {
        cout << c << " ";
    }

    auto it = data.begin();
    while (it != data.end())
    {
        if (*it >= 0)
        {

            while (next(it) != data.end() && next(next(it)) != data.end())
            {
                int couple_sum = *next(it) + *next(next(it));

                if (couple_sum < 0)
                    break;

                *it += couple_sum;
                data.erase(next(it), next(next(next(it))));
            }
        }
        it = next(it);
    }

    cout << endl;
    for (auto c : data)
    {
        cout << c << " ";
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
