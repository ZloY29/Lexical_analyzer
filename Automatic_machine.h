#pragma once
#include "Token.h"
using namespace std;

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vch=vector<char>;
using vst=vector<string>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;


class Automatic_machine {
public:
    // Конструктор
    Automatic_machine();
    // Распознавание типа токена
    void determining_the_token_type(vector <Token> &tokens, string &line, ll &current, string &term_str);
    // Пробежка по каждому символу строки
    void running_through_symbols(vector <Token> &tokens, string &line, ll &current, string &term_str, map <char, ll> alphabet);
    // Функция получения токена по строке
    vector <Token> get_tokens(string &line);
    // Вектор всех операций
    vch operations = {'+', '-', '=', '<', '>'};
    // Вектор всех разделительных символов
    vch separators = {',', ':', ';', '(', ')'};
    // Вектор ключевых слов
    vst key_words = {"begin", "procedure", "end", "if", "then", "else", "integer", "var"};
    // Матрица функции перехода тета от одного состояния к другому
    vvl Transit_function_matrix;
};