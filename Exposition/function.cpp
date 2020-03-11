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

using namespace std;
#define wait(a); Sleep(a);


#define clr system("cls")



ifstream fin;
ofstream fout;




random_device rd;
mt19937 gen(rd());
void print(string s, int tm)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout << char(s[i]);
        wait(tm);
    }
    wait(500);
}

//#define print(s, tm); print(s, 0);
//#define Sleep(a) Sleep(0)
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

void print_col(int x, int n)
{
    while(n--)
    {
        cout << x << ' ';
    }
}

void infile(string names){
        fin.open(names);
        string x;
        while(getline(fin, x))cout << x << endl;
        fin.close();
    }

void print_logo()
{
    int f = 0;
    int ff = 1;
    int i = 5;
    while(i--)
    {
        print_col(ff, 5);
        cout << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        cout << ff << ' ' << f << ' ' << ff << ' ' << f << ' ' << ff << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        print_col(ff, 5);
        cout << endl;
        f = 1 - f;
        ff = 1 - ff;
        wait(1000);
        clr;
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
    print1 ("������������.....");
    cout<<endl;
    wait (1500);
    print1 ("�������������� ������.....");
    wait (1500);
    SetColor( 15, 0);
    clr;
    wait(2000);
    SetColor( 15, 0);
    clr;
}

void tasks()
{
    int col = 95998762;
    for(int i = 0 ; i < 6 ; i++)
    {
        print1("��������� ��������:");
        cout << col;
        cout << endl;
        int a = gen()%4, b = gen()%5;
        int ot = a + b;
        cout << a << '+' << b << '=\n';if(i == 5)cout << "3453468928938 + 34547677634\n";
        int x = -1;
        cin >> x;

        if(i == 5)
        {
            wait(2000);
            crash(500);
            return;
        }

        while(x != ot)
        {
            clr;
            print1("L.A.I:�� �������� ������ �������, ���������� ��� ���");
            cout << endl;
            print1("��������� ��������:");
            cout << col;
            cout << endl;
            cout << a << '+' << b << '=';
            cin >> x;
        }
        col--;

        clr;
    }
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


int saves()
{
    int nm;
    fin.open("saves.txt");
    fin >> nm;
    fin.close();
    if(nm == 1)
    {
        return 1;
    }
    print("������ ���������� � ���������� ����������? (Y/N)", 60);
    cout << endl;
    print("���� ������������:", 60);
    string save;
    while(save!= "Y" && save != "N")
    {
        cin >> save;
        if(save!= "Y" && save != "N")
        {
            cout << endl;
            print("��������� ����������: ��������� ������� �����...", 60);
            cout << endl;
        }
    }
    int num_save;
    if(save == "Y")
    {
        fin.open("saves.txt");
        fin >> num_save;
        fin.close();
        return num_save;
    }
    int nm_save;
    print("������� ����� ����� �� 1 �� 12.", 60);
    cout <<endl;
    while(num_save < 1 || num_save >12)
    {
        print("���� ������������: ", 60);
        cin >> num_save;
        if(num_save < 1 || num_save > 12)
        {
            cout << endl;
            print("��������� ����������: ��������� ������� �����...", 60);
            cout << endl;
        }
        else
        {


            fin.open("saves.txt");
            fin >> nm_save;
            if(nm_save < num_save)
                print("��������� ����������: ��������� ������� �����, �� �� ������ ������� � ���� �����...", 60);
            cout << endl;
            fin.close();

        }
    }
    clr;
    fin.close();

}


void check_nick()
{
    fin.open("nick.txt");
    string nickname;
    fin >> nickname;
    fin.close();
    if (nickname == "")
    {
        print("�� ��� �� ������������� �������, ������� ��� ������ ��������� � ������� ���_�������", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: ��� ��� ��� ������, �� ��������� ������ Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("������������ ������� ���������������, ��������� ���.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("������ �������������� ������.....", 50);
    cout <<endl;
    wait (1000);
    print ("����� ������.", 50);
    cout <<endl;
    wait (1000);
    print ("C���� ������ ������������.....", 50);
    cout<<endl;
    wait (2000);
    print ("C������ �� ���������� ����� � ���� Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("����������� �������...", 150);
    cout << endl;
    wait (1500);
    print ("����������� ����� ���� ��� ����������� ������, ���������� � ������ ��������� ������, ������ � ����� contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("�� ���� ���� �������, �� �� ������ �� ��������. ���� ������(�).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("����� ����: Bill, Dedalius.", 60);
    cout << endl;
    print("����������� ��������� � �����: Dedalius, game ruiner, TemaTop.", 60);
    cout << endl;
    print("������: ������� ����, ��������� ������.", 60);
    cout << endl;
    print("�������� ������� ����������: VaryaSch.", 60);
    cout << endl;
    wait(3000);
    print("�������� ������������� ���� ����� ������� � �������, �������, ��� ������ � ���.", 60);
    cout << endl;
    wait(1000);
    print("���������� ������.", 60);
    print("...", 160);
}



void estimation()
{
    print("������������� ������������", 60);
    print("...........", 200);
    cout << endl;
    wait(400);
    clr;
    print("L.A.I:��� ����� ������������ L.A.I", 50);
    cout << endl;
    wait(1000);
    print("L.A.I:������ ����, Steve175RN34 Emptine", 60);
    cout << endl;
    wait(1000);
    print("L.A.I: ����� ����� ������� ���� ������������ �� ����� �� 1 �� 1000, �� ���������, ��� ��� ������������� ���������������� �� ������ ������ ����� 0", 60);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print("L.A.I:�������� ����� ������������", 50);
    print("...", 1000);
    cout << endl;
    print("Steve:", 60);
    int player_in_estimation;
    cin >> player_in_estimation;
    if(player_in_estimation <= 300)
    {
        print("L.A.I:�������� ����� ������������, ��������� ����", 60);
        clr;
        estimation();
    }
    if(player_in_estimation >= 301 && player_in_estimation <= 999)
    {
        print("L.A.I:����� �� ����� �������� ����������, ��������� ����", 60);
        cout << endl;
        clr;
        print("�� ����������, ��� ������������", 60);
        estimation();
    }
    if(player_in_estimation >= 1000)
    {
        print("L.A.I:����� ������, ��������� ��� ��������", 60);
        clr;
        return;
    }

}


string input(string x, string y)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y)
    {
        print("������ �����, ��������� �������\n", 60);
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
        print("������ �����, ��������� �������\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_1()
{
    int dey = -1;
    int act[] = {1, 1, 1, 1, 1};
    int ach = 0;
    while(dey != 4)
    {
        cin >> dey;

        while(dey > 5 || dey < 1 || act[dey - 1] != 1)
        {
            print("������������ ����. ��������� ������� �����.\n", 60);
            cin >> dey;
        }
        if(dey == 1)
        {
            if(act[0] == 1)
            {
                act[0] = 0;
                wait(1000);
                print("������� ����������� � ������������ ������, �� ������� ������ �������� ������������ ���������� ���� �� ������-�� ��������� ���� ���������� (��� �� ������� ��������� ���� ������ ������� �� �������� �������).\n", 60);
                print("������ ������ ��������� ������������� ���������� ������ ������� ��������. �� ����� ����� ��������� ��� ���������� ����� � �������, ����� ��� �������� �������. �� ����� ����� ��� � ����� ������ � ������� �����������.\n", 60);
                print(" � ������ ������, ����� �������� ����������� ������� ����� ����������� ���������� ���� ��������, ������� �� ������� ����� �������� ������. ���� ����� ������������ �� ���� ���� � ����� ��� 1000 �������, �� ������ ���� ������� �����: '��� ���� ������� �����������' � '���� ������ � �����'. �������, �� ���� ����� ��������� �� ������ ����������� ������, �� � ��������� ��������� �� �� ��������� ������ ������� ����������./n", 60);
                print(" �� ������� ���� ��������: '�������� ������ ���� �� 175 ��������� ��������� ������� � ������� ������ �����������!'. ���� ���� �������� ����� ������� � �������: ������������ '������'.", 70);
                print(" �� ������ ������� ��� ����������� �������� ��� ��� ���� ������� � ���������, ��� ����������� ����, ��� ������ ����� ���� ������ ����� ������ ��������� � ��� ���������� � '�������������' ����������. ", 60);
                print(" ��� ������� ������ ������ ��� -", 70);
                wait(500);
                print(" � ������� ��������� �������, �������� ������ ���������� ����� ����, ���������� ���� ������� �����, �������, � ����� ������� ��������, ���������� ����� ��������� ��� �� �������� ������ �������� � ��� �������� ����� ������, ������� ������ ��� ���� � ����� �������.", 70);
                print(" ������� ����� ��������� ���� ����� � ����������� ��� � ��������� ���, � ����� ����������� �� ��� �����, ��������� ���� ���� ������.", 70);
                wait(700);
                print(" ��� �����.", 80);
                print(" �����, ��� ��������� ������, ��� �� ��� ����� ����� �� ������.", 80);
                print(" ���� ����� ���� �� ������������� ������������ ������. ������������ ��� �� ������������ ������������ ��� �������� �� ��� ���������� ��� �����, ��� ����������� � ������� ����������� � ���� ������ ������ ������� � ������ ���������� �� ����� ��������.", 70);
                print(" ������� �� ������ ���������� �� ��� ��� ����� ������, � ��� ���� �� ���� ������� ��������. �� ���� � ��� ���� �� ���� ������, ������ � ������, �� � ������, ������� ����� ��������� ������.", 70);
                print(" ������ ��� ������ �� �� �����. �� ������� ���� ������� �� ���� �����, �� ������ � ��������� ���, �������� ��� � � �������, ��������� ������� �� ����� ��������, ��� ���� ���� ������ �����, ������ ����� ������������ ������ ����, �� ���� ������, ������ ������� ��������, �������� �� �������� �������, ��� ���-��� ����������� ���� ������� �����.", 70);
                print(" ����, ���������� ��������� � �������, ��� ���� ������� ����� � ��� ������� �����.", 70);
                print(" �� ��� ��������� ����� ���������, ������ ����������� ������ ������� ����������� �������� � ��������� � ������ �����, �� ���� ������� ������������ ������� ������ ��������.", 70);
                print(" ������ ������ ����������� � ���������� �������� �� ���������.\n", 60);
                print(" �� ������� �������� ���� ������� � ����� ���, � ��������� �������� �� �� ���� �������, ����� ���� ������� ����.", 70);
                wait(1000);
                print("������ ������ ����������� � ���������� �������� �� ���������.\n", 60);
                wait(1000);
                print("������ ���� �������� ������� ����������� ������� ������, ��������� ������������� ��������� �����: '���� ������...', '��������� ��������� X � 122-����...', '����� �������� �����...'\n", 60);
                print("�� ���� ����� ��������, �������������, � � ���� ����� ������������� ��������\n", 60);
                print("��� ������ ������...\n", 60);
                print("�� �� � ����� �������������...\n", 60);
                print("��� ����� �� ������� � ���������� �� ��������� �������...\n", 60);
                print("1. ������� ������\n", 60);
                print("2. ������� �� ���\n", 60);
                while(1)
                {
                    int gazet;
                    cin >> gazet;
                    if(gazet == 1)
                    {
                        print("���� ���������� �� ������, �� ������������� ������������� ��������\n", 30);
                        print("�� ������� ����������� �� ���� ������\n", 30);
                        print("�� ���� ��� ���������\n", 30);
                        wait(3000);
                        print("���� �� ���������� ���������� ������ �� ������, ���� ������, ��� � ���� ��������� �� �� ������, ������ ������� ������ ������� ���������\n", 60);
                        print("����� ��� ���� �� ���������, �� ������ �������� �� ����� � ������ ��������� �� ���-������ ����� �������\n", 60);
                        wait(2000);
                        clr;
                        break;
                    }
                    else if(gazet == 2)
                    {
                        print("�� �������, ��� ������� ������ �� ������� ������ �������� � ������ ���������� �� �����\n", 60)
                        wait(1000);
                        clr;
                        ach++;
                        break;
                    }
                    else
                    {
                        print("��������� ������� �����\n", 60);
                        wait(1000);
                    }
                    clr;
                    cout << "1. ������� ������\n";
                    cout << "2. ������� �� ���\n";
                }
            }


        }
        if(dey == 2)
        {
            act[1] = 0;
            print("�� ������ ������� ������������ ����� � ����� ������ �����.\n", 60);
            print("�� ����� �����������, ��� � ������ �������� ��������� ������������ ����� �� ����� ������ ������� ������ ����.\n", 60);
            print("����� ��� �������� ����� ������������ ��������.\n", 60);
            print("�������� � ��� �� ������ �������������� �������, ������� �������� SLOPO.inc ��������� �� ������ ����� ������, '���� ���� �����', ������� ����\n", 60);
            print("����� �� ����� ������������ ��������� � ����������� �����.\n", 60);
            wait(1000);
            print("1. ������ ����� �� ������(����� ���� �� ��� ������)\n", 60);
            print("2. ���������\n", 60);
            while(1)
            {
                int cask;
                cin >> cask;
                if(cask == 1)
                {
                    clr;
                    fin.open("flag.txt");
                    string flag;
                    ach++;
                    while(getline(fin, flag))
                    {
                        for(int i = 0; i < flag.size(); i++)
                        {
                            if(flag[i] == '%')
                            {
                                SetColor(4, 0);
                            }
                            else
                            {
                                SetColor(14, 0);
                            }
                            cout << flag[i];
                        }
                        cout << endl;
                    }
                    fin.close();
                }
                else
                {
                    break;
                }

            }

        }
        if(dey == 3)
        {
            act[2] = 0;
            print("��� �� �� �� ���������, �� ������ �� ������ ���������, ��� ������ ������ ���� '������'.\n", 60);
            print("�� ���� ������ ��������� ����������� � ����, ��� ����� ������ �������� �������� ���������, ���-����� ����� ���� ����������.\n", 60);
            print("����� ������� ������ �������� �������, ����� � ��� ���� ����� ����������\n", 60);
            wait(1000);
            for(int i = 0; i < 29998 * 4; i++)
            {
                cout <<char(gen() % 256);
            }
            clr;
            print("�� ����� ��������� ��� �� ����, � ����� � ������ ���� ������, ��� ������� ������.\n", 60);
            print("�� �������, ��� ��� ���������� ������� ������������� ��������, ������� ���������� ����������� ����� � ����, ����� �������� ����.\n", 60);
            print("��� ��������� '������' - ��� ������ ������� ������ ��������\n", 60);
            print("��� ������ ������ ������ ����� SLOPE(��� ��� ������ ��, ������ ���� ���������� SLOPPO.inc).\n", 60);
            wait(1000);
        }
        if(dey == 4)
        {
            act[3] = 0;
            print("�� ��������� � ������� �����, �������, ����� ������������ ������ ���-��� ��������� �� ��������� �������\n", 60);
            print("�� ������� ���� ���������� ��������. ���� �� ������, �� �������� �� ���� ���� � ������� ��������� � ����� �������\n", 60);
            print("����� ����� ��� ��������� ��������, ����� ��� � ������ � ������� �����, �� � ������� � 1 �� ��� ������� ��������\n", 60);
            print("��������� ������ ��� �������� ���������, � ��� ��� � ���� �����?\n", 60);
            print("���� ����� ��� ��-�� ���������� ��.\n", 60);
            wait(1000);
        }
        if(dey == 5)
        {
            print("����� � ���� ������, �������� ��. �� ������������ � ����� �������, ���� �� ������ ������� ��� �� ����� ����� ���� �������.\n", 60);
            wait(1000);
            break;
        }
        if(dey == 6 && act[5] == 0){
            print("6.����! ��� ������-������ �������� ���� ������ �������� � ����(��� ���) ��� ���� ����.", 60);
        }
        int root = 0;
        for(int i = 0; i < 4; i++)
            root += act[i];
        clr;
        if(act[0] == 0)
            SetColor(8, 0);
        print("1.�������� � ��������.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[1] == 0)
            SetColor(8, 0);
        print("2.��������� ������������� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[2] == 0)
            SetColor(8, 0);
        print("3.���������� ������ ������ �� ��������� ��������, ��������� �� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[3] == 0)
            SetColor(8, 0);
        print("4.��������� ������ �� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[4] == 0)
            SetColor(8, 0);
        print("5.����� � ���� ������ (��������� � LAI).", 60);
        SetColor(7, 0);
        if(root == 0)
        {
            act[5] = 0;
            fout.open("achievement.txt");
            fout << "Geduld, mein Freund";
            fout.close();
        }
    }
}



void logo()
{


    cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
    wait(1000);
    for(int i = 0; i < 10; i++)
    {
        clr;
        cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
        cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
        cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
        clr;
        wait(gen()%200);
    }
    wait(3000);
    clr;
}


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

using namespace std;
#define wait(a); Sleep(a);


#define clr system("cls")



ifstream fin;
ofstream fout;




random_device rd;
mt19937 gen(rd());
void print(string s, int tm)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout << char(s[i]);
        wait(tm);
    }
    wait(500);
}

//#define print(s, tm); print(s, 0);
//#define Sleep(a) Sleep(0)
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

void print_col(int x, int n)
{
    while(n--)
    {
        cout << x << ' ';
    }
}

void print_logo()
{
    int f = 0;
    int ff = 1;
    int i = 5;
    while(i--)
    {
        print_col(ff, 5);
        cout << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        cout << ff << ' ' << f << ' ' << ff << ' ' << f << ' ' << ff << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        print_col(ff, 5);
        cout << endl;
        f = 1 - f;
        ff = 1 - ff;
        wait(1000);
        clr;
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
    print1 ("������������.....");
    cout<<endl;
    wait (1500);
    print1 ("�������������� ������.....");
    wait (1500);
    SetColor( 15, 0);
    clr;
    wait(2000);
    SetColor( 15, 0);
    clr;
}

void tasks()
{
    int col = 95998762;
    for(int i = 0 ; i < 6 ; i++)
    {
        print1("��������� ��������:");
        cout << col;
        cout << endl;
        int a = gen()%4, b = gen()%5;
        int ot = a + b;
        cout << a << '+' << b << '=\n';if(i == 5)cout << "3453468928938 + 34547677634\n";
        int x = -1;
        cin >> x;

        if(i == 5)
        {
            wait(2000);
            crash(500);
            return;
        }

        while(x != ot)
        {
            clr;
            print1("L.A.I:�� �������� ������ �������, ���������� ��� ���");
            cout << endl;
            print1("��������� ��������:");
            cout << col;
            cout << endl;
            cout << a << '+' << b << '=';
            cin >> x;
        }
        col--;

        clr;
    }
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


int saves()
{
    int nm;
    fin.open("saves.txt");
    fin >> nm;
    fin.close();
    if(nm == 1)
    {
        return 1;
    }
    print("������ ���������� � ���������� ����������? (Y/N)", 60);
    cout << endl;
    print("���� ������������:", 60);
    string save;
    while(save!= "Y" && save != "N")
    {
        cin >> save;
        if(save!= "Y" && save != "N")
        {
            cout << endl;
            print("��������� ����������: ��������� ������� �����...", 60);
            cout << endl;
        }
    }
    int num_save;
    if(save == "Y")
    {
        fin.open("saves.txt");
        fin >> num_save;
        fin.close();
        return num_save;
    }
    int nm_save;
    print("������� ����� ����� �� 1 �� 12.", 60);
    cout <<endl;
    while(num_save < 1 || num_save >12)
    {
        print("���� ������������: ", 60);
        cin >> num_save;
        if(num_save < 1 || num_save > 12)
        {
            cout << endl;
            print("��������� ����������: ��������� ������� �����...", 60);
            cout << endl;
        }
        else
        {


            fin.open("saves.txt");
            fin >> nm_save;
            if(nm_save < num_save)
                print("��������� ����������: ��������� ������� �����, �� �� ������ ������� � ���� �����...", 60);
            cout << endl;
            fin.close();

        }
    }
    clr;
    fin.close();

}


void check_nick()
{
    fin.open("nick.txt");
    string nickname;
    fin >> nickname;
    fin.close();
    if (nickname == "")
    {
        print("�� ��� �� ������������� �������, ������� ��� ������ ��������� � ������� ���_�������", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: ��� ��� ��� ������, �� ��������� ������ Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("������������ ������� ���������������, ��������� ���.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("������ �������������� ������.....", 50);
    cout <<endl;
    wait (1000);
    print ("����� ������.", 50);
    cout <<endl;
    wait (1000);
    print ("C���� ������ ������������.....", 50);
    cout<<endl;
    wait (2000);
    print ("C������ �� ���������� ����� � ���� Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("����������� �������...", 150);
    cout << endl;
    wait (1500);
    print ("����������� ����� ���� ��� ����������� ������, ���������� � ������ ��������� ������, ������ � ����� contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("�� ���� ���� �������, �� �� ������ �� ��������. ���� ������(�).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("����� ����: Bill, Dedalius.", 60);
    cout << endl;
    print("����������� ��������� � �����: Dedalius, game ruiner, TemaTop.", 60);
    cout << endl;
    print("������: ������� ����, ��������� ������.", 60);
    cout << endl;
    print("�������� ������� ����������: VaryaSch.", 60);
    cout << endl;
    wait(3000);
    print("�������� ������������� ���� ����� ������� � �������, �������, ��� ������ � ���.", 60);
    cout << endl;
    wait(1000);
    print("���������� ������.", 60);
    print("...", 160);
}



void estimation()
{
    print("������������� ������������", 60);
    print("...........", 200);
    cout << endl;
    wait(400);
    clr;
    print("L.A.I:��� ����� ������������ L.A.I", 50);
    cout << endl;
    wait(1000);
    print("L.A.I:������ ����, Steve175RN34 Emptine", 60);
    cout << endl;
    wait(1000);
    print("L.A.I: ����� ����� ������� ���� ������������ �� ����� �� 1 �� 1000, �� ���������, ��� ��� ������������� ���������������� �� ������ ������ ����� 0", 60);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print("L.A.I:�������� ����� ������������", 50);
    print("...", 1000);
    cout << endl;
    print("Steve:", 60);
    int player_in_estimation;
    cin >> player_in_estimation;
    if(player_in_estimation <= 300)
    {
        print("L.A.I:�������� ����� ������������, ��������� ����", 60);
        clr;
        estimation();
    }
    if(player_in_estimation >= 301 && player_in_estimation <= 999)
    {
        print("L.A.I:����� �� ����� �������� ����������, ��������� ����", 60);
        cout << endl;
        clr;
        print("�� ����������, ��� ������������", 60);
        estimation();
    }
    if(player_in_estimation >= 1000)
    {
        print("L.A.I:����� ������, ��������� ��� ��������", 60);
        clr;
        return;
    }

}


string input(string x, string y)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y)
    {
        print("������ �����, ��������� �������\n", 60);
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
        print("������ �����, ��������� �������\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_1()
{
    int dey = -1;
    int act[] = {1, 1, 1, 1, 1};
    int ach = 0;
    while(dey != 4)
    {
        cin >> dey;

        while(dey > 5 || dey < 1 || act[dey - 1] != 1)
        {
            print("������������ ����. ��������� ������� �����.\n", 60);
            cin >> dey;
        }
        if(dey == 1)
        {
            if(act[0] == 1)
            {
                act[0] = 0;
                wait(1000);
                print("������� ����������� � ������������ ������, �� ������� ������ �������� ������������ ���������� ���� �� ������-�� ��������� ���� ����������(��� �� ������� ��������� ���� ������ ������� �� �������� �������).\n", 60);
                print("������ ������ 3 ���������� ����� ��� ���������� �������.\n", 60);
                print("��� ���� ��� ���� � 1000 �������, �� ������ ���� ��������: '��� ���� ������� �����������. ���� ������ � �����' � ������� ��� 1, 2, 3(��� ��������� �� 175)./n", 60);
                print("������ ������ ����������� � ���������� �������� �� ���������.\n", 60);
                wait(1000);
                print("������ ���� �������� ������� ����������� ������� ������, ��������� ������������� ��������� �����: '���� ������...', '��������� ��������� X � 122-����...', '����� �������� �����...'\n", 60);
                print("�� ���� ����� ��������, �������������, � � ���� ����� ������������� ��������\n", 60);
                print("��� ������ ������...\n", 60);
                print("�� �� � ����� �������������...\n", 60);
                print("��� ����� �� ������� � ���������� �� ��������� �������...\n", 60);
                print("1. ������� ������\n", 60);
                print("2. ������� �� ���\n", 60);
                while(1)
                {
                    int gazet;
                    cin >> gazet;
                    if(gazet == 1)
                    {
                        print("���� ���������� �� ������, �� ������������� ������������� ��������\n", 30);
                        print("�� ������� ����������� �� ���� ������\n", 30);
                        print("�� ���� ��� ���������\n", 30);
                        wait(3000);
                        print("���� �� ���������� ���������� ������ �� ������, ���� ������, ��� � ���� ��������� �� �� ������, ������ ������� ������ ������� ���������\n", 60);
                        print("����� ��� ���� �� ���������, �� ������ �������� �� ����� � ������ ��������� �� ���-������ ����� �������\n", 60);
                        wait(2000);
                        clr;
                        break;
                    }
                    else if(gazet == 2)
                    {
                        print("�� �������, ��� ������� ������ �� ������� ������ �������� � ������ ���������� �� �����\n", 60)
                        wait(1000);
                        clr;
                        ach++;
                        break;
                    }
                    else
                    {
                        print("��������� ������� �����\n", 60);
                        wait(1000);
                    }
                    clr;
                    cout << "1. ������� ������\n";
                    cout << "2. ������� �� ���\n";
                }
            }


        }
        if(dey == 2)
        {
            act[1] = 0;
            print("�� ������ ������� ������������ ����� � ����� ������ �����.\n", 60);
            print("�� ����� �����������, ��� � ������ �������� ��������� ������������ ����� �� ����� ������ ������� ������ ����.\n", 60);
            print("����� ��� �������� ����� ������������ ��������.\n", 60);
            print("�������� � ��� �� ������ �������������� �������, ������� �������� SLOPO.inc ��������� �� ������ ����� ������, '���� ���� �����', ������� ����\n", 60);
            print("����� �� ����� ������������ ��������� � ����������� �����.\n", 60);
            wait(1000);
            print("1. ������ ����� �� ������(����� ���� �� ��� ������)\n", 60);
            print("2. ���������\n", 60);
            while(1)
            {
                int cask;
                cin >> cask;
                if(cask == 1)
                {
                    clr;
                    fin.open("flag.txt");
                    string flag;
                    ach++;
                    while(getline(fin, flag))
                    {
                        for(int i = 0; i < flag.size(); i++)
                        {
                            if(flag[i] == '%')
                            {
                                SetColor(4, 0);
                            }
                            else
                            {
                                SetColor(14, 0);
                            }
                            cout << flag[i];
                        }
                        cout << endl;
                    }
                    fin.close();
                }
                else
                {
                    break;
                }

            }

        }
        if(dey == 3)
        {
            act[2] = 0;
            print("��� �� �� �� ���������, �� ������ �� ������ ���������, ��� ������ ������ ���� '������'.\n", 60);
            print("�� ���� ������ ��������� ����������� � ����, ��� ����� ������ �������� �������� ���������, ���-����� ����� ���� ����������.\n", 60);
            print("����� ������� ������ �������� �������, ����� � ��� ���� ����� ����������\n", 60);
            wait(1000);
            for(int i = 0; i < 29998 * 4; i++)
            {
                cout <<char(gen() % 256);
            }
            clr;
            print("�� ����� ��������� ��� �� ����, � ����� � ������ ���� ������, ��� ������� ������.\n", 60);
            print("�� �������, ��� ��� ���������� ������� ������������� ��������, ������� ���������� ����������� ����� � ����, ����� �������� ����.\n", 60);
            print("��� ��������� '������' - ��� ������ ������� ������ ��������\n", 60);
            print("��� ������ ������ ������ ����� SLOPE(��� ��� ������ ��, ������ ���� ���������� SLOPPO.inc).\n", 60);
            wait(1000);
        }
        if(dey == 4)
        {
            act[3] = 0;
            print("�� ��������� � ������� �����, �������, ����� ������������ ������ ���-��� ��������� �� ��������� �������\n", 60);
            print("�� ������� ���� ���������� ��������. ���� �� ������, �� �������� �� ���� ���� � ������� ��������� � ����� �������\n", 60);
            print("����� ����� ��� ��������� ��������, ����� ��� � ������ � ������� �����, �� � ������� � 1 �� ��� ������� ��������\n", 60);
            print("��������� ������ ��� �������� ���������, � ��� ��� � ���� �����?\n", 60);
            print("���� ����� ��� ��-�� ���������� ��.\n", 60);
            wait(1000);
        }
        if(dey == 5)
        {
            print("����� � ���� ������, �������� ��. �� ������������ � ����� �������, ���� �� ������ ������� ��� �� ����� ����� ���� �������.\n", 60);
            wait(1000);
            break;
        }
        if(dey == 6 && act[5] == 0){
            print("6.����! ��� ������-������ �������� ���� ������ �������� � ����(��� ���) ��� ���� ����.", 60);
        }
        int root = 0;
        for(int i = 0; i < 4; i++)
            root += act[i];
        clr;
        if(act[0] == 0)
            SetColor(8, 0);
        print("1.�������� � ��������.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[1] == 0)
            SetColor(8, 0);
        print("2.��������� ������������� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[2] == 0)
            SetColor(8, 0);
        print("3.���������� ������ ������ �� ��������� ��������, ��������� �� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[3] == 0)
            SetColor(8, 0);
        print("4.��������� ������ �� �����.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[4] == 0)
            SetColor(8, 0);
        print("5.����� � ���� ������ (��������� � LAI).", 60);
        SetColor(7, 0);
        if(root == 0)
        {
            act[5] = 0;
            fout.open("achievement.txt");
            fout << "Geduld, mein Freund";
            fout.close();
        }
    }
}



void logo()
{


    cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
    wait(1000);
    for(int i = 0; i < 10; i++)
    {
        clr;
        cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
        cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
        cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
        clr;
        wait(gen()%200);
    }
    wait(3000);
    clr;
}


