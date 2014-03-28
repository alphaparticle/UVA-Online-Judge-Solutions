// RAT ATTACK
// ak92thelooser
#include <bits/stdc++.h>
using namespace std ;

int killed [1027][1027] ;

int main(){
int test , i, j , k ,n , x, y , d ,pop;
scanf("%d",&test) ;
   while ( test -- ){
      scanf("%d",&d);
      scanf("%d",&n);
      for ( i = 0 ; i < 1026 ; i++)
      memset ( killed[i] , 0 , sizeof killed[i]);

      for ( i = 0 ; i < n ; i++){
      	  scanf("%d %d %d",&x,&y, &pop);
      	  for ( j = max ( 1 , x-d) ;  j <= min(1026 , x+d) ; j++ )
      	  for(  k = max ( 1 , y-d) ;  k <= min(1026 , y+d) ; k++ )
      	  killed[j][k] += pop ;
      }

      int ans = 0 ;
      for ( i = 1 ; i < 1026 ; i++)
      for( j =  1 ; j < 1026 ; j++)
      if ( killed[i][j] > ans){
      	ans = killed[i][j] ;
      	x = i; y = j ;
      }
     printf("%d %d %d\n",x,y,ans);
   }
	return 0 ;
}
