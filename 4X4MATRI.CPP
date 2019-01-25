// NIKHIL B THAKARE
// MINI +logic code new + 4x4 matrix

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int gd=DETECT,gm;
int A1,A2,A3,A4,S=0;
const int size=4;
const int sim=3;

int checkinputvalid(int ,int );
void getaddress(int,int *,int *);//return address of specific index(as pointer)
void display(int N[size][size],int ,int ,int ,int ,int ,int );
int check(int N[size][size],int );
int beginME(void );
void TheEnd(int );
//update
void copyMatrix(int N[size][size],int Z[size][size]);
void dispMatrix(int Z[size][size]);
//int freezecondi(int N[size][size],int Z[size][size]);
//int checkRfreeze(int Z[size][size]);
//int checkCfreeze(int Z[size][size]);
void swapR(int Z[size][size],int ,int ,int ,int );
void swapC(int Z[size][size],int ,int ,int ,int );
void inst();
void invalid();
//void changeset();

void main()
{
 int temp,ind1=0,ind2=0,i,j,chance=5,valid,N[size][size],result,Z[size][size],ch,rdn,S1,S2;
 ch=beginME();
 switch(ch)
{
 case 1:
 inst();
 srand(time(NULL));
 {for(i=0;i<size;i++)
 {
   for(j=0;j<size;j++)
    {
     rdn=1+rand()%5;
     N[i][j]=rdn;
    }
 }
 copyMatrix(N,Z);
 result=0;//freezecondi(N,Z);
 S=check(N,S);
 S=0;
 for(chance;chance>0;chance--)
 {
  copyMatrix(N,Z);
  result=0;//freezecondi(N,Z);
  display(N,S,chance,0,0,result,1);
  S=check(N,S);//here should be auto check
RETRY:
 copyMatrix(N,Z);
 result=0;//freezecondi(N,Z);
 display(N,S,chance,ind1,ind2,result,0);
 scanf("%d %d",&ind1,&ind2);
 valid=checkinputvalid(ind1,ind2);
 if(valid==1)
{ getaddress(ind1,&A1,&A2);
  getaddress(ind2,&A3,&A4);

// swapping of element
 {
  temp=N[A1][A2];
  N[A1][A2]=N[A3][A4];
  N[A3][A4]=temp;
 }
 display(N,S,chance,ind1,ind2,result,1);
 S1=S;
  S=check(N,S);
  display(N,S,chance,ind1,ind2,result,1);
  S=check(N,S);

 if(S1==S)
  {
  temp=N[A1][A2];
  N[A1][A2]=N[A3][A4];
  N[A3][A4]=temp;
 }

 display(N,S,chance,ind1,ind2,result,1);
 }
 else
 {invalid();
  goto RETRY;
 }

 }
 break;
}

case 2:
{break;}
};

 closegraph();
 TheEnd(S);
 getch();
}

/*---------------------------------------*/
void getaddress(int IND,int *m,int *n) /*IND=index value*/
{
 //for row
 if(IND==1||IND==2||IND==3||IND==4)
 {*m=0;}
 if(IND==5||IND==6||IND==7||IND==8)
 {*m=1;}
 if(IND==9||IND==10||IND==11||IND==12)
 {*m=2;}
 if(IND==13||IND==14||IND==15||IND==16)
 {*m=3;}

 //for column
 if(IND==1||IND==5||IND==9||IND==13)
 {*n=0;}
 if(IND==2||IND==6||IND==10||IND==14)
 {*n=1;}
 if(IND==3||IND==7||IND==11||IND==15)
 {*n=2;}
 if(IND==4||IND==8||IND==12||IND==16)
 {*n=3;}

}

