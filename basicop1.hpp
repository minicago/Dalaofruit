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
		cout<<"ѡ����Ľ�ɫ"<<endl;
		cout<<"1 Dyw ������4�� ��������4��"<<endl;
		cout<<"ÿ�β������ͷ�ը������"<<endl;
		cout<<"2 Minicago ������5�� ��������3��"<<endl;
		cout<<"ÿ100���ύ����һ�β�������"<<endl;
		cout<<"3 FM_ding ������6�� ��������2��"<<endl;
		cout<<"ÿ100���ύ����һ�λ���"<<endl;
		if(RC[1].id){	
			cout<<"4 LEGEND_MAO ������3�� ��������5��"<<endl;
			cout<<"ÿ100���ύ�������ʮ��Ч������"<<endl;
		}else cout<<"4 һ����˵�ȴ������죡"<<endl; 
		if(RC[1].sco>=15000){
			cout<<"5 PSS ������7�� ��������1��"<<endl;
			cout<<"ʧȥ����������ģʽ������"<<endl;
		} else cout<<"5 ��������"<<endl;
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
		cout<<"ѡ����ļ���"<<endl;
		cout<<"1 ������Ϣ����������"<<endl;
		cout<<"2 �ͷŻ��ܣ���֤ƽ��"<<endl;
		cout<<"3 ը�������������漣"<<endl;
		cout<<"4 �ǳ����ˣ�̰��AC"<<endl;
		cout<<"5 ���ù�ˣ��˻��ȹ�"<<endl;
		cout<<"6 ������ȣ��μ�WC"<<endl;
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
