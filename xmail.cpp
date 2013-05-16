#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<dir.h>
#include<dos.h>
#include<iomanip.h>

const MIN=102400;
const MAX=(1024*1024);
const char LIST[]={"C:\\econ\\xmail\\list.sys"};
const char UINFO[]={"C:\\econ\\xmail\\uinfo.sys"};
void prs()                                          //function to exit a page
{
   int x=wherex();int y=wherey();
	cout<<"\n\nPress '0' / '<-' / 'Esc' to go back ";
   register char q;
   q=char(getch());
   int k=(int)q;
   switch(k)
   {
   	case 27:break;
      case 8:break;
      case 48:break;
      default:gotoxy(x,y);prs();
   }

}
void charat(int x, int y, char ch)
{
	gotoxy(x, y);
	cprintf("%c", ch);
}
void box1(int x1, int y1, int x2, int y2)                //draw a box
{

	textcolor(LIGHTGRAY);
	textbackground(MAGENTA);
	for(int col=x1;col<x2;col++)
	{
		charat(col, y1, 196);
		charat(col, y2, 196);
	}
	for(int row=y1;row<y2;row++)
	{
		charat(x1, row, 179);
		charat(x2, row, 179);
	}
	charat(x1, y1, 218);
	charat(x1, y2, 192);
	charat(x2, y1, 191);
	charat(x2, y2, 217);
}
void box2(int x1, int y1, int x2, int y2)           //draw a double line box
{

	textcolor(15);
	textbackground(BLACK);
	for(int col=x1;col<x2;col++)
	{
		charat(col, y1, 205);
		charat(col, y2, 205);
	}
	for(int row=y1;row<y2;row++)
	{
		charat(x1, row, 186);
		charat(x2, row, 186);
	}
	charat(x1, y1, 201);
	charat(x1, y2, 200);
	charat(x2, y1, 187);
	charat(x2, y2, 188);
}
void loadlog()                                   //logging in display function
{
   _setcursortype(_NOCURSOR);
	box2(30,12,52,15);
   gotoxy(31,13);
   cout<<"Loging in please wait";
   gotoxy(31,14);
   textcolor(14);
	textbackground(WHITE);
   for(int x=1;x<88000000;x++)
      if(x%4000000==0)
   	cprintf(" ");
   textcolor(LIGHTGRAY);
	textbackground(BLACK);
   _setcursortype(_NORMALCURSOR);
}
void load()                                      //loading dieplay function
{
   clrscr();
   _setcursortype(_NOCURSOR);
	box2(30,12,52,15);
   gotoxy(31,13);
   cout<<"Loading......";
   gotoxy(31,14);
	textbackground(9);
   for(int x=1;x<176000000;x++)
      if(x%8000000==0)
   	cprintf(" ");
   textcolor(LIGHTGRAY);
	textbackground(BLACK);
   _setcursortype(_NORMALCURSOR);
}                                                          //menu display
void mendis()
{
   clrscr();
	cout<<"---------------------------------";
   cout<<"---------------------------------------------"<<endl;
   cout<<"\t\t\t\tCommand choice"<<endl;
   cout<<'\t'<<'\t'<<'\t'<<char(27)<<'\t'<<'\t'<<"esc"<<'\t'<<'\t'<<"0"<<endl;
   cout<<"----------------------------------";
   cout<<"--------------------------------------------"<<endl<<endl<<endl;
}

void mygets(char *s, int limit)                             //MY gets
{
	void delchar(char*, int, int, int&);
   int i, curx, done;
   int col=wherex();int row=wherey();
   for(i=0; i<limit; i++)
      cout<<'.';
   gotoxy(col,row);
    int endx=col;int endy=row;
   done=curx=i=0;
   do
   {
      char ch=char(getch());
      switch(ch)
      {
         case 0:
            ch=char(getch());
            switch (ch)
            {
               case 75:
                  if (curx>0)
                  {
                     curx--;
                     gotoxy(wherex()-1, wherey());
                  }
                  break;
               case 77:
                  if (curx<i)
                  {
                     curx++;
                     gotoxy(wherex()+1, wherey());
                  }
                  break;
               case 83:
                  if (i>0)
                  {
                     if (curx<i)
                     {
                        delchar(s, col, curx+1, i);
                        gotoxy(col+curx, wherey());
                        if (i==0)
                           s[i]=0;
                     }
                  }
            }
            break;
         case 8:
            if (curx>0)
            {
               delchar(s, col, curx, i);
               gotoxy(col+curx-1, wherey());
               curx--;
               if (i==0)
                  s[i]=0;
            }
            break;
         case 13:
            done=1;
            s[i]=0;
            break;
         case 27:
            done=1;
            s[0]=0;
            break;
         default:
            if (i<limit)
            {
               if (curx<i)
               {
                  s[curx]=ch;
                  cout<<ch;
                  curx++;
               }
               else
               {
                  s[i]=ch;
                  cout<<ch;
                  i++;
                  curx=i;
               }
            }
            else
               s[i]=0;
      }
   }
   while(!done);
   cout<<endl;
   gotoxy(endx,endy);
   cout<<endl;
}
void delchar(char *s, int col, int p, int &len)          //delete ch( 4 mygets)
{
   int i;
   for(i=p; i<len; i++)
      s[i-1]=s[i];
   gotoxy(col+p-1, wherey());
   len--;
   for(i=p-1; i<len; i++)
      cout<<s[i];
   cout<<'.';
}

