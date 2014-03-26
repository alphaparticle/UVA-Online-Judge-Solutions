// ak92thelooser
// complexity : O (( Z-Y)log(Z) ) or O(NlogN) 
// Time = 0.042
// Rank - 197
// Binary Search


#include <bits/stdc++.h>
using namespace std;

vector <long> v ;

int main(){
long Y ,P , i , j , k ;
long ans, start , end ;
vector <long> :: iterator it , fit ;
while ( scanf("%ld" ,&Y) == 1 ){
     v.clear() ;
     scanf("%ld",&P) ;
     for ( i = 0 ; i < P  ; i++ ){
     	 scanf("%ld",&j);
     	 v.push_back (j);
     }
     ans = 0 ;
     for ( i = P-1 ; v[i] >= Y ; i-- ){
     	 it = lower_bound ( v.begin() , v.end() , v[i] - Y + 1 );
        // cout << i - ( it - v.begin()  ) + 1 <<" "<< v[it - v.begin()] <<" "<< v[i] << endl;
         if ( i - ( it - v.begin()  ) + 1 >= ans ){
         	 ans = i - ( it - v.begin()  ) + 1 ;
         	 start = v[it - v.begin()] ;
         	 end = v[i] ; 
         }

     } 
    printf("%ld %ld %ld\n",ans ,start ,end );
}
return 0 ;

}
