//ak92thelooser
//DP+SORTING
//Sorting is done on the basis such that the dimension of the base of the block below are largest.
//Use all the possible base and height combinations i.e 3! = 6 



#include <bits/stdc++.h>
using namespace std ;
typedef pair  < int , int > ii ;
typedef pair < int , ii > iii ;

vector <iii> coll ;
int dp[1000];

bool comp ( const iii A ,const iii B){
	 if ( A.first < B.first)
	 return false ;
	 else if ( A.first > B.first)
	 return true ;
	else {
		 if ( A.second.first < B.second.first)
		 return false;
		else if( A.second.first > B.second.first)
			return true ;
    else {
       if(  A.second.second > B.second.second )
        return true;
      else
        return false ;
       
    }
	}
}

int main(){
 int n , i, j , k ;
 int arr[3] , kase = 0;
 while( cin >> n) {
      if ( n == 0)
      break  ; 
      coll.clear() ;

      for ( i = 0 ; i < n ; i++){
          scanf("%d %d %d" ,&arr[0] ,&arr[1] , &arr[2]);
          sort(arr,arr+3);
          coll.push_back ( iii (arr[2] ,  ii(arr[1] ,arr[0])));
          coll.push_back ( iii ( arr[1] , ii (arr[2] ,arr[0])));
          coll.push_back( iii ( arr[0] , ii (arr[2],arr[1]))) ;
          coll.push_back( iii ( arr[0] , ii (arr[1],arr[2]))) ;
          coll.push_back( iii ( arr[1] , ii (arr[0],arr[2]))) ;
          coll.push_back( iii ( arr[2] , ii (arr[0],arr[1]))) ;
      }

     sort ( coll.begin() , coll.end() , comp);
 
    // for ( i = 0 ; i < coll.size() ; i++)
    // cout << i <<" "<<coll[i].first <<" "<<coll[i].second.first<<" "<<coll[i].second.second<<endl;

     int ans = 0 ;

     for (i = 0 ; i < coll.size() ; i++ ){
     	 bool f = false ;
       dp[i] = coll[i].second.second ;
     	 for ( j = i-1 ; j >=0 ; j--){
         if ( coll[j].second.first > coll[i].second.first )
     	 	 if ( coll[j].first > coll[i].first && dp[j] + coll[i].second.second > dp[i])
     	 	 {
     	 	 	 dp[i] = dp[j]+coll[i].second.second ;
     	 	 	 ans =max ( ans ,dp[i]);
           f = true ;
     	 	 }
     	 }
     	ans = max ( ans ,dp[i]);
     	//cout << i <<" "<<dp[i]<<endl;
     }
    printf("Case %d: maximum height = %d\n",++kase ,ans);

 }

return 0 ;
}
