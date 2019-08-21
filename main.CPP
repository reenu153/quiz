
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>


fstream ip,fin,fout;
int n=0;

void addques1();
void addques2();
void displayques1();
void displayques2();

class lvl1
{
public:
int qno;
char ques[300];
char ans[3][100];
char cor;
void add()
{
cout<<"\nEnter the question number";
cin>>qno;
cout<<"Enter the question \n";
gets(ques);
cout<<"\nEnter the options a,b and c \n";
gets(ans[0]);
gets(ans[1]);
gets(ans[2]);
cout<<"Enter correct option ";
cin>>cor;
}
void display()
{
cout<<"\n";
puts(ques);
cout<<"\n";
cout<<"(a) ";puts(ans[0]);
cout<<"\n";
cout<<"(b) ";puts(ans[1]);
cout<<"\n";
cout<<"(c) ";
puts(ans[2]);
}
}q1;

class lvl2
{
public:
int qno;
char ques[300];
char ans[3][100];
char cor;
void add()
{
cout<<"\nEnter the question number";
cin>>qno;
cout<<"Enter the question \n";
gets(ques);
cout<<"\nEnter the options a,b and c \n";
gets(ans[0]);
gets(ans[1]);
gets(ans[2]);
cout<<"Enter correct option ";
cin>>cor;
}

void display()
{
cout<<"\n";
puts(ques);
cout<<"\n";
cout<<"(a) ";puts(ans[0]);
cout<<"\n";
cout<<"(b) ";puts(ans[1]);
cout<<"\n";
cout<<"(c) ";
puts(ans[2]);
}
}q2;

class play
{
public:
char name[30];
int score1;
int score2;
int tot;
play()
{
strcpy(name," ");
score1=0;
score2=0;
tot=0;
}
void playlvl1();
void playlvl2();
}p;

void play:: playlvl1()
{
char save;
cout<<"\nEnter username ";
gets(name);
score1=0;
score2=0;
int b=0;
clrscr();
cout<<"     LEVEL 1";
cout<<"\nRead questions carefully and enter right answers";
char an;
ifstream op("Qn1.dat",ios::binary|ios::in);
while(op.read((char*)&q1,sizeof(q1)))
{
cout<<"\nQuestion "<<++b;
q1.display();
cout<<"\nEnter the correct choice";
cin>>an;
if(an==q1.cor)
{
score1+=10;
cout<<"\nCORRECT ANSWER!";
}
else
cout<<"\nWRONG ANSWER!";
}
cout<<"\nYOUR TOTAL SCORE IN LEVEL 1 IS "<<score1;
op.close();
getch();
}

void play::playlvl2()
{
if(score1>=30)
{
score2=0;
int a=0;
clrscr();
cout<<"\nCongrats!! YOU'VE ENTERED LEVEL 2";
cout<<"\n\n\n\n\n\n\n";
cout<<"\n                    |    |--- \    / |--- |     /--|     ";
cout<<"\n                    |    |---  \  /  |--- |   :   /      ";
cout<<"\n                    |--- |---   \/   |--- |---  /--|     ";
getch();
clrscr();
char sure,an;
cout<<"\n       ONLINE QUIZ CONTEST";
cout<<"\n         *** LEVEL 2 ***  ";
cout<<"\nRead questions carefully and enter right answers\n\n";
ifstream op("Q2.dat",ios::binary|ios::in);
while(op.read((char*)&q2,sizeof(q2)))
{
cout<<"\nQuestion "<<++a;
q2.display();
cout<<"\nEnter the correct option";
cin>>an;
if(an==q2.cor)
{score2+=10;
cout<<"CORRECT ANSWER!\n";
}
else
cout<<"\nWRONG ANSWER!";
}
cout<<"\nYOUR SCORE IN LEVEL 2 IS "<<score2;
tot=score1+score2;
cout<<"\nCONGRATS! YOUR TOTAL SCORE IN THE GAME IS "<<tot;
op.close();
ofstream gi("plam.dat",ios::binary|ios::app);
gi.write((char*)&p,sizeof(p));
cout<<"\nGame saved.Enter any character to continue";
gi.close();
getch();
return;
}
else if(score1<30)
{
score2=0;
cout<<"\nSORRY YOU'VE NOT QUALIFIED FOR THE 2ND ROUND.BETTER LUCK NEXT TIME!";
ofstream gi("plam.dat",ios::binary|ios::app);
gi.write((char*)&p,sizeof(p));
cout<<"\nGame saved.Enter any character to continue";
getch();
return;
}
}

