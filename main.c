#include <gb/gb.h>
//#include "alpha.c"
//#include "helloWorld.c"
//#include "blankScreen.c"
//#include "sprites.c"
//#include "exportSec.c"
#include "Gang.c"
#include "GangMap.c"
#include <stdio.h>
#include <stdlib.h> 
#include <rand.h> 
#include "Equation.h"
#include <gb/console.h>
//#include <gb.h>



  

   /////*/
   
   void init();
void checkInput();
void updateSwitches();


// The player array will hold the player's position as X ([0]) and Y ([1])
UINT8 player[2];
UINT8 NumberOne[2];
UINT8 NumberTwo[2];
UINT8 NumberThree[2];
UINT8 NumberFour[2];
UINT8 digit=1;
UINT8 NumberOneSprite=5;
UINT8 NumberTwoSprite=5;
UINT8 NumberThreeSprite=5;
UINT8 NumberFourSprite=5;
UINT8 OffSet=5;

UINT8 firstDigitOfFirstNumber[2];
UINT8 secondDigitOfFirstNumber[2];

UINT8 firstDigitOfSecondNumber[2];
UINT8 secondDigitOfSecondNumber[2];
UINT8 sign[2];
int life=3;
int speed=1;
int RandSingle=0;
int RandTen=0;
//int r = 0;
int win=0;
int  ThousandDigit=0;
int  HundredDigit=0;
int  TenDigit=0;
int SingleDigit=0;
int RandValue=0;
int RandValueTwo=0;
int EquationA=0;
int  Answer=0;
unsigned int seed,r;
//const char AnswerData[];
void main() {
while(!joypad()){seed++; if(seed>=255)seed=1;}
	//printf("click A to start. move the Numbers below and lock a number with B. solve 10 Equations to win! if you miss 3 , you lose!");
	waitpadup();
  initrand(seed);
	
	init();
	
	while(1) {
		
		checkInput();				
		updateSwitches();			
		wait_vbl_done();			
	}
	
}
int ReturnIndex(int rand){

int temp =0;

if(rand<0){rand=rand*-1;}
if(rand<10){
	RandTen=0;
	RandSingle=rand;
	rand=rand+OffSet;
	return rand;}
else {
	while(rand>9){rand-=10;temp++;};;
}
	
RandTen=temp+OffSet;
	RandSingle=rand;
	rand=rand+OffSet;
return rand;
}
void Hit(){
	firstDigitOfFirstNumber[0]=135;
firstDigitOfFirstNumber[1]=2;
secondDigitOfFirstNumber[0]=130;
secondDigitOfFirstNumber[1]=2;


firstDigitOfSecondNumber[0]=155;
firstDigitOfSecondNumber[1]=2;
secondDigitOfSecondNumber[0]=150;
secondDigitOfSecondNumber[1]=2;

sign[0]=142;
sign[1]=0;


///////////////////////////////////////////	
	RandValue=0;
	r=0;
	RandTen=0;
	RandSingle=0;
	//r= rand() % 99 + 1;
	
	r=rand()% 99 + 1;                         
	while(r>99){r=rand()%99 +1;}
   gotoxy(0,2);
	///r= rand() % 99 + 1;
	
	if(r<1){r=r*-1;}
	RandValue=r;
	
	r=ReturnIndex(r);
//printf(" ran  %d  Ten %d ",r,RandTen);
	//r=r+4;
	set_sprite_tile(5,r);

	if(RandTen==0){set_sprite_tile(6,23);}
		else{
	set_sprite_tile(6,RandTen);
		}//RandValue=RandValue*r;
	/////////////////
	r=0;
	RandTen=0;
RandSingle=0;
//RandValue=0;
	//r= rand() % 99 + 1;
	///r= rand() % 99 + 1;
	r=rand()% 99 + 1;                         
	while(r>99){r=rand()%99 +1;}
   gotoxy(0,2);
	if(r<1){r=r*-1;}
	//RandValue=r;
	RandValueTwo=r;
	r=ReturnIndex(r);
//r=r+4;
	set_sprite_tile(7,r);
	if(RandTen==0){set_sprite_tile(8,23);}
		else
	{set_sprite_tile(8,RandTen);}
	
//	 r=0;
	//r= rand() % 99 + 1;
	///r= rand() % 99 + 1;
	if(r<1){r=r*-1;}
//	RandValue=RandValue*r;
	//r=ReturnIndex(r);
	
	r=rand()% 3 + 1;                        
	while(r>4){r=rand()%2 +1;}
	r=r+15;
	if(r>17){r--;}
   gotoxy(0,2);
   
   if(r==15){EquationA=RandValueTwo*RandValue;}
   if(r==16){EquationA=RandValueTwo+RandValue;}
   if(r==17){EquationA=RandValueTwo-RandValue; if(EquationA<0){EquationA=EquationA*-1;}}
   set_sprite_tile(9,r);
	
	//////////////////////////////////////////////////
	

	}
