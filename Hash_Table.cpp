#pragma once
#include "Hash_Table.h"

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vch=vector<char>;
using vst=vector<string>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;

// Конструктор
Hash_Table::Hash_Table() {
    Hash_t = vector <double_linked_list> (9999);
}

// Получение хэша через хэш функцию по имени
ll Hash_Table::hash_function(string &name) {
    ll capacity = 9999;
    unsigned int hash = 0;
    for (int i = 0; i < name.size(); i++)
        hash = 31 * hash + name[i];
    return hash % capacity;
}

// Добавление токена в хэш таблицу
void Hash_Table::add_to_hash_table(Token Term_Token) {
    ll hash = this->hash_function(Term_Token.name);
    // Если такого хэша еще нет
    if (this->Hash_t[hash].info.type == "_type_" && this->Hash_t[hash].info.name == "_name_")
        this->Hash_t[hash].info = Term_Token;
    // Если по этому хэшу уже лежит элемент
    else {
        double_linked_list* buf_dll = new double_linked_list;
        buf_dll->info = this->Hash_t[hash].info;
        buf_dll->right = this->Hash_t[hash].right;
        this->Hash_t[hash].info = Term_Token;
        this->Hash_t[hash].right = buf_dll;
        buf_dll->left = this->Hash_t[hash].left;
    }
}