char* iattach(char name[])       				 			//attach inbox extension
{
	char arr[100];
   strcpy(arr,"C:\\econ\\xmail\\");
   strcat(arr,name);
   strcat(arr,"i.GEN-X");
	return arr;
}
char* mattach(char name[])               		 	  //attach message extension
{
	char arr[100];
   strcpy(arr,"C:\\econ\\xmail\\");
   strcat(arr,name);
   strcat(arr,"m.GEN-X");
	return arr;
}
struct dte{ int dd,mm,yy;};
int checkdate(dte dt)
{
  	int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  	if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   	maxdays[1]=29;
  	if (dt.mm>=1 && dt.mm<=12)
  	{
    	if (dt.dd>=1 && dt.dd<=maxdays[dt.mm-1])
      	return 1;
    	else
      	return 0;
  	}
  	else
    	return 0;
}
void inputdate(dte& dt)
{
   int valid;
   do
   {
      cout<<"\nEnter Day [1-31]  ? "; cin>>dt.dd;
      cout<<"\nEnter Month [1-12]? "; cin>>dt.mm;
      cout<<"\nEnter Year [YYYY] ? "; cin>>dt.yy;cout<<endl;
      valid=checkdate(dt);
      if (valid==0)
      	cout<<"Invalid date. Input again.\n";
   }
   while(valid==0);
}
int valcity(char* arr)                          //validate city
{
	int len=0;while(arr[len]) len++;
   int k=0,f=1;
   while(k<len && f==1)
   {
   	if(arr[k]>='a' && arr[k]<='z')
       	continue;
      if(arr[k]>='A' && arr[k]<='Z')
       	continue;
      else
      	f=0;
      k++;
   }
   if(f==1)
   	return 1;
   else return 0;
}




class info                                       //new user info class
{

   dte dob;
   char city[20];
   char qn[80];
   char ans[30];
   public:
   char fname[40];
   void infoin()
   {
   	cout<<"\n\n\nInput your full name : ";mygets(fname,30);
      cout<<"\nInput date of birth : ";inputdate(dob);
      cout<<"\nInput city of residence : ";mygets(city,20);
      if(checkdate(dob)==0 && valcity(city)==0)
      	{cout<<"\nInvalid Input!";infoin();}
      else
      {
      	cout<<"\nInput a question of you choice : ";mygets(qn,80);
         cout<<"\nInput answer to the question : ";mygets(ans,30);
      }
   }
   void qndisp()
   {
      cout<<"\n";
   	puts(qn);
   }
   void ansin()
   {
   	cout<<"\nInput answer to the question : ";mygets(ans,30);
   }
   void fnamein()
   {
   	cout<<"\n\nInput your full name : ";mygets(fname,30);
   }
   void dispinfo()
   {
   	cout<<fname<<'\n'<<dob.dd<<'\n'<<dob.mm;
      cout<<'\n'<<dob.yy<<'\n'<<" "<<city<<" "<<qn<<'\n'<<ans<<endl<<endl;
   }
   char* retans(){return ans;}

};
void crinfo()                                    //creatin info
{
   info a;
   ofstream fout(UINFO,ios::binary|ios::app);
   a.infoin();
   fout.write((char*)&a,sizeof(a));
   fout.close();
}

void passin(char*);
class logon                                    //user class
{
   public:
	char user[25];
   char pass[20];
   int sp;
   logon(){strcpy(pass," ");sp=MIN;}
   void input()
   {
   	box2(20,8,60,20);
      gotoxy(22,12);
   	cout<<"Username : ";
      gotoxy(22,15);
      cout<<"Password : ";
      gotoxy(35,12);
		gets(user);
      gotoxy(35,15);
      passin(pass);
   }
   void display()
   {
   	printf("%-25s %-20s",&user,&pass);cout<<sp<<endl;
   }
};
void passin(char s[])                                //input password
{
  	void delch(char*, int, int, int&);
   int i,curx,f;
   int col=wherex();int row=wherey();
   int endx=wherex();int endy=wherey();
   gotoxy(col,row);
   f=curx=i=0;
   do
   {
      char ch=char(getch());
      switch(int(ch))
      {
         case 8:
            if (curx>0)
            {
               delch(s, col, curx, i);
               gotoxy(col+curx-1, wherey());
               curx--;
               if (i==0)
                  s[i]=0;
            }
            break;
         case 13:
            f=1;
            s[i]=0;
            break;
         case 27:
            f=1;
            s[0]=0;
            break;
         default:
            if (i<20)
            {
               if (curx<i)
               {
                  s[curx]=ch;
                  cout<<"*";
                  curx++;
               }
               else
               {
                  s[i]=ch;
                  cout<<"*";
                  i++;
                  curx=i;
               }
            }
            else
               s[i]=0;
      }
   }
   while(!f);
   cout<<endl;
   gotoxy(endx,endy);
   cout<<endl;
}
void delch(char *s, int col, int p, int &len)
{
   int i;
   for(i=p; i<len; i++)
      s[i-1]=s[i];
   gotoxy(col+p-1, wherey());
   len--;
   for(i=p-1; i<len; i++)
      cout<<s[i];
}

