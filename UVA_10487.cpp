//ak92thelooser
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;

vector <int> sums ;
int arr [1001] ;
int main(){
 int test , n , q , i , j , k , temp ,kase= 0  ;
  vector <int> :: iterator it , fit;
 
  while ( scanf("%d",&n) ){
  	 if( n == 0)
  	 break ;
  	 sums.clear() ;
  	 kase++ ;
  	 for ( i = 0; i < n ; i++)
  	 scanf("%d" ,&arr[i]) ;
     for ( i = 0 ; i < n ; i++)
     for ( j = i + 1 ; j < n ; j++)
     {
     	  temp = arr[i] + arr[j] ;
     	  //cout<< " --- >  "<< temp << endl;
     	  sums.push_back (temp);
     }
     sort( sums.begin() , sums.end() ) ;
     scanf("%d",&q) ;
     printf("Case %d:\n",kase) ;
     for ( i = 0 ; i < q; i++){
     	 scanf("%d" ,&temp);
     	 it = lower_bound ( sums.begin() , sums.end() , temp);
     	 
     	 if ( it != sums.begin () && it != sums.end() ){
     	 int temp2 = *it ;
     	 it -- ;
      	 if ( abs ( temp - temp2) <= abs ( temp - (*it) ) )
     	 printf("Closest sum to %d is %d.\n",temp , temp2);
     	  else
     	 printf("Closest sum to %d is %d.\n",temp , *it);
        }
        else if ( it == sums.begin())
        printf("Closest sum to %d is %d.\n",temp , *it);
        else if ( it == sums.end())
        printf("Closest sum to %d is %d.\n",temp , sums[sums.size()-1] );
     }

  }
	
return  0 ;
}
