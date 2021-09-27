#include <iostream>
#include <cmath>

 void symbolic_sqrt( uint64_t radicand){
   
       uint64_t factor = 1;
       uint64_t twofactor = __builtin_ctz(radicand); // strips out factors of two
       radicand>>=twofactor; 
 
       uint64_t suprenum = sqrt(radicand);
   
     if (suprenum > 1000) {       // shorter upper bound for larger numbers
         suprenum = sqrt(suprenum);
     }

    for (uint64_t i = 1; i< suprenum; i++){
        while  (radicand%(4*i*i + 4*i+1)==0){// check divisibility of x
           factor*=(2*i+1);    // multiply the exterior factor by 2Z+1
           radicand/=(4*i*i+4*i+1);   // divides by (2Z+1)^2
       }
    }   
   
  factor<<=(twofactor>>1);
  radicand<<=(twofactor&1);
   
  std::cout<<factor<<"sqrt"<<radicand;
}