/*---------------------------------------*/
void display(int N[size][size],int S,int CL,int i1,int i2,int PM,int CG)//PM=possible moves,CL=chance left
{
   int i,j,C[16],c=0;
   char ch,arr1[5],arr2[5],arr3[5],inde1[2],inde2[2];

  for(i=0;i<size;i++)
 {
   for(j=0;j<size;j++)
    {if(N[i][j]==1)
     {C[c]=9;}
     else
     if(N[i][j]==2)
     {C[c]=10;}
     else
     if(N[i][j]==3)
     {C[c]=12;}
     else
     if(N[i][j]==4)
     {C[c]=14;}
     else
     if(N[i][j]==5)
     {C[c]=11;}
     c++;
    }

 }
 //small black squares
 //int sq1[10]={500,175,500,145,580,145,580,175,500,175};
 //int sq2[10]={550,225,550,195,580,195,580,225,580,225};
// int sq3[10]={300,425,300,395,330,395,330,425,300,425};
 //int sq4[10]={350,425,350,395,380,395,380,425,350,425};
 //int sq5[10]={550,275,550,245,580,245,580,275,580,275};
// int tdia1[12]={550,125,530,90,536,78,564,78,570,90,550,125};

//NEW 4x4 matrix
 char arr[50];
// int S,i1,i2;
 int gd=DETECT,gm,DP=6;//DP=daimond pattern
 int rect1[10]={20,380,20,20,380,20,380,380,20,380};
 int rect2[10]={10,460,10,10,590,10,590,460,10,460};
 int rect3[10]={10,460,10,10,400,10,400,460,10,460};
 int sq1[10]={550,175,550,145,580,145,580,175,550,175};
 int sq2[10]={550,225,550,195,580,195,580,225,580,225};
 int x=200,y=325,sq3[10]={100+x,100+y,100+x,70+y,130+x,70+y,130+x,100+y,100+x,100+y};//,sq2={},sq3={};
 int x1=250,y1=325,sq4[10]={100+x1,100+y1,100+x1,70+y1,130+x1,70+y1,130+x1,100+y1,100+x1,100+y1};//,sq2={},sq3={};
 i=450;j=10;
 int tdia1[12]={100+i,115+j,80+i,80+j,86+i,68+j,114+i,68+j,120+i,80+j,100+i,115+j};

 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 rectangle(1,1,638,478);

 setfillstyle(9,8);
 fillpoly(5,rect2); /* Boader */
 setfillstyle(9,7);
 fillpoly(5,rect3);
 setfillstyle(1,0);
 fillpoly(5,rect1); /* Square(Main Game) */

 //line
 line(20,110,380,110);
 line(20,200,380,200);
 line(20,290,380,290);
 line(110,20,110,380);
 line(200,20,200,380);
 line(290,20,290,380);

 line(400,10,400,460);
 int d2ia1[12]={65,95,37,50,52,35,78,35,93,50,65,95};
 int d2ia2[12],d2ia3[12],d2ia4[12],d2ia5[12],d2ia6[12],d2ia7[12],d2ia8[12],d2ia9[12],d2ia10[12],d2ia11[12],d2ia12[12],d2ia13[12],d2ia14[12],d2ia15[12],d2ia16[12];

 for(i=0;i<12;i++)
 {  if(i%2==0)
  {d2ia2[i]=d2ia1[i]+90;
   d2ia3[i]=d2ia1[i]+90*2;
   d2ia4[i]=d2ia1[i]+90*3;
   d2ia5[i]=d2ia9[i]=d2ia13[i]=d2ia1[i];
   d2ia6[i]=d2ia10[i]=d2ia14[i]=d2ia2[i];
   d2ia7[i]=d2ia11[i]=d2ia15[i]=d2ia3[i];
   d2ia8[i]=d2ia12[i]=d2ia16[i]=d2ia4[i];
   }

  else
   {d2ia2[i]=d2ia3[i]=d2ia4[i]=d2ia1[i];
    d2ia5[i]=d2ia6[i]=d2ia7[i]=d2ia8[i]=d2ia1[i]+90;
    d2ia9[i]=d2ia10[i]=d2ia11[i]=d2ia12[i]=d2ia1[i]+90*2;
    d2ia13[i]=d2ia14[i]=d2ia15[i]=d2ia16[i]=d2ia1[i]+90*3;
   }

  }
 setfillstyle(DP,C[0]);
 fillpoly(6,d2ia1);
 setfillstyle(DP,C[1]);
 fillpoly(6,d2ia2);
 setfillstyle(DP,C[2]);
 fillpoly(6,d2ia3);
 setfillstyle(DP,C[3]);
 fillpoly(6,d2ia4);
 setfillstyle(DP,C[4]);
 fillpoly(6,d2ia5);
 setfillstyle(DP,C[5]);
 fillpoly(6,d2ia6);
 setfillstyle(DP,C[6]);
 fillpoly(6,d2ia7);
 setfillstyle(DP,C[7]);
 fillpoly(6,d2ia8);
 setfillstyle(DP,C[8]);
 fillpoly(6,d2ia9);
 setfillstyle(DP,C[9]);
 fillpoly(6,d2ia10);
 setfillstyle(DP,C[10]);
 fillpoly(6,d2ia11);
 setfillstyle(DP,C[11]);
 fillpoly(6,d2ia12);
 setfillstyle(DP,C[12]);
 fillpoly(6,d2ia13);
 setfillstyle(DP,C[13]);
 fillpoly(6,d2ia14);
 setfillstyle(DP,C[14]);
 fillpoly(6,d2ia15);
 setfillstyle(DP,C[15]);
 fillpoly(6,d2ia16);


 //BEJEWELED GAME TITLE
 setcolor(10);
 settextstyle(9,0,1);
 outtextxy(410,30,"BEJEWELED");
 outtextxy(411,30,"BEJEWELED");
 outtextxy(412,30,"BEJEWELED");
 setcolor(10);
 setfillstyle(1,10);
 fillpoly(6,tdia1);
 setcolor(10);
 outtextxy(430,70,"GAME");
 outtextxy(431,70,"GAME");
 outtextxy(432,70,"GAME");

 setcolor(14);
 line(410,70,570,70);
 line(450,110,520,110);
 setcolor(15);
 settextstyle(2,0,7);
 outtextxy(410,150,"SCORED :");
 outtextxy(411,150,"SCORED :");
 sprintf(arr1,"%d",S);//sprintf---->use to display no. store as character
 outtextxy(510,150,arr1);

 setcolor(15);
 setlinestyle(3,0,0);
 line(410,175,480,175);
 settextstyle(2,0,7);
 outtextxy(410,200,"CHANCE LEFT:");
 outtextxy(411,200,"CHANCE LEFT:");
 sprintf(arr2,"%d",CL);
 outtextxy(555,200,arr2);

 setlinestyle(3,0,0);
 line(410,225,535,225);

 settextstyle(2,0,7);
 outtextxy(410,250,"POSSIBLE ");
 outtextxy(411,250,"POSSIBLE ");
 outtextxy(470,270,"MOVES:");
 outtextxy(471,270,"MOVES:");
 sprintf(arr3,"%d",PM);
 outtextxy(555,250,arr3);

 setcolor(15);
 settextstyle(2,0,7);
 outtextxy(30,400,"Enter two Index value -");
 outtextxy(31,400,"Enter two Index value -");
 sprintf(inde1,"%d",i1);
 sprintf(inde2,"%d",i2);
 outtextxy(310,400,inde1);
 outtextxy(360,400,inde2);

 //Level up bar
 setlinestyle(0,0,0);
 setfillstyle(0,12);
 bar(20,435,580,455);//level up bar
 rectangle(21,436,579,454);
 setfillstyle(1,11);
 bar(160,440,350,450);//increase level bar
 rectangle(159,439,501,451);

 settextstyle(0,0,1);
 outtextxy(510,442,"LEVEL UP");
 outtextxy(30,442,"EXPERIENCE BAR");

 if(CG==1)
 {closegraph();}
}

