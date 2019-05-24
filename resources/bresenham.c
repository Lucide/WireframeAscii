swap=0;
DX=x2-x1;
DY=y2-y1;
//siccome scambio DY e DX ho sempre DX>=DY allora per sapere quale coordinata occorre cambiare uso una variabile
if(abs(DX)<abs(DY)){
   swap(DX,DY);
   swap=1;
}
//per non scrivere sempre i valori assoluti cambio DY e DX con altre variabili
a=abs(DY);
b=-abs(DX);
//assegna le coordinate iniziali
x=x1;
y=y1;
//il nostro valore d0
d=2*a+b;
//s e q sono gli incrementi/decrementi di x e y
q=1;
s=1;
if(x1>x2)
	q=-1;
if(y1>y2)
	s=-1;
	mna[x,y]=1;
	mna[x2,y]=1;
for(k=0;k<(-b);k+=1){
	if(d>0){
		x=x+q;
		y=y+s;
		d=d+2*(a+b);
	}
	else{
		x=x+q;
		if(swap==1){
			y=y+s;
			x=x-q;
		}
		d=d+2*a;
	}
	mna[x,y]=1;
}
