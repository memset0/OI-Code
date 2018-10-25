#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iostream>

using namespace std;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define inf 2147483647

struct type_block
{
    int a[10][10];
    int color;
    int size;
}now, nextA, nextB, nextC, hold;

int sblock[20][10][10] = {{{7, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
{{8, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
{{9, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
{{10, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 0}},
{{13, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}},
{{5, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
{{16, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}},

{{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}},
{{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}},
{{2, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
{{11, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
{{12, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}}, //11
{{3, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},
{{14, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
{{15, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
{{4, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 0}},
{{17, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}},
{{18, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}}, //17
{{6, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}}};

HANDLE hOut = GetStdHandle (STD_OUTPUT_HANDLE);
int map[22][12];
int mode = 1;
int fraction = 0;
int positionX, positionY;
bool locked;
int keytime = 100000000;
bool keytimeflag;
int sleeptime = 0;
bool holdflag = 1;
int passcondition = 200;
int addlinetime = 10000, addlineflag;
int locktime = 1000;
int keydownflag;
int xray = 0;
int firstwin = 1;
int exfraction = 0;
int exgamestarttime;
int blind = 0;
int lockdelay = 300;
int clockms, stclockms;
double blockpersecond, blockperminute;
int blocknum;

void gotoxy (int x, int y);
void welcomepage ();
void reset ();
void choosedifficulty ();
void ready_go ();
void updatedata ();
void updatetime ();
type_block roundblock ();
void printblock (type_block m_block, int x, int y);
void clearblock (type_block m_block, int x, int y);
int checkblock (type_block m_block, int x, int y);
type_block myup (type_block m_block);
type_block mydown (type_block m_block);
void checkkey ();
void checkline ();
void addline ();
void gameover ();
void win ();
void easy_extra_game ();
void master_extra_game ();
void shirase_extra_game ();

int main()
{
    welcomepage ();
    reset ();
    choosedifficulty();
    ready_go ();
    clearblock (nextA, 34, 4); clearblock (nextB, 38 + nextA.size, 4); clearblock (nextC, 42 + nextA.size + nextB.size, 4);
    now = nextA; nextA = nextB; nextB = nextC; nextC = roundblock();
    printblock (nextA, 34, 4); printblock (nextB, 38 + nextA.size, 4); printblock (nextC, 42 + nextA.size + nextB.size, 4);
    positionX = 0; positionY = 4; locked = 0;
    keytime = clock(); keytimeflag = 1;
    addlineflag = clock (); stclockms = clock ();
        while (1)
        {
            updatedata (); updatetime ();
            if (locked)
            {
                ++blocknum;
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                now.color = -xray * 2;
                printblock (now, positionY * 2 + 8, positionX + 1);
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (!(i + j))
                            continue;
                        if (now.a[i][j]) 
                            map[positionX + i][positionY + j] = 1;
                    }
                }
                checkline ();
                Sleep (lockdelay);
                updatetime ();
                if (blind)
                    clearblock (now, positionY * 2 + 8, positionX + 1);
                locked = 0;
                clearblock (nextA, 34, 4); clearblock (nextB, 38 + nextA.size, 4); clearblock (nextC, 42 + nextA.size + nextB.size, 4);
                now = nextA; nextA = nextB; nextB = nextC; nextC = roundblock();
                printblock (nextA, 34, 4); printblock (nextB, 38 + nextA.size, 4); printblock (nextC, 42 + nextA.size + nextB.size, 4);
                positionX = 0; positionY = 4;
                if (!checkblock (now, positionX, positionY))
                    gameover ();
                if (fraction % 100 != 99 && fraction != passcondition)
                    ++fraction;
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                gotoxy (56, 10);
                printf ("%4d", fraction);
                gotoxy (57, 11);
                printf ("---");
                gotoxy (56, 12);
                int lssc = fraction % 100 ? (fraction / 100 + 1) * 100 : fraction;
                if (mode == 1 && lssc >= 200) lssc = 200;
                if (mode == 2 && lssc >= 999) lssc = 900;
                if (mode == 3 && lssc >= 1300) lssc = 1300;
                printf ("%4d", lssc);
                keytime = clock(); holdflag = 1;
                if (clock () - addlineflag > addlinetime)
                {
                    addlineflag = clock ();
                    addline ();
                }
                keydownflag = 0;
            }
            if (checkblock (now, positionX + 1, positionY))
            while (checkblock (now, positionX + 1, positionY))
            {
                ++positionX; updatetime ();
                if (sleeptime)
                {
                    printblock (now, positionY * 2 + 8, positionX + 1);
                    int sttime = clock (), timeover;
                    while ((timeover = (clock () - sttime < sleeptime)) && !kbhit());
                    clearblock (now, positionY * 2 + 8, positionX + 1);
                    if (timeover)
                        checkkey ();
                }
                checkkey ();
            }
            printblock (now, positionY * 2 + 8, positionX + 1);
            Sleep (100);
            clearblock (now, positionY * 2 + 8, positionX + 1);
            checkkey ();
        }
}

void gotoxy (int x, int y)
{
    COORD pos;
    pos.X = x; pos.Y = y;
    SetConsoleCursorPosition (hOut, pos);
}
void welcomepage ()
{
    puts ("                                                                               ");
    puts ("   ■■■■■■■■■■                                                        ");
    puts ("   ■■■■■■■■■■                                                        ");
    puts ("           ■■                                                                ");
    puts ("           ■■                                                                ");
    puts ("           ■■                                                                ");
    puts ("           ■■          ■■■■      ■     ■         ■    ■■■          ");
    puts ("           ■■          ■    ■   ■■■■  ■ ■■■      ■      ■        ");
    puts ("           ■■          ■■■■      ■     ■■       ■  ■                ");
    puts ("           ■■          ■            ■     ■         ■    ■■■          ");
    puts ("           ■■          ■■■■      ■     ■         ■          ■        ");
    puts ("                                                                     ■        ");
    puts ("                                                             ■■■■          ");
    puts ("                                                                               ");
    puts ("     ------------------------------------------------------------------        ");
    puts ("                             ＣＨＡＭＰＩＯＮ                                  ");
    puts ("                                                                               ");
    puts ("                   Can you survive for more than 5 minutes ?                   ");
    puts ("   F顺时针   D逆时针  space 坠落 J 左 L 右 IK选择难度   空格确认难度           ");
    puts ("                                                                               ");
    puts ("                                                                               ");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    int modnum = 0;
    while (1)
    {
        gotoxy (22, 20);
        if (modnum)
            puts ("ＰＵＳＨ　ＳＴＡＲＴ　ＢＵＴＴＯＭ(按下Space)");
        else
            puts ("                                  ");
        int sttime = clock (), timeover;
        while ((timeover = (clock () - sttime < 700)) && !kbhit());
        if (timeover)
        {
            if (_getch () == ' ')
                break;
        }
        modnum ^= 1;
    }
    gotoxy (0, 0);
    for (int i = 1; i <= 25; ++i)
        puts ("                                                                               ");
    gotoxy (0, 0);
}
void reset ()
{
    srand (time (0));
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    puts ("");
    puts ("        ■■■■■■■■■■■■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■                    ■");
    puts ("        ■■■■■■■■■■■■");
    nextA = roundblock (); nextB = roundblock (); nextC = roundblock ();
    for (int i = 34; i <= 34 + nextA.size; ++i)
    {
        gotoxy (i, 4);
        for (int j = 4; j <= 4 + nextA.size; ++j)
            printf (" ");
    }
    printblock (nextA, 34, 4);
    for (int i = 38 + nextA.size; i <= 38 + nextA.size + nextB.size; ++i)
    {
        gotoxy (i, 4);
        for (int j = 4; j <= 4 + nextB.size; ++j)
            printf (" ");
    }
    printblock (nextB, 38 + nextA.size, 4);
    for (int i = 42 + nextA.size + nextB.size; i <= 42 + nextA.size + nextB.size + nextC.size; ++i)
    {
        gotoxy (i, 4);
        for (int j = 4; j <= 4 + nextC.size; ++j)
            printf (" ");
    }
    printblock (nextC, 42 + nextA.size + nextB.size, 4);
    for (int i = 1; i <= 20; ++i)
        map[i][0] = map[i][11] = 1;
    CONSOLE_CURSOR_INFO CursorInfo;  
    GetConsoleCursorInfo (hOut, &CursorInfo);
    CursorInfo.bVisible = 0;
    SetConsoleCursorInfo (hOut, &CursorInfo);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy (56, 10);
    printf ("%4d", fraction);
    gotoxy (57, 11);
    printf ("---");
    gotoxy (56, 12);
    if (fraction)
        printf ("%4d", fraction % 100 ? (fraction / 100 + 1) * 100 : fraction);
    else
        printf (" 100");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy (45, 20);
    printf ("00:00:00");
}
void choosedifficulty ()
{
    while (1) 
    {
        gotoxy (0, 0);
        switch (mode)
        {
            case 1:
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    puts ("");
                    puts ("        ■■■■■■■■■■■■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■■■■■■■■■■■■");
                gotoxy (18, 9);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                puts (" EASY  ");
                gotoxy (10, 16);
                printf ("慢速的经典俄罗斯");
                gotoxy (10, 17);
                printf ("方块，适合初学者.");
                break;
            case 2:
                    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    puts ("");
                    puts ("        ■■■■■■■■■■■■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■■■■■■■■■■■■");
                gotoxy (17, 9);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                puts ("MASTER ");
                gotoxy (10, 16);
                printf ("中速的街机俄罗斯");
                gotoxy (10, 17);
                printf ("方块，适合中级者.");
                break;
            case 3:
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    puts ("");
                    puts ("        ■■■■■■■■■■■■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■                    ■");
                    puts ("        ■■■■■■■■■■■■");
                gotoxy (16, 9);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                puts ("SHIRASE");
                gotoxy (10, 16);
                printf ("高速俄罗斯方块，");
                gotoxy (10, 17);
                printf ("挑战速度的极限.");
                break;
        }
        char key = _getch ();
        if (key == 'i' && mode != 1)
            --mode;
        if (key == 'k' && mode != 3)
            ++mode;
        gotoxy (10, 16);
        printf ("                 ");
        gotoxy (10, 17);
        printf ("                 ");
        if (key == ' ')
            break;
    }
    gotoxy (16, 9);
    printf ("          ");
} 
void ready_go ()
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    Sleep (1000);
    gotoxy (18, 8);
    puts ("READY");
    Sleep (800);
    gotoxy (18, 8);
    puts (" GO! ");
    Sleep (800);
    gotoxy (18, 8);
    puts ("     ");
}
void updatedata ()
{
    switch (mode)
    {
        case 1:
            addlinetime = inf; lockdelay = 300;
            if (fraction >= 0)
            {
                sleeptime = 2000 - fraction * 5;
                locktime = 800;
            }
            else if (fraction >= 100)
            {
                sleeptime = 1000 - fraction * 5 / 2;
                locktime = 700;
            }
            if (fraction >= 200)
                win ();
            break;
        case 2:
            addlinetime = inf; lockdelay = 300;
            if (fraction >= 0)
            {
                sleeptime = 1000 - fraction * 3;
                locktime = 700;
            }
            if (fraction >= 100)
            {
                sleeptime = 1000 - fraction * 3;
                locktime = 600;
            }
            if (fraction >= 200)
            {
                sleeptime = 1000 - fraction * 3;
                locktime = 500;
                if (fraction >= 300)
                    locktime = 700;
                else if (fraction >= 400)
                    locktime = 600;
            }
            if (fraction >= 999)
                win ();
            break;
        case 3:
            addlinetime = inf; lockdelay = 300 - fraction / 400 * 50; sleeptime = 0;
            locktime = 240 - fraction / 300 * 40;
            if (fraction >= 600)
                addlinetime = 10000;
            if (fraction >= 800)
                addlinetime = 7000;
            if (fraction >= 1000)
            {
                addlinetime = inf;
                xray = 1;
            }
            if (fraction >= 1300)
                win ();
    }
}
void updatetime ()
{
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy (45, 20); clockms = clock () - stclockms;
    printf ("%02d:%02d:%02d", clockms / 60000 % 100, clockms / 1000 % 60, clockms % 1000 / 10);
}
type_block roundblock ()
{
    type_block c;
    int kind = rand () % 7;
    while (kind < 2 && fraction <= 6)
        kind = rand () % 7;
    c.size = 4; c.color = kind + 1;
    if (xray) c.color = -2;
    for (int i = 0; i < c.size; ++i)
        for (int j = 0; j < c.size; ++j)
            c.a[i][j] = sblock[kind][i][j];
    return c;
}
void printblock (type_block m_block, int x, int y)
{
    switch (m_block.color)
    {
        case 1:
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 2:
            SetConsoleTextAttribute (hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case 3:
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case 4:
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN | FOREGROUND_RED);
            break;
        case 5:
            SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case 6:
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case 7:
            SetConsoleTextAttribute (hOut, FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case -1:
            SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            break;
        case -2:
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN);
            break;
        default:
            SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
    }
    for (int i = 0; i < m_block.size; ++i)
    {
        for (int j = 0 + !i; j < m_block.size; ++j)
            if (m_block.a[i][j])
            {
                gotoxy (x + j * 2, y + i);
                if (xray)
                    puts ("[]");
                else
                    puts ("■");
            }
    }
}
void clearblock (type_block m_block, int x, int y)
{
    for (int i = 0; i < m_block.size; ++i)
    {
        for (int j = 0 + !i; j < m_block.size; ++j)
            if (m_block.a[i][j])
            {
                gotoxy (x + j * 2, y + i);
                puts ("  ");
            }
    }
}
int checkblock (type_block m_block, int x, int y)
{
    for (int i = 0; i < m_block.size; ++i)
        for (int j = 0; j < m_block.size; ++j)
        {
            if (!(i + j))
                continue;
            if (m_block.a[i][j] && (map[x + i][y + j] || x + i > 20 || y + j < 1 || y + j > 10))
                return 0;
        }
    return 1;
}
type_block myup (type_block m_block)
{
    type_block c;
    int kind = m_block.a[0][0];
    for (int i = 0; i < m_block.size; ++i)
        for (int j = 0; j < m_block.size; ++j)
            c.a[i][j] = sblock[kind][i][j];
    c.size = m_block.size; c.color = m_block.color;
    return c;
}
type_block mydown (type_block m_block)
{
    type_block c = m_block;
    for (int t = 1; t <= 3; ++t)
        c = myup (c);
    return c;
}
void checkkey ()
{
    if (checkblock (now, positionX + 1, positionY) && keydownflag < (sleeptime > 100 ? 0 : 4))
    {
        ++keydownflag;
        if (KEY_DOWN('J'))
        {
            if (checkblock (now, positionX, positionY - 1))
                --positionY;
        }
        if (KEY_DOWN('L'))
        {
            if (checkblock (now, positionX, positionY + 1))
                ++positionY;
        }
    }
    if (kbhit())
            {
                keytime = clock ();
                char key = _getch();
                if (key == 'j')
                {
                    if (checkblock (now, positionX, positionY - 1))
                        --positionY;
                }
                if (key == 'l')
                {
                    if (checkblock (now, positionX, positionY + 1))
                        ++positionY;
                }
                if (key == 's')
                {
                    if (!holdflag)
                        return;
                    if (hold.a[0][0])
                    {
                        clearblock (hold, 60, 5);
                        type_block t = now; now = hold; hold = t;
                        printblock (hold, 60, 5);
                        positionX = 0; positionY = 4; keytime = clock();
                        holdflag = 0;
                    }
                    else
                    {
                        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                        gotoxy (60, 4);
                        puts ("Hold");
                        clearblock (hold, 60, 5);
                        hold = now;
                        printblock (hold, 60, 5);
                        clearblock (nextA, 34, 4); clearblock (nextB, 38 + nextA.size, 4); clearblock (nextC, 42 + nextA.size + nextB.size, 4);
                        now = nextA; nextA = nextB; nextB = nextC; nextC = roundblock();
                        printblock (nextA, 34, 4); printblock (nextB, 38 + nextA.size, 4); printblock (nextC, 42 + nextA.size + nextB.size, 4);
                        positionX = 0; positionY = 4; keytime = clock();
                    }
                }
                if (key == 'f')
                {
                    type_block newnow = myup (now);
                    if (checkblock (newnow, positionX, positionY))
                        now = newnow;
                    else if (checkblock (newnow, positionX - 1, positionY))
                    {
                        now = newnow;
                        --positionX;
                    }
                    else if (checkblock (newnow, positionX - 2, positionY)) 
                    {
                        now = newnow;
                        positionX -= 2;
                    }
                    else if (checkblock (newnow, positionX, positionY - 1))
                    {
                        now = newnow;
                        --positionY;
                    }
                    else if (checkblock (newnow, positionX, positionY + 1))
                    {
                        now = newnow;
                        ++positionY;
                    }
                }
                if (key == 'd')
                {
                    type_block newnow = mydown (now);
                    if (checkblock (newnow, positionX, positionY))
                        now = newnow;
                    else if (checkblock (newnow, positionX - 1, positionY))
                    {
                        now = newnow;
                        --positionX;
                    }
                    else if (checkblock (newnow, positionX - 2, positionY)) 
                    {
                        now = newnow;
                        positionX -= 2;
                    }
                    else if (checkblock (newnow, positionX, positionY - 1))
                    {
                        now = newnow;
                        --positionY;
                    }
                    else if (checkblock (newnow, positionX, positionY + 1))
                    {
                        now = newnow;
                        ++positionY;
                    }
                }
                if (KEY_DOWN(' '))
                {
                    for (int i = 1; i <= 20; ++i)
                        if (checkblock (now, positionX + 1, positionY))
                            ++positionX;
                    locked = 1;
                }
            }
            if (clock() - keytime > locktime && !checkblock (now, positionX + 1, positionY))
                locked = 1;
}
void checkline ()
{
    bool tf = 0;
    for (int i = 1; i <= 20; ++i)
    {
        int x = 0;
        for (int j = 1; j <= 10; ++j)
            if (map[i][j])
                ++x;
        if (x == 10)
        {
            tf = 1;
            for (int k = i; k >= 1; --k)
                for (int l = 1; l <= 10; ++l)
                    map[k][l] = map[k - 1][l];
            SetConsoleTextAttribute (hOut, FOREGROUND_RED);
            gotoxy (10, i + 1);
            for (int k = 1; k <= 10; ++k)
            {
                map[1][k] = 0;
                printf ("..");
            }
            if (firstwin)
                ++fraction;
        }
    }
    if (tf)
    {
        Sleep (100);
        if (xray)
            SetConsoleTextAttribute (hOut, FOREGROUND_GREEN);
        else
            SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        for (int i = 1; i <= 20; ++i)
        {
            gotoxy (10, i + 1);
            for (int j = 1; j <= 10; ++j)
                if (map[i][j] && !blind)
                    if (xray)
                        printf ("[]");
                    else
                        printf ("■");
                else
                    printf ("  ");
        }
    }
}
void addline ()
{
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= 10; ++j)
            map[i][j] = map[i + 1][j];
    for (int i = 1; i <= 10; ++i)
        map[20][i] = map[19][i];
    if (xray)
        SetConsoleTextAttribute (hOut, FOREGROUND_GREEN);
    else
        SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        for (int i = 1; i <= 20; ++i)
        {
            gotoxy (10, i + 1);
            for (int j = 1; j <= 10; ++j)
                if (map[i][j] && !(i != 1 && blind))
                    if (xray)
                        printf ("[]");
                    else
                        printf ("■");
                else
                    printf ("  ");
        }
    if (blind)
    {
        Sleep (200);
        gotoxy (10, 2);
        printf ("                    ");
    }
}
void gameover ()
{
    clockms = clock () - stclockms;
    blockpersecond = (double) blocknum / clockms * 1000; blockperminute = blockpersecond * 60.0;
    for (int i = 20; i >= 1; --i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            gotoxy (j * 2 + 8, i + 1);
            puts ("  ");
        }
        Sleep (150);
    }
    Sleep (2000);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoxy (14, 10);
    puts ("  暂定段位");
    gotoxy (13, 19);
    printf ("BPS  %lf", blockpersecond);
    gotoxy (13, 20);
    printf ("BPM  %lf", blockperminute);
    for (int i = 1; i <= 29; ++i)
    {
        if (i % 2)
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        else
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        gotoxy (19, 13);
        switch (mode)
        {
            case 1:
                gotoxy (18, 13);
                printf ("H%d", fraction + exfraction * 10 + rand () % 10);
                break;
            case 2:
                if (fraction >= 999)
                    printf ("S13");
                else if (fraction >= 950)
                    printf ("S12");
                else if (fraction >= 900)
                    printf ("S11");
                else if (fraction >= 850)
                    printf ("S10");
                else if (fraction >= 800)
                    printf ("S9");
                else if (fraction >= 750)
                    printf ("S8");
                else if (fraction >= 700)
                    printf ("S7");
                else if (fraction >= 650)
                    printf ("S6");
                else if (fraction >= 600)
                    printf ("S5");
                else if (fraction >= 550)
                    printf ("S4");
                else if (fraction >= 500)
                    printf ("S3");
                else if (fraction >= 450)
                    printf ("S2");
                else if (fraction >= 400)
                    printf ("S1");
                else if (fraction >= 350)
                    printf (" 1");
                else if (fraction >= 300)
                    printf (" 2");
                else if (fraction >= 250)
                    printf (" 3");
                else if (fraction >= 200)
                    printf (" 4");
                else if (fraction >= 150)
                    printf (" 5");
                else if (fraction >= 100)
                    printf (" 6");
                else if (fraction >= 50)
                    printf (" 7");
                else printf (" 8");
                break;
            case 3:
                if (fraction >= 1300)
                    printf ("S13");
                else if (fraction >= 1200)
                    printf ("S12");
                else if (fraction >= 1100)
                    printf ("S11");
                else if (fraction >= 1000)
                    printf ("S10");
                else if (fraction >= 900)
                    printf ("S9");
                else if (fraction >= 800)
                    printf ("S8");
                else if (fraction >= 700)
                    printf ("S7");
                else if (fraction >= 600)
                    printf ("S6");
                else if (fraction >= 500)
                    printf ("S5");
                else if (fraction >= 400)
                    printf ("S4");
                else if (fraction >= 300)
                    printf ("S3");
                else if (fraction >= 200)
                    printf ("S2");
                else if (fraction >= 100)
                    printf ("S1");
                else
                {
                    gotoxy (15, 13);
                    printf ("Let's go");
                    gotoxy (15, 14);
                    printf ("better");
                    gotoxy (15, 15);
                    printf ("next time!");
                }
                break;
        }
        Sleep (120);
    }
    Sleep (2000);
    system ("pause>nul");
    exit (0);
}
void win ()
{
    if (firstwin)
    {
        for (int i = 20; i >= 1; --i)
        {
            for (int j = 1; j <= 10; ++j)
            {
                gotoxy (j * 2 + 8, i + 1);
                puts ("  ");
                map[i][j] = 0;
            }
            Sleep (150);
        }
        Sleep (1000);
        firstwin = 0;
        switch (mode)
        {
            case 1:
                easy_extra_game ();
                break;
            case 2:
                master_extra_game ();
                break;
            case 3:
                shirase_extra_game ();
                break;
            default:
                break;
        }
        return;
    }
    gotoxy (15, 9);
    switch (mode)
    {
        case 1:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            puts ("  EASY MODE ");
            break;
        case 2:
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            puts (" MASTER MODE");
            break;
        case 3:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            puts ("SHIRASE MODE");
            break;
    }
    gotoxy (15, 10);
    puts ("  ALL CLEAR  ");
    Sleep (5000);
    gotoxy (15, 9);
    puts ("             ");
    gotoxy (15, 10);
    puts ("             ");
    gameover ();
}
void easy_extra_game ()
{
    sleeptime = 0; exgamestarttime = clock (); locktime = 300; keytime = clock ();
    if (mode == 3)
        locktime = 200;
    while (clock () - exgamestarttime < 40000)
        {
            if (locked)
            {
                ++exfraction;
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                now.color = -xray * 2;
                printblock (now, positionY * 2 + 8, positionX + 1);
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (!(i + j))
                            continue;
                        if (now.a[i][j]) 
                            map[positionX + i][positionY + j] = 1;
                    }
                }
                checkline ();
                Sleep (lockdelay);
                if (blind)
                    clearblock (now, positionY * 2 + 8, positionX + 1);
                locked = 0;
                clearblock (nextA, 34, 4); clearblock (nextB, 38 + nextA.size, 4); clearblock (nextC, 42 + nextA.size + nextB.size, 4);
                now = nextA; nextA = nextB; nextB = nextC; 
                if (mode == 3 && !rand () % 4)
                    xray = 0;
                nextC = roundblock();
                xray = 1;
                printblock (nextA, 34, 4); printblock (nextB, 38 + nextA.size, 4); printblock (nextC, 42 + nextA.size + nextB.size, 4);
                positionX = 0; positionY = 4;
                if (!checkblock (now, positionX, positionY))
                    gameover ();
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                gotoxy (56, 10);
                printf ("%4d", fraction);
                gotoxy (57, 11);
                printf ("---");
                gotoxy (56, 12);
                int lssc = fraction % 100 ? (fraction / 100 + 1) * 100 : fraction;
                if (mode == 1 && lssc >= 200) lssc = 200;
                if (mode == 2 && lssc >= 999) lssc = 900;
                if (mode == 3 && lssc >= 1300) lssc = 1300;
                printf ("%4d", lssc);
                keytime = clock(); holdflag = 1;
                if (clock () - addlineflag > addlinetime)
                {
                    addlineflag = clock ();
                    addline ();
                }
                keydownflag = 0;
            }
            if (checkblock (now, positionX + 1, positionY))
            while (checkblock (now, positionX + 1, positionY))
            {
                ++positionX;
                if (sleeptime)
                {
                    printblock (now, positionY * 2 + 8, positionX + 1);
                    int sttime = clock (), timeover;
                    while ((timeover = (clock () - sttime < sleeptime)) && !kbhit());
                    clearblock (now, positionY * 2 + 8, positionX + 1);
                    if (timeover)
                        checkkey ();
                }
                checkkey ();
            }
            printblock (now, positionY * 2 + 8, positionX + 1);
            Sleep (100);
            clearblock (now, positionY * 2 + 8, positionX + 1);
            checkkey ();
        }
    if (xray)
        SetConsoleTextAttribute (hOut, FOREGROUND_GREEN);
    else
        SetConsoleTextAttribute (hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        for (int i = 1; i <= 20; ++i)
        {
            gotoxy (10, i + 1);
            for (int j = 1; j <= 10; ++j)
                if (map[i][j])
                    if (xray)
                        printf ("[]");
                    else
                        printf ("■");
                else
                    printf ("  ");
        }
    win ();
}
void master_extra_game ()
{
    blind = 1;
    easy_extra_game ();
}
void shirase_extra_game ()
{
    blind = 1;
    easy_extra_game ();
}