/*---------------------------------------*/
int checkinputvalid(int x,int y)
{
 if((x<=16&&x>=0)&&(y<=16&&y>=0))
 {
  if(x==1)
  {if(y==2||y==5)
   return(1);
  }
  if(x==2)
  {if(y==1||y==3||y==6)
   return(1);
  }
    if(x==3)
  {if(y==2||y==4||y==7)
   return(1);
  }
    if(x==4)
  {if(y==3||y==5)
   return(1);
  }
    if(x==5)
  {if(y==1||y==6||y==9)
   return(1);
  }
  if(x==6)
  {if(y==2||y==5||y==7||y==10)
   return(1);
  }
    if(x==7)
  {if(y==3||y==6||y==8||y==11)
   return(1);
  }
    if(x==8)
  {if(y==4||y==7||y==12)
   return(1);
  }
    if(x==9)
  {if(y==5||y==10||y==13)
   return(1);
  }
   if(x==10)
  {if(y==6||y==9||y==11||y==14)
   return(1);
  }
  if(x==11)
  {if(y==7||y==10||y==12||y==15)
   return(1);
  }
   if(x==12)
  {if(y==8||y==11||y==16)
   return(1);
  }
    if(x==13)
  {if(y==9||y==14)
   return(1);
  }
    if(x==14)
  {if(y==13||y==10||y==15)
   return(1);
  }
    if(x==15)
  {if(y==11||y==14||y==16)
   return(1);
  }
    if(x==16)
  {if(y==12||y==15)
   return(1);
  }
 }

return(0);
}

