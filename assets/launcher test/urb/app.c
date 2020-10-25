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
	int i,p,z;
	FILE *dc;

	printf("\tLAUCHED\n");
	if((dc=fopen("./urb/pt.sc","r"))){
			printf("\tFILE FOUND\n");
			fscanf(dc,"%d",&p);
			for(i=1;i<8&&z!=-1;i=i+1){
				fscanf(dc,"%d",&z);
				if(z!=(p*(i+i*i)+p)){
					printf("\tWRONG CODE\n");
					z=-1;
				}
			}
		fclose(dc);
		dc=fopen("./urb/pt.sc","w");
			fprintf(dc,"ⓛⓤⓒⓘⓓⓔ");
		fclose(dc);
	}
	else{
		printf("\tFILE NOT FOUND\n");
		z=-1;
	}
	if(z==-1)
		printf("\tFAILED\n");
	else{
		printf("\tCORRECT CODE\n\tSUCCESS\n");
		printf("\tSIMULATING\n");
		getch();
		printf("\tSKIPPED\n");
	}
return 0;
}
