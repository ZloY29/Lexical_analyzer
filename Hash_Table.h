#pragma once
#include <vector>
#include <string>
#include "Automatic_machine.h"

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vch=vector<char>;
using vst=vector<string>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;

using namespace std;

// Структура двусвязного списка, для того чтобы хранить одинаковые элементы по одному хэшу
struct double_linked_list {
    // Ссылка на левого сына
    double_linked_list* left = __null;
    // Ссылка на правого сына
    double_linked_list* right = __null;
    // Информация по токену
    Token info;
};

class Hash_Table {
public:
    // Конструктор
    Hash_Table();
    // Хэш таблица
    vector <double_linked_list> Hash_t;
    // Хэш функция
    ll hash_function(string &name);
    // Добавление токена в хэш таблицу
    void add_to_hash_table(Token Term_Token);
};