void main()
{
clrscr();
cout<<"\n\n\n";
cout<<"\n ------------------------------------------------------------------------     ";
cout<<"\n|         * *  *     * *     *  *     * * * *    * *    *    * *  * * *  |    ";
cout<<"\n|        *   * * *   * *     *  * *   * *       *   *   *    * *     *   |    ";
cout<<"\n|        *   * *  *  * *     *  *  *  * * * *   *   *   *    * *    *    |    ";
cout<<"\n|        *   * *   * * *     *  *   * * *       * * *   *    * *   *     |    ";
cout<<"\n|         * *  *    ** * * * *  *    ** * * *    * * **   **   *  * * *  |    ";
cout<<"\n|                                                                        |    ";
cout<<"\n|                ***    * *  *     * * * * * * *  *  *  * * * *          |    ";
cout<<"\n|               *     *    * * *   *   *   *      *         *            |    ";
cout<<"\n|              *      *    * *  *  *   *   * * *  *  *  *   *            |    ";
cout<<"\n|               *     *    * *   * *   *   *            *   *            |    ";
cout<<"\n|                ***    **   *    **   *   * * *  *  *  *   *            |    ";
cout<<"\n ------------------------------------------------------------------------     ";
getch();
int ch;
do
{
prestart:
clrscr();
cout<<"\n             ************************************  ";
cout<<"\n             *         ONLINE QUIZ CONTEST      *  ";
cout<<"\n             *            1.ADMIN MENU          *  ";
cout<<"\n             *            2.PLAYERS MENU        *  ";
cout<<"\n             *            3.EXIT                *  ";
cout<<"\n             ************************************  ";
cout<<"\n\nEnter your choice ";
cin>>ch;
switch(ch)
{
case 1:clrscr();
       char pw[5];
       int c;
       cout<<"\nADMIN MENU";
       cout<<"\nEnter the password";
       gets(pw);
       if(strcmpi(pw,"*****")==0)
       {
       start:
       do
       {
       clrscr();
       cout<<"\n\n";
       cout<<"\n            ******************************     ";
       cout<<"\n            *         ADMIN MENU         *     ";
       cout<<"\n            *   1.Add more questions     *     ";
       cout<<"\n            *   2.Delete a question      *     ";
       cout<<"\n            *   3.Modify a question      *     ";
       cout<<"\n            *   4.Display the questions  *     ";
       cout<<"\n            *   5.Go back to main menu   *     ";
       cout<<"\n            ******************************     ";
       cout<<"\n\nEnter a choice";
       cin>>c;
       switch(c)
       {
       case 1: clrscr();
	       int lvl;
	       cout<<"Enter the level you want to add questions(1or2)";
	       cin>>lvl;
	       switch(lvl)
		{case 1: int choice;
			  cout<<"\n         **********************      "    ;
			  cout<<"\n                 LEVEL 1             "    ;
			  cout<<"\n         **********************      "    ;
			  cout<<"\n";
			  cout<<"Enter the required details ";
			  addques1();
			  cout<<"Do you want to goto main menu or level2(1or2) ";\
			  cin>>choice;
			  if(choice==1)
			  goto start;
			  else
			  goto lvl2;

		case 2:  clrscr();
			 lvl2:
			 int choic;
			 cout<<"\n          **********************      "   ;
			 cout<<"\n                 LEVEL2               "   ;
			 cout<<"\n          **********************      "   ;
			 cout<<"\n";
			 cout<<"\nEnter the required details ";
			 addques2();
			 break;
			}
			break;

       case 2: void del();
	       void del2();
	       cout<<"\n                  DELETE A QUESTION        \n";
	       int levl;
	       cout<<"\nWhich level question do you want to delete?";
	       cin>>levl;
	       if(levl==1)
	       del();
	       else if(levl==2)
	       del2();
	       break;

       case 3: int l;
	       cout<<"\nEnter the level you want to modify (1or2)";
	       cin>>l;
	       switch(l)
		{case 1:  cout<<"\n         **********************      "    ;
			  cout<<"\n                 LEVEL 1             "    ;
			  cout<<"\n         **********************      "    ;
			  cout<<"\n";
			  void modify1();
			  modify1();
			  break;

		case 2:  clrscr();
			 cout<<"\n          **********************      "   ;
			 cout<<"\n                 LEVEL2               "   ;
			 cout<<"\n          **********************      "   ;
			 cout<<"\n";
			 void modify2();
			 modify2();
			 break;
		}
		break;

       case 4:clrscr();
	      int co;
	      cout<<"Which level questions do you want to see(1 or 2)?";
	      cin>>co;
	      if(co==1)
	      displayques1();
	      else if(co==2)
	      displayques2();
	      break;

       case 5:goto prestart;

       }
       }
       while(c!=0);
       }
       else
       cout<<"\nWrong password";
       getch();
       break;
case 2:clrscr();
      int choi;
      char re;
      cout<<"\n\n\n";
      cout<<"\n  ------------------------------------------------------------------------     ";
      cout<<"\n |        * *  *     * *      *  *     * * * *    * *    *    * *  * * *  |    ";
      cout<<"\n |       *   * * *   * *      *  * *   * *       *   *   *    * *     *   |    ";
      cout<<"\n |       *   * *  *  * *      *  *  *  * * * *   *   *   *    * *    *    |    ";
      cout<<"\n |       *   * *   * * *      *  *   * * *       * * *   *    * *   *     |    ";
      cout<<"\n |        * *  *    ** * * *  *  *    ** * * *    * * **   **   *  * * *  |    ";
      cout<<"\n";
      cout<<"\n |                ***    * *  *     * * * * * * *  *  *  * * * *          |    ";
      cout<<"\n |               *     *    * * *   *   *   *      *         *            |    ";
      cout<<"\n |              *      *    * *  *  *   *   * * *  *  *  *   *            |    ";
      cout<<"\n |               *     *    * *   * *   *   *            *   *            |    ";
      cout<<"\n |                ***    **   *    **   *   * * *  *  *  *   *            |    ";
      cout<<"\n  ------------------------------------------------------------------------     ";
      getch();
       clrscr();
       player:
       do
       {
       clrscr();
       cout<<"\n            **************************    ";
       cout<<"\n            *     PLAYER'S MENU      *    ";
       cout<<"\n            *  1.Read instructions   *    ";
       cout<<"\n            *  2.Start game          *    ";
       cout<<"\n            *  3.Check high scores   *    ";
       cout<<"\n            *  4.Check results       *    ";
       cout<<"\n            *  5.Go to main menu     *    ";
       cout<<"\n            **************************    ";
       cout<<"\n\n                Enter a choice ";
       cin>>choi;
       switch(choi)
       {
       case 2:clrscr();
	      char con,cn;
	      cout<<"\n\n\n\n\n\n\n";
	      cout<<"\n                         |    |--- \    / |--- |     /|   ";
	      cout<<"\n                         |    |---  \  /  |--- |   :  |   ";
	      cout<<"\n                         |--- |---   \/   |--- |---  -|-  ";
	      getch();
	      clrscr();
	      cout<<"\n ***   LEVEL 1   ***";
	      p.playlvl1();
	      p.playlvl2();
	      break;
       case 1:clrscr();
	      cout<<"\n\n                  INSTRUCTIONS";
	      cout<<"\n ********************************************************************";
	      cout<<"\n *  There are two level in this quiz                                 * ";
	      cout<<"\n *  Each right answer is awarded 10 points                           * ";
	      cout<<"\n *  The first level contains questions of medium difficulty level    * ";
	      cout<<"\n *  To enter level2,you need to secure minimum 30 points in level1   * ";
	      cout<<"\n *  The second round contains questions of hard difficulty level     * ";
	      cout<<"\n *  You can save the game after level 1 to continue later on         * ";
	      cout<<"\n ********************************************************************* ";
	      cout<<"\n\n---------------------Press Enter key to continue----------------------";
	      getch();
	      break;

       case 3:clrscr();
	      void high();
	      high();
	      break;
       case 4:clrscr();
	      void scoreread();
	      scoreread();
	      break;
       case 5:goto prestart;
       }
       }
       while(choi!=0);
       break;
case 3:exit(0);
}
}
while(ch!=0);
getch();
}

