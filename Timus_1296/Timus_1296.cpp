// Timus_1296.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    vector<int> data;


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
    if (!data.empty() && data.front() <= 0)
        data.erase(data.begin());


    /*cout << endl;
    for (auto c : data)
    {
        cout << c << " ";
    }*/

    int max_sum = 0;

    for (size_t i = 0; i < data.size(); i += 2)
    {
        int local_sum = data[i];
        if (local_sum > max_sum)
            max_sum = local_sum;
        for (size_t j = i + 1; j < data.size(); j++)
        {
            local_sum += data[j];
            if (local_sum > max_sum)
                max_sum = local_sum;
        }
    }

    /*cout << endl;
    for (auto c : data)
    {
        cout << c << " ";
    }*/

    cout << max_sum << endl;


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
