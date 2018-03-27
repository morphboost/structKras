#include <iostream>
using namespace std;


struct Autom {
    char name[50];
    char autoname[20];
    char number[15];
    int power;
};

void PrintStruct();
void FillStruct();
void SortStruct();

int usercounter = 0;    //Переменная количества пользователей

Autom *autom = new Autom[1];    //Массив структур

void FillStruct() {
    char ch;
    do {
        cout << "Enter name : ";
        cin >> autom[usercounter].name;
        cout << endl << "Enter auto name : ";
        cin >> autom[usercounter].autoname;
        cout << endl << "Enter auto number : ";
        cin >> autom[usercounter].number;
        cout << endl << "Enter power : ";
        cin >> autom[usercounter].power;
        usercounter++;
        cout << endl << "Continue ? (y/n) : ";
        cin >> ch;
    } while(ch != 'n');
    PrintStruct();
}

void PrintStruct() {
    for (int i=0; i<usercounter; i++) {
        cout << "Name " << i + 1 << " : " << autom[i].name << endl;
        cout << "Auto name " << i + 1 << " : " << autom[i].autoname << endl;
        cout << "Auto number " << i + 1 << " : " << autom[i].number << endl;
        cout << "Auto power " << i + 1 << " : " << autom[i].power << endl;
        cout << endl;
    }
    cout << endl << endl << endl;
}

void SortStruct() {         //Пузырьком
        bool exit = false;
        while (!exit) {
            exit = true;
            for (int i=0; i<usercounter-1; i++)
                if (autom[i].power > autom[i+1].power) {
                    swap (autom[i],autom[i+1]);
                    exit = false;
                }
        }
    PrintStruct();
    }

int main()
{
    FillStruct();
    SortStruct();
    delete[] autom;     //Удаляем массив структур
}