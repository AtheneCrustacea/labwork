#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
int RandomGenerator()
{
    static mt19937 rnd((uint64_t)&rnd);
    uniform_int_distribution<int> d(-1000000000,1000000000);
    return d(rnd);
}

int main()
{
    using namespace std::chrono;
    setlocale(LC_ALL, "Russian");
    steady_clock::time_point tp1 = steady_clock::now();
    vector <int> v1;
    for (int i = 0; i < 10000000; i++)
        v1.push_back(RandomGenerator());
    steady_clock::time_point tp2 = steady_clock::now();
    duration<double> d = tp2 - tp1;
    wcout << L"Длительность заполнения первого вектора: " << d.count() << endl;
    tp1 = steady_clock::now();
    vector <int> v2(10000000);
    generate(v2.begin(),v2.end(),RandomGenerator);
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    wcout << L"Длительность заполнения второго вектора: " << d.count() << endl;

    tp1 = steady_clock::now();
    vector <int> v3(v2);
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    wcout << L"Длительность заполнения третьего вектора: " << d.count() << endl;
    tp1 = steady_clock::now();
    sort(v2.begin(),v2.end());
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    wcout << L"Длительность сортировки второго вектора: " << d.count() << endl;
    tp1 = steady_clock::now();
    stable_sort(v3.begin(),v3.end());
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    wcout << L"Длительность сортировки третьего вектора: " << d.count() << endl;
    return 0;
}
