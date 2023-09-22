struct wz
{
	bool flag;
	int x,y,sco,life,grav;
	char ico;
	
	inline void crea()
	{
		x=2;
		y=rand()%7+2;
		grav=1;
		while(scr[x][y]!=' ')
		{
			x=2;
			y=rand()%7+2;
		}
		int type=rand()%100;
		if(LUCK>0)
		{
			LUCK--;
			if(_sco<6000){
				if(type<60){sco=10;life=0;ico='+';}
				if(60<=type){sco=30;life=0;ico='$';}
				if(85<=type){life=1;sco=0;ico='@';}
				if(95<=type){sco=0;life=0;ico='S';}	
			}else{
				if(type<60){sco=10;life=0;ico='+';}
				if(60<=type){sco=30;life=0;ico='$';}
				if(85<=type){life=1;sco=0;ico='@';}
				if(99<=type){sco=0;life=0;ico='S';}	
			}
			
		}
		else if(BAD>0)
		{
			BAD--;
			if(_sco<7000){
				if(type<90) {sco=-30;life=-1;ico='!';}
				if(type>=90) {ico='B';}
				if(type==99) {ico='Y';}		
			}else{
				if(type<97) {sco=-30;life=-1;ico='!';}
				if(type>=97) {ico='B';}
				if(type==99) {ico='Y';}					
			}
		}
		else if(_sco<300)
		{
			if(type<30){sco=10;life=0;ico='+';}
			if(30<=type){sco=30;life=0;ico='$';}
			if(40<=type){sco=-30;life=-1;ico='!';}
			if(90<=type){sco=0;life=0;ico='B';}
			if(93<=type){sco=0;life=0;ico='U';}
			if(95<=type){life=1;sco=0;ico='@';}
			if(99<=type){sco=0;life=0;ico='S';}
		}else if(_sco<1000)
		{
			if(type<20){sco=10;life=0;ico='+';}
			if(20<=type){sco=30;life=0;ico='$';}
			if(25<=type){sco=-30;life=-1;ico='!';}
			if(94<=type){sco=0;life=0;ico='B';}
			if(96<=type){sco=0;life=0;ico='U';}
			if(97<=type){life=1;sco=0;ico='@';}
			if(99<=type){sco=0;life=0;ico='S';}
		}else if(_sco<5000)
		{
			if(type<15){sco=10;life=0;ico='+';}
			if(15<=type){sco=30;life=0;ico='$';}
			if(20<=type){sco=-50;life=-1;ico='!';}
			if(90<=type){sco=0;life=0;ico='B';}
			if(98<=type){sco=0;life=0;ico='U';}
			if(99<=type){sco=0;life=0;ico='S';}
//			if(95<=type){life=1;sco=0;ico='@';}
		}else if(_sco<10000){
			if(type<10){sco=10;life=0;ico='+';}
			if(10<=type){sco=30;life=0;ico='$';}
			if(15<=type){sco=-50;life=-1;ico='!';}
			if(95<=type){sco=0;life=0;ico='B';}
			if(98<=type){sco=0;life=0;ico='U';}
			if(99<=type){sco=0;life=0;ico='S';}			
		}else{
			if(type<10){sco=10;life=0;ico='+';}
			if(10<=type){sco=30;life=0;ico='$';}
			if(15<=type){sco=-50;life=-1;ico='!';}
			if(97<=type){sco=0;life=0;ico='B';}
			if(99<=type){sco=0;life=0;ico='U';}
		}
		if(fightwithboss){
			sco=0;
			if(ico!='!'&&ico!='B'){
				ico='A';life=0;
			}
			else if(ico!='B'){
				int rr=rand()%100;
				if(rr>80&&BossSkill[2]){
					ico='V';grav=3;
				}
				if(rr>75&&rr<80&&BossSkill[3]){
					ico='?';life=0;
				}
				if(rr>60&&rr<75&&BossSkill[4]){
					ico='T';grav=-1;
				}
			}
		} 
		scr[x][y]=ico;
	}	
	void drop()
	{
		if(!flag) scr[x][y]=' ';		
		if(grav>0) {
			x+=grav;
			if (grav==3) grav=2;
		}
		else if(grav==0){
			x++;grav=-1;
		}else grav++;
		if(x>=12) flag=1;
		if((scr[x][y]!=' ')&&(scr[x][y]!='*')&&(scr[x][y]!='O')&&(scr[x][y]!='W')) flag=1;
		if(flag==0) scr[x][y]=ico;
	}
	void kill()
	{
		scr[x][y]=' ';
		flag=1;
	}
	inline void pick(int t)
	{
		if(x==11&&y==_y&&flag==0)
		{
			int tmp=_life;
			_life+=life*t;
			_sco+=sco*t;
			flag=1;
			if(ico=='U') {if(skill_type==4||t7==5)LUCK+=30*t;else LUCK+=20*t;}
			if(ico=='B') {if(skill_type==5||t7==5)BAD+=10*t;else BAD+=20*t;}
			if(ico=='S') SKILL+=t;
			if(ico=='A') BOSS_HP-=t;
			if(ico=='@'&&skill_type==1) _life+=t;
			if(ico=='Y')
			{
				t6+=t;
				if(t6==2) bcast("你找到作者了！\n你获得了作者的庇护：当你的生命即将归0时，回复所有生命。");
				_sco+=50*t;
			}
			if(ico=='?') DIZZY+=10;
			if(_life>MLIFE[ptp]) _life=MLIFE[ptp];
			if(SKILL>MSKILL[ptp]) SKILL=MSKILL[ptp];
			if((inv||shield)&&life<0)
			{
				_life-=life*t;
				_sco-=sco*t; 
				shield=0;
			}else if(t8&&!fightwithboss) if(ico=='B'||ico=='!') _sco+=40*t;
			if(tmp>_life){
				inv=1;
				inv_time=r;
				if(ptp==5)CRAZY+=30;
				if(fightwithboss) bosshurt=1;
			}
		}
	}

}fru[10000001]; 