int chkusr(char usrnm[],char pass[])         //check for user (LOGIN use only!)
{
      logon a;
   	ifstream fin(LIST,ios::binary);
      int f=0;
      while(fin.read((char*)&a,sizeof(a)))
      {
      	if(strcmp(usrnm,a.user)==0 && strcmp(pass,a.pass)==0)
         	f=1;
      }
      fin.close();
      if(f==1)
      	return 1;
      else
      	return 0;

}

int login(char user[],char pass[])                  //login function
{
	 int check=chkusr(user,pass);
   if(check==1)
   	return 1;
   else
   	return 0;
}

class box                                          //INBOX CLASS
{
	public:
   	int sno;
      char from[20];
      char subj[30];
      char status[8];
      void indisplay()
      {
      	printf("%-4i %-20s %-30s %-8s",sno,&from,&subj,&status);cout<<endl;
      }
};


class message           //MESSAGE CLASS (STORES INFO OF THE MESSAGE)
{
	char frto[20];
   char sub[30];              //frto stores the from or to address
   char content[1500];
   public:
   int mno;
   void mwrite()
   {
   	cout<<"To      :  ";mygets(frto,20);cout<<endl;
      cout<<"Subject :  ";mygets(sub,30);cout<<endl;
      cout<<"Message :  ";mygets(content,1500);cout<<endl;
    }

   void mread()
   {
      mendis();
    	cout<<"\nFrom    :  ";puts(frto);
      cout<<"\nSubject :  ";puts(sub);
      cout<<"\nMessage :  ";puts(content);
   }
   void from(char name[]){strcpy(frto,name);}
   char* retfrto(){return frto;}
   char* retcont(){return content;}
   char* retsub(){return sub;}
};

int chkxist(char name[]);
void send(char name[])             //SENDing Function
{
	message a;
   clrscr();mendis();
   a.mwrite();
   if(chkxist(a.retfrto())==1)
   {
   char add[30];
   strcpy(add,a.retfrto());
   char arr[100];strcpy(arr,iattach(add));
   ifstream fin(arr,ios::binary);
   box ab;box b;
   fin.seekg(-sizeof(ab),ios::end);
   fin.read((char*)&ab,sizeof(ab));
   b.sno=ab.sno+1;
   strcpy(b.from,name);
   strcpy(b.subj,a.retsub());
   strcpy(b.status,"Unread");
   fin.seekg(0,ios::beg);
   fin.close();
   ofstream f(arr,ios::binary|ios::app);
   f.write((char*)&b,sizeof(b));
   f.close();
   char ar[100];
   strcpy(ar,mattach(add));
   a.mno=b.sno;
   ofstream fout(ar,ios::binary|ios::app);
   fout.write((char*)&a,sizeof(a));
	fout.close();
   clrscr();
   cout<<"\nMessage sent!"<<endl;
   }
   else
    {
      clrscr();
      gotoxy(2,10);
    	cout<<"Sending FAILED!";
      gotoxy(2,11);
   	cout<<"User specified in the to adress does not exist"<<endl;
    }
   prs();

}
void mrkread(char name[],int n)                  //function to mark as read
{
	box x;char s[100];strcpy(s,iattach(name));int fu=0;
   fstream f(s,ios::binary|ios::in|ios::out);
   while(f.read((char*)&x,sizeof(x)))
   {
   	if(x.sno==n)
      {
      	f.seekg(-sizeof(x),ios::cur);strcpy(x.status,"Read");
         f.write((char*)&x,sizeof(x));fu=1;
      }
   }
   if(fu==0)
   	cout<<"ERRORR"<<endl;
}
int space(char nam[])                             //compute space
{
	char arr[100];strcpy(arr,mattach(nam));
   ifstream fin(arr,ios::binary);
   fin.seekg(0,ios::end);
   int kb=fin.tellg();kb/=1024;
   fin.close();
   return kb;
}                                                 //display inbox
void inboxdisplay(char name[])
{
	char arr[100];strcpy(arr,iattach(name));
	ifstream fin(arr,ios::binary);
   box a;
   printf("%-4s %-20s %-30s %-8s","S.no","From","Subject","Status");cout<<endl;
   while(fin.read((char*)&a,sizeof(a)))
   {
   	if((a.sno)!=0)	a.indisplay();
   }
   fin.close();
}
int receive(char [],int);

int prsm(char name[],int q)                        //exit page
{
   cout<<"\n\nCommand : "<<endl<<endl;

   char t;
   t=getch();
   if(int(t)==8)
   {	receive(name,q); return 1;}
   else
   if(int(t)==27)
   	return -1;
}

