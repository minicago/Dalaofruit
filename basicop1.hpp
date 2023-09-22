namespace basicop1{
	struct Reco{
		int id,sco,tt;
	}RC[12];
	bool cmp1(Reco a,Reco b){
		if(a.sco==b.sco) return a.tt<b.tt;
		return a.sco>b.sco;
	}
	FILE *fp;
	void choose_player(){
		CLEAR();
		cout<<"选择你的角色"<<endl;
		cout<<"1 Dyw 离退役4年 操作次数4次"<<endl;
		cout<<"每次操作会释放炸弹清屏"<<endl;
		cout<<"2 Minicago 离退役5年 操作次数3次"<<endl;
		cout<<"每100次提交奖励一次操作机会"<<endl;
		cout<<"3 FM_ding 离退役6年 操作次数2次"<<endl;
		cout<<"每100次提交奖励一次护盾"<<endl;
		if(RC[1].id){	
			cout<<"4 LEGEND_MAO 离退役3年 操作次数5次"<<endl;
			cout<<"每100次提交中最后三十次效果翻倍"<<endl;
		}else cout<<"4 一个传说等待被创造！"<<endl; 
		if(RC[1].sco>=15000){
			cout<<"5 PSS 离退役7年 操作次数1次"<<endl;
			cout<<"失去生命进入疯狂模式！！！"<<endl;
		} else cout<<"5 别惹他！"<<endl;
		while(1){
			a=getch();
			while(a<'1'||a>'0'+PNUM) a=getch();
			if(a=='4'&&(!RC[1].id)) continue;
			if(a=='5'&&(RC[1].sco<15000))continue;
			break;
		}
		ptp=a-'0'; 
		_life=MLIFE[ptp];SKILL=MSKILL[ptp];
		waitpause();
	}
	void choose_skill(){
		CLEAR();
		cout<<"选择你的技能"<<endl;
		cout<<"1 生生不息，永不退役"<<endl;
		cout<<"2 释放护盾，保证平安"<<endl;
		cout<<"3 炸弹清屏，暴力奇迹"<<endl;
		cout<<"4 非常幸运，贪心AC"<<endl;
		cout<<"5 告别霉运，退火稳过"<<endl;
		cout<<"6 绝对零度，参加WC"<<endl;
		a=getch();
		while(a<'1'||a>'6') a=getch();
		skill_type=a-'0';
	}
	void load_data(){
		fp=fopen("highplus","rb");//cout<<(fp==NULL)<<endl;
		if(fp==NULL) {
			fp=fopen("highplus","wb");
			for(register int i=1;i<=10;i++){
				fprintf(fp,"0 %d %d\n",(10-i)*1000,(10-i)*300);
			}
			fclose(fp);
			fp=fopen("highplus","rb");
		}
		
		for(register int i=1;i<=10;i++){
			fscanf(fp,"%d%d%d",&RC[i].id,&RC[i].sco,&RC[i].tt);
		} 
	}
}