//function to insert questions
void addques1()
{
char sur='y';
int n=0;
ip.open("Qn1.dat",ios::binary|ios::in);
while(ip.read((char*)&q1,sizeof(q1)))
++n;
ip.close();
cout<<"\nThere are "<<n<<" questions as of now";
ofstream ki("Qn1.dat",ios::binary|ios::app);
while(sur=='y')
{
{
q1.add();
ki.write((char*)&q1,sizeof(q1));
}
cout<<"\nDo you want to enter more(y/n)?";
cin>>sur;
}
ki.close();
}

void addques2()
{
char suro='y';
int n=0;
ip.open("Q2.dat",ios::binary|ios::in);
while(ip.read((char*)&q2,sizeof(q2)))
++n;
cout<<"\nThere are "<<n<<" questions as of now";
ip.close();
ofstream ope("Q2.dat",ios::binary|ios::app);
while(suro=='y')
{
q2.add();
ope.write((char*)&q2,sizeof(q2));
cout<<"\nDo you want to enter more(y/n)?";
cin>>suro;
}
ope.close();
}

//function to display questions
void displayques1()
{
ifstream opn("Qn1.dat",ios::binary|ios::in);
int no,flag=0;
cout<<"\nEnter the question number to display";
cin>>no;
while(opn.read((char*)&q1,sizeof(q1)))
if(q1.qno==no)
{
q1.display();
getch();
flag=1;
break;
}
if (flag==0)
cout<<"\nQuestion not found";
getch();
opn.close();
}

