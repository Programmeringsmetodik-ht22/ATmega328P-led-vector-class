/********************************************************************************
* main.cpp: Demonstration av dynamisk vektor för lagring och styrning av 
*           multipla lysdioder
********************************************************************************/
#include "led.hpp"
#include "button.hpp"
#include "led_vector.hpp"

/********************************************************************************
* main: Ansluter fem lysdioder till pin 6 - 10 och lagrar i en dynamisk vektor.
*       Ansluter en tryckknapp till pin 13. Vid nedtryckning av tryckknappen
*       blinkar lysdioderna i en slinga var 100:e millisekund, annars blinkar
*       de kollektivt var 500:e millisekund.
********************************************************************************/
int main(void)
{
   led l1(6);
   led l2(7);
   led l3(8);
   led l4(9);
   led l5(10);

   button b1(13);
   led_vector v1;

   v1.push(l1);
   v1.push(l2);
   v1.push(l3);
   v1.push(l4);
   v1.push(l5);

   while (1)
   {
      if (b1.is_pressed())
      {
         v1.blink_sequentially(100);
      }
      else
      {
         v1.blink_colletively(500);
      }
   }

   return 0;
}

