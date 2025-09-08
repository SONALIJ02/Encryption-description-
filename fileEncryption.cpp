#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

class Encryption
{
    bool check = false;
    char ch;
    string fileName = "sample.txt";

public:
    void encryptFile();
    void decryptFile();
    void showFile();
};

void Encryption::encryptFile()
{
    fstream fin, fout;
    fin.open(fileName, fstream::in);
    fout.open("sample.txt", fstream::out);
    while (fin >> noskipws >> ch)
    {
        ch = ch + 100;
        fout << ch;
    }
    fin.close();
    fout.close();
    fin.open("sample.txt", fstream::in);
    fout.open(fileName, fstream::out);
    while (fin >> noskipws >> ch)
    {
        fout << ch;
    }
    fin.close();
    fout.close();
    remove("sample.txt");
    cout << "\nFile is successfully encrypted\n\n";
    check = true;
}

void Encryption::decryptFile()
{
    fstream fin, fout;
    fin.open(fileName, fstream::in);
    fout.open("sample.txt", fstream::out);
    while (fin >> noskipws >> ch)
    {
        ch = ch - 100;
        fout << ch;
    }
    fin.close();
    fout.close();
    fin.open("sample.txt", fstream::in);
    fout.open(fileName, fstream::out);
    while (fin >> noskipws >> ch)
    {
        fout << ch;
    }
    fin.close();
    fout.close();
    remove("sample.txt");
    cout << "\nFile is successfully decrypted\n\n";
    check = false;
}

void Encryption::showFile()
{
    fstream fout;
    cout << endl;
    fout.open(fileName, fstream::in);
    while (fout >> noskipws >> ch)
    {
        cout << ch;
    }
    fout.close();
    cout << endl<< endl;
}

int main()
{
    int choose;
    Encryption file;
    cout << "\nWELCOME TO FILE ENCRYPTION PROJECT\n\n";
    do
    {
        cout << "Press 1 to encrypt file\n";
        cout << "Press 2 to decrypt file\n";
        cout << "Press 3 to show file\n";
        cout << "Press 4 to exit\n";
        cout << "Please choose any option: ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            file.encryptFile();
            break;
        case 2:
            file.decryptFile();
            break;
        case 3:
            file.showFile();
            break;
        case 4:
            break;
        default:
            cout << "\nInvalid option try again\n";
            break;
        }
    } while (choose != 4);

    return 0;