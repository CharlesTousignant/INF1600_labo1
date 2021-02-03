#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"

short parity(const short c){
   short p = 0;  
   
   // Completer la fonction ici

   for (int i = 0; i < 16; i++)
   { // 0000 1111
      if(c & (1 << i))
      {
         p = p ^ 1;
      }
   }
   
   return  p & 1;
}

short hamming_encoding(const char c){
   short code = 0;
   

   // Completer la fonction ici
   int i = 0;

   for(int j = 0; j < 12; j++)
   {
      if(j == 0 || j == 1 || j == 3 || j == 7)
         continue;

      else
      {  
         code = code | ((c & (1 << i)) << (j - i));
         i++;
      }
   }

   // masque p0 = 0b 0101 0101 0101 0100 = 0x5554
   // masque p1 = 0b 0110 0110 0110 0100 = 0x6664
   // masque p2 = 0b 0111 1000 0111 0000 = 0x7870
   // masque p3 = 0b 0111 1000 0111 0000 = 0x7870
   code |= parity(code & 0x5554);
   code |= parity(code & 0x6664) << 1;
   code |= parity(code & 0x7870) << 3;
   code |= parity(code & 0x7870) << 7;

   return code;
}

char hamming_decoding(const short c){   
   // Completer la fonction ici
   short cc = c;

   //masque c0 = 0b 0101 0101 0101 0101 = 0x5555
   //masque c1 = 0b 0110 0110 0110 0110 = 0x6666
   //masque c2 = 0b 0111 1000 0111 1000 = 0x7878
   //masque c3 = 0b 0111 1111 1000 0000 = 0x7F80

   short erreur = 0;

   erreur |= parity(cc & 0x5555);
   erreur |= parity(cc & 0x6666) << 1;
   erreur |= parity(cc & 0x7878) << 2;
   erreur |= parity(cc & 0x7F80) << 3;

   cc ^= 1 << (erreur - 1);
 
   char code = 0;
   code |= (cc & 0x0004) >> 2;
   code |= (cc & 0x0070) >> 3;
   code |= (cc & 0x0F00) >> 4;
   
   return code;
}

