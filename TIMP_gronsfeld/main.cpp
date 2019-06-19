#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
void check(const string& Text, const string& key, const bool destructCipherText = false)
{
    try {
        setlocale(LC_ALL,"Russian");
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText) {
            wstring ws = cipher.inhir(cipherText);
            ws.front() = towlower(ws.front());
            cipherText = cipher.izhir(ws);
        }
        decryptedText = cipher.decrypt(cipherText);
        cout << "key = " << key<<endl;
        cout << Text << endl;
        cout << cipherText << endl;
        cout << decryptedText << endl;
    } catch (const cipher_error & e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main()
{
    check("ААААААААААААААААААААААААААААААГГГАААА","АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    check("аааааааааааааааааааааааааааааагггаааа","абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    check("АБВГД ЕЁЖЗИЙ КЛМНО ПРСТУ ФХЦЧШ ЩЪЫЬЭЮЯ","Пробелы");
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","");
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","31БАРСУК");
    check("12345678","АБВ");
    check("ААААААААААААААААААААААААААААААГГГАААА","ГДЕЁЖ", true);
    return 0;
}
