//ak92thelooser
//Knapsack Problem

#include <bits/stdc++.h>
using namespace std ;
#define maxn 1001
#define maxw 31

int dp [maxn][maxw] ;
int n , test , g  ;
int price[maxn] , weight[maxn] ;

int rec ( int cur , int left ){
	
	// cout << cur <<" "<<left <<" "<<dp[cur][left] << endl;
	 if ( cur == n || weight == 0 ) return 0 ;
	 if ( dp[cur][left] != -1 ) return dp[cur][left] ;
	 if ( weight[cur] > left) {
	 	 dp[cur][left] = rec( cur+1 ,left);
	 	 return dp[cur][left] ;
	 }
   
    dp[cur][left] = max ( rec(cur+1, left) , price[cur] + rec(cur+1 , left-weight[cur]) );
    return dp[cur][left] ;

}


int main(){
 int i , j ,k ,ans;
 scanf("%d" ,&test) ;
 while  ( test -- ){
 	  memset ( dp , -1 ,sizeof dp);
 	  scanf("%d" ,&n);
 	 
 	  for ( i = 0 ; i < n ;i++ ){
 	  	 scanf("%d %d" ,&price[i] , &weight[i]);
 	  }

 	  ans = 0 ;
 	  scanf("%d" ,&g);
 	  while ( g-- ){
 	  	  scanf("%d" ,&k);
 	  	  ans += rec ( 0 , k );
 	  	
 	  }
    printf("%d\n",ans);
 }
	return 0 ;
}
