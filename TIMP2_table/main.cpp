#include <iostream>
#include <table.h>
using namespace std;

void check(int key, int Switch,string s)
{
    try{
        table worker(key);
        if (Switch > 2 || Switch < 1)
        {
            throw string( "wrong operation mode.");
        }
        if(Switch == 1){
            s = worker.encrypt(s);
        }
        else if (Switch == 2){
            s = worker.decrypt(s);
        }
        cout <<"Result:" << s << endl;
    }
    catch(string &e){
        cerr << "Error:" << e << endl;
    }
}
int main()
{
    check(5,1,"primermarsrutnoyperestanovki");
    check(0,1,"primermarsrutnoyperestanovki");
    check(5,3,"primermarsrutnoyperestanovki");
    check(5,-1,"primermarsrutnoyperestanovki");
    check(5,1,"");
    check(5,2,"esoeomrnrniateairmuptkprrysv");
    return 0;
}
