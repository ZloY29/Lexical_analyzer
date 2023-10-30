#include <vector>
#include <string>
#include "Automatic_machine.cpp"
#include "Hash_Table.cpp"

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

class Lexer
{
public:
    // Конструктор
    Lexer();
    // Все токены
    vector <Token> Tokens;
    // Функция добавления токенов
    void add_tokens(string &line);
    // Хэш-таблица
    Hash_Table hash_t;
};