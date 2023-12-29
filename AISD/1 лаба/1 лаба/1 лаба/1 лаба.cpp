#include <iostream>
using namespace std;


void Hanoi(int i, int k, int n)
{
  
    if (n == 1)
        cout << "Переместить диск 1 с " << i << " на " << k << " стержень." << endl;
    else
    {
        /* 1 + 2 + 3 = 6
        i + k + temp = 6
        * => temp = 6 - i - k */

        int dop = 6 - i - k;
        Hanoi(i, dop, n - 1);
        cout << "Переместить диск " << n << " с " << i << " на " << k << " стержень." << endl;
        Hanoi(dop, k, n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, k;

    while (true)
    {
        cout << "Введите число дисков: ";
        cin >> n;
        if (cin.get() != (int)'\n')
        {
            cout << "\n Данные введены неверно, попробуйте ещё раз " << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (n <= 0 || n > 1000)
        {
            cout << "\n Данные введены неверно, попробуйте ещё раз" << endl;
            continue;
        }
        cout << "\nВведите номер стрежня, на которые нужно переместить диски (2 или 3): ";
        cin >> k;
        if (cin.get() != (int)'\n')
        {
            cout << "\n Данные введены неверно, попробуйте ещё раз " << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (k > 3 || k <= 1)
        {
            cout << "\n Данные введены неверно, попробуйте ещё раз " << endl;
            continue;
        }
        else
        {
            Hanoi(1, k, n);
            break;
        }
    }

    system("pause");
    return 0;
}