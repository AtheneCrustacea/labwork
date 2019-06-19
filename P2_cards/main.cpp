#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
using namespace std;
struct Cards {
    int suit;
    int value;
    Cards(int w,int h) {
        suit=w;
        value=h;
    }
    friend ostream& operator<< (ostream &out, const Cards &b) {
        out << "SUIT " << b.suit << ", VALUE " << b.value;
    }
    friend bool operator== (const Cards &a, const Cards &b) {
        return (a.suit == b.suit and a.value== b.value);
    }
};
int main()
{
    setlocale (LC_ALL,"Russian");
    enum suit {peaks=0,clubs=1,hearts=2,diamond=3};
    enum value {six,seven,eight,nine,ten,jack,queen,king,ACE};
    Cards y(0,0);
    vector <Cards> deck;
    for(int k=0; k<4; k++) {
        for(int i=0; i<9; i++) {
            Cards y(k,i);
            deck.push_back(y);
        }
    }

    shuffle(deck.begin(),deck.end(),mt19937(time(NULL)));
    for(int i=0; i<36; i++)
        cout<<deck[i]<<endl;
    for(int i=0; i<36; i++) {
        if((deck[i].suit==diamond or deck[i].suit==hearts) and (deck[i+1].suit==hearts or deck[i+1].suit==diamond)) {
            wcout<<L"Пара карт красной масти в позициях "<<i+1<<", "<<i+2<<endl;
            cout<<deck[i]<<" "<<deck[i+1]<<endl;
        }
    }
    for(int i=0; i<36; i++) {
        if(deck[i].value==deck[i+1].value) {
            wcout<<L"Пара карт с одинаковыми значениями в позициях "<<i+1<<L", "<<i+2<<endl;
            cout<<deck[i]<<" "<<deck[i+1]<<endl;
        }
    }
    Cards q(clubs,queen);
    auto it1=find(deck.begin(),deck.end(),q);
    auto index = distance(deck.begin(), it1);
    wcout<<L"Пиковая дамма в колоде на "<<index+1<<L" позиция"<<endl;
    for(int i=0; i<36; i++) {
        if(deck[i].value==ACE) {
            wcout<<L"Туз ";
            cout<<deck[i];
            wcout<<L". Позиция в колоде "<<i+1<<endl;
        }
    }
    return 0;
}
