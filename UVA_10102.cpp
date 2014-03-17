//ak92thelooser
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std  ;
typedef pair  <int,int> ii ;

vector  < ii > V1 , V3 ;

int main(){
 int i , j, M , ans , temp ;
 char c ;
 while ( scanf("%d" ,&M) != EOF ) {
   	getchar();
 	V1.clear() ; V3.clear() ;
     for (  i = 0 ; i < M ; i++)
      {
           for( j = 0 ; j < M ; j++)
            {
            	 c = getchar() ;
            	 if ( c == '1')
            	 V1.push_back ( ii ( i , j));
            	 else if ( c == '3')
            	 V3.push_back ( ii ( i , j));
            }
            getchar () ;
      }
      ans = 0 , temp = 99999;

     for ( i = 0 ; i < V1.size() ; i++){
     temp = 99999 ;
     for ( j = 0 ; j < V3.size() ; j++)
      temp = min ( temp , abs (V1[i].first - V3[j].first) + abs (V1[i].second - V3[j].second));
     //cout << ">" << V1[i].first << " "<<V1[i].second <<" "<< temp << endl;
     ans = max ( ans , temp ) ;
    }
    printf("%d\n",ans);
  
 }

return 0  ;

}
