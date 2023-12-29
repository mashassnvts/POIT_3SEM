#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Rus");
    int n;

    while (true) 
    {
        cout << "Введите N (длина последовательности):" << endl;
        cin >> n;

        if (cin.get() != (int)'\n') 
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear(); 
            cin.ignore(32767, '\n'); 
            continue; 
        }
        else {
            break; 
        }
    }

    int sequence[1000]; 
    int maxLen[1000]; 
    int next[1000]; 

    cout << "Вводите массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << i << "-й элемент: ";
        cin >> sequence[i];

        if (cin.get() != (int)'\n') 
        {
            cout << "\n---------- Данные введены неверно, начните сначала (с первого элемента массива) --------------" << endl;
            cin.clear(); 
            cin.ignore(32767, '\n'); 
            i = -1; 
        }
    }

    // Алгоритм поиска максимальной возрастающей подпоследовательности
    for (int i = n - 1; i >= 0; i--) 
    {
        int maxNextLen = 0; 
        int bestNext = -1; 
       
        for (int j = i + 1; j < n; j++) 
        {
            if (sequence[j] > sequence[i]) 
            {// Была ли найденная длина подпоследовательности для sequence[j] больше текущей максимальной
                if (maxLen[j] > maxNextLen) 
                {
                    maxNextLen = maxLen[j]; 
                    bestNext = j; 
                }
            }
        }
        next[i] = bestNext; 
        maxLen[i] = maxNextLen + 1; 
    }


   
    int max = 0; 
    int bestStart = -1; 
    // Находим индекс начала максимальной подпоследовательности
    for (int i = 0; i < n; i++) 
    {// Проверяем, если длина подпоследовательности, начинающейся с текущего элемента, больше текущей максимальной длины
        if (maxLen[i] > max) 
        {
            max = maxLen[i]; 
            bestStart = i;
        }
    }

    cout << "Максимальная длина: " << max << endl;
    for (int i = bestStart; i != -1; i = next[i])
        cout << sequence[i] << " ";

    return 0;
}
