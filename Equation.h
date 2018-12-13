#ifndef Equation_h
#define Equation_h


typedef struct Equation {
   int firstNum;
   int secondNum;
	int EquAnswer;
	int firstNumTen;
	int firstNumSingle;
	int secondNumTen;
	int secondNumSingle;
   
   int firstNumTenDigit;
	int firstNumSingleDigit;
	int secondNumTenDigit;
	int secondNumSingleDigit;
   //char subject[100];
   //int book_id;
UINT8 firstNumTenX[2];
UINT8 firstNumSingleX[2];

UINT8 secondNumTenX[2];
UINT8 secondNumSingleX[2];
   
   
  /* int ReturnIndex(int rand){

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
	//if(rand>0){rand=rand*-1;}
RandTen=temp;
	RandSingle=rand;
	rand=rand+OffSet;
return rand;
}*/


   } Equation;
int ReturnIndex(int);
   #endif