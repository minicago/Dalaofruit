namespace basicop3{
	inline void level_up(){
		lv++;
		levelupflag=1;
		switch (lv) {
			case 5:
				make_boss1();
				bcast("他来了!");
				break;
			case 16:
				make_boss2();
				bcast("Warning:Unexpected Vistor!");
				break;
			case 25:
				make_boss3();
				bcast("二刺螈能不能爬？");
				break;
			case 35:
				make_boss4();
				bcast(words1[ptp]);	
				break;
			case 50:
				make_boss5();
				bcast("尽头是。。。？");	
				break;
				
		}
		CLEAR();
		printf("Score:%d 离退役还有%d年 操作机会:%d Day:%d 提交:%d\n",_sco,_life,SKILL,lv,r);
		printf("You AK Day%d\n",lv-1);		
		cout<<"1 好好颓一会，补满生命值"<<endl;
		cout<<"2 赶快刷oj，回复所有技能"<<endl;
		cout<<"3 退役了，弃坑了，重新选择技能"<<endl;
		if(!fightwithboss) cout<<"4 明天翻盘？获得50分"<<endl;
		else cout<<"4 无畏强者，护盾护体"<<endl;
		a=getch();
		while(a<'1'||a>'5') a=getch();
		if(a=='1') _life=MLIFE[ptp];
		if(a=='2') SKILL=MSKILL[ptp];
		if(a=='3') choose_skill();		
		if(a=='4') {
			if(!fightwithboss) _sco+=50;
			else{
				shield=1;shield_time=r;
			}	
		}
		if(lv==10) {
			bcast("Day10!!! You win extra 1000!"); 
			_sco+=1000,t7++;	
		}
		_t_begin=time(NULL);
	}
	inline void check100(){
		if(ptp==4){
			if(bonus==1) if(r%100>=69) {bonus=2;}
			if(bonus==2) if(r%100<69) {bonus=1;}
		}		
		if(r%100==0){
			if(ptp==2) SKILL++;
			if(ptp==3){
				shield=1;shield_time=r;
			}
			if(SKILL>=MSKILL[ptp]) SKILL=MSKILL[ptp]; 
		}
	} 
	inline void CREA(){
		fru[++r].crea();
		check100();
		if(_sco>4000) fru[++r].crea();
			else if(_sco>1500&&rand()%100<50) fru[++r].crea();
		check100();
		if(_sco>14000) fru[++r].crea();
			else if(_sco>8000&&rand()%100<20) fru[++r].crea(); 
		check100();
	}
	inline void pupdata(){
		if(ptp==5){
			if(CRAZY) CRAZY--;
			if(CRAZY>=50) bonus=5;
			if(CRAZY<50) bonus=3;
			if(!CRAZY) bonus=1; 
		}
	}
}
