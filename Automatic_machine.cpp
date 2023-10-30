#pragma once
#include "Automatic_machine.h"
#include <iostream>
#include <map>

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vch=vector<char>;
using vst=vector<string>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;

// Распознавание типа токена
void Automatic_machine::determining_the_token_type(vector <Token> &tokens, string &line, ll &current, string &term_str) {
    Token Term_Token;
    if (current == 1) {
        Term_Token.type = "Id";
        for (int i = 0; i < this->key_words.size(); ++i) {
            if (term_str == this->key_words[i]) {
                Term_Token.type = "Key_word";
            }
        }
        Term_Token.name = term_str;
        tokens.push_back(Term_Token);
    }
    if (current == 2) {
        Term_Token.type = "Constant";
        Term_Token.name = term_str;
        tokens.push_back(Term_Token);
    }
    if (current == -1) {
        Term_Token.type = "Invalid_token";
        Term_Token.name = term_str;
        tokens.push_back(Term_Token);
    }
}

// Функция проверки является ли символ операцией
bool isOperation(vector<Token> &tokens, vector<char> &operations, char c, string &term_str, ll &current, vector<string> &key_words) {
    for (int i = 0; i < operations.size(); ++i) {
        if (c == operations[i]) {
            Token Term_Token;
            if (current == 1) {
                Term_Token.type = "Id";
                for (int i = 0; i < key_words.size(); ++i) {
                    if (term_str == key_words[i]) {
                        Term_Token.type = "Key_word";
                    }
                }
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            if (current == 2) {
                Term_Token.type = "Constant";
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            if (current == -1) {
                Term_Token.type = "Invalid_token";
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            current = 0;
            term_str = "";
            Term_Token.type = "Operation";
            Term_Token.name = c;
            tokens.push_back(Term_Token);
            return true;
        }
    }
    return false;
}

// Задание матрицы функции перехода тета от одного состояния к другому
Automatic_machine::Automatic_machine() {
    this->Transit_function_matrix = vvl(4, vll(62, -1));
    for (int i = 0; i < 51; ++i) {
        this->Transit_function_matrix[0][i] = 1;
        this->Transit_function_matrix[1][i] = 1;
        this->Transit_function_matrix[2][i] = -1;
    }
    for (int i = 52; i < 62; ++i) {
        this->Transit_function_matrix[0][i] = 2;
        this->Transit_function_matrix[1][i] = -1;
        this->Transit_function_matrix[2][i] = 2;
    }
}

// Функция проверки является ли символ разделительным
bool isSeparation(vector<Token> &tokens, vector<char> &del_separators, char c, string &term_str, ll &current, vector<string> &key_words) {
    for (int i = 0; i < del_separators.size(); ++i) {
        if (c == del_separators[i]) {
            Token Term_Token;
            if (current == 1) {
                Term_Token.type = "Id";
                for (int i = 0; i < key_words.size(); ++i) {
                    if (term_str == key_words[i]) {
                        Term_Token.type = "Key_word";
                    }
                }
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            if (current == 2) {
                Term_Token.type = "Constant";
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            if (current == -1) {
                Term_Token.type = "Invalid_token";
                Term_Token.name = term_str;
                tokens.push_back(Term_Token);
            }
            current = 0;
            term_str = "";
            Term_Token.type = "Separation";
            Term_Token.name = c;
            tokens.push_back(Term_Token);
            return true;
        }
    }
    return false;
}

// Пробежка по каждому символу строки
void Automatic_machine::running_through_symbols(vector <Token> &tokens, string &line, ll &current, string &term_str, map <char, ll> alphabet) {
    for (int i = 0; i < line.size(); ++i) {
        if (isOperation(tokens, this->operations, line[i], term_str, current, this->key_words)) {
            continue;
        }
        if (isSeparation(tokens, this->separators, line[i], term_str, current, this->key_words)) {
            continue;
        }
        if (line[i] == '\t' || line[i] == ' ') {
            determining_the_token_type(tokens, line, current, term_str);
            current = 0;
            term_str = "";
        }
        else {
            current = Transit_function_matrix[current][alphabet[line[i]]];
            term_str += line[i];
        }
    }
}

// Функция получения токена по строке
vector <Token> Automatic_machine::get_tokens(string &line) {
    vector <Token> tokens;
    string term_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    map <char, ll> alphabet;
    for (int i = 0; i < 62; ++i) {
        alphabet[term_alphabet[i]] = i;
    }
    ll current = 0;
    string term_str = "";
    running_through_symbols(tokens, line, current, term_str, alphabet);
    determining_the_token_type(tokens, line, current, term_str);
    return tokens;
}