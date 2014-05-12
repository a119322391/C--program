// Fig. 10.16: fig10_16.c
// Representing cards with bit fields in a struct
#include <stdio.h>
#define CARDS 52



// bitCard structure definition with bit fields
struct bitCard {                                  
   unsigned int face : 4; // 4 bits; 0-15        
   unsigned int suit : 2; // 2 bits; 0-3         
   unsigned int color : 1; // 1 bit; 0-1          
}; // end struct bitCard                          

typedef struct bitCard Card; // new type name for struct bitCard   
void shuffle( Card * const wDeck );
void fillDeck( Card * const wDeck ); // prototype
void deal( const Card * const wDeck ); // prototype

int main( void )
{ 
   Card deck[ CARDS ]; // create array of Cards
   
   srand( time( NULL ) );
    
   fillDeck( deck );
   shuffle( deck );
   deal( deck );
  
   system("pause");
} // end main

// initialize Cards
void fillDeck( Card * const wDeck )
{ 
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = i % (CARDS / 4); 
      wDeck[ i ].suit = i / (CARDS / 4);  
      wDeck[ i ].color = i / (CARDS / 2);
   } // end for
   
} // end function fillDeck

// deal cards
void shuffle( Card * const wDeck )
{ 
   size_t i; // counter
   size_t j; // variable to hold random value between 0 - 51
   Card temp; // define temporary structure for swapping Cards

   // loop through wDeck randomly swapping Cards
   for ( i = 0; i < CARDS; ++i ) { 
      j = rand() % CARDS;
      temp = wDeck[ i ];      
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;      
   } // end for
} // end function shuffle
   
// output cards in two-column format; cards 0-25 subscripted with 
// k1 (column 1); cards 26-51 subscripted with k2 (column 2)
void deal( const Card * const wDeck )
{ 
   size_t k1; // subscripts 0-25
   // loop through wDeck
   for ( k1 = 0 ; k1 < 5; ++k1  ) { 
      printf("Card:%3d  Suit:%3d  Color:%3d\n",
         wDeck[ k1 ].face, wDeck[ k1 ].suit, wDeck[ k1 ].color );
    
      } // end for
} // end function deal
