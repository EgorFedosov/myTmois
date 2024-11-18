#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n1, n2;
    vector<pair<int, int>> graph1, graph2;
    set<pair<int, int>> uniquePairs1, uniquePairs2; // Для проверки уникальности

    cout << "Введите количество пар в первом графике: ";
    cin >> n1;
    cout << "Введите пары для первого графика (два числа через пробел):" << endl;
    for (int i = 0; i < n1; ++i)
    {
        int u, v;
        cin >> u >> v;
        pair<int, int> p = {u, v};
        if (uniquePairs1.find(p) == uniquePairs1.end()) // find функция проверяет на повторы кортежей Если == то не найдены Если != то найдены
        {
            uniquePairs1.insert(p); // добавляем в сет чтобы учитывать пару при следущей проверке
            graph1.push_back(p);
        }
        else
        {
            cout << "Пара <" << u << ", " << v << "> уже существует. Введите другую пару.\n";
            --i;
        }
    }

    cout << "Введите количество пар во втором графике: ";
    cin >> n2;
    cout << "Введите пары для второго графика (два числа через пробел):" << endl;
    for (int i = 0; i < n2; ++i)
    {
        int u, v;
        cin >> u >> v;
        pair<int, int> p = {u, v};
        if (uniquePairs2.find(p) == uniquePairs2.end())
        {
            uniquePairs2.insert(p);
            graph2.push_back(p);
        }
        else
        {
            cout << "Пара <" << u << ", " << v << "> уже существует. Введите другую пару.\n";
            --i;
        }
    }
    cout << endl;

    cout << "Первый график: ";
    for (size_t i = 0; i < graph1.size(); ++i) // size_t лучше чем инт так как тут нету отрицательных значений
    {
        cout << "<" << graph1[i].first << ", " << graph1[i].second << ">  ";
    }
    cout << endl;

    cout << "Второй график: ";
    for (size_t i = 0; i < graph2.size(); ++i)
    {
        cout << "<" << graph2[i].first << ", " << graph2[i].second << ">  ";
    }
    cout << endl;

    // Векторы для инверсий
    vector<pair<int, int>> invertedGraph1, invertedGraph2;

    for (size_t i = 0; i < graph1.size(); ++i)
    {
        invertedGraph1.push_back({graph1[i].second, graph1[i].first});
    }

    for (size_t i = 0; i < graph2.size(); ++i)
    {
        invertedGraph2.push_back({graph2[i].second, graph2[i].first});
    }

    cout << endl;
    cout << "Инверсия первого графика: ";
    for (size_t i = 0; i < invertedGraph1.size(); ++i)
    {
        cout << "<" << invertedGraph1[i].first << ", " << invertedGraph1[i].second << ">  ";
    }
    cout << endl;

    cout << "Инверсия второго графика: ";
    for (size_t i = 0; i < invertedGraph2.size(); ++i)
    {
        cout << "<" << invertedGraph2[i].first << ", " << invertedGraph2[i].second << ">  ";
    }
    cout << endl;

    // Вектор для композиции графиков
    vector<pair<int, int>> composition;

    for (size_t i = 0; i < graph1.size(); ++i)
    {
        for (size_t j = 0; j < graph2.size(); ++j)
        {
            if (graph1[i].second == graph2[j].first)
            {
                composition.push_back({graph1[i].first, graph2[j].second});
            }
        }
    }

    cout << "Композиция графиков: ";
    for (size_t i = 0; i < composition.size(); ++i)
    {
        cout << "<" << composition[i].first << ", " << composition[i].second << ">  ";
    }
    cout << endl;

    // Проекция на ось X
    set<int> projectionX1, projectionX2;
    for (size_t i = 0; i < graph1.size(); i++)
    {
        int x = graph1[i].first;
        projectionX1.insert(x);
    }
    for (size_t i = 0; i < graph2.size(); i++)
    {
        int x = graph2[i].first;
        projectionX2.insert(x);
    }

    // Проекция на ось Y
    set<int> projectionY1, projectionY2;
    for (size_t i = 0; i < graph1.size(); i++)
    {
        int y = graph1[i].second;
        projectionY1.insert(y);
    }
    for (size_t i = 0; i < graph2.size(); i++)
    {
        int y = graph2[i].second;
        projectionY2.insert(y);
    }

    cout << "Проекция первого графика на ось X: ";
    for (int x : projectionX1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Проекция первого графика на ось Y: ";
    for (int y : projectionY1)
    {
        cout << y << " ";
    }
    cout << endl;

    cout << "Проекция второго графика на ось X: ";
    for (int x : projectionX2)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Проекция второго графика на ось Y: ";
    for (int y : projectionY2)
    {
        cout << y << " ";
    }
    cout << endl;

    // декартово произведение

    vector<int> set1;
    int choice1;
    cout << "Как вы хотите заполнить первое множество?\n";
    cout << "1 - Вручную\n2 - Квадратами натуральных чисел в диапазоне [A, B]\n";
    cin >> choice1;

    if (choice1 == 1)
    {
        // Заполнение вручную
        int n1;
        cout << "Введите количество элементов первого множества: ";
        cin >> n1;
        cout << "Введите элементы первого множества:\n";
        for (int i = 0; i < n1; ++i)
        {
            int value;
            cin >> value;
            set1.push_back(value);
        }
    }
    else if (choice1 == 2)
    {
        // Заполнение квадратами натуральных чисел
        int a, b;
        cout << "Введите диапазон [A, B] для квадратов натуральных чисел:\n";
        cin >> a >> b;
        for (int i = 1; i * i <= b; ++i)
        {
            int square = i * i;
            if (square >= a)
            {
                set1.push_back(square);
            }
        }
    }
    else
    {
        cout << "Неверный выбор. Завершение программы.\n";
        return 1;
    }

    // Второе множество
    vector<int> set2;
    int choice2;
    cout << "Как вы хотите заполнить второе множество?\n";
    cout << "1 - Вручную\n2 - Квадратами натуральных чисел в диапазоне [A, B]\n";
    cin >> choice2;

    if (choice2 == 1)
    {
        // Заполнение вручную
        int n2;
        cout << "Введите количество элементов второго множества: ";
        cin >> n2;
        cout << "Введите элементы второго множества:\n";
        for (int i = 0; i < n2; ++i)
        {
            int value;
            cin >> value;
            set2.push_back(value);
        }
    }
    else if (choice2 == 2)
    {
        // Заполнение квадратами натуральных чисел
        int a, b;
        cout << "Введите диапазон [A, B] для квадратов натуральных чисел:\n";
        cin >> a >> b;
        for (int i = 1; i * i <= b; ++i)
        {
            int square = i * i;
            if (square >= a)
            {
                set2.push_back(square);
            }
        }
    }
    else
    {
        cout << "Неверный выбор. Завершение программы.\n";
        return 1;
    }

    cout << "Первое множество: ";
    for (int i = 0; i < set1.size(); ++i)
    {
        cout << set1[i] << " ";
    }
    cout << endl;

    cout << "Второе множество: ";
    for (int i = 0; i < set2.size(); ++i)
    {
        cout << set2[i] << " ";
    }
    cout << endl;

    // Вычисление декартова произведения
    cout << "Декартово произведение:\n";
    for (int i = 0; i < set1.size(); ++i)
    {
        for (int j = 0; j < set2.size(); ++j)
        {
            cout << "(" << set1[i] << ", " << set2[j] << ") ";
        }
    }
    cout << endl;

    cout
        << endl
        << endl;
    return 0;
}
