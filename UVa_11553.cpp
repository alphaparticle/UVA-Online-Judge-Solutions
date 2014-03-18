//ak92thelooser
#include <bits/stdc++.h>
using namespace std ;
int main(){
  
   int test , i , n , j , k , l ,temp ;
   cin >> test ;
   while ( test -- ){
   	  cin >> n;
   	  int arr [n][n] ;
   	  for ( i = 0 ; i < n ; i++)
   	  for ( j = 0 ; j < n ; j++)
   	  cin >> arr[i][j] ;
   	  int x[n] ;
   	  for ( i = 0 ; i < n ; i++)
   	  x[i] = i ;
      set <int> used ; used.clear() ;
      int ans = 0 ;
      for ( i = 0 ; i < n ; i++)	   
      {    
      	   int mini = 1001 ; int row = 0 ;
      	   for ( j = 0 ; j < n ; j++)
      	   if ( arr[j][ x[i] ] < mini && used.find ( j ) == used.end() ){
      	   	   mini = arr[j] [x[i]] ; row = j ;
      	   }
      	   used.insert ( row ) ;
           ans += mini ;
      }
     //cout << ans << endl; 
   	  while ( next_permutation (x ,x+n) ){
   	  	  bool f = true ;
   	  	  for ( i = 0 ; i < n ; i++)
   	  	  if ( x[i] != i)
   	  	  {
   	  	  	 f = false ; break ;
   	  	  }
   	  	  if (f)
   	  	  break ;
   	  	  
   	  	    temp = 0 ; used.clear() ;
                     for ( i = 0 ; i < n ; i++)	   
                     {    
      	                 int mini = 1001 ; int row ;
      	                 for ( j = 0 ; j < n ; j++)
      	                 if ( arr[j][ x[i] ] < mini && used.find ( j ) == used.end() ){
      	   	             mini = arr[j] [x[i]] ; row = j ;
      	             }
      	            used.insert ( row ) ;
                    temp += mini ;
   	             }
   	       //cout << "> "<<temp << endl;
   	       ans = min ( temp , ans );
   }
cout << ans << endl ;
}

	return  0 ;

}
