#include<stdio.h>
#include<string.h>
 
int d(char);
 
int main(){
 
    char rN[1000];
    int i=0;
    long int n =0;
    scanf("%s",rN);
 
    while(rN[i]){
 
         if(d(rN[i]) < 0){
             printf("Invalid roman digit : %c",rN[i]);
             return 0;
         }
 
         if((strlen(rN) -i) > 2){
             if(d(rN[i]) < d(rN[i+2])){
                 printf("Invalid roman number");
                 return 0;
             }
         }
 
         if(d(rN[i]) >= d(rN[i+1]))
             n = n + d(rN[i]);
         else{
             n = n + (d(rN[i+1]) - d(rN[i]));
             i++;
         }
         i++;
    }
 
    printf("%ld",n);
 
    return 0;
 
}
 
int d(char c){
 
    int value=0;
 
    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}