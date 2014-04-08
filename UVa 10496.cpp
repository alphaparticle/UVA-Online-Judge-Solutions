//ak92thelooser
//Brute_force (Permutations n!) + Adjacency Matrix

#include <bits/stdc++.h>
using namespace std ;

int arr[11][11] ;
int x[11] , y[11] ;

int main(){
 int test , n , i , j , k ,xx ,yy,ans ;
 scanf("%d",&test);
 while ( test-- ){
 	 scanf("%d %d",&xx,&yy);
 	 scanf("%d %d",&x[0] ,&y[0]);
 	 scanf("%d" ,&n);
 	// cout << n << endl;
 	 for ( i = 1 ; i <= n ; i++ ){
 	 	scanf("%d %d" ,x+i , y+i);
 	 }
 	for ( i = 0 ; i <= n ; i++){
 		 for ( j = i+1 ; j <= n ; j++){
 		 	arr[i][j] = arr[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
 		 }
 	}
 /*	for ( i = 0 ; i <= n ; i++)
 	{
 		 for(j = 0 ; j <= n ; j++)
 		 cout<<arr[i][j]<<" ";
 	  cout<<endl;
 	}*/
   ans = 100000 ;
   int per[n] , temp;
   for ( i = 0 ; i < n ; i++)
   per[i] = i+1 ;
   
   temp = arr[0][per[0]] ;
   for ( i = 0 ; i < n-1 ; i++){
      temp += arr[per[i]][per[i+1]] ;
   }
   temp += arr[0][per[n-1]] ;
   ans= min(ans , temp );

   while ( next_permutation(per,per+n) ){
   	  bool f = true ;
   	  //for ( i = 0;  i < n ; i++)
   	  //cout<<per[i]<<" ";
   	  //cout<<endl;
   	  for ( i = 0 ; i < n ; i++)
   	  if ( per[i] != i+1){ f = false ; break ;}
   	  if(f)break ;
        
        temp = arr[0][per[0]] ;
        for ( i = 0 ; i < n-1 ; i++){
           temp += arr[per[i]][per[i+1]] ;
        }
        temp += arr[0][per[n-1]] ;
        //cout << temp << endl;
        ans= min(ans , temp );
   }
   printf("The shortest path has length %d\n",ans);
   
 }

	return 0 ;
}


// II> TSP ( Bitmasking + DP ) 


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int i, j, TC, xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1 << 11]; // Karel + max 10 beepers

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
  if (bitmask == (1 << (n + 1)) - 1)
    return dist[pos][0]; // return trip to close the loop
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  int ans = 2000000000;
  for (int nxt = 0; nxt <= n; nxt++) // O(n) here
    if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
      ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main() {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &xsize, &ysize); // these two values are not used
    scanf("%d %d", &x[0], &y[0]);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // karel's position is at index 0
      scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i <= n; i++) // build distance table
      for (j = i+1; j <= n; j++)
        dist[i][j] = dist[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]); // Manhattan distance

    memset(memo, -1, sizeof memo);
    printf("The shortest path has length %d\n", tsp(0, 1)); // DP-TSP
  }

  return 0;
}