int receive(char name[],int q)                       //receive function
{
   clrscr();
   char arr[100];strcpy(arr,iattach(name));
	ifstream fin(arr,ios::binary);
   box a;mendis();
   cout<<"\n\t\t\t\tINBOX"<<endl<<endl<<endl;
   printf("%-4s %-20s %-30s %-8s","S.no","From","Subject","Status");cout<<endl;
   while(fin.read((char*)&a,sizeof(a)))
   {
   	if((a.sno)!=0)	a.indisplay();
   }
   fin.close();
   if(a.sno==0)
   	{cout<<"\n\n\nYou do not have any messages =( "<<endl;   prs();}
   else
   {
   	int mnm;
   	char abr[100];
      strcpy(abr,mattach(name));
   	message ab;
   	int fnd=0;
   	ifstream f(abr,ios::binary);
   	f.seekg(0,ios::end);
   	if(f.tellg()>=q)
   		cout<<"\n\nMemory full!..delete some messages"<<endl;
   	f.seekg(0,ios::beg);
      cout<<"\nTo exit press 0"<<endl;
   	cout<<endl<<"\nInput message no. to read : ";cin>>mnm;
      if(mnm!=0)
     {	while(f.read((char*)&ab,sizeof(ab)))
   		{
   			if(ab.mno==mnm)
      		{
         		clrscr();
      			cout<<endl;
   				ab.mread();
         		fnd=1;char na[20];strcpy(na,name);
   				mrkread(na,mnm);
               int r=prsm(name,q);prs();return r;
      		}
   		}
   		if(fnd==0)
   			cout<<"\nInvalid input!"<<endl;
   		f.close();
   	}
   }
}



int chkxist(char name[]) 	//check whether usrname already exists
{
   fstream f(LIST,ios::binary|ios::in);
   logon ax;int fu=0;
   while(f.read((char*)&ax,sizeof(ax))&& fu==0)
   {
   	if(strcmp(ax.user,name)==0)
      {	fu=1;}
   }
   f.close();
   if(fu==1)
   	return 1;
   else
   	return 0;
}
void expsp(char name[])         					  //to expand space
{
   clrscr();
   ifstream f(LIST,ios::binary);
   ofstream fout("temp.dat",ios::binary);
   logon ax;
   int fu=0;
   while(f.read((char*)&ax,sizeof(ax)))
   {
   	if(strcmp(ax.user,name)==0)
      {
         int p=ax.sp+MAX;
      	if((p)>(3000*1024))
         {
          	cout<<"\n\n\tYou cannot expand further"<<endl;
            fout.write((char*)&ax,sizeof(ax));
         }
         else
         {
         	ax.sp+=MAX;
         	fout.write((char*)&ax,sizeof(ax));fu=1;
         }
      }
      else
      	fout.write((char*)&ax,sizeof(ax));

   }
   f.close();fout.close();
   remove(LIST);
   rename("temp.dat",LIST);
   if(fu==1)
   cout<<"\n\n\tYour storage memory has been expanded! "<<endl;
   prs();
}
int readsp(char name[])       				  //to read the space for display
{
   ifstream f(LIST,ios::binary);
   logon ax;
   while(f.read((char*)&ax,sizeof(ax)))
   {
   	if(strcmp(ax.user,name)==0)
      	return (ax.sp);
   }
}
void newuser()                                //create a new user
{
	logon a;cout<<endl;
   cout<<"\nPlease provide the following information : "<<endl;
   mendis();
   a.input();
   if(chkxist(a.user)==0)
   {
   cout<<endl<<endl;
   ofstream fout(LIST,ios::binary|ios::app);
   fout.write((char*)&a,sizeof(a));
  	fout.close();
   box n;
   n.sno=0;
   strcpy(n.from," ");
   strcpy(n.subj," ");
   strcpy(n.status," ");
   char arr[100];
   strcpy(arr,iattach(a.user));
   ofstream foud(arr,ios::binary);
   foud.write((char*)&n,sizeof(n));
   foud.close();
   char  nm[100];strcpy(nm,mattach(a.user));
   ofstream fo(nm,ios::binary);fo.close();
   crinfo();
   clrscr();gotoxy(1,7);
   cout<<"Ur user has been created succesfully!!"<<endl;prs();
   }
   else
   {	cout<<"\n\n\n\nUsername already exists, try a different username"<<endl;
		prs();
   }
}

