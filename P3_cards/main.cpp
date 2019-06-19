#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
static const string suits[]{"HEART","DIAMOND","CLUB","SPADE"},value_[]{"Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
enum suits{heart, diamond, club, spade};
enum value{six, seven, eight, nine, ten, Jack, Queen, King, Ace};
struct card{
    int suit;
    int value;
    card(int i, int j){
        suit = i;
        value = j;
    }
    friend ostream& operator<< (ostream &out, const card &b) {
        out << setw(7)<< left << suits[b.suit] << ", " << setw(5)<< left << value_[b.value];
    }
    friend bool operator== (const card &a, const card &b) {
        return (a.suit == b.suit and a.value== b.value);
    }
};

int main()
{
    setlocale (LC_ALL,"Russian");
    vector <card> deck;
    for (int i = 0; i <= spade; i++){//объявление карт
        for (int j = 0; j <= Ace; j++){
            card sth(i,j);
            deck.push_back(sth);
        }
    }
    for(int i=0; i<36; i++){//вывод колоды
        cout<<deck[i]<<endl;
    }
    shuffle(deck.begin(),deck.end(),mt19937(time(NULL)));//перетасовка карт
    for(int i=0; i<36; i++) {//вывод пары красных карт
        if((deck[i].suit==diamond or deck[i].suit==heart) and (deck[i+1].suit==heart or deck[i+1].suit==diamond)) {
            wcout<<L"Пара карт красной масти на позициях "<<i+1<<", "<<i+2<<endl;
            cout<<deck[i]<<" | "<<deck[i+1]<<endl;
        }
    }
    for(int i=0; i<36; i++) {//пара карт с одинаковым достоинством
        if(deck[i].value==deck[i+1].value) {
            wcout<<L"Пара карт с одинаковым достоинтсвом в позициях "<<i+1<<L", "<<i+2<<endl;
            cout<<deck[i]<<" | "<<deck[i+1]<<endl;
        }
    }
    {//поиск пиковой дамы
        card q(club,Queen);
        auto it1=find(deck.begin(),deck.end(),q);
        auto index = distance(deck.begin(), it1);
        wcout<<L"Пиковая дамма "<<index+1<<L"-ая в колоде"<<endl;
    }
    for(int i=0; i<36; i++) {//поиск туза
        if(deck[i].value==Ace) {
            wcout<<L"Туз ";
            cout<<deck[i];
            wcout<<L". Позиция в колоде "<<i+1<<endl;
        }
    }
    return 0;
}
