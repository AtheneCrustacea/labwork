#include <iostream>
#include <chrono>
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
    wstring month[]{L" Январь ",L" Февраль ",L" Март ",L" Апрель ",L" Май ",L" Июнь ",
        L" Июль ",L" Август ",L" Сентябрь ",L" Октябрь ",L" Ноябрь ",L" Декабрь "};
    wstring day[]{L"Вс",L"Пн",L"Вт",L"Ср",L"Чт",L"Пт",L"Сб"};
    time_t t = time(NULL);
    cout<<ctime(&t);
    tm * ptm;
    ptm = localtime(&t);
    wcout <<day[ptm->tm_wday]<< month[ptm->tm_mon]<< ptm->tm_mday<< L" " <<ptm->tm_hour<<L":";
    wcout<<ptm->tm_min<<L":"<<ptm->tm_sec<< L" " << ptm->tm_year + 1900<< endl;
    return 0;
}