/*---------------------------------------*/
int check(int N[size][size],int score)
{
 int random,x,root,i,j,c=0,r=0,countR=0,countC=0,val,prevscore;//GO=GameOver
  // For row check
do{
  prevscore=score;
  srand(time(NULL));
  for(i=0;i<size;i++)
 {
   root=N[i][c];
   countR=0;
   for(j=0;j<size;j++)
    {if(root==(N[i][j]))
     {countR++;
      if(countR==sim)
      {x=j;
       for(x=j;x>j-sim;x--)
       { Again1:
	 random=1+rand()%5;
	 if(random==root)
	 {goto Again1;}
	 N[i][x]=random;}
	 score+=10;
	countR=1;
	root=N[i][j];

	}
      }	else
      {countR=1;
       root=N[i][j];
      }
      }
     }

//printf("\n/*-----------------*/\n");
  srand(time(NULL));
  for(i=0;i<size;i++)
 {
   root=N[r][i];
   countC=0;
   for(j=0;j<size;j++)
    {if(root==(N[j][i]))
     {countC++;
      if(countC==sim)
      {
       x=j;
       for(x=j;x>j-sim;x--)
       { Again2:
	 random=1+rand()%5;
	 if(random==root)
	 {goto Again2;}
	 N[x][i]=random;}
	  score+=10;
	countC=1;
	root=N[j][i];
	}
      }	else
      {countC=1;
       root=N[j][i];
      }
      }
     }
}while(prevscore!=score);
return(score);
}

/*---------------------------------------*/
int beginME(void )
{
 int i=0,X=10,Y=0,choice;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 int Bigdiamond1[12]={120,100,220,100,270,150,170,300,70,150,120,100};
 int Sdiamond1[12]={70,170,110,170,120,180,90,230,60,180,70,170};
 int Sdiamond2[12]={190,230,230,230,240,240,210,290,180,240,190,230};

 while(i<15)
 {
  cleardevice();
  rectangle(1,1,638,478);

  setcolor(14);
  settextstyle(9,0,0);
  outtextxy(X,130,"BEJEWELED");
  outtextxy(X+1,130,"BEJEWELED");
  outtextxy(X+2,130,"BEJEWELED");

  outtextxy(Y+30,180,"GAME");
  outtextxy(Y+31,180,"GAME");
  outtextxy(Y+32,180,"GAME");

  setcolor(7);
  settextstyle(2,0,8);
  outtextxy(Y+30,240,"1> START :)");
  outtextxy(Y+30,260,"2> EXIT  :(");
  settextstyle(2,0,7);
  outtextxy(X,360,"MADE BY:");
  outtextxy(250,Y-20,"NIKHIL B. THAKARE");
  outtextxy(250,Y,"BILMAN D. SHIRA");
  delay(50);
  X=X+20;
  Y=Y+30;
  i++;
  }
  setfillstyle(6,10);
  fillpoly(6,Bigdiamond1);
  setfillstyle(6,12);
  fillpoly(6,Sdiamond1);
  setfillstyle(6,14);
  fillpoly(6,Sdiamond2);

  scanf("%d",&choice);
  closegraph();
  return(choice);

}

/*---------------------------------------*/
void TheEnd(int S)
{
 char arr[20],name[10];
 FILE *fp2;
 fp2=fopen("SCORE1.txt","r");
 if(fp2!=NULL)
 {
  fgets(name,10,fp2);
 }
 int gd=DETECT,gm,i=0,X=10,Y=0;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 while(i<15)
 {
  cleardevice();
  rectangle(1,1,638,478);

  setcolor(12);
  settextstyle(9,0,4);
  outtextxy(Y+10,150,"GAME OVER");
  outtextxy(Y+11,150,"GAME OVER");
  outtextxy(Y+12,150,"GAME OVER");

  setcolor(7);
  settextstyle(2,0,9);
  outtextxy(Y-90,240,name);
  outtextxy(Y+30,240,"SCORED:");
  sprintf(arr,"%d",S);
  outtextxy(X+30,240,arr);
  delay(50);
  X=X+25;
  Y=Y+15;
  i++;
  }
  getch();
  closegraph();
}

/*---------------------------------------*/
void copyMatrix(int N[size][size],int Z[size][size])
{
int i,j;
 for(i=0;i<size;i++)
 {
  for(j=0;j<size;j++)
  { Z[i][j]=N[i][j]; }
 }
}

