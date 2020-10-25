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

int main(int argv, char**argc){
	int i,p;
	FILE *sc;
	srand(time(NULL));
	do{
		printf("CL TEST\n");
		i=getch();
		if(i!='x'){
			printf("LAUNCHING\n");
			sc=fopen("./urb/pt.sc","w");
				p=rand()%8+1;
				fprintf(sc,"%d ",p);
				for(i=1;i<8;i=i+1)
					fprintf(sc,"%d ",p*(i+i*i)+p);
			fclose(sc);
			system("./urb/app");
			sc=fopen("./urb/pt.sc","w");
				fprintf(sc,"ⓛⓤⓒⓘⓓⓔ");
			fclose(sc);
			printf("DONE\n");
			getch();
			printf("\n\n\n");
		}
	}while(i!='x');
return 0;
}
