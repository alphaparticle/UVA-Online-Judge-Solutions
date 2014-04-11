//ak92thelooser


#include <bits/stdc++.h>
using namespace std ;

string a , b ,temp ;
int arr[370][10] ;
int main(){
 memset( arr , 0 , sizeof arr) ;
  int n , i , j ,carry , prod;
  a = '1' ;

 // freopen("b.txt" , "w" , stdout);
  arr[1][1] = 1 ;
  for ( i = 2 ; i <= 366 ; i++){
      temp.clear() ; carry =  0 ;
      for ( j = 0 ; j < a.length() ; j++){
      	 prod = (a[j] - '0') * i + carry ;
      	 temp += (prod%10)+'0' ;
      	 carry = prod/10 ;
      }
      while ( carry != 0){
      	 temp += (carry%10) + '0' ; carry /=10 ;
      }
     for ( j = 0 ; j < temp.length() ; j++){
     	 arr[i][ temp[j] - '0' ]++ ;
     }
     //cout << temp << endl;
     a.clear() ; a = temp ;
  }
   bool f= true ;
   while(scanf("%d",&n)){
   	 if( n==0)
   	 break ;
   	 if (!f)
     printf("\n");
   	 f = false ;
   	 printf("%d! --\n" , n);
   	 printf("   (0)%5d",arr[n][0]);
   	 for ( i = 1 ; i < 5 ; i++)
   	 printf("    (%d)%5d",i , arr[n][i]);
   	 printf("\n");
   	 printf("   (5)%5d",arr[n][5]);
   	 for ( i = 6 ; i < 10 ; i++)
   	 printf("    (%d)%5d",i , arr[n][i]);
    // printf("\n");

   }


	return 0;
}