void init() {
	//printf("click A to start. move the Numbers below and lock a number with B. solve 10 Equations to win! if you miss 3 , you lose!");
	DISPLAY_ON;						
	set_bkg_data(0, 23,Gang);		
	//set_bkg_tiles(0,0,26,26,blankScreen);
	
	set_bkg_tiles(0,0,20,18,GangMap);
	
	
	set_sprite_data(0, 19, Gang);
	
	
	set_sprite_tile(0,1);
	set_sprite_tile(1,NumberOneSprite);
	set_sprite_tile(2,NumberTwoSprite);
	set_sprite_tile(3,NumberThreeSprite);
	set_sprite_tile(4,NumberFourSprite);
	
	set_sprite_tile(5,r);
	set_sprite_tile(6,r);
	set_sprite_tile(7,r);
	set_sprite_tile(8,r);
	
	set_sprite_tile(9,r);
	set_sprite_tile(10,0);

NumberOne[0]=15;
NumberOne[1]=144;

NumberTwo[0]=8;
NumberTwo[1]=144;

NumberThree[0]=22;
NumberThree[1]=144;

NumberFour[0]=30;
NumberFour[1]=144;

player[0]=10;
player[1]=127;
Hit();
	
	}

void updateSwitches() {
if(win>2){if(life!=100){printf("You Win! ");life=100;





set_sprite_tile(0,23);
	set_sprite_tile(1,23);
	set_sprite_tile(2,23);
	set_sprite_tile(3,23);
	set_sprite_tile(4,23);
	
	set_sprite_tile(5,23);
	set_sprite_tile(6,23);
	set_sprite_tile(7,23);
	set_sprite_tile(8,23);
	
	set_sprite_tile(9,23);
	set_sprite_tile(10,0);
}};
	if(life<1){printf("Game Over Ashely...");life=100;}
	 else if (life==100){} else  {
	 HIDE_WIN;
	// if(win>1){printf()};
	SHOW_SPRITES;
	SHOW_BKG;
	delay(100);
	firstDigitOfFirstNumber[1]+=speed;
	secondDigitOfFirstNumber[1]+=speed;
	sign[1]+=speed;
	move_sprite(5, firstDigitOfFirstNumber[0], firstDigitOfFirstNumber[1]);
	move_sprite(6, secondDigitOfFirstNumber[0], secondDigitOfFirstNumber[1]);

	
	
	firstDigitOfSecondNumber[1]+=speed;
	secondDigitOfSecondNumber[1]+=speed;
	move_sprite(7, firstDigitOfSecondNumber[0], firstDigitOfSecondNumber[1]);
	move_sprite(8, secondDigitOfSecondNumber[0], secondDigitOfSecondNumber[1]);
	
	move_sprite(9, sign[0],sign[1]);
	move_sprite(10, player[0],player[1]);
	if(firstDigitOfFirstNumber[1]>150){life--;
	//if()
	Hit();
	
		}
	}
	
	}