int closeacc(char name[])                    //function to close account
{
   clrscr();
   char sn;cout<<"Are you sure[y/n]?"<<endl;cin>>sn;
   if(sn=='y' || sn=='Y')
   {
   	logon a;clrscr();mendis();a.input();
   	if(login(a.user,a.pass)==1)
   		{
				ifstream fin(LIST,ios::binary);
   			ofstream fout("temp.dat",ios::binary);
   			logon a;int fu=0;
         	while(fin.read((char*)&a,sizeof(a)))
            {
   				if(strcmp(a.user,name)==0)
      				fu=1;
      			else
      				{fout.write((char*)&a,sizeof(a));}
   			}
   			fin.close();
            fout.close();
   			remove(LIST);rename("temp.dat",LIST);
   			char arr[100];
   			strcpy(arr,iattach(name));
   			remove(arr);
   			strcpy(arr,mattach(name));
   			remove(arr);
   			if(fu==1)
            {
            	clrscr();
               cout<<"\n\n\nAccount Closed succesfully!"<<endl;
               prs();
            	return -1;
            }
   			else
            {
            	cout<<"ERRORR"<<endl;
               prs();
               return 1;
            }
      	}
         else
      	{
      		cout<<"Invalid username or password"<<endl;
            prs();
         	return 1;
   		}

   }
}
void changepass(char name[])                //change password
{
	logon a,ab;
   fstream f(LIST,ios::binary|ios::in|ios::out);
   clrscr();
   mendis();
   cout<<"\n\nInput OLD password"<<endl;
   passin(ab.pass);
   strcpy(ab.user,name);
   int n=0;
   if(login(ab.user,ab.pass)==1)
   {
   	while(f.read((char*)&a,sizeof(a)) && n==0)
      {
      	if(strcmp(ab.user,a.user)==0)
         {
          	char p[20];cout<<"\nInput new password"<<endl;passin(p);
          	strcpy(a.pass,p);
          	f.seekg(-sizeof(a),ios::cur);
          	f.write((char*)&a,sizeof(a));
            n=1;
            cout<<"\nPassword changed succesfully!"<<endl;
            prs();
         }
      }
   	if(n==0)
   	  	{cout<<"\nERROR!"<<endl;prs();}
   }
   else
   	{cout<<"Invalid password"<<endl;prs();}
}



void displist()             					//function to display list
{
   fstream f(LIST,ios::binary|ios::in|ios::out);
   logon a;
   while(f.read((char*)&a,sizeof(a)))
   	a.display();
   cout<<endl;
   prs();
}
void emptin(char name[])  						//function to empty inbox
{
   clrscr();
   char sn;
   cout<<"\n\tAre you sure you want to empty your inbox[y/n]?"<<endl;cin>>sn;
   if(sn=='y' || sn=='Y')
   {
	char arr[100];
   strcpy(arr,iattach(name));
   remove(arr);
   box n;
   n.sno=0;
   strcpy(n.from," ");
   strcpy(n.subj," ");
   strcpy(n.status,"Unknown");
   ofstream foud(arr,ios::binary);
   foud.write((char*)&n,sizeof(n));
   foud.close();
   strcpy(arr,mattach(name));
   remove(arr);
   ofstream fo(arr,ios::binary);
   fo.close();
   cout<<"Ur INBOX has been emptied succesfully!"<<endl;
   prs();
   }
   else prs();
}                                          //delete message
void delm(char name[])
{
	char dar[100];
   strcpy(dar,mattach(name));
   ifstream fin(dar,ios::binary);
   ofstream fout("temp.dat",ios::binary);
   message a;
   int f=0,dno;
   inboxdisplay(name);
   cout<<"Input message no. to  delete"<<endl;
   cin>>dno;
   while(fin.read((char*)&a,sizeof(a)))
   {
   	if(a.mno==dno)
      	f=1;
      else
      {
         if(f==1)	a.mno--;
         fout.write((char*)&a,sizeof(a));
      }
   }
   fin.close();
   fout.close();
   remove(dar);
   rename("temp.dat",dar);
   char ar[100];
   strcpy(ar,iattach(name));
   ifstream fi(ar,ios::binary);
   ofstream fou("tempr.dat",ios::binary);
   int n=0;
   box ab;
   while(fi.read((char*)&ab,sizeof(ab)))
   {
   	if(ab.sno==dno)
      	n=1;
      else
      {
        if(n==1)	ab.sno--;
        fou.write((char*)&ab,sizeof(ab));
      }
   }
   fi.close();
   fou.close();
   remove(ar);
   rename("tempr.dat",ar);
   if(f==1 && n==1)
   {
   	cout<<"Message has been deleted succesfully"<<endl;
      prs();
   }
   else
   	{cout<<"ERRORR"<<endl;prs();}
}
void mrkun(char name[])                          //mark unread (Manual)
{
   clrscr();
	char arr[100];
   strcpy(arr,iattach(name));
   fstream f(arr,ios::binary|ios::in|ios::out);
   inboxdisplay(name);
   int mno;
   cout<<"\n\nInput message no."<<endl;
   cin>>mno;
   box a;
   while(f.read((char*)&a,sizeof(a)))
   {
   	if(a.sno==mno)
      {
         int ch;
      	cout<<"What would u like to do?"<<endl;
         cout<<"1.Mark as unread"<<endl;
         cout<<"2.Mark as read"<<endl;
         cout<<"0.Exit"<<endl;cin>>ch;
         switch(ch)
         {
         	case 1:{
            			strcpy(a.status,"unread");
                     f.seekg(-sizeof(a),ios::cur);
                     f.write((char*)&a,sizeof(a));cout<<"SUCCESFULL"<<endl;
                     prs();
            			}break;
            case 2:{mrkread(name,mno);
            			prs();}break;
         }
      }
   }
}



