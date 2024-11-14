﻿#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int getValidNumber() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            cout << "Ошибка: введено не число. Пожалуйста, попробуйте снова: ";
        }
        else {
            return num; // Если введено число, возвращаем его
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b, n1;

    // Ввод размера первого множества с проверкой на максимальный размер
    do {
        cout << "Введите размер первого множества (до 201): ";
        a = getValidNumber(); // Используем функцию для проверки на число

        if (a < 0 || a > 201) { // Проверка, что размер находится в допустимом диапазоне
            cout << "Ошибка: размер должен быть от 1 до 201. Попробуйте снова.\n";
        }
    } while (a < 0 || a > 201); // Повторяем ввод, пока не введено корректное значение

    vector<int> vec1;  // Вектор для хранения элемент   ов первого множества
    if (a == 0) {
        cout << "Вы ввели пустое множество.\n";
    }
    else {
        int element1;
        cout << "Введите " << a << " элемента(ов) первого множества (от -100 до 100):\n";
        for (int i = 0; i < a; ++i) {
            bool isDuplicate = false;
            do {
                cout << "Введите элемент " << i + 1 << ": ";
                element1 = getValidNumber(); // Используем функцию для проверки на число
                // Проверка, входит ли элемент в диапазон от -100 до 100
                if (element1 < -100 || element1 > 100) {
                    cout << "Ошибка: элемент должен быть в диапазоне от -100 до 100. Попробуйте снова.\n";
                    isDuplicate = true; // Ставим true, чтобы продолжить ввод
                    continue; // Пропускаем остальную часть цикла и возвращаемся к вводу
                }
                // Проверка, есть ли элемент уже в векторе  
                isDuplicate = false;
                for (int j = 0; j < vec1.size(); ++j) {
                    if (vec1[j] == element1) {
                        cout << "Элемент уже существует! Попробуйте снова.\n";
                        isDuplicate = true;
                        break;
                    }
                }
                // Добавляем элемент, если дубликатов нет
                if (!isDuplicate) {
                    vec1.push_back(element1);
                }

            } while (isDuplicate);  // Повторяем ввод, если найден дубликат
        }
        cout << "Вы ввели первое множество: ";
        for (int i = 0; i < vec1.size(); ++i) {
            cout << vec1[i] << " ";
        }
        cout << endl << endl;
    }

    // Ввод размера второго множества с проверкой на максимальный размер
    do {
        cout << "Введите размер второго множества (до 201): ";
        b = getValidNumber(); // Используем функцию для проверки на число

        if (b < 0 || b > 201) { // Проверка, что размер находится в допустимом диапазоне
            cout << "Ошибка: размер должен быть от 1 до 201. Попробуйте снова.\n";
        }
    } while (b < 0 || b > 201); // Повторяем ввод, пока не введено корректное значение

    vector<int> vec2;  // Вектор для хранения элементов второго множества
    if (b == 0) {
        cout << "Вы ввели пустое множество.\n";
    }
    else {
        int element2;
        cout << "Введите " << b << " элемента(ов) второго множества (от -100 до 100):\n";
        for (int i = 0; i < b; ++i) {
            bool isDuplicate = false;
            do {
                cout << "Введите элемент " << i + 1 << ": ";
                element2 = getValidNumber(); // Используем функцию для проверки на число
                // Проверка, входит ли элемент в диапазон от -100 до 100
                if (element2 < -100 || element2 > 100) {
                    cout << "Ошибка: элемент должен быть в диапазоне от -100 до 100. Попробуйте снова.\n";
                    isDuplicate = true; // Ставим true, чтобы продолжить ввод
                    continue; // Пропускаем остальную часть цикла и возвращаемся к вводу
                }
                // Проверка, есть ли элемент уже в векторе
                isDuplicate = false;
                for (int j = 0; j < vec2.size(); ++j) {
                    if (vec2[j] == element2) {
                        cout << "Элемент уже существует! Попробуйте снова.\n";
                        isDuplicate = true;
                        break;
                    }
                }
                // Добавляем элемент, если дубликатов нет
                if (!isDuplicate) {
                    vec2.push_back(element2);
                }
            } while (isDuplicate);  // Повторяем ввод, если найден дубликат
        }
        cout << "Вы ввели второе множество: ";
        for (int i = 0; i < vec2.size(); ++i) {
            cout << vec2[i] << " ";
        }
        cout << endl << endl;
    }




    cout << "Укажите операцию : " << endl;
    cout << "1_Дополнение " << endl;
    cout << "2_Объединение " << endl;
    cout << "3_Пересечение " << endl;
    cout << "4_Разность " << endl;
    cout << "5_Симметричная разность " << endl;
    cout << "6_Разбиение " << endl;
    cout << endl;
    cin >> n1;
    
    switch (n1) {   
    case 1: {
        // Диапазон универсального множества от -100 до 100
        const int MIN_VALUE = -100;
        const int MAX_VALUE = 100;
        vector<int> complement1;
        vector<int> complement2;

        // Находим дополнение множества 1 до универсального множества 
        for (int i = MIN_VALUE; i <= MAX_VALUE; ++i) {
            bool found = false;

            // Проверяем, есть ли элемент i в множестве 1
            for (int j = 0; j < vec1.size(); ++j) {
                if (vec1[j] == i) {
                    found = true;
                    break;
                }
            }

            // Если элемент не найден в мн1, добавляем его в дополнение
            if (!found) {
                complement1.push_back(i);
            }
        }
               cout << "Дополнение множества 1 до универсального множества : ";
        for (int i = 0; i < complement1.size(); ++i) {
               cout << complement1[i] << " ";
        }
               cout << endl << endl;



        // Находим дополнение множества 2 до универсального множества 
        for (int i1 = MIN_VALUE; i1 <= MAX_VALUE; ++i1) {
            bool found = false;

            // Проверяем, есть ли элемент i1 в множестве 2
            for (int j1 = 0; j1 < vec1.size(); ++j1) {
                if (vec1[j1] == i1) {
                    found = true;
                    break;
                }
            }

            // Если элемент не найден в мн2, добавляем его в дополнение
            if (!found) {
                complement2.push_back(i1);
            }
        }

        cout << "Дополнение множества 2 до универсального множества: ";
        for (int i = 0; i < complement2.size(); ++i) {
            cout << complement1[i] << " ";
        }


        break;
    }

    case 2: {
        vector<int> unionVec = vec1;  // вектор для хранения
        if (a == 0 && b == 0) {
            cout << "Пустое множество";
        }
        else {

        for (size_t i = 0; i < vec2.size(); ++i) { 
            int elem2 = vec2[i]; // Получаем элемент из vec2 по индексу
            bool isDuplicate = false; // Переменная для отслеживания дубликатов

            // Проверка на дубликаты ВРОДЕ бы не нужно
            for (size_t j = 0; j < unionVec.size(); ++j) { 
                int elem1 = unionVec[j]; // Получаем элемент unionVec по индексу
                if (elem2 == elem1) { // Сравнение элементов
                    isDuplicate = true; 
                    break; 
                }
            }

            // Если дубликата нет, добавляем элемент
            if (!isDuplicate) {
                unionVec.push_back(elem2); // Добавляем элемент в результирующий вектор
            }
        }
        // Вывод объединенного вектора
        cout << endl;
        cout << "Объединение векторов: ";
        for (size_t i = 0; i < unionVec.size(); ++i) {
            cout << unionVec[i] << " "; 
        }
        cout << std::endl;
        }
        break;

    }

    case 3: {
        // Вектор для хранения пересечения
        vector<int> leto;
        if (a == 0 && b == 0) {
            cout << endl;
            cout << "Пустое множество";
        }

        else {

        // Нахождение пересечения
        for (int i = 0; i < a; ++i) { // Проходим по элементам первого вектора
            for (int j = 0; j < b; ++j) { // Проходим по элементам второго вектора
                if (vec1[i] == vec2[j]) { // Если элемент найден в обоих векторах
                    // Проверяем, есть ли уже этот элемент в результате
                    bool isDuplicate = false;
                    for (int k = 0; k < leto.size(); ++k) {
                        if (leto[k] == vec1[i]) {
                            isDuplicate = true; // Если найден дубликат, помечаем
                            break; // Выходим из цикла
                        }
                    }
                    // Если элемент не дубликат, добавляем его в результирующий вектор
                    if (!isDuplicate) {
                        leto.push_back(vec1[i]);
                    }
                }
            }
        }

        cout << "Пересечение векторов: ";
        for (int elem : leto) {
            cout << elem << " "; 
        }
        cout << endl;
        }
        break;
    }

    case 4:  {
        // Проверяем, если оба множества пустые
        if (a == 0 && b == 0) {
            cout << "Разность M1-M2: Пустое множество" << endl;
            cout << "Разность M2-M1: Пустое множество" << endl;
        }
        else if (a == 0) {
            // Если первое множество пустое
            cout << "Разность M1-M2: Пустое множество" << endl;

            // Вычисляем только разность M2-M1
            vector<int> difference2; // Разность второго от первого
            for (int i = 0; i < vec2.size(); ++i) {
                bool found = false;
                for (int j = 0; j < vec1.size(); ++j) {
                    if (vec2[i] == vec1[j]) {
                        found = true;
                        break; // Если нашли элемент в первом множестве, выходим из цикла
                    }
                }
                if (!found) {
                    difference2.push_back(vec2[i]); // Добавляем элемент в разность, если его нет в первом множестве
                }
            }

            cout << "Разность M2-M1: ";
            for (int i = 0; i < difference2.size(); ++i) {
                cout << difference2[i] << " ";
            }
            cout << endl;
        }
        else if (b == 0) {
            // Если второе множество пустое
            cout << "Разность M2-M1: Пустое множество" << endl;

            // Вычисляем только разность M1-M2
            vector<int> difference1; // Разность первого от второго
            for (int i = 0; i < vec1.size(); ++i) {
                bool found = false;
                for (int j = 0; j < vec2.size(); ++j) {
                    if (vec1[i] == vec2[j]) {
                        found = true;
                        break; // Если нашли элемент во втором множестве, выходим из цикла
                    }
                }
                if (!found) {
                    difference1.push_back(vec1[i]); // Добавляем элемент в разность, если его нет во втором множестве
                }
            }

            cout << "Разность M1-M2: ";
            for (int i = 0; i < difference1.size(); ++i) {
                cout << difference1[i] << " ";
            }
            cout << endl;
        }
        else {
            // Если оба множества не пустые, вычисляем обе разности
            vector<int> difference1; // Разность первого от второго
            for (int i = 0; i < vec1.size(); ++i) {
                bool found = false;
                for (int j = 0; j < vec2.size(); ++j) {
                    if (vec1[i] == vec2[j]) {
                        found = true;
                        break; // Если нашли элемент во втором множестве, выходим из цикла
                    }
                }
                if (!found) {
                    difference1.push_back(vec1[i]); // Добавляем элемент в разность, если его нет во втором множестве
                }
            }

            vector<int> difference2; // Разность второго от первого
            for (int i = 0; i < vec2.size(); ++i) {
                bool found = false;
                for (int j = 0; j < vec1.size(); ++j) {
                    if (vec2[i] == vec1[j]) {
                        found = true;
                        break; // Если нашли элемент в первом множестве, выходим из цикла
                    }
                }
                if (!found) {
                    difference2.push_back(vec2[i]); // Добавляем элемент в разность, если его нет в первом множестве
                }
            }

            // Вывод результатов
            cout << "Разность M1-M2: ";
            for (int i = 0; i < difference1.size(); ++i) {
                cout << difference1[i] << " ";
            }
            cout << endl;

            cout << "Разность M2-M1: ";
            for (int i = 0; i < difference2.size(); ++i) {
                cout << difference2[i] << " ";
            }
            cout << endl;
        }
        break;
    }

    case 5: {
      vector<int> symmetricDifference; // Вектор для симметрической разности

      // Если оба множества пустые
      if (a == 0 && b == 0) {
          cout << "Симметрическая разность: Пустое множество" << endl;
      }
      else if (a == 0) {
          // Если первое множество пустое, симметрическая разность = vec2
          for (int i = 0; i < vec2.size(); ++i) {
              symmetricDifference.push_back(vec2[i]);
          }

          cout << "Симметрическая разность: ";
          for (int i = 0; i < symmetricDifference.size(); ++i) {
              cout << symmetricDifference[i] << " ";
          }
          cout << endl;
      }
      else if (b == 0) {
          // Если второе множество пустое, симметрическая разность = vec1
          for (int i = 0; i < vec1.size(); ++i) {
              symmetricDifference.push_back(vec1[i]);
          }

          cout << "Симметрическая разность: ";
          for (int i = 0; i < symmetricDifference.size(); ++i) {
              cout << symmetricDifference[i] << " ";
          }
          cout << endl;
      }
      else {
          // Вычисляем симметрическую разность, если оба множества не пустые

          // Элементы, которые есть в первом множестве, но нет во втором
          for (int i = 0; i < vec1.size(); ++i) {
              bool found = false;
              for (int j = 0; j < vec2.size(); ++j) {
                  if (vec1[i] == vec2[j]) {
                      found = true;
                      break; // Если нашли элемент во втором множестве, выходим из цикла
                  }
              }
              if (!found) {
                  symmetricDifference.push_back(vec1[i]); // Добавляем элемент в симметрическую разность
              }
          }

          // Элементы, которые есть во втором множестве, но нет в первом
          for (int i = 0; i < vec2.size(); ++i) {
              bool found = false;
              for (int j = 0; j < vec1.size(); ++j) {
                  if (vec2[i] == vec1[j]) {
                      found = true;
                      break; // Если нашли элемент в первом множестве, выходим из цикла
                  }
              }
              if (!found) {
                  symmetricDifference.push_back(vec2[i]); // Добавляем элемент в симметрическую разность
              }
          }

          // Вывод симметрической разности
          cout << "Симметрическая разность: ";
          for (int i = 0; i < symmetricDifference.size(); ++i) {
              cout << symmetricDifference[i] << " ";
          }
          cout << endl;
      }
      break;
  }

    case 6: {
        int numSubsets;

        // Спросим пользователя, сколько подмножеств требуется
        cout << "Сколько подмножеств вы хотите? ";
        cin >> numSubsets;

        // Проверка, чтобы число подмножеств было корректным
        if (numSubsets <= 0) {
            cout << "Некорректное количество подмножеств." << endl;
            break;
        }

        // Создаем векторы для хранения подмножеств
        vector<vector<int>> subsets1(numSubsets); // Подмножества для vec1
        vector<vector<int>> subsets2(numSubsets); // Подмножества для vec2

        // Разбиение первого множества (vec1)
        for (int i = 0; i < vec1.size(); ++i) {
            subsets1[i % numSubsets].push_back(vec1[i]); // Добавляем элементы по кругу в подмножества
        }

        // Разбиение второго множества (vec2)
        for (int i = 0; i < vec2.size(); ++i) {
            subsets2[i % numSubsets].push_back(vec2[i]); // Добавляем элементы по кругу в подмножества
        }

        // Вывод подмножеств для vec1
        cout << "Подмножества для vec1:" << endl;
        for (int i = 0; i < numSubsets; ++i) {
            cout << "Подмножество " << i + 1 << ": ";
            for (int j = 0; j < subsets1[i].size(); ++j) {
                cout << subsets1[i][j] << " ";
            }
            cout << endl;
        }

        // Вывод подмножеств для vec2
        cout << "Подмножества для vec2:" << endl;
        for (int i = 0; i < numSubsets; ++i) {
            cout << "Подмножество " << i + 1 << ": ";
            for (int j = 0; j < subsets2[i].size(); ++j) {
                cout << subsets2[i][j] << " ";
            }
            cout << endl;
        }

        break;
    }

    default:
        cout << "error number" << endl;
        break;
    }
    return 0;   
}


