/*
	Name: Wangyihan Guo & Xiaoyu Zhang
	Copyright: dgklr & Ally_stoppable
	Author: 4096 Team
	Date: 26/11/17 12:41
*/
#include <bits/stdc++.h>
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define br BACKGROUND_RED
#define bg BACKGROUND_GREEN
#define bb BACKGROUND_BLUE
#define bi BACKGROUND_INTENSITY
#define fr FOREGROUND_RED
#define fg FOREGROUND_GREEN
#define fb FOREGROUND_BLUE
#define fi FOREGROUND_INTENSITY
/* copyright dgklr-----------*/
#define normal 0
#define bright 1
#define code 2
#define dev 4
#define three 5
/* copyright Ally_stoppable--*/
#define slight 3
/* copyright jiande----------*/
#define warm 6
#define grass 7
#define sea 8
#define choice_theme sea
using namespace std;
int dx=1,dy=1;
int a[101][101];
int score=0;
/* copyright dgklr-----------*/
void col(int co)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),co);
}
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
bool check(char c){
	return KEY_DOWN(c);
}
/* This function does not have copyright */
void prin(int num,bool choice,int theme=choice_theme)
{
	if (theme == bright)
	{
	    col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(fr+fg+fb);
	            break;
	        }
	        case 1:
	        {
	            col(br+bg+bi);
	            break;
	        }
	        case 2:
	        {
	            col(bg+bb+bi);
	            break;
	        }
	        case 3:
	        {
	            col(bb+br+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == normal)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(fr+fg+fb);
	            break;
	        }
	        case 1:
	        {
	            col(br+bi);
	            break;
	        }
	        case 2:
	        {
	            col(bg+bi);
	            break;
	        }
	        case 3:
	        {
	            col(bb+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == slight)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb+bi);
	            break;
	        }
	        case 1:
	        {
	            col(br+bg);
	            break;
	        }
	        case 2:
	        {
	            col(br);
	            break;
	        }
	        case 3:
	        {
	            col(br+bb);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == dev)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb+bi);
	            break;
	        }
	        case 1:
	        {
	            col(br+bi);
	            break;
	        }
	        case 2:
	        {
	            col(fr+fg+fb);
	            break;
	        }
	        case 3:
	        {
	            col(bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == three)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb+bi);
	            break;
	        }
	        case 1:
	        {
	            col(br+bi);
	            break;
	        }
	        case 2:
	        {
	            col(br+bg+bi);
	            break;
	        }
	        case 3:
	        {
	            col(bg+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
		
	if (theme == warm)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb);
	            break;
	        }
	        case 1:
	        {
	            col(br+bi);
	            break;
	        }
	        case 2:
	        {
	            col(br+bb+bi);
	            break;
	        }
	        case 3:
	        {
	            col(br+bg+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == grass)
	{	   
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb);
	            break;
	        }
	        case 1:
	        {
	            col(bg+bi);
	            break;
	        }
	        case 2:
	        {
	            col(bg+br+bi);
	            break;
	        }
	        case 3:
	        {
	            col(bg+bb+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == sea)
	{	  
		col(fr+fg+fb);
	    switch (num)
	    {
	        case 0:
	        {
	            col(br+bg+bb);
	            break;
	        }
	        case 1:
	        {
	            col(bb+bi);
	            break;
	        }
	        case 2:
	        {
	            col(bb+br+bi);
	            break;
	        }
	        case 3:
	        {
	            col(bb+bg+bi);
	            break;
	        }
	    }
	    if (choice) cout<<"**";
	    else cout<<"  ";
	}
	
	if (theme == code)
	{
		col(fr+fg+fb+fi);
		if (choice) cout<<num<<"*";
		else cout<<num<<" ";
	}
}
bool dfs_map[101][101];
#define n 10
/* copyright dgklr-----------*/
int dfs(int x,int y,int color)
{
    if (color==0) return 0;
    if (x<1||x>n||y<1||y>n) return 0;
    if (dfs_map[x][y]) return 0;
    if (a[x][y]!=color) return 0;
    dfs_map[x][y]=1;
    a[x][y]=0;
    return 1+dfs(x-1,y,color)+dfs(x+1,y,color)+dfs(x,y+1,color)+dfs(x,y-1,color);

}
bool wron()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=0) return 1;
    return 0;
}
/* copyright Ally_stoppable--*/
void getdown()
{
	for(int i = 1; i <= n; i ++)
	{
		for(int j = n; j >= 1; j --)
		if(a[j][i] == 0)
		{
			for(int k = j; k >= 1; k --)
			a[k][i] = a[k-1][i]; 
		}
	}
}
/* copyright dgklr-----------*/
void getleft()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==0)
			{
				for (int k=j;k<=n;k++)
				{
					a[i][k]=a[i][k+1];
				}
			}
		}
	}
}

int main()
{
    HideCursor();
    srand((unsigned)time(NULL));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            a[i][j]=rand()%3+1,prin(a[i][j],0);//cout<<a[i][j];
        col(0),cout<<endl;
    }
    while (wron())
    {
        int tmp=0;
        memset(dfs_map,0,sizeof(dfs_map));
        gotoxy(0,0);
        getdown();
        getleft();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                if (i!=dx||j!=dy) prin(a[i][j],0);//cout<<a[i][j];
                else prin(a[i][j],1);
            col(0),cout<<endl;
        }
        gotoxy(30,0);
        col(fr+fg+fb),cout << "dx:" << dx << " dy:" << dy << " score:" << score << "         ";
        Sleep(50);
        if (check(VK_UP)||check('W')) dx=max(dx-1,1);
        if (check(VK_LEFT)||check('A')) dy=max(dy-1,1);
        if (check(VK_DOWN)||check('S')) dx=min(dx+1,n);
        if (check(VK_RIGHT)||check('D')) dy=min(dy+1,n);
        if (check(VK_RETURN)) tmp=dfs(dx,dy,a[dx][dy]),score+=tmp*(tmp+1);
		Sleep(20);
    }
    system("cls");
    gotoxy(10,10);cout << "score:" << score;
    Sleep(10000);
}
