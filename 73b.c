//Riccardo Cavasin

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#include<time.h>
#include<math.h>

int getch(){
	struct termios oldattr,newattr;
	int ch;
	tcgetattr(STDIN_FILENO,&oldattr);
	newattr=oldattr;
	newattr.c_lflag&=~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&newattr);
	ch=getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);
	if(ch=='\033'){
		getch();
		ch=getch();
	}
return ch;
}
void sleepm(int milliseconds){
    clock_t time_end;
    time_end=clock()+milliseconds*CLOCKS_PER_SEC/1000;
    while(clock()<time_end);
}
double matan(double a){
	a=atan(a)*(180/M_PI);
return a;
}
double msin(double a){
	a=sin(a*(M_PI/180));
return a;
}
double mcos(double a){
	a=cos(a*(M_PI/180));
return a;
}

struct sNode{
	int px,py;
	double x,y,z,rod,rodir;
};
typedef struct sNode node;


void render(int mna[][70]);
void clean(int mna[][70]);
void set(node vert[]);
void wiredreams(node vert[],int mna[][70]);
void engine(int mx,int my,float prs,int zm,node vert[],int mna[][70]);
void drawline(int x1,int y1,int x2,int y2,int mna[][70]);

void cabual(int *mx,int *my,float *prs,int *zm);
void peepingtom();

int main(int argv, char**argc){

	int mx=0,my=0,zm=18,mna[300][70];
	node vert[8];
	int n,f=1;
	float prs=1;
	srand(time(NULL));
	peepingtom();

	set(vert);
	while(1){
			clean(mna);
			engine(mx,my,prs,zm,vert,mna);
			wiredreams(vert,mna);
			render(mna);
			if(f){
				mx=0;
				my=0;
				n=getch();
				switch(n){
					case 'A':
						my=-3;
					break;
					case 'B':
						my=3;
					break;
					case 'C':
						mx=3;
					break;
					case 'D':
						mx=-3;
					break;
					case 'q':
						if(zm<25)
							zm=zm+1;
					break;
					case 'a':
						if(zm>1)
							zm=zm-1;
					break;
					case 'w':
						prs=prs+0.1;
					break;
					case 's':
						if(prs>1)
							prs=prs-0.1;
					break;
					case 'z':
					case 'p':
						zm=18;
						prs=1;
						set(vert);
						if(n=='p')
							f=0;
					break;
				}
				
			}
			else{
				cabual(&mx,&my,&prs,&zm);
				sleepm(80);
			}
	}

return 0;
}

void clean(int mna[][70]){
	int x,y;

	for(y=0;y<70;y=y+1){
		for(x=0;x<300;x=x+1)
			mna[x][y]=0;
	}
}

void render(int mna[][70]){
	int x,y;

	system("clear");
	printf("\n  ╭────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮\n");
	for(y=0;y<70;y=y+1){
		printf("  │");
		for(x=0;x<300;x=x+1){
			switch(mna[x][y]){
				case 0:
					printf(" ");
				break;
				case 1:
				case 2:
					printf("#");
				break;
			}
		}
		printf("│\n");
	}
	printf("  ╰────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯\n");
}

void set(node vert[]){

	vert[0].x=1;
	vert[0].y=1;
	vert[0].z=1;

	vert[1].x=1;
	vert[1].y=-1;
	vert[1].z=1;

	vert[2].x=-1;
	vert[2].y=1;
	vert[2].z=1;

	vert[3].x=-1;
	vert[3].y=-1;
	vert[3].z=1;

	vert[4].x=1;
	vert[4].y=1;
	vert[4].z=-1;

	vert[5].x=1;
	vert[5].y=-1;
	vert[5].z=-1;

	vert[6].x=-1;
	vert[6].y=1;
	vert[6].z=-1;

	vert[7].x=-1;
	vert[7].y=-1;
	vert[7].z=-1;
}

void wiredreams(node vert[],int mna[][70]){
	drawline(vert[0].px,vert[0].py,vert[4].px,vert[4].py,mna);
	drawline(vert[4].px,vert[4].py,vert[6].px,vert[6].py,mna);
	drawline(vert[6].px,vert[6].py,vert[2].px,vert[2].py,mna);
	drawline(vert[2].px,vert[2].py,vert[0].px,vert[0].py,mna);

	drawline(vert[1].px,vert[1].py,vert[5].px,vert[5].py,mna);
	drawline(vert[5].px,vert[5].py,vert[7].px,vert[7].py,mna);
	drawline(vert[7].px,vert[7].py,vert[3].px,vert[3].py,mna);
	drawline(vert[3].px,vert[3].py,vert[1].px,vert[1].py,mna);

	drawline(vert[0].px,vert[0].py,vert[1].px,vert[1].py,mna);
	drawline(vert[2].px,vert[2].py,vert[3].px,vert[3].py,mna);
	drawline(vert[4].px,vert[4].py,vert[5].px,vert[5].py,mna);
	drawline(vert[6].px,vert[6].py,vert[7].px,vert[7].py,mna);
};