/*----------------------------------*/
void swapR(int Z[size][size],int d,int e,int f,int g)
{
 int temp;
 temp=Z[d][e];
 Z[d][e]=Z[f][g];
 Z[f][g]=temp;
}
/*----------------------------------*/
void swapC(int Z[size][size],int e,int d,int g,int f)
{
 int temp;
 temp=Z[d][e];
 Z[d][e]=Z[f][g];
 Z[f][g]=temp;
}
/*----------------------------------*/
/*int freezecondi(int N[size][size],int Z[size][size])
{
 int count=0,i,j,rdn;
   swapR(Z,0,0,1,0); //1r
  if((checkRfreeze(Z))==1)
   {count++;}
   swapR(Z,0,0,1,0);

    swapR(Z,1,0,2,0); //2r
  if((checkRfreeze(Z))==1)
   {count++;}
   swapR(Z,1,0,2,0);

    swapR(Z,0,1,1,1); //3r
  if((checkRfreeze(Z))==1)
   {count++;}
  swapR(Z,0,1,1,1);

   swapR(Z,1,1,2,1);//4
  if((checkRfreeze(Z))==1)
   {count++;}
  swapR(Z,1,1,2,1);


    swapR(Z,0,2,1,2);//5
  if((checkRfreeze(Z))==1)
   {count++;}
   swapR(Z,0,2,1,2);


    swapR(Z,0,0,0,1);//6
  if((checkRfreeze(Z))==1)
   {count++;}
   swapR(Z,0,0,0,1);

  //column
   swapC(Z,0,0,1,0); //1c
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,0,0,1,0);

    swapC(Z,1,0,2,0); //2c
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,1,0,2,0);

    swapC(Z,0,1,1,1); //3c
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,0,1,1,1);

   swapC(Z,1,1,2,1);//4
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,1,1,2,1);

    swapC(Z,0,2,1,2);//5
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,0,2,1,2);

    swapC(Z,0,0,0,1);//6
  if((checkCfreeze(Z))==1)
   {count++;}
   swapC(Z,0,0,0,1);


  if(count==0)
  {
   // changeset();
    for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)
    {
     rdn=1+rand()%4;
     N[i][j]=rdn;
    }
   }
  }

   return(count);
}

/*----------------------------------*/
/*int checkRfreeze(int Z[size][size])
{
   int root,i,j,c=0,countR=0;
   // For row check
  for(i=0;i<size;i++)
 {
   root=Z[i][c];
   countR=0;
   for(j=1;j<size;j++)
    {if(root==(Z[i][j]))
     { countR++;
       if(countR==2)
	 {for(j=2;j>=0;j--)
	   {return 1;}
	 }
     }
    }
 }
 return 0;
}
/*----------------------------------*/
/*int checkCfreeze(int Z[size][size])
{
   int root,i,j,r=0,countC=0;
   for(j=0;j<size;j++)
 {
   root=Z[r][j];
   countC=0;
   for(i=1;i<size;i++)
    {if(root==(Z[i][j]))
     {countC++;
      if(countC==2)
      { for(i=2;i>=0;i--)
       {return 1;}
      }
      }
     }
    }
 return(0);


}
/*----------------------------------*/

void inst()
{
 char name[15];
 FILE *fp1;
 fp1=fopen("SCORE1.txt","w");

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGi");

 rectangle(1,1,638,478);
 settextstyle(6,0,1);
 outtextxy(100,100,"NAME PLZ !! ");
 rectangle(250,100,370,130);
 scanf("%s",name);
 if(fp1!=NULL)
 {
  fputs(name,fp1);
 }
 fclose(fp1);
 setcolor(14);
 outtextxy(270,100,name);
 setcolor(15);
  outtextxy(180,240,"Select any two adjacent gems to swap,");
  outtextxy(170,270,"three similar gems lead to increase in score");
  outtextxy(520,430,"press any key");
 settextstyle(1,0,2);
 outtextxy(270,200,"INSTRUCTION");
 rectangle(160,190,515,310);


 getch();
 closegraph();

}

void invalid()
{
  initgraph(&gd,&gm,"C:\\TurboC3\\BGi");
  setfillstyle(1,0);
  bar(1,199,638,279);
  rectangle(3,201,636,277);
  setcolor(14);
  settextstyle(2,0,7);
  outtextxy(200,225,"Invalid Input RETRY !");
  outtextxy(201,225,"Invalid Input RETRY !");
  outtextxy(202,225,"Invalid Input RETRY !");
  delay(1500);
  closegraph();

}

/*void levelup()
{
  initgraph(&gd,&gm,"C:\\TurboC3\\BGi");
  setfillstyle(1,0);
  bar(1,199,638,279);
  rectangle(3,201,636,277);
  setcolor(14);
  settextstyle(2,0,7);
  outtextxy(200,225,"LEVEL UP !");
  outtextxy(201,225,"LEVEL UP !");
  outtextxy(202,225,"LEVEL UP !");
  delay(1000);
  closegraph();

}

void changeset()
{
  initgraph(&gd,&gm,"C:\\TurboC3\\BGi");
  setfillstyle(1,0);
  bar(1,199,638,279);
  rectangle(3,201,636,277);
  setcolor(14);
  settextstyle(2,0,7);
  outtextxy(200,225,"SET CHANGING !!");
  outtextxy(201,225,"SET CHANGING !!");
  outtextxy(202,225,"SET CHANGING !!");
  delay(1500);
  closegraph();

} */