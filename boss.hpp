/*
  1 封印 
  2 快速
  3 迷惑
  4 慢速 
*/
inline bool checkbossalive(){
	if(BOSS_HP<=0) fightwithboss=0;
	return fightwithboss;
}
inline void make_boss1(){
	BOSS_HP=30;BOSS_Name="你好，世界！";BOSS_Sco=500; 
	BossSkill[1]=0;BossSkill[2]=0;BossSkill[3]=0;BossSkill[4]=0;
	fightwithboss=1;bosshurt=0;color=1;
}
inline void make_boss2(){
	BOSS_HP=50;BOSS_Name="卡尼阿克";BOSS_Sco=900; 
	BossSkill[1]=1;BossSkill[2]=1;BossSkill[3]=0;BossSkill[4]=0;
	fightwithboss=1;bosshurt=0;color=1;
}
inline void make_boss3(){
	BOSS_HP=60;BOSS_Name="Koish";BOSS_Sco=1200; 
	BossSkill[1]=0;BossSkill[2]=0;BossSkill[3]=1;BossSkill[4]=1;
	fightwithboss=1;bosshurt=0;color=1;
}
inline void make_boss4(){
	BOSS_HP=80;BOSS_Name="The Xuan";BOSS_Sco=1500; 
	BossSkill[1]=1;BossSkill[2]=1;BossSkill[3]=0;BossSkill[4]=1;
	fightwithboss=1;bosshurt=0;color=1;
}
inline void make_boss5(){
	BOSS_HP=200;BOSS_Name=pname[ptp]+"的思念";BOSS_Sco=5000; 
	BossSkill[1]=1;BossSkill[2]=1;BossSkill[3]=1;BossSkill[4]=1;
	fightwithboss=1;bosshurt=0;color=1;
}
inline void winboss(){
	if(fightwithboss){
		if(!checkbossalive()){
				bcast("You beat "+BOSS_Name+"!");
				_sco+=BOSS_Sco; 
		
			if(!bosshurt){
				bcast("Perfect Skill!");
				if((MSKILL[ptp]+MLIFE[ptp])%2==0){
					bcast("You feel young!");
					MLIFE[ptp]++;_life++;
				}else{
					bcast("You feel power!");
					MSKILL[ptp]++;SKILL++;
				}
				if(BOSS_Sco==1200){
					bcast("你是二次元战士吗?1000分给你。");
					_sco+=1000;t7++;
				}
			}
		}	
	} 
}
