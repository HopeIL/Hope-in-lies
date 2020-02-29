#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <clocale>

//#define int int64_t
using namespace std;
#define wait Sleep


#define clr system("cls")



ifstream fin;
ofstream fout;




random_device rd;
mt19937 gen(rd());


enum ConsoleColor
{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, ConsoleColor/*int*/ background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void print(string s, int tm)
{
    //SetColor(0, 15);
    for(int i = 0; i < s.size(); i++)
    {
        cout << char(s[i]);
        wait(tm);
    }
    wait(500);
}
void print_col(int x, int n)
{
    while(n--)
    {
        cout << x << ' ';
    }
}

void load(int x)
{
    string s;
    for(int i = 0; i <= x; i++)
    {
        cout << i  << '%' << endl;
        cout << s;
        s += '_';
        wait(80);
        clr;
    }
}

void print1(string x)
{
    for (int i=0; i<x.size(); ++i)
    {
        cout << x[i];
        wait(75);
    }
}

void crash(int x)
{
    for (int j = 0; j < x; ++j)
    {
        SetColor(gen()%16, gen()%16);
        cout << ' ';
        for (int i=0; i<gen()%100+50; ++i)
        {
            cout << char (gen()%50+10);/*wait(1);*/
        }
        cout << ' ';
    }
    SetColor( 15, 0);
    clr;
    wait (1500);
    string ans="Fatal error 453";
    print1(ans);
    wait (1500);
    cout << endl;
    print1 ("Перезагрузка.....");
    cout<<endl;
    wait (1500);
    print1 ("Восстановление данных.....");
    wait (1500);
    SetColor( 15, 0);
    clr;
    wait(2000);
    SetColor( 15, 0);
    clr;
}

void update_save()
{
    fin.open("saves.txt");
    int x;
    fin >> x;
    fin.close();
    fout.open("saves.txt", ios_base::trunc);
    fout << x + 1;
    fout.close();
}


void check_nick()
{
    fin.open("nick.txt");
    string nickname;
    fin >> nickname;
    fin.close();
    if (nickname == "")
    {
        print("Вы еще не представились системе, введите имя вашего персонажа в формате ИМЯ_ФАМИЛИЯ", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: Это имя уже занято, из свободных только Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("Пользователь успешно зарегистрирован, приятного дня.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("Ошибка восстановления данных.....", 50);
    cout <<endl;
    wait (1000);
    print ("Утеря данных.", 50);
    cout <<endl;
    wait (1000);
    print ("Cброс данных пользователя.....", 50);
    cout<<endl;
    wait (2000);
    print ("Cпасибо за проведённое время в игре Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("Продолжение следует...", 150);
    cout << endl;
    wait (1500);
    print ("Предложения своих идей для продолжения сюжета, отправлять в личные сообщения группы, ссылка в файле contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("Во всем есть красота, но не каждый ее замечает. Энди Уорхол(с).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("Автор идеи: Bill, Dedalius.", 60);
    cout << endl;
    print("Технические наработки и релиз: Dedalius.", 60);
    cout << endl;
    wait(3000);
    print("Огромная благодарность всем нашим друзьям и близким, спасибо, что верили в нас.", 60);
    cout << endl;
    wait(1000);
    print("Завершение работы.", 60);
    print("...", 160);
}

string input(string x, string y)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y)
    {
        print("Ошибка ввода, повторите попытку\n", 60);
        cin >> ans;
    }
    return ans;
}
string input(string x)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x)
    {
        if(ans.find(x)!= -1)
        {
            print("Очистите все от лишних символов и повторите ввод\n", 60);
            //cout << "Странно, мой процессор ожидал не тумбочку за вашим столом, попробуйте еще раз" << endl;
        }
        else
        {
            print("Ошибка ввода, повторите попытку\n", 60);
        }
        cin >> ans;
    }
    return ans;
}

string input(string x, string y, string z)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y && ans != z)
    {
        print("Ошибка ввода, повторите попытку\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_2()
{

}

void eye_logo()
{
    string s[25];
    s[0] = "--------------------------------------------------";
    s[1] = "--------------------------------------------------";
    s[2] = "--------------------------------------------------";
    s[3] = "--------------------------------------------------";
    s[4] = "--------------------------------------------------";
    s[5] = "--------------------------------------------------";
    s[6] = "--------------------------------------------------";
    s[7] = "-----------------+@############@*-----------------";
    s[8] = "-------------*#####@-        :#####@:-------------";
    s[9] = "-----------%#####=      *%+.   .@#####+-----------";
    s[10] = "---------=######*       .####=   =######*---------";
    s[11] = "--------#######%        =#####%   #######@--------";
    s[12] = "-------########+  :############.  %#######@-------";
    s[13] = "--------#######%   ###########%   #######@--------";
    s[14] = "---------=######*  .%########+   =######*---------";
    s[15] = "-----------=#####%.   -+==*.   .@#####+-----------";
    s[16] = "-------------:#####@-        :#####@--------------";
    s[17] = "-----------------*@############%*-----------------";
    s[18] = "--------------------------------------------------";
    s[19] = "--------------------------------------------------";
    s[20] = "--------------------------------------------------";
    s[21] = "--------------------------------------------------";
    s[22] = "--------------------------------------------------";
    s[23] = "--------------------------------------------------";
    s[24] = "--------------------------------------------------";
    for(int i = 0; i < s[0].size(); i++)
    {
        for(int j = 0; j < 25; j++)
        {
            COORD position = {i, j}; //позиция x и y
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(hConsole, position);
            cout << s[j][i];
        }
        wait(200);
    }
    for(int z = 0; z < 20; z++)
    {
        clr;
        for(int i = 0; i < s[0].size(); i++)
        {
            for(int j = 0; j < 25; j++)
            {
                COORD position = {i, j}; //позиция x и y
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleCursorPosition(hConsole, position);
                if((gen() % (25 - z))%3 != 0)

                    cout << s[j][i];
                else
                    cout << char(rand()%256);
            }
        }
        clr;
        wait(gen()%25);
    }
}

void browser_logo()
{
    string s[25];
    s[0] = "]]]]]...]]]]]....]]]]...]]]]]...]]]]]]..]]..]]..]]]]]...]]]]].";
    s[1] = "]]..]]..]]......]]..]]..]]........]]....]]..]]..]]......]]..]]";
    s[2] = "]]..]]..]]]]....]]......]]]]......]]....]]..]]..]]]]....]]]]].";
    s[3] = "]]..]]..]]......]]..]]..]]........]].....]]]]...]]......]]..]]";
    s[4] = "]]]]]...]]]]]....]]]]...]]]]]...]]]]]]....]]....]]]]]...]]..]]";

    wait(1000);
    for(int i = 0; i < s[0].size(); i++)
    {
        for(int j = 0; j < 5; j++)
        {
            COORD position = {i, j}; //позиция x и y
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(hConsole, position);
            cout << s[j][i];
        }
        wait(200);
    }
}

void color (int x, int y)
{
    SetColor(x, y);
}

void browser(bool error)
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN);
    fin.open("browser.txt");
    string browser;
    int k = 0;
    while(getline(fin, browser))
    {
        k++;

        for(int i = 0; i < browser.size(); i++)
        {
            if(error == 1)
                goto error;
            if(k == 40)
                if((browser[i] >= 'A' && browser[i] <= 'Z') ||(browser[i] == ')' || browser[i] == '('))
                {
                    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);

                }
error:
            cout << browser[i];
            HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN);
        }
        cout << endl;
    }

    fin.close();
}


void porthack()
{
    fin.open("port.txt");
    string port;
    fin >> port;
    int k = -1;
    int z = 1;
    fin.close();
    while(z)
    {
        z = 0;
        for(int i = 0; i < port.size(); i++)
        {
            k++;
            if(k > 72)
            {
                cout << endl;
                k = 0;
            }
            if(port[i] != 'Z')
                z = 1;
            cout << port[i];
            if(port[i] != 'Z')
                port[i] += (gen() + 1) % 2;
            if(port[i] > '9')
                port[i] = 'Z';
        }
        clr;
    }




}



