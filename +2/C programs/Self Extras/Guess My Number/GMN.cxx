/*
 * GMN.cxx
 * 
 * Copyright 2013 Shriraj Sawant <shri@SR13>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
 
/* Hello, I'm Shriraj a CS Student.
 * This is my first c++ program.
 * This program is a basic construct for a game based programs
 * This is a program for Guess my number game*/
 
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	char pg,a0;
	cout<<"INSTRUCTION:\n[In this game either cpu or you will have to choose a number between 1 to 100\n and accordingly the other one will have to guess it.]\n#=> y=yes\n    n=no\n    h=too high\n    l=too low\n\n\n";			
	do {
		int mx=100,mn=1,c,d;
		char r;
		srand(time(0));
		int n=rand()%mx+mn;
		int tpc=0,thu=0,gpc,ghu; // tries & guesses variables for computer and human
		
		cout<<"\t\tWelcome To Guess My Number\n\n\t\t\t'CPU vs HUMAN'\n\t\t\t'!!SHOWDOWN!!'\n\n";
		cout<<"\nChoose your difficulty (for CPU Player):-\n1)Mindless mode\n2)Intelli mode\nYour Choice: ";
		cin>>d;
		
		if (d!=1&&d!=2) {
			cout<<"\nINVALID DIFFICULTY LEVEL!";
			continue;
		}		
		cout<<"\nChoose who will get the first chance to guess the number from the others mind.  'Challenge me if you dare!!'";  
		cout<<"\n1) Human\n2) CPU\n3) Exit Game\n\n# Your Choice: ";
		cin>>c;
		
		if (c==1) {
			cout<<"\nAll right! I swear you'll give up in less than 3 tries\nI have chose my number, let us see how much time you'll take to guess it!";
			do {
				cout<<"\nEnter your guess: ";
				cin>>ghu;
				++thu;
			
				if (ghu>n) {
					cout<<"\nYour guess is too high!\n";
					if ((ghu-n)<=2) cout<<"\nBut you are very much close to it.";
					else if ((ghu-n)<=7) cout<<"\nBut you are closer to it.";
				}
				if (ghu<n) {
					cout<<"\nYour guess is too low!\n";
					if ((n-ghu)<=2) cout<<"\nBut you are very much close to it.";
					else if ((n-ghu)<=7) cout<<"\nBut you are closer to it.";
				}
				if (thu==5&&ghu!=n) cout<<"\nGive up human! You are sweating!!";	
			}
			while (ghu!=n);
			cout<<"\nThat's it!!";
			if (thu==1) cout<<"You got it in your first try itself!!!\nCongratulations!\nYou are truly a mind reader!\nTeach me your technique if you get time.\n";
			else if (thu<=3) cout<<"You got it in "<<thu<<" guesses!\nCongratulations.\nYou are in my top three list!\n";
			if (thu>3) cout<<"You got it in "<<thu<<" guesses.\nAtleast you didn't give up.By the way try next time for higher rankings.\n";
		}				
			
		if (c==2) {
			cout<<"\nChoose a number in your mind.\nEnter y when you are ready.\n";
			cin>>a0;
			if (d==1) {
				cout<<"\nOkay then, let's begin the game!\n";
				do{
					srand(time(0));
					gpc=rand()%mx+mn;
					++tpc;
					cout<<"\nIs the number in your mind'"<<gpc<<"'?\nReply: ";
					cin>>r;
					if(r=='h'|| r=='l'|| r=='n')	continue;
					if(r=='y') {
						if(tpc==1) cout<<"\nSee, I got it in my first try itself!\nCan you do it human! I doesn't think so!!\nHa! Ha! HAA!!!!\n";
						if(tpc>1 && tpc<5) cout<<"\nYes!! I got it in less than 5 tries! Try yourself next time and beat me!!\n";
						else cout<<"\nAtleast I got it (tries="<<tpc<<")! \nYou would have given up by this time!\n";
					}
				}
				while (r!='y');
			}
					
			if (d==2) {
				char a1=0,b1=0,c1=0,d1=0,e1=0,f1=0,g1=0,h1=0,i1=0,j1=0,k1=0,l1=0,m1=0,n1=0,o1=0,p1=0,q1=0,r1=0,s1=0,t1=0,u1=0,v1=0,w1=0,x1=0,y1=0,z1=0;
				int as=0,z0=1,ext=0;
				do {
					cout<<"\n(Thinking)...";
					srand(time(0));
					gpc=rand()%mx+mn;
					if (a1==gpc || b1==gpc || c1==gpc || d1==gpc || e1==gpc || f1==gpc || g1==gpc || h1==gpc || i1==gpc || j1==gpc || k1==gpc  || l1==gpc || m1==gpc || n1==gpc || o1==gpc || p1==gpc || q1==gpc || r1==gpc || s1==gpc || t1==gpc || u1==gpc || v1==gpc || w1==gpc || x1==gpc || y1==gpc || z1==gpc ) continue;
					if (gpc>mx) {ext=gpc-mx;gpc-=ext;}
					if(gpc<mn) {ext=mn-gpc;gpc+=ext;}
					reset:
					switch(++as) {
						case 1: a1=gpc;break;
						case 2: b1=gpc;break;
						case 3: c1=gpc;break;
						case 4: d1=gpc;break;
						case 5: e1=gpc;break;
						case 6: f1=gpc;break;
						case 7: g1=gpc;break;
						case 8: h1=gpc;break;
						case 9: i1=gpc;break;
						case 10: j1=gpc;break;
						case 11: k1=gpc;break;
						case 12: l1=gpc;break;
						case 13: m1=gpc;break;
						case 14: n1=gpc;break;
						case 15: o1=gpc;break;
						case 16: p1=gpc;break;
						case 17: q1=gpc;break;
						case 18: r1=gpc;break;
						case 19: s1=gpc;break;
						case 20: t1=gpc;break;
						case 21: u1=gpc;break;
						case 22: v1=gpc;break;
						case 23: w1=gpc;break;
						case 24: x1=gpc;break;
						case 25: y1=gpc;break;
						case 26: z1=gpc;break;
						default: as=0; goto reset; 
					}
					if(z0==1) {
						cout<<"\nNow I'll show you the real power of a silicon chip human!Begin the GAME!!\n";
						++z0;
					}
					cout<<"\nIs the number in your mind'"<<gpc<<"'?\nReply: ";
					++tpc;
					cin>>r;
					if(r=='n') continue;
					if(r=='h') {mx=gpc-1;}
					if(r=='l') {mn=gpc+1;}
					if(r=='y') {
						if(tpc==1) cout<<"\nSee, I got it in my first try itself!\nCan you do it human! I doesn't think so!!\nHa! Ha! HAA!!!!\n";
						if(tpc>1 && tpc<6) cout<<"\nYes!! I got it in less than 5 tries! Try yourself next time and beat me!!\n";
						else if(tpc>5) cout<<"\nAtleast I got it (tries= "<<tpc<<")! \nYou would have given up by this time!\n";
					}
				}
				while (r!='y');
			}
		}							
		if (c==3) return 0;
		
		if (c!=1&&c!=2&&c!=3) {
			cout<<"\nINVALID CHOICE!\n\n";
			continue;
		}
		cout<<"\n'GAME OVER'\nDo you want to play again? (y/n)\nChoice: ";
		cin>>pg;
	}
	while (pg!='n');
	return 0;
}
	



