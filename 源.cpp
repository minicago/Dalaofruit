#include "thebasic.hpp"
#include "thewz.hpp"
#include "boss.hpp"
#include "basicop2.hpp"
using namespace basicop2;
#include "basicop1.hpp"
using namespace basicop1;
#include "basicop3.hpp"
using namespace basicop3;
inline void _init(){
	HideCursor();
	load_data();
	for(register int i=1;i<=12;i++)
		for(register int j=1;j<=9;j++)
			scr[i][j]=' ';
	for(register int i=1;i<=12;i++) {scr[i][1]='|';scr[i][9]='|';}
	for(register int i=1;i<=9;i++) {scr[1][i]='=';scr[12][i]='=';}
	scr[11][_y]='*';	
	cout<<"这是你们从来也没有玩过的\n接果子情怀纪念版(byy制作)："<<endl;
	waitpause();
	CLEAR();
	cout<<"方向键←向左移动"<<endl;
	cout<<"方向键→向右移动"<<endl;
	cout<<"方向键↑加速"<<endl;
	cout<<"方向键↓释放技能"<<endl;
	cout<<"空格键暂停"<<endl; 
	cout<<"*表示你的位置"<<endl; 
	cout<<"+ $ @ ! U B S表示掉落的果实"<<endl;
	cout<<"+ 回复0点生命 得10分"<<endl;
	cout<<"$ 回复0点生命 得30分"<<endl;
	cout<<"@ 回复1点生命 得0分"<<endl;
	cout<<"! 扣除1点生命 扣30分"<<endl;
	cout<<"U 使你变得幸运"<<endl;
	cout<<"B 使你变得霉运"<<endl;
	cout<<"S 恢复你的技能"<<endl; 
	cout<<"与BOSS作战时你的分数不会变化。"<<endl;
	cout<<"T V 扣除1点生命"<<endl; 
	cout<<"A 攻击BOSS"<<endl; 
	cout<<"? 使你混乱"<<endl;
	cout<<"听说将字体调成点阵字体10*20使用起来味道更佳"<<endl;
	cout<<"If you can't see the chinese.please change the Windows default.Thanks"<<endl;	
	waitpause();
	srand(clock());
	choose_player();
	choose_skill();
	CLEAR();
	cout<<"成就1：天赋选手：释放6种技能各一次。奖励：1000分"<<endl;
	cout<<"成就2：二次元战士：无伤打败koishi。奖励：1000分"<<endl;
	cout<<"成就3：稳步进队：达到10Day。奖励：1000分"<<endl; 
	cout<<"成就4：弃坑边缘：达到-500分。奖励：1000分"<<endl;
	cout<<"成就5：6年长途：提交1000次。奖励：1000分"<<endl;
	cout<<"隐藏成就：寻找作者。 奖励：作者的馈赠（被动）"<<endl;
	cout<<"超级成就：达成成就1-5。 奖励：dalao之力（被动）"<<endl;
	cout<<"隐藏成就：向死而生 奖励：不死的庇护（被动）"<<endl;
	waitpause();
}

