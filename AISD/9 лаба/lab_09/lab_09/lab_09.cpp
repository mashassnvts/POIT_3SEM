#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define G 8
#define START 0 

int children = 0;
int popSize = 0;
int evoCycles = 0;

int distances[G][G] =
{
    {INT_MAX, 25, 40, 31, 27, 16, 7, 9 },
    {5, INT_MAX, 17, 30, 25, 4, 23, 23},
    {19, 15, INT_MAX, 6, 1,19,10,8},
    {9, 50, 24, INT_MAX, 6, 6,12,11},
    {22, 8, 7, 10, INT_MAX, 19,10,9},
    {9, 50, 24, 6, 11,INT_MAX,11,18},
    {9, 50, 24, 6, 6,14,INT_MAX,10},
    {9, 50, 24, 6, 6,12,15,INT_MAX}
};

struct Person
{
    string genes;
    int fitness;
};
// Генерация случайного числа в заданном диапазоне
int randomNum(int start, int end)
{
    return start + rand() % (end - start);
}
// Проверка наличия повторения символа в строке.
bool hasDuplicate(const string& s, char ch)
{
    return s.find(ch) != string::npos;
}
// Функция mutateGenes меняет местами два случайных города в геноме,
// создавая тем самым мутацию в маршруте.
string mutateGenes(const string& genome)
{
    string mutatedGenome = genome;

    while (true)
    {
        int r = randomNum(1, G);
        int r1 = randomNum(1, G);

        if (r1 != r)
        {
            swap(mutatedGenome[r], mutatedGenome[r1]);
            break;
        }
    }

    return mutatedGenome;
}
// Функция createGenome создает начальный геном (перестановку городов) для особи
string createGenome()
{
    string genome = "0";

    while (genome.size() < G)
    {
        int temp = randomNum(1, G);

        if (!hasDuplicate(genome, (char)(temp + 48)))
            genome += (char)(temp + 48);
    }

    return genome + genome[0];
}
// Функция calculateFitness вычисляет приспособленность особи, то есть вес ее маршрута
int calculateFitness(const string& genome)
{
    int totalDistance = 0;

    for (int i = 0; i < genome.size() - 1; i++)
    {
        if (distances[genome[i] - 48][genome[i + 1] - 48] == INT_MAX)
            return INT_MAX;

        totalDistance += distances[genome[i] - 48][genome[i + 1] - 48];
    }

    return totalDistance;
}
// Функция coolDown уменьшает температуру в алгоритме отжига.
//для большей гибкости в поиске оптимального решения
int coolDown(int temp)
{
    return (90 * temp) / 100;
}
//функция используется при сортировке популяции, чтобы расположить особи в порядке возрастания их приспособленности
bool isLessFit(const Person& p1, const Person& p2)
{
    return p1.fitness < p2.fitness;
}

void solveTSP(int distances[G][G])
{
    int generation = 1;  // Переменная для отслеживания текущего поколения в генетическом алгоритме
    int genThreshold = evoCycles;  // Порог эволюционных циклов, после которого алгоритм завершает работу

    Person population[1000];
    Person tempPerson;

    for (int i = 0; i < popSize; i++)
    {
        tempPerson.genes = createGenome();
        tempPerson.fitness = calculateFitness(tempPerson.genes);
        population[i] = tempPerson;
    }

    cout << "Начальная популяция: \n";
    cout << "Геном популяции \t\tВес маршрута\n";
    for (int i = 0; i < popSize; i++)
        cout << population[i].genes << "\t" << population[i].fitness << endl;
    cout << "\n";

    sort(population, population + popSize, isLessFit);

    int temperature = 10000;

    while (temperature > 100 && generation <= genThreshold)
    {
        cout << "\nЛучший геном: " << population[0].genes;
        cout << "\tВес маршрута: " << population[0].fitness << "\n\n";

        Person newPopulation[1000];

        for (int i = 0; i < children; i++)
        {
            Person parent = population[i];

            while (true)
            {
                string newGenome = mutateGenes(parent.genes);
                Person newPerson;
                newPerson.genes = newGenome;
                newPerson.fitness = calculateFitness(newPerson.genes);

                if (newPerson.fitness <= population[i].fitness)
                {
                    newPopulation[i] = newPerson;
                    break;
                }
                else
                {
                    newPerson.fitness = INT_MAX;
                    newPopulation[i] = newPerson;
                    break;
                }
            }
        }

        temperature = coolDown(temperature);

        for (int i = 0; i < children; i++)
        {
            population[i + popSize] = newPopulation[i];
        }

        sort(population, population + popSize + children, isLessFit);

        for (int i = 0; i < children; i++)
        {
            population[i + popSize] = newPopulation[i];
        }

        cout << " Текущая популяция: " << generation << "\n";
        cout << "Геном популяции \t\tВес маршрута\n";

        for (int i = 0; i < popSize; i++)
            cout << population[i].genes << "\t" << population[i].fitness << endl;

        generation++;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите параметры генетического алгоритма:\n";
    cout << "Количество потомков в одной популяции (количество новых маршрутов): ";
    cin >> popSize;
    cout << "Количество эволюционных циклов (количество итераций): ";
    cin >> children;
    cout << "Количество потомков в одной популяции (количество новых маршрутов): ";
    cin >> evoCycles;

    solveTSP(distances);

    return 0;
}
