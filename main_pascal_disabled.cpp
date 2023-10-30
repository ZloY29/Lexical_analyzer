#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#include <cmath>

#include "Lexer.cpp"
#include "Hash_Table.cpp"
#include "Hash_Table.h"
#include "Automatic_machine.cpp"
#include "Token.cpp"

using namespace std;

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vpi=vector<pair<int,int>>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;

int main() {
    ifstream in("vhod_procedure.txt");
    ofstream out("vihod_procedure.txt");
    string line;
    Lexer lexer;
    // Пока из файла что-то считывается мы обрабатываем это в токены
    while (getline(in, line)) {
        lexer.add_tokens(line);
    }
    for (int i = 0; i < lexer.Tokens.size() - 1; ++i) {
        // Обработка случая операции присвоения ':='
        if (lexer.Tokens[i].name == ":" && lexer.Tokens[i + 1].name == "=") {
            Token Term_Token;
            Term_Token.type = "Operation";
            Term_Token.name = ":=";
            lexer.hash_t.add_to_hash_table(Term_Token);
            ++i;
        }
        // Обработка случая операции не равно '<>'
        else if (lexer.Tokens[i].name == "<" && lexer.Tokens[i + 1].name == ">") {
            Token Term_Token;
            Term_Token.type = "Operation";
            Term_Token.name = "<>";
            lexer.hash_t.add_to_hash_table(Term_Token);
            ++i;
        }
        // Во всех остальных случаях пушим токен в хэш таблицу
        else
            lexer.hash_t.add_to_hash_table(lexer.Tokens[i]);
    }
    out << "Token type" << "\t\t|\t\t" << "Token name" << "\t\t|\t\t" << "Token index\n\n";
    for (int i = 0; i < 9999; i++) {
        // Рассматриваем ветку хэш таблицы с индексом i
        double_linked_list* root = &lexer.hash_t.Hash_t[i];
        if (root->info.type != "_type_" && root->info.name != "_name_") {
            // Пока не обработаем всю ветку выводим детей
            while (root->right != __null) {
                out << "(" << root->info.type << "   " << root->info.name << "   ), ";
                root = root->right;
            }
            // Потом выводим корень
            out << "(" << root->info.type << "   " << root->info.name << "   )";
            // И в конце выводим индекс
            out << " idx: " << i << "\n";
        }
        else continue;
    }
}