// ak92thelooser

//knapsack

//DP

#include <bits/stdc++.h>
using namespace std ;
#define maxt 1010
#define maxn 31

int dp [maxn] [maxt] ;
int n , t , w ;
int depth[maxn] , value[maxn] ;
int mark [maxn] ;
//vector <int> v;

int sol ( int cur , int left ){
// cout<<cur<<" "<<left <<" "<<dp[cur][left]<<endl;
 if ( dp[cur][left] != -1)
 { return dp[cur][left]; }
 
 if ( cur >= n || left < 0 ) return 0 ;

 if ( left < 3*(w*depth[cur]) ){

      dp[cur][left] = sol(cur+1 , left) ;
      return dp[cur][left];
 }

 int temp1=  sol(cur+1 ,left) ;
 int temp2 =  value[cur] + sol( cur+1 , left - 3*(w*depth[cur])) ;
 if ( temp1 >= temp2 )
 {
     dp[cur][left] = temp1 ;
     return dp[cur][left] ;
 }
 else{

      dp[cur][left] = temp2 ;
      return dp[cur][left] ;
 }


}



int main(){
int i , j ,k , l , temp ;
l = 0 ;
//memset(dp ,-1 ,sizeof dp);
while ( scanf("%d %d" ,&t ,&w) == 2){
   memset (dp ,-1 ,sizeof dp);
   memset( mark, 0 ,sizeof mark);
    //v.clear() ;
    if (l)
    printf("\n");
    l = 1 ;
    scanf("%d" ,&n);
    for ( i = 0 ;  i < n ; i++)
    {
         scanf("%d %d" ,&depth[i] , &value[i]);
    }

  int ans = sol ( 0 , t );
  printf("%d\n",ans);
  ans = 0;
  i = 0 ; j = t ;
  while ( i < n-1 ){
       //cout << i <<" "<< j <<" "<< dp[i][j]<<endl;
       if (dp[i+1][j] != dp[i][j] ){
            mark[i] =1 ;ans++ ;
            j -= 3*w*depth[i];
       }
      i++ ;
  }
  if ( j != 0 )
  mark[i] = 1, ans++;
 
  printf("%d\n",ans);
  for ( i = 0 ; i < n ; i++)
  if(mark[i]){
      printf("%d %d\n",depth[i], value[i]);
  }
}

    return 0 ;
}
