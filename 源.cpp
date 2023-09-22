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
	cout<<"�������Ǵ���Ҳû�������\n�ӹ����黳�����(byy����)��"<<endl;
	waitpause();
	CLEAR();
	cout<<"������������ƶ�"<<endl;
	cout<<"������������ƶ�"<<endl;
	cout<<"�����������"<<endl;
	cout<<"��������ͷż���"<<endl;
	cout<<"�ո����ͣ"<<endl; 
	cout<<"*��ʾ���λ��"<<endl; 
	cout<<"+ $ @ ! U B S��ʾ����Ĺ�ʵ"<<endl;
	cout<<"+ �ظ�0������ ��10��"<<endl;
	cout<<"$ �ظ�0������ ��30��"<<endl;
	cout<<"@ �ظ�1������ ��0��"<<endl;
	cout<<"! �۳�1������ ��30��"<<endl;
	cout<<"U ʹ��������"<<endl;
	cout<<"B ʹ����ù��"<<endl;
	cout<<"S �ָ���ļ���"<<endl; 
	cout<<"��BOSS��սʱ��ķ�������仯��"<<endl;
	cout<<"T V �۳�1������"<<endl; 
	cout<<"A ����BOSS"<<endl; 
	cout<<"? ʹ�����"<<endl;
	cout<<"��˵��������ɵ�������10*20ʹ������ζ������"<<endl;
	cout<<"If you can't see the chinese.please change the Windows default.Thanks"<<endl;	
	waitpause();
	srand(clock());
	choose_player();
	choose_skill();
	CLEAR();
	cout<<"�ɾ�1���츳ѡ�֣��ͷ�6�ּ��ܸ�һ�Ρ�������1000��"<<endl;
	cout<<"�ɾ�2������Ԫսʿ�����˴��koishi��������1000��"<<endl;
	cout<<"�ɾ�3���Ȳ����ӣ��ﵽ10Day��������1000��"<<endl; 
	cout<<"�ɾ�4�����ӱ�Ե���ﵽ-500�֡�������1000��"<<endl;
	cout<<"�ɾ�5��6�곤;���ύ1000�Ρ�������1000��"<<endl;
	cout<<"���سɾͣ�Ѱ�����ߡ� ���������ߵ�������������"<<endl;
	cout<<"�����ɾͣ���ɳɾ�1-5�� ������dalao֮����������"<<endl;
	cout<<"���سɾͣ��������� �����������ıӻ���������"<<endl;
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
				bcast("���߱ӻ���");
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
			bcast("����,��̫ǿ��,ף����������\n ���������ÿ��ʹ�ü��ܵ㽫�ͷ����м���");
			t7++;
		}
		if(BAD>=200&&t8==0){
			t8=1;
			bcast("�������������� \n ���㲻��BOSSս��ʱ!��B���������ķ���"); 			
		}
		if(t1[0]==6&&!fightwithboss) 
		{
			_sco+=1000,t7++;
			bcast("ÿ�������㶼�ù��ˣ��治��");
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
	else cout<<"������"<<endl;
	cout<<"��ľ����ɼ�:"<<_sco<<endl;
	cout<<"����ʱ��:"<<r<<endl; 
	for(register int i=1;i<=500000000;i++);
	waitpause();
	CLEAR();
	cout<<"��߷�"<<endl;

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
