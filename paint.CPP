#include <iostream.h>
#include <conio.h>

char funkey ( int & i ) {
char a = getch  () ;
if ( a==0 ) {
   i= 1 ;
   a= getch () ;
   }
else i = 0 ;
return a ;
}


void init (void) {
	int x, y , co ;
	int far * scr = ( int far * ) 0xb8000000;
	for ( int i = 0 ; i < 2000 ; i ++ )
	* ( scr + i ) = 0xF0 * 256 + 32 ;
	x= 12 ;
	y=40 ;
	co = 0xF0 ;
	* (scr + x * 80 + y)= (co* 256)+ '*' ;
	y = 0x70 << 8 + 32 ;

int n ;
for ( n=0 ; n<80 ; n++ ){
     *(scr+n)=0x50 * 256+32;
     }

}

void docommand (int i,char c){
	int far * scr = ( int far *) 0xb8000000 ;
	int g, co , x , y ;
	if (!i) switch(c){
		case '1':co=0x71; break;
		case '2':co=0x72; break;
		case '3':co=0x73; break;
		case '4':co=0x74; break;
		case '5':co=0x75; break;
		case '6':co=0x76; break;
		case '7':co=0x77; break;
	}
	else switch(c){
		case 'h' : if (x>0)  {
			* ( scr + x* 80 + y )=g ;
			g= * ( scr + (x-1) * 80 + y ) ;
			* ( scr + (x-1 ) * 80 + y )= co << 8 + '*';
			x-- ;
		       }
			break;


		case 'P' : if ( x < 24 ) {
		* ( scr + x * 80 + y ) =g ;
		g= * ( scr + ( x + 1 ) * 80 + y ) ;
		* ( scr + ( x+1 ) * 80 + y ) = co << 8 + '*' ;
		x++ ;
		}


		case 'M' : if ( x < 79 ) {
		* ( scr + x* 80 + y) = g ;
		g = * ( scr + x * 80 + y+ 1 ) ;
		 * ( scr + x * 80 + y + 1 ) = co << 8 + '*' ;
		 y ++ ;
		 }
		 break;
		case 'K' : if ( x > 0 ) {
		* ( scr+ x * 80 + y ) = g ;
		g = * ( scr + x * 80 +y- 1 ) ;
		* ( scr + x * 80 + y - 1 ) = co << 8 + '*' ;
		y-- ;
	}
}
   *(scr + x *80+y)=g;
   g=co <<8+32;
   *(scr +(x-1)*80+y)=co <<80+'*';
   x--;

   }





int g ;
void main (void) {
	int i ;
	init () ;
	char c = funkey (i) ;
	char s = 1;
	while ( (i != 1 ) || ( c !='p' ) && s !=27 ) {
		c = funkey ( i ) ;
		docommand (i, c ) ;
		//getch () ;
	}
}