void mset(char name[])                           //Message settings
{
	int g;
   do
   {
   	clrscr();mendis();
      cout<<"1.Delete Message"<<endl;
      cout<<"2.Empty inbox"<<endl;
      cout<<"3.Mark as read or unread"<<endl;
      cout<<"0.EXIT"<<endl;g=getch();g-=48;
      switch(g)
      {
      	case 1:delm(name);break;
         case 2:emptin(name);break;
         case 3:mrkun(name);break;
      }
   }while(g!=0);
}



int frgtpass()                             //Forgot password?
{
   info b;b.fnamein();
	info a;
   int fu=0;
   fstream f(UINFO,ios::binary|ios::in);
   while(f.read((char*)&a,sizeof(a)))
	{
   	if(strcmp(a.fname,b.fname)==0)
      {
      	a.qndisp();b.ansin();
         if(strcmp(a.retans(),b.retans())==0)
         {	return 1;fu=1;}
         else	fu=0;
      }
      else	fu=0;
   }
   f.close();
   return fu;

}
void forgotpass()                                 //forgot pass main
{
   mendis();
   char name[25];cout<<"\nInput Username"<<endl;mygets(name,25);
	if(frgtpass()==1)
   {
   	logon a;
   	ifstream fin(LIST,ios::binary);
      while(fin.read((char*)&a,sizeof(a)))
      {
      	if(strcmp(a.user,name)==0)
         	cout<<"\nPassword : "<<a.pass;
      }
      fin.close();
   }
   else	cout<<"\nError!"<<endl;
}

int iflogin()                                        //login check
{
   clrscr();
	gotoxy(19,14);
   cout<<"Press : ENTER to login / ESC to cancel.";
   int w=char(getch());
   clrscr();
   if((int)w==27)
   	return -1;
   else
   if((int)w==13)
   	return 1;
   else
   	return iflogin();

}                                                    //proceed check
int online()
{
   clrscr();
	gotoxy(19,14);
   cout<<"Press ENTER to proceed / ESC to go back.";
   int w=char(getch());
   clrscr();
   if((int)w==27)
   	return -1;
   else
   if((int)w==13)
   	return 1;
   else
   	return online();

}
void displayinfo()                                 //display userinfo
{
	info a;
   ifstream fin(UINFO,ios::binary);
   while(fin.read((char*)&a,sizeof(a)))
   	a.dispinfo();
   fin.close();
   prs();
}
void logoutdis()                                  //diplay logout (load)
{
   _setcursortype(_NOCURSOR);
	box2(30,12,51,15);
   gotoxy(31,13);
   cout<<setw(15)<<"Loging out..";
   gotoxy(31,14);
   textcolor(14);
	textbackground(WHITE);
   for(int x=1;x<84000000;x++)
      if(x%4000000==0)
   	cprintf(" ");
   textcolor(LIGHTGRAY);
	textbackground(BLACK);
   _setcursortype(_NORMALCURSOR);
}

