#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;


struct Node
{
    char ch;          
    int freq;         
    Node* left, * right;  
};

// Функция для создания нового узла
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    
    Node* node = new Node();

    // Присвоение значений атрибутам узла
    node->ch = ch; 
    node->freq = freq; 
    node->left = left; 
    node->right = right;

    return node;
}

// Структура для сравнения узлов в приоритетной очереди
struct comp
{
    // Функция сравнения узлов по частоте
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;  // Узлы с меньшей частотой имеют более высокий приоритет
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int& index, string str)
{
    if (root == nullptr) 
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }
    index++;

    // Рекурсивно декодируем в зависимости от текущего бита (0 или 1)
    if (str[index] == '0')
        decode(root->left, index, str);
   
    else
        decode(root->right, index, str);
}


void buildHuffmanTree(string text)
{
    // Хэш-таблица для хранения частот каждого символа
    unordered_map<char, int> freq;

    // Цикл for используется для итерации по каждому символу в строке 'text'.
    for (char ch : text)
    {
        // Увеличиваем частоту символа 'ch' в хэш-таблице 'freq' на 1.
        freq[ch]++;
    }

    // Приоритетная очередь 'pq' используется для хранения узлов дерева Хаффмана в порядке их приоритета.
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Цикл for используется для итерации по парам (ключ, значение) в хэш-таблице 'freq'.
    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    cout << "Частота символов" << endl;
    for (auto pair : freq)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    // Строим дерево Хаффмана, объединяя узлы с наименьшей частотой
    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
      
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // Корень дерева Хаффмана
    Node* root = pq.top();

    // Хэш-таблица для хранения кодов Хаффмана для каждого символа
    unordered_map<char, string> huffmanCode;

    encode(root, "", huffmanCode);

    cout << "Коды Хаффмана :\n" << '\n';
    for (auto pair : huffmanCode)
    {
        cout << "Символ: '" << pair.first << "' Код: " << pair.second << '\n';
    }

    cout << "\nИсходная строка :\n" << text << '\n';

    string str = "";
    for (char ch : text)
    {
        str += huffmanCode[ch];
    }

    cout << "\nЗакодированная строка :\n" << str << '\n';

    int index = -1;

    cout << "\nДекодированная строка: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    string text = "ABRCD";

    buildHuffmanTree(text);

    return 0;
}
