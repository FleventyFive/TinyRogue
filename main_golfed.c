#include <curses.h>
#include <stdlib.h>
#include <time.h>
#define I int
#define R rand()%
#define G getch()
#define F(x,y,i) for(i=x;i<y;++i)
#define A mvaddch
#define PS mvprintw
#define CW(y,x) mvinch(y,x)=='#'
#define CE(y,x) mvinch(y,x)=='Y'
#define CT for(I i=0;i<30;++i)for(I j=0;j<9;++j)A(j+1,i+31,' ')
#define UH(h,g) PS(0,31,"Health %d, Gold %d  ",h,g)
#define EI else if
#define X ch.x
#define Y ch.y
#define EX(i) es[i].x
#define EY(i) es[i].y
#define PH ch.h
#define AH if(PH<25)++PH
#define WH PS(1,31,"Wall here!")
typedef struct E{I h,x,y;}E;typedef struct C{I h,x,y,g;}C;void H(I y,I x,E*es,C*c){
for(I i=0;i<3;++i){if(EX(i)==x&&EY(i)==y){I d=R 5;es[i].h-=d;PS(1,31,"Dealt %d damage",d);
if(es[i].h<=0){++c->g;A(EY(i),EX(i),'.');es[i].h=5;EX(i)=R 27+2;EY(i)=R 7+2;A(EY(i),EX(i)
,'Y');}}}}I main(){srand(time(NULL));I xb=30,yb=10,i,j;char c;E *es=(E*)malloc(sizeof(E)*3)
;C ch;initscr();noecho();curs_set(FALSE);F(0,yb,i)F(0,xb,j)A(i,j,'.');F(0,yb,i)A(i,0,'#');F(0,yb,i
)A(i,xb-1,'#');F(0,xb,i)A(0,i,'#');F(3,6,i)A(5,i,'#');F(2,5,i)A(i,5,'#');F(0,xb,i)A(yb-1,i,'#');CT;
X=1;Y=1;PH=10;ch.g=0;UH(ch.h,ch.g);F(0,3,i){es[i].h=5;EX(i)=R 27+2;EY(i)=R 7+2;A(EY(i),EX
(i),'Y');}A(Y,X,'@');refresh();c=G;while(c!='Q'){CT;A(Y,X,'.');if(c=='w'){if(CE(Y-1,X)){H(Y-1
,X,es,&ch);}EI(CW(Y-1,X)){WH;AH;}else{--Y;AH;}}EI(c=='a'){if(CE(Y,X-1)){H(Y,X-1,es,&ch);}EI(CW(Y,X-
1)){WH;AH;}else{--X;AH;}}EI(c=='s'){if(CE(Y+1,X)){H(Y+1,X,es,&ch);}EI(CW(Y+1,X)){WH;AH;}else{++Y;AH
;}}EI(c=='d'){if(CE(Y,X+1)){H(Y,X+1,es,&ch);}EI(CW(Y,X+1)){WH;AH;}else{++X;AH;}}EI(c=='.'){AH;}F(0,
3,i){A(EY(i),EX(i),'.');if(((X==EX(i)-1||X==EX(i)+1)&&Y==EY(i))||((Y==EY(i)-1||Y==EY(i)+1)&&X==EX(i
))){--PH;}else{if(X>EX(i)){if(CE(EY(i),EX(i)+1)!=true&&CW(EY(i),EX(i)+1)!=true){++EX(i);}}EI(X<EX(i
)){if(CE(EY(i),EX(i)-1)!=true&&CW(EY(i),EX(i)-1)!=true){--EX(i);}}EI(Y>EY(i)){if(CE(EY(i)+1,EX(i))!=
true&&CW(EY(i)+1,EX(i))!=true){++EY(i);}}EI(Y<EY(i)){if(CE(EY(i)-1,EX(i))!=true&&CW(EY(i)-1,EX(i))
!=true){--EY(i);}}}A(EY(i),EX(i),'Y');}if(PH<=0){PS(5,3,"You Loose!");G;break;}if(ch.g>=20){
PS(5,3,"You Win!");G;break;}A(Y,X,'@');UH(PH,ch.g);refresh();c=G;}endwin();return 0;}
