#pragma once
#include "Lexer.h"

using ll=long long;
using ull=unsigned long long;
using vll=vector<ll>;
using pii=pair<int, int>;
using pll=pair<ll,ll>;
using vch=vector<char>;
using vst=vector<string>;
using vpl=vector<pair<ll,ll>>;
using vvl=vector<vector<ll>>;

Lexer::Lexer(){};

// Добавление токена по строке
void Lexer::add_tokens(string &line) {
    Automatic_machine automatic_machine;
    vector <Token> Tokens_from_line = automatic_machine.get_tokens(line);
    for (int i = 0; i < Tokens_from_line.size(); ++i) {
        this->Tokens.push_back(Tokens_from_line[i]);
    }
}