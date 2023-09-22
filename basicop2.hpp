namespace basicop2{	

	inline void change_color(){
	// color
	// 1 black-red 2 black-white 3blue-white
	// 4 black-yellow 5blue-yellow 6black-yellow(stable)
	// 7 color has changed
		if(bonus==1){
			if(color>3) color=2;
			if(color==2){
				system("color 07");	
				color=0;
			}
			if(color==1){
				system("color 04");
				color=2;
			}else{
				if(FROZEN&&color!=3) {
					system("color 97"); 
					color=3;	
				}
			}
			if(color==3&&FROZEN==0) color=2;		
		}
		if(bonus==2){
			if(color<=3) color=4;
			if(FROZEN&&color!=5){
					system("color 96");
					color=5;
				}
			if(color==5&&FROZEN==0) color=4;
			if(color==4){
				system("color 06");
				color=6;
			}
		}
		if(bonus>=3){
			if(color!=7){
				system("color 47");
				color=7;
			}
		}
	}
	inline void output(bool type)
	{	
		CLEAR();
		change_color();
		int pn=0;
		if(type){
			printf("BOSS:");
			cout<<BOSS_Name;
			printf("\nHP:") ;
			for(int i=1;i<=(BOSS_HP-1)%10+1;i++) printf("*");
			if(BOSS_HP>10) {
				for(int i=(BOSS_HP-1)%10+2;i<=10;i++) printf("O");
				printf(" *%d",BOSS_HP/10);
			}
			printf("\n");
		}
		for(register int i=2;i<=10;i++) {
			putchar(scr[i][1]);putchar(scr[i][2]);putchar(scr[i][3]);
			putchar(scr[i][4]);putchar(scr[i][5]);putchar(scr[i][6]);
			putchar(scr[i][7]);putchar(scr[i][8]);putchar(scr[i][9]);
			switch(i){
				case 2:printf("Score:%d",_sco);break; 
				case 3:printf("离退役还有%d年(最大%d)",_life,MLIFE[ptp]);break;
				case 4:printf("操作机会:%d(最多%d)",SKILL,MSKILL[ptp]);break;
				case 5:printf("Day:%d",lv);break;
				case 6:printf("提交:%d",r);break;
				case 7:if(FROZEN) printf("WC ");if(shield)printf("SHIELD");break;
				case 8:if(LUCK) printf("LUCK(%d)",LUCK); else if(BAD) printf("BAD(%d)",BAD);break;
				case 9:if(bonus>3) printf("CRAZY!!!");else if(bonus==3) printf("CRAZY");else if(bonus==2) printf("LEGEND!");break; 
				case 10:if(DIZZY) printf("DIZZY(%d) ",DIZZY);if(fightwithboss&&BossSkill[1])printf("LOCKED!");break;
			}
			putchar('\n');
		}
		putchar(scr[11][1]);putchar(scr[11][2]);putchar(scr[11][3]);
		putchar(scr[11][4]);putchar(scr[11][5]);putchar(scr[11][6]);
		putchar(scr[11][7]);putchar(scr[11][8]);putchar(scr[11][9]);
		if(pn>=5&&_sco>100&&t2==0) {
			bcast("You are a legend!!!You win 1000 extra score!!!");
			_sco+=1000,t2=1,t7++;
		}
	} 
	inline void use_skill()
	{
		if(fightwithboss&&BossSkill[1]) return;
		if(SKILL<=0) return;
		if(t7==6){
			int t=SKILL-1;
			if(_life==MLIFE[ptp]) SKILL++;
			else _life++;
			if(shield) SKILL++;
			else 
			{
				shield=1;
				shield_time=r;
			}
			for(;l<=r;l++) fru[l].kill();
			if(LUCK==0) LUCK+=10;
			else SKILL++; 
			if(BAD==0) SKILL++;
			else BAD=0;
			if(FROZEN==0) FROZEN=500;
			else SKILL++;
			SKILL=t;
			color=1;
			return;
		}	 
		int M=SKILL;
		if(SKILL>0)
		{
			SKILL--;
			if(skill_type==1) 
			{
				if(_life==MLIFE[ptp]) SKILL++;
				else _life++;
			}	
			if(skill_type==2)
			{
				if(shield) SKILL++;
				else 
				{
					shield=1;
					shield_time=r;
				}		
			}
			if(skill_type==3)
			{
				for(;l<=r;l++) fru[l].kill();
				color=1;
			}
			if(skill_type==4)
			{
				if(LUCK==0) LUCK+=10;
				else SKILL++; 
			}
			if(skill_type==5)
			{
				if(BAD==0) SKILL++;
				else BAD=0;
			}
			if(skill_type==6)	
			{
				if(FROZEN==0) FROZEN=500;
				else SKILL++;
			}
		}
		if(M!=SKILL)
		{
			if(ptp==1) for(;l<=r;l++) {fru[l].kill();color=1;}
			if(t1[skill_type]==0)
			{
				t1[skill_type]=1;
				t1[0]++;
			}
		}
	}
}
