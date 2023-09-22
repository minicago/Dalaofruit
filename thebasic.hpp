#include<conio.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<Windows.h>

using namespace std;
char a,scr[23][20],t=0;
int _sco,_life=5,_y=5,_t,l=1,r=0,LUCK=0,BAD=0,DIZZY=0,SKILL,skill_type,shield_time,FROZEN,lv=1;
int ptp;
bool levelupflag; 
int bonus=1,CRAZY;
bool shield=0;
int _t_begin,_t_end;
int t1[7],t2,t4,t5,t6,t7,t8,t9;
int color=0; 
bool inv;
int inv_time; 
const int PNUM=5;
int MLIFE[41]={0,4,5,6,3,7};
int MSKILL[41]={0,4,3,2,5,1};
inline void CLEAR(){
	fflush(stdout);
	system("CLS");
}
inline void waitpause(){
	char ch='?';
	printf("按空格键或回车键继续\n");
	while(ch!=' '&&ch!='\n'&&ch!='\r') ch=getch();
} 
inline void bcast(string ss){
	CLEAR();
	cout<<ss<<endl;
	for(int i=1;i<=500000000;i++);
	waitpause();
}
void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false; 
	SetConsoleCursorInfo(handle, &CursorInfo);
}

string pname[21]={"Nobody     ","Dyw        ","minicago   ","FM_ding    ","LEGEND_MAO ","PSS        "};
string words1[21]={"BUG?CHEATOR!","我们越是什么，便越是认为别人是什么。","天赋决定了上限?","绝境！？","即使是平凡的失败。","小侠僧！"}; 
string words2[21]={"STOP!!!","你个dalao","上限不能决定我们。","这才是奇迹。","我们依然信仰传说！","后生可畏！"};
bool fightwithboss,bosshurt;
int BOSS_HP,BOSS_Sco; 
string BOSS_Name; 
int BossSkill[11];
