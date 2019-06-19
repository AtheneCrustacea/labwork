#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
struct second_name{
    string name = "NULL";
    string patronymic = "NULL";
    friend fstream& operator>>(ifstream& in, second_name &sth){
        in >> sth.name >> sth.patronymic;
    }
    friend ostream& operator<<(ostream& out, second_name sth){
        out << sth.name << " " << sth.patronymic;
        return out;
    }
    bool operator==(const string sth){
        return (name == sth);
    }

};

int main()
{
    ifstream file;
    file.open("D:\\binfiles\\names.txt", ios::in);
    string buffer, c, nameMax, nameMin;
    unsigned int counterMin = -1, counterMax = 0, counter = 0;
    second_name sth;
    multimap<string,second_name> name;
    while(file >> buffer && file >> sth){//ввод ФИО
        name.insert(pair<string,second_name> (buffer,sth));
    };
    for (auto it = name.begin();it != name.end(); it++){//вывод упорядоченных ФИО
        cout << (*it).first<< " " << (*it).second << endl;
    }
    for (auto it = name.begin();it != name.end(); it++){//поиск однофамильцев
        if ((*it).first == (*(it++)).first){
            c = (*it).first;
            cout << "namesake: \n";
            for (it=name.equal_range(c).first; it!=name.equal_range(c).second; ++it){
                cout << (*it).first<< " " << (*it).second << endl;
            }
        }else {it--;}
    }
    multiset<string> nameC;
    for (auto it = name.begin();it != name.end(); it++){//инициализация именами
        nameC.insert((*it).second.name);
    }
    for (auto it = nameC.begin();it != nameC.end(); it++){//поиск наиболее и наименее популярного имени
        c = (*it);
        counter = nameC.count(c);
        for (int i = 0; i < counter - 1; i++)
            it++;
        if (counter == counterMax){nameMax += ", " + c;}
        if (counter == counterMin){nameMin += ", " + c;}
        if (counter > counterMax){counterMax = counter; nameMax = c;}
        if (counter < counterMin){counterMin = counter; nameMin = c;}
    }
    if (counterMax == counterMin){
        nameMax = "NONE";
        nameMin = "NONE";
    }
    cout << "The most poular name:\n" << nameMax << endl;
    cout << "The least popular:\n" << nameMin << endl;
    return 0;
}