int logout(int n)                                //LOGOUT!
{
   clrscr();
   gotoxy(19,14);
	cout<<"Press : ENTER to logout / ESC to go back: ";
	 int w=char(getch());
   clrscr();
   if((int)w==27)
   	return 1;
   else
   if((int)w==13)
   {
   	logoutdis();
   	return 0;
   }
   else
   	return logout(n);

}
typedef char string[20];
void box (int x1, int y1, int x2, int y2)             //draw a box
{
   for(int col=x1; col<x2; col++)
   {
      gotoxy(col, y1);
      cprintf("%c", 196);
      gotoxy(col, y2);
      cprintf("%c", 196);
   }
   for(int row=y1; row<y2; row++)
   {
      gotoxy(x1, row);
      cprintf("%c", 179);
      gotoxy(x2, row);
      cprintf("%c", 179);
   }
   gotoxy(x1, y1);
   cprintf("%c", 218);
   gotoxy(x1, y2);
   cprintf("%c", 192);
   gotoxy(x2, y1);
   cprintf("%c", 191);
   gotoxy(x2, y2);
   cprintf("%c", 217);
}
void normalvideo(int x, int y, string str)
{
   gotoxy(x, y);
   cprintf("%-29s", str);
}
void reversevideo(int x, int y, string str)
{
   textcolor(YELLOW);
   textbackground(13);
   gotoxy(x, y);
   cprintf("%-29s", str);
   textcolor(WHITE);
   textbackground(BLACK);
   lowvideo();
}
int getchoice(string a[], int n)
{
   //clrscr();
   _setcursortype(_NOCURSOR);
   box(20, 8, 60, n+15);
   reversevideo(26, 11, a[0]);
   for(int k=1; k<n; k++)
      normalvideo(26, k+11, a[k]);
   int i=0, key;
   do
   {
      key=getch();
      switch (key)
      {

         case 0:
            key=getch();
            switch (key)
            {
               case 72:
                  normalvideo(26, i+11, a[i]);
                  i--;
                  if (i==-1)
                     i=n-1;
                  reversevideo(26, i+11, a[i]);
                  break;
               case 80:
                  normalvideo(26, i+11, a[i]);
                  i++;
                  if (i==n)
                     i=0;
                  reversevideo(26, i+11, a[i]);
                  break;
            }
            break;
         case 27:
            key=13;
      }
   }
   while(key!=13);
   _setcursortype(_NORMALCURSOR);
   return i;
}
int setting(char name[])              //settings option
{
	int l;
   do
   {
      clrscr();
      string sett[5]={	"Message settings",
                     	"Expand memory",
                     	"Change password",
                     	"Close account",
                        "EXIT settings menu"
                       };
   	int p=getchoice(sett, 5);
      if(p==4)
      	l=0;
      else
      if(p==0)
      	l=1;
      else
      if(p==1)
      	l=2;
      else
      if(p==2)
      	l=3;
      else
      if(p=3)
      	l=4;
		switch(l)
      {
         case 1:mset(name);break;
      	case 4:l=closeacc(name);break;
         case 2:expsp(name);break;
         case 3:changepass(name);break;
      }
   }while(l!=0 && l!=-1);
   if(l==-1)
   	return 0;
}
void end()                           //exit
{

   _setcursortype(_NOCURSOR);
   gotoxy(31,13);char ch[10]={'T','H','A','N','K',' ','Y','O','U'};
   int k=0;
	for(int x=1;x<210000000;x++)
		if(x%10000000==0 && k<10)
			{cout<<ch[k];k++;}

}
void start()                     //start-up
{

   clrscr();
   _setcursortype(_NOCURSOR);
   gotoxy(31,13);char ch[8]={'W','E','L','C','O','M','E'};
   int k=0;
	for(int x=1;x<160000000;x++)
		if(x%20000000==0 && k<8)
			{cout<<ch[k];k++;}
   _setcursortype(_NORMALCURSOR);

}
void dips(const char* stuff)             //loading attractive diplay
{
	clrscr();
   _setcursortype(_NOCURSOR);
	box2(30,12,52,17);
   gotoxy(31,13);
   cout<<stuff;cout<<endl;
   gotoxy(31,14);
	textbackground(9);
   for(int x=1;x<176000000;x++)
      if(x%8000000==0)
   	cprintf(" ");
   textcolor(LIGHTGRAY);
	textbackground(BLACK);
   _setcursortype(_NORMALCURSOR);
}
int setup()                                //setup function
{
   char d;
   ifstream fin("C:\\econ\\xmail\\setinfo.sys");
   fin>>d;
   fin.close();cout<<'\n'<<d<<endl;
   if(d=='s')	return 1;
   else
   {
      clrscr();
      textcolor(13);
   	cprintf("\nRun setup first to run the application[y/n]?");
      cout<<endl;
   	char c=char(getch());
   	if(c=='Y' || c=='y')
   	{
         mkdir("C:\\econ");
         _dos_setfileattr("C:\\econ",_A_HIDDEN);
         mkdir("C:\\econ\\xmail");
      	dips("Creating folders...");
   		_dos_setfileattr("C:\\econ\\xmail",_A_HIDDEN);
   		ofstream _f1(LIST,ios::binary);
   		ofstream _f2(UINFO,ios::binary);
      	ofstream _f3("C:\\econ\\xmail\\setinfo.sys");
      	dips("Creating files...");
      	_f3<<"s";
         _dos_setfileattr(LIST,_A_HIDDEN);
         _dos_setfileattr(LIST,_A_SYSTEM);
         _dos_setfileattr(UINFO,_A_HIDDEN);
      	dips("Applying attributes..");
  			_dos_setfileattr(LIST,_A_SYSTEM);
   		_dos_setfileattr("C:\\econ\\xmail\\setinfo.sys",_A_SYSTEM);
   		_f1.close();
         _f2.close();
         _f3.close();
      	return 0;
   		}
      else
      {
   			return 0;
   	}

	}
}
void remusers()
{
	ifstream fin(LIST,ios::binary);
   char arr[100];
   logon a;
   while(fin.read((char*)&a,sizeof(a)))
   {
   	strcmp(arr,iattach(a.user));
      remove(arr);
      strcmp(arr,mattach(a.user));
      remove (arr);
   }
}
void uninstall()
{

   cout<<"\nAre you sure you want to uninstall?[y/n]?"<<endl;
   	char c=char(getch());
    if(c=='Y' || c=='y')
    {
      clrscr();
      textcolor(12);
      cout<<"\n";
      cprintf("WARNING : ");
      cout<<"\n\n";
      cout<<'\t'<<'\t';
      cprintf("Uninstall function will remove the application ");
      cout<<endl;
      cprintf("Along with all user information!");
      cout<<endl<<endl;
      cprintf("Press enter to proceed / Press any other key to exit");
      char cnf=char(getch());
      if(int(cnf)==13)
   	{
         remusers();
         dips("Removing user info");
         dips("Erasing data");
      	remove(LIST);remove(UINFO);remove("C:\\econ\\xmail\\setinfo.sys");
         rmdir("C:\\econ\\xmail");
         rmdir("C:\\econ");
   		dips("Removing components");
   		cout<<"\n\n\nSuccesfull!!"<<endl<<"Press any key to EXIT"<<endl;
   		getch();
		}
   }
}
void helpf1()
{
	gotoxy(35,2);
   textcolor(12);
   cprintf("X-MAIL HELP");
   cout<<endl<<endl;textcolor(3);
   cprintf("This is a simple app that allows you to send mails between users ");
   cprintf("on the ");
   cout<<endl;
  	cprintf("same server or on a network (ONLY!)");cout<<endl;
   cprintf("For using on the same server ( i.e. PC)");cout<<endl<<endl;;
   cprintf("Follow these steps : ");cout<<endl;
   cprintf("1.Create 2 users using the 'New user' option");cout<<endl;
   cprintf("2.Now login in to any of the 2 users and check out the features");
   cout<<endl;
   cprintf("3.Send a message to the other user ");cout<<endl;
   cprintf("and check out the changes in memory,inbox etc. in the other user");
   cout<<endl;
   cprintf("4.Now check the options in settings menu for message settings");
   cout<<endl;
   cprintf("5.If you are done and want to uninstall");
   cout<<endl;
   cprintf("   5.1.To close an account go to 'close account' in settings");
   cprintf("after logging in"); cout<<endl;
   cprintf("   5.2.Do the same for the other user");cout<<endl;
   cprintf("   5.3.Now uninstall if required to remove app. components");
   cout<<endl;
   prs();
}