void displayques2()
{
ifstream opn("Q2.dat",ios::binary|ios::in);
int no,flag=0;
cout<<"\nEnter the question number to display";
cin>>no;
while(opn.read((char*)&q2,sizeof(q2)))
if(q2.qno==no)
{
q2.display();
getch();
flag=1;
break;
}
if (flag==0)
cout<<"\nQuestion not found";
getch();
opn.close();
}

void modify1()
{
int c,que;
char mod;
cout<<"\nEnter the no. of the question you want to modify ";
cin>>que;
fstream op;
op.open("Qn1.dat",ios::binary| ios::out|ios::in);
while(!op.eof())
{
int pos= op.tellg();
op.read((char*) &q1,sizeof(q1));
if(q1.qno==que)
{
q1.display();
cout<<"\nWhat do you want to modify?\n(q).Question \n(o).Options \n(a).Answer\n ";
cin>>mod;
switch(mod)
{
 case 'q' :
	   cout<<"\nEnter the new question ";
	   gets(q1.ques);
	   op.seekg(pos);
	   op.write((char*) &q1,sizeof(q1));
	   break;
 case 'o' :char opt;
	   cout<<"\nWhich opt do u want to modify? ";
	   cin>>opt;
	   if(opt=='a')
	   { cout<<"\nEnter the new option ";
	   gets(q1.ans[0]);
	   op.seekg(pos);
	   op.write((char*) &q1,sizeof(q1));
	   }
	   else if(opt=='b')
	   { cout<<"\nEnter the new option ";
	   gets(q1.ans[1]);
	   op.seekg(pos);
	   op.write((char*) &q1,sizeof(q1));
	   }
	   else if(opt=='c')
	   { cout<<"\nEnter the new option ";
	   gets(q1.ans[2]);
	   op.seekg(pos);
	   op.write((char*) &q1,sizeof(q1));
	   }
	   break;
 case 'a' :
	   cout<<"\nEnter the correct ans ";
	   cin>>q1.cor;
	   op.seekg(pos);
	   op.write((char*) &q1,sizeof(q1));
	   break;

 }
 break;
}
}
cout<<"\nModification successful!";
getch();
}

void modify2()
{
int c,que;
char mod;
cout<<"\nEnter the no. of the question you want to modify ";
cin>>que;
fstream op;
op.open("Q2.dat",ios::binary|ios::out|ios::in);
while(!op.eof())
{
int pos= op.tellg();
op.read((char*) &q2,sizeof(q2));
if(q2.qno==que)
{
q2.display();
cout<<"\nWhat do you want to modify? \n(q).Question \n(o).Options \n(a).Answer\n";
cin>>mod;
switch(mod)
{
 case 'q':
	   cout<<"\nEnter the new question ";
	   gets(q2.ques);
	   op.seekg(pos);
	   op.write((char*) &q2,sizeof(q2));
	   break;

 case 'o': char opt;
	   cout<<"\nWhich option do u want to modify? ";
	   cin>>opt;
	   if(opt=='a')
	   {
	   cout<<"\nEnter the new option ";
	   gets(q2.ans[0]);
	   op.seekg(pos);
	   op.write((char*) &q2,sizeof(q2));
	   }
	   else if(opt=='b')
	   {
	   cout<<"\nEnter the new option ";
	   gets(q2.ans[1]);
	   op.seekg(pos);
	   op.write((char*) &q2,sizeof(q2));
	   }
	   else if(opt=='c')
	   {
	   cout<<"\nEnter the new option ";
	   gets(q2.ans[2]);
	   op.seekg(pos);
	   op.write((char*) &q2,sizeof(q2));
	   }
	   break;

 case 'a':
	   cout<<"\nEnter the correct ans ";
	   cin>>q2.cor;
	   op.seekg(pos);
	   op.write((char*) &q2,sizeof(q2));
	   break;
}
break;
}
}
cout<<"\nModification successful!";
getch();
}

