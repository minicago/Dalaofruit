namespace basicop3{
	inline void level_up(){
		lv++;
		levelupflag=1;
		switch (lv) {
			case 5:
				make_boss1();
				bcast("������!");
				break;
			case 16:
				make_boss2();
				bcast("Warning:Unexpected Vistor!");
				break;
			case 25:
				make_boss3();
				bcast("������ܲ�������");
				break;
			case 35:
				make_boss4();
				bcast(words1[ptp]);	
				break;
			case 50:
				make_boss5();
				bcast("��ͷ�ǡ�������");	
				break;
				
		}
		CLEAR();
		printf("Score:%d �����ۻ���%d�� ��������:%d Day:%d �ύ:%d\n",_sco,_life,SKILL,lv,r);
		printf("You AK Day%d\n",lv-1);		
		cout<<"1 �ú���һ�ᣬ��������ֵ"<<endl;
		cout<<"2 �Ͽ�ˢoj���ظ����м���"<<endl;
		cout<<"3 �����ˣ������ˣ�����ѡ����"<<endl;
		if(!fightwithboss) cout<<"4 ���췭�̣����50��"<<endl;
		else cout<<"4 ��ηǿ�ߣ����ܻ���"<<endl;
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