inline void _body(){
	CLEAR();
	output(fightwithboss);
	while(1)
	{
		bool moved=1;
		while(_sco>=lv*300) level_up();
		pupdata();
		CREA();
		output(fightwithboss);
		_t=clock();
		if(levelupflag){
			_t=clock()+400;
			levelupflag=0;
		}
		winboss();
		while(1){
			a='+';	
			while((clock()-_t<max(6000-_sco,0)/20+FROZEN*3+250)&&(!kbhit()));
			scr[11][_y]=' ';		
			if(clock()-_t<max(6000-_sco,0)/20+FROZEN*3+250) a=getch();
			if(DIZZY){
				switch (a) {
					case 75:
						a=77;
						break;
					case 77:
						a=75;
						break;
					case 80:
						a=72;
						break;
					case 72:
						a=80;
						break;					
				}
			}
			if(a==75) _y=max(_y-1,2);
			if(a==77) _y=min(_y+1,8);
			if(a==' ') {waitpause();output(fightwithboss);}
			if(a==80) use_skill();
			if(a==80||a==75||a==77) moved=1;
			if(r-shield_time>=100) shield=0;
			if(inv) scr[11][_y]='W';
			else if(shield) scr[11][_y]='O';
			else scr[11][_y]='*';
			if(moved){
				printf("\r");
				putchar(scr[11][1]);putchar(scr[11][2]);putchar(scr[11][3]);
				putchar(scr[11][4]);putchar(scr[11][5]);putchar(scr[11][6]);
				putchar(scr[11][7]);putchar(scr[11][8]);putchar(scr[11][9]);
				for(register int i=l;i<=r;i++) {fru[i].pick(bonus);}
				moved=0;
			}
			if(a==72) break;
			if(clock()-_t>=max(6000-_sco,0)/20+FROZEN*3+250) break;
		}
		if(FROZEN>0) FROZEN-=FROZEN/14+5;
		if(FROZEN<0) FROZEN=0;
		if(DIZZY) DIZZY--;
		for(;fru[l].flag&&l<=r;) ++l;
		for(register int i=l;i<=r;i++) {fru[i].pick(bonus);fru[i].drop();fru[i].pick(bonus);}
		if(r-shield_time>=100) shield=0;	
		if(r-inv_time>=10) inv=0;	
		if(inv) scr[11][_y]='W';
		else if(shield) scr[11][_y]='O';
		else scr[11][_y]='*';
		if(_life<=0){
			if(t6>=2){
				bcast("作者庇护你");
				_life=MLIFE[ptp];
				t6=-9999;
			}else break;
		}
		if(_sco<=-500&&t4==0)
		{
			bcast("Oh No!!!Are you a loser?!Give you 1000 extra score!!!");
			t4=1;t7++;
			_sco+=1000;
		}
		if(r>=1000&&t5==0&&fightwithboss==0)
		{
			bcast("You submit 1000 times!!!Come on!!!You win 1000 extra score!!!");
			t5=1;t7++;
			_sco+=1000;
		}
		if(t7==5){
			bcast("大佬,您太强了,祝福您！！！\n 你从现在起每次使用技能点将释放所有技能");
			t7++;
		}
		if(BAD>=200&&t8==0){
			t8=1;
			bcast("向死而生！！！ \n 当你不与BOSS战斗时!与B将给你额外的分数"); 			
		}
		if(t1[0]==6&&!fightwithboss) 
		{
			_sco+=1000,t7++;
			bcast("每个技能你都用过了，真不错。");
		}
		if(!fightwithboss){
			if(BOSS_Sco==5000) return;
		}
	}
}

void _end(){
	CLEAR();
	_t_end=time(NULL);
	if(_sco>20000) _sco=20000;
	if(_sco==20000) cout<<words2[ptp]<<endl; 
	else cout<<"退役了"<<endl;
	cout<<"你的竞赛成绩:"<<_sco<<endl;
	cout<<"运行时间:"<<r<<endl; 
	for(register int i=1;i<=500000000;i++);
	waitpause();
	CLEAR();
	cout<<"最高分"<<endl;

	fclose(fp);
	fp=fopen("highplus","wb");
	RC[11].id=ptp;RC[11].sco=_sco;RC[11].tt=r;
	sort(RC+1,RC+12,cmp1);
	for(register int i=1;i<=10;i++){
		cout<<pname[RC[i].id]; 
		printf(" %d %d\n",RC[i].sco,RC[i].tt);
		fprintf(fp,"%d %d %d\n",RC[i].id,RC[i].sco,RC[i].tt);
	} 	
	
	for(register int i=1;i<=500000000;i++);
	waitpause();
}
int main()
{
	_init();
	_body();
	_end();

}