void engine(int mx,int my,float prs,int zm,node vert[],int mna[][70]){
	int i;

	for(i=0;i<8;i=i+1){
		vert[i].rod=sqrt(vert[i].x*vert[i].x+vert[i].z*vert[i].z);
		if(vert[i].z==0){
			if(vert[i].x>0)
				vert[i].rodir=90;
			else
				vert[i].rodir=-90;
		}
		else{
			if(vert[i].z<0)
				vert[i].rodir=matan(vert[i].x/vert[i].z)+180;
			else
				vert[i].rodir=matan(vert[i].x/vert[i].z);
		}
		vert[i].x=msin(vert[i].rodir+mx)*vert[i].rod;
		vert[i].z=mcos(vert[i].rodir+mx)*vert[i].rod;
		vert[i].rod=sqrt(vert[i].y*vert[i].y+vert[i].z*vert[i].z);
		if(vert[i].z==0){
			if(vert[i].y>0)
				vert[i].rodir=90;
			else
				vert[i].rodir=-90;
		}
		else{
			if(vert[i].z<0)
				vert[i].rodir=matan(vert[i].y/vert[i].z)+180;
			else
				vert[i].rodir=matan(vert[i].y/vert[i].z);
		}
		vert[i].y=msin(vert[i].rodir+my)*vert[i].rod;
		vert[i].z=mcos(vert[i].rodir+my)*vert[i].rod;

		vert[i].px=zm*(vert[i].x)*(sqrt(pow(prs,vert[i].z)))+130;
		vert[i].py=zm*(vert[i].y)*(sqrt(pow(prs,vert[i].z)))+35;
	}
}

void drawline(int x1,int y1,int x2,int y2,int mna[][70]){
	int x=x1,y=y1,a,b,q=1,s=1,i,d,swp=0;

	a=abs(y2-y1);
	b=abs(x2-x1);
	if(b<a){
		i=a;
		a=b;
		b=i;
		swp=1;
	}
	b=-b;
	d=2*a+b;
	if(x1>x2)
		q=-1;
	if(y1>y2)
		s=-1;
	mna[x][y]=1;
	for(i=0;i<(-b);i=i+1){
		if(d>0){
			x=x+q;
			y=y+s;
			d=d+2*(a+b);
		}
		else{
			x=x+q;
			if(swp==1){
				y=y+s;
				x=x-q;
			}
			d=d+2*a;
		}
		mna[x][y]=1;
	}
}

void cabual(int *mx,int *my,float *prs,int *zm){
	int i,n,j;

	i=rand()%2;
	if(i)
		*mx=rand()%13-6;
	else
		*my=rand()%13-6;
	n=0;
	j=0;
	i=rand()%4;
	if(i==0){
		if(*zm<20)
			n=1;
		if(*zm>1)
			j=1;
		if(n==1&&j==1){
			j=rand()%2;
			n=n-j;
		}
		if(n)
			*zm=*zm+1;
		if(j)
			*zm=*zm-1;
	}
	n=0;
	j=0;
	i=rand()%4;
	if(i==0){
		if(*prs<1.4)
			n=1;
		if(*prs>1)
			j=1;
		if(n==1&&j==1){
			j=rand()%2;
			n=n-j;
		}
		if(n)
			*prs=*prs+0.1;
		if(j)
			*prs=*prs-0.1;
	}
}

void peepingtom(){
	int i,p,z;
	FILE *dc;

	system("clear");
	if((dc=fopen("./urb/pt.sc","r"))){
			fscanf(dc,"%d",&p);
			for(i=1;i<8&&z!=-1;i=i+1){
				fscanf(dc,"%d",&z);
				if(z!=(p*(i+i*i)+p)){
					z=-1;
				}
			}
		fclose(dc);
		dc=fopen("./urb/pt.sc","w");
			fprintf(dc,"ⓛⓤⓒⓘⓓⓔ");
		fclose(dc);
	}
	else
		z=-1;
	if(z==-1){
		printf("  ‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥\n  :             ERTP= CLEVERLAUNCHER ERROR             :\n  : you are not using CL or your copy is not original  :\n  :                   Ctrl+c to exit                   :\n  ‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥\n");
		while(1);
	}
}
