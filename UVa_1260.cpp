//ak92thelooser
#include <bits/stdc++.h>
using namespace std ;
 int arr[1005] ;

int main(){
  int test , n , i , j ,ans ;
   scanf("%d" ,&test);
   while( test -- ){
   	 scanf("%d" ,&n);
   	 for ( i = 0 ; i < n ; i++)
   	 scanf("%d" ,&arr[i]);

   	  ans = 0 ;
   	  for ( i = 0 ; i < n ; i++){
   	  	  for ( j = i-1 ; j >= 0 ; j-- )
   	  	  if ( arr[j] <= arr[i])
   	  	  ans++;
   	  }
   	  printf("%d\n",ans);
   }
return 0 ;
}