void del()
{
int no;
char sur3;
cout<<"\nEnter the question no: of the question you want to delete ";
cin>>no;
ifstream op("Qn1.dat",ios::binary|ios::in);
ofstream file("temp.dat",ios::binary|ios::app);
while(!op.eof())
{
op.read((char*) &q1,sizeof(q1));
if(q1.qno==no)
{q1.display();
cout<<"\nAre you sure you want to delete?(y/n)";
cin>>sur3;
break;
}
}
op.close();
if(sur3=='y')
{
op.open("Qn1.dat",ios::binary|ios::in);
while(!op.eof())
{
op.read((char*) &q1, sizeof(q1));
if(q1.qno!=no)
file.write((char*)&q1,sizeof(q1));
}
op.close();
file.close();
remove("Qn1.dat");
rename("temp.dat","Qn1.dat");
cout<<"\nQuestion deleted";
getch();
}
else if(sur3=='n')
return;
op.close();
file.close();
}

void del2()
{
int no;
char sur3;
cout<<"\nEnter the question no: of the question you want to delete ";
cin>>no;
ifstream op("Q2.dat",ios::binary|ios::in);
ofstream file("tempo.dat",ios::binary|ios::app);
while(!op.eof())
{
op.read((char*) &q2,sizeof(q2));
if(q2.qno==no)
{q2.display();
cout<<"\nAre you sure you want to delete?(y/n)";
cin>>sur3;
break;
}
}
op.close();
if(sur3=='y')
{
op.open("Q2.dat",ios::binary|ios::in);
while(!op.eof())
{
op.read((char*) &q2, sizeof(q2));
if(q2.qno!=no)
file.write((char*)&q2,sizeof(q2));
}
op.close();
file.close();
remove("Q2.dat");
rename("tempo.dat","Q2.dat");
cout<<"\nQuestion deleted";
getch();
}
else if(sur3=='n')
return;
op.close();
file.close();
}


//function to see the score of a player
void scoreread()
{
clrscr();
cout<<"\n              PLAYER SCORE               ";
char req[50];
cout<<"\nEnter the name of the player for scores ";
gets(req);
int flag=0;
ifstream fi("plam.dat",ios::binary|ios::in);
while(!fi.eof())
{
fi.read((char*)&p,sizeof(p));
if(strcmpi(p.name,req)==0)
{
flag=1;
cout<<setw(20)<<"\n       YOUR SCORES     ";
cout<<setw(15)<<"\n\n| PLAYER NAME:";
puts(p.name);
cout<<setw(15)<<"\n| PLAYER SCORE IN LEVEL 1:"<<p.score1;
cout<<setw(15)<<"\n| PLAYER SCORE IN LEVEL 2:"<<p.score2;
cout<<setw(15)<<"\n| PLAYER TOTAL SCORE :"<<p.score1+p.score2;
getch();
fi.close();
break;
}
if(flag==1)
break;
fi.close();
}
if(flag==0)
cout<<"\nPlayer not found";
getch();
return;
}

//function to see the highscores
void high()
{
clrscr();
cout<<"\n\n  ************************************************************";
cout<<"\n     |   | | |---- |   |   |---- |---|---||---||---|----      ";
cout<<"\n     |---| | |  -| |---|   |----||   |   ||\--||-- |---|      ";
cout<<"\n     |   | | |---| |   |    ----||---|---|| \  |--- ---|      ";
cout<<"\n    ************************************************************";
cout<<"\n\n";
cout<<setw(15)<<"\n* SI NO:";
cout<<setw(25)<<"PLAYER NAME";
cout<<setw(30)<<"PLAYER TOTAL"<<setw(4)<<"*"<<"\n";
getch();
int f=0,s=0,d=0,small=0,tempe=0,pos=0,mk[25],c=0;
char nme[25][50],temp2[50];
fin.open("plam.dat",ios::binary|ios::in);
while(!fin.eof())
{fin.read((char*) &p,sizeof(p));
 p.tot=p.score1+p.score2;
 mk[f]=p.tot;
 strcpy(nme[f],p.name);
 ++f;
 s=f;
}
fin.close();
for(d=0;d<s;d++)
{small=mk[d];
pos=d;
for(int u=d+1;u<s+1;u++)
if(mk[u]<small)
{small=mk[u];
 pos=u;
 }
tempe=mk[d];
mk[d]=mk[pos];
mk[pos]=tempe;
strcpy(temp2,nme[d]);
strcpy(nme[d],nme[pos]);
strcpy(nme[pos],temp2);
}

for(int o=s-1;o>0;o--)
{
cout<<"\n*";
cout<<setw(5)<<++c;
cout<<setw(25)<<nme[o];
cout<<setw(30)<<mk[o]<<setw(6)<<"*";
getch();
}

getch();
clrscr();
}