void checkInput() {

    if (joypad() & J_B) {
	
	if(digit==1){digit=0;}
	else if(digit==0){digit=2;}
	else if(digit==2){digit=3;}
	else if(digit==3){digit=1;}
	delay(100);

	
	
	
	
	
	
	
	
	

	
	////////////
	}
	if (joypad() & J_A) {
	
	Answer=0;
	Answer+=(ThousandDigit)*100;
	Answer+=HundredDigit*1000;
	Answer+=TenDigit*10;
	Answer+=SingleDigit;
	
	
	if(Answer==EquationA){win++;player[0]+=9;Hit();}
	
  NumberOneSprite=5;
  ThousandDigit=0;
set_sprite_tile(1,NumberOneSprite); 

NumberTwoSprite=5;
 HundredDigit=0;
set_sprite_tile(2,NumberTwoSprite); 

NumberThreeSprite=5;
  TenDigit=0;
set_sprite_tile(3,NumberThreeSprite); 

NumberFourSprite=5;
  SingleDigit=0;
set_sprite_tile(4,NumberFourSprite); 
 }
	
	// UP
	if (joypad() & J_UP) {
		if(digit==0){
			ThousandDigit++;
			NumberOneSprite++;
			
			if(NumberOneSprite>14){NumberOneSprite=5;ThousandDigit-=10;}
			set_sprite_tile(1,NumberOneSprite);
		//delay(100);
		}	
		if(digit==1){
			HundredDigit++;
			NumberTwoSprite++;
			if(NumberTwoSprite>14){NumberTwoSprite=5;HundredDigit-=10;}
		set_sprite_tile(2,NumberTwoSprite);
		//delay(100);
		}
		//player[1]--;
		if(digit==2){
			TenDigit++;
			NumberThreeSprite++;
			if(NumberThreeSprite>14){NumberThreeSprite=5;TenDigit-=10;}
			set_sprite_tile(3,NumberThreeSprite);
		//delay(100);
		}	
		if(digit==3){
			SingleDigit++;
			NumberFourSprite++;
			if(NumberFourSprite>14){NumberFourSprite=5;SingleDigit-=10;}
		set_sprite_tile(4,NumberFourSprite);
		//delay(100);
		}
		
	}

	// DOWN
	if (joypad() & J_DOWN) {
		if(digit==0){
			ThousandDigit--;
			NumberOneSprite--;
			
			if(NumberOneSprite<5){NumberOneSprite=14;ThousandDigit+=10;}
			set_sprite_tile(1,NumberOneSprite);
		//delay(100);
		}	
		if(digit==1){
			HundredDigit--;
			NumberTwoSprite--;
			if(NumberTwoSprite<5){NumberTwoSprite=14;HundredDigit+=10;}
		set_sprite_tile(2,NumberTwoSprite);
		//delay(100);
		}
		//player[1]--;
		if(digit==2){
			TenDigit--;
			NumberThreeSprite--;
			if(NumberThreeSprite<5){NumberThreeSprite=14;TenDigit+=10;}
			set_sprite_tile(3,NumberThreeSprite);
		//delay(100);
		}	
		if(digit==3){
			SingleDigit--;
			NumberFourSprite--;
			if(NumberFourSprite<5){NumberFourSprite=14;SingleDigit+=10;}
		set_sprite_tile(4,NumberFourSprite);
		
		}
	}

	// LEFT
	if (joypad() & J_LEFT) {
		
		
		
	}	
	
	// RIGHT
	if (joypad() & J_RIGHT) {
		
	
		
	}
	
	
	
	move_sprite(1, NumberOne[0], NumberOne[1]);
	//move_sprite(2, NumberTwo[0], NumberTwo[1]);
	move_sprite(2, NumberTwo[0], NumberTwo[1]);
	move_sprite(3, NumberThree[0], NumberThree[1]);
	//move_sprite(2, NumberTwo[0], NumberTwo[1]);
	move_sprite(4, NumberFour[0], NumberFour[1]);
	
	}