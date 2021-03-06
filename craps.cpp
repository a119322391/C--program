#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Status { CONTINUE, WON, LOST };

int rollDice( void ); 
int switchofsum(int sum);
int whileofsum(int gameStatus,int myPoint);
void ifofstatus(int gameStatus);

int main( void )
{ 
   int sum; 
   int myPoint; 
   
   enum Status gameStatus; 

   
   srand( time( NULL ) );

   sum = rollDice(); 
   
   int mystatus = switchofsum(sum);
   ifofstatus(mystatus);
   system("pause");
   return 0;
   
}
int switchofsum(int sum){

      int myPoint;
      int gameStatus;
      switch( sum ) {
    
      case 7: 
      case 11:       
         gameStatus = WON; 
         myPoint = 0;
         break;

      case 2: 
      case 3: 
      case 12: 
         gameStatus = LOST; 
         myPoint = 0;
         break;
   
      default:                  
         gameStatus = CONTINUE; 
         myPoint = sum; 
         printf( "Point is %d\n", myPoint );
         break; 
         
      } 
      gameStatus = whileofsum(gameStatus, myPoint);
      return gameStatus;
}
   
int whileofsum(int gameStatus,int myPoint){
    enum Status { CONTINUE, WON, LOST };
    int sum;
    while ( CONTINUE == gameStatus ) { 
      sum = rollDice(); 
      if ( sum == myPoint ) { 
         gameStatus = WON;
      } 
      else {
         if ( 7 == sum ) { 
            gameStatus = LOST;
         } 
      }    
   } 
   return gameStatus;
}
  void ifofstatus(int gameStatus){
   if ( WON == gameStatus ) { 
      puts( "Player win" );
   } 
   else { 
      puts( "Player lose" );
   } 
}
int rollDice( void )
{
   int die1; 
   int die2; 
   int workSum; 

   die1 = 1 + ( rand() % 6 ); 
   die2 = 1 + ( rand() % 6 ); 
   workSum = die1 + die2; 

   
   printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
   return workSum;
} 