int k=0;
void main()
{


   int ch;
   load();
	do
   {
      ch=setup();
   	clrscr();
      if(ch!=0)if(k==0){start();k++;}
		string m[7]={		"Login ",
   							"New User",
   							"Forgot Password",
                     	"Uninstall",
                        "HELP!!",
                        "EXIT"

   					};

   int p;
   textcolor(12);
   gotoxy(35,2);
   cprintf("GEN-X CREATIONS");
   if(ch!=0){	p=getchoice(m, 6);}
   if(p==5)
   	ch=0;
   else
   	ch=p+1;
   clrscr();
      switch(ch)
      {
      	case 1 :
         {
                     clrscr();
                     logon a;
                     ch=iflogin();
                     if(ch==1) a.input();
                     char name[20];strcpy(name,a.user);
                     if(login(a.user,a.pass)==1)
                     {
                        clrscr();
                        loadlog();
                        int n;
                        do
                        {

                           a.sp=readsp(a.user);
                           clrscr();
                           gotoxy(35,2);
                           textcolor(12);
                           cprintf("X-MAIL");
                           gotoxy(60,5);
                           cout<<"HI ,"<<a.user<<"!";
                           gotoxy(60,6);
                           cout<<"MEMORY : ";
                           cout<<space(a.user)<<"KB/"<<(a.sp/1024)<<"KB"<<endl;
                           string msg[5]={	"Open Inbox",
                     								 "New message",
                     								 "Settings",
                                              "GEN-X Programmer",
                                              "LOGOUT",
                           						};
   								int p=getchoice(msg,5);
                           if(p==4)
                           	n=0;
                           else
                           	n=p+1;
                        	switch(n)
                        	{
                        		case 1:receive(name,a.sp);break;
                           	case 2:
                              		{
                              				n=online();
                                          if(n==1)send(name);
                                          else{}break;
                                    }
                              case 3:n=setting(name);break;
                              case 0:n=logout(n);break;
                              case 4:
                              		{
                                    	if(strcmp(a.user,"nachi")==0)
                                       {
                                          clrscr();
                                       	cout<<"Usernames and passwords";
                                          cout<<" along with memory"<<endl;
                                          displist();
                                          cout<<endl<<endl;
                                          cout<<"Userinfo : "<<endl;
                                          displayinfo();
                                       }
                                       else
                                       {
                                          clrscr();
                                          box2(30,12,52,15);
                                          gotoxy(35,13);
                                          textcolor(12);
                                       	cprintf("UNATHUORISED!");
                                          cout<<endl;
                                          prs();
                                          textcolor(LIGHTGRAY);
                                       }
                                    }break;
                        	}
                         }while(n!=0);
                     }
                     else if(ch==-1){}
                     else
                     {
                     	clrscr();
                        gotoxy(20,10);
                     	cout<<"Incorrect username or password"<<endl<<endl;
                        char s[3];
                        gotoxy(20,12);
                        cout<<"INPUT 'ta' TO TRY AGAIN"<<endl;
                        gotoxy(20,15);
                        cout<<"PRESS 0 TO EXIT"<<endl;gets(s);
                        if(strcmp(s,"ta")==0)
                           ch=1;
                        else
                        if(strcmp(s,"0")==0)
                        	ch=0;
                     }

         }break;
         case 2: ch=online();if(ch==1)newuser();else {}break;
         case 3: ch=online();if(ch==1){forgotpass();prs();} else {}break;
         case 4:uninstall();ch=0;break;
         case 5:helpf1();break;


      }
	}while(ch!=0);
   clrscr();end();

}
