//ak92thelooser
#include <bits/stdc++.h>
using namespace std ;
typedef pair < int , int > ii ;
typedef pair  < ii ,int> iii ;
vector <iii > v ;
//map < ii , int > dic ;

int dp [1100][2] ;

bool comp ( const iii A , const iii B){
	 if ( A.first.first < B.first.first )
	 	return true ;
	 else if ( A.first.first > B.first.first )
	 	return false;
	 else{
	 	 if ( A.first.second > B.first.second)
	 	 return true;
	 	else if (A.first.second < B.first.second)
	 		return false ;
    else {
          if(A.second > B.second)
          return false;
          else
            return true ;
    }
	 }
}

int main(){
	//freopen("input.txt" , "r" , stdin);
  int i , j , w , iq ;
  i = 0;
  while ( scanf("%d %d",&w ,&iq) == 2){
  	 v.push_back (iii( ii ( w ,iq) , i++)) ;
  	 //dic[ ii(w,iq) ] = i++;
  } 
   
   //for ( i = 0; i < v.size() ; i++)
   //cout<<i <<" "<<v[i].first.first <<" "<<v[i].first.second<<endl;
   //cout<<"----------------------\n";

   sort(v.begin() , v.end() , comp );
   //for ( i = 0; i < v.size() ; i++)
   //cout<<i <<" "<<v[i].first.first <<" "<<v[i].first.second<<" "<<v[i].second<<endl;
   dp[0][0] = 1 ; dp[0][1] = 0 ;
  for ( i = 0 ; i < v.size() ; i++ ){
        bool f = false ;
        dp[i][0] = 0; //dp[i][1] = v.size() ;
        for( j = i-1 ; j >= 0 ; j-- ){
        	if ( dp[j][0]+1 >= dp[i][0]  && v[j].first.first < v[i].first.first && v[j].first.second > v[i].first.second ){
        	dp[i][0] = dp[j][0] + 1 ;
          dp[i][1] = j ; f = true ;
           }
        }
        if (!f)
        {
        	 dp[i][0] = 1 ;
        	 dp[i][1] = i ;
        } 
      //cout<<i <<" "<<dp[i][0] <<" "<<dp[i][1]<<" "<<v[dp[i][1]].second<<endl;
  }

  int ans = 0 ;
  int index ;
  for ( i = 0 ; i < v.size() ; i++ )
  if ( dp[i][0] > ans){
  	 ans = dp[i][0] ;
  	 index = i ;
  }
  vector <int> u ;
  printf("%d\n",ans);
  u.push_back ( v[index].second );
  while ( dp[index][1] != index && index >= 0){
  	  
  	    index = dp[index][1] ;
  	    u.push_back( v[index].second );
  }
  //cout<<u.size()<<endl;
  //sort ( u.begin() , u.end());
  for( i = u.size()-1 ; i >= 0 ; i-- )
  printf("%d\n" , u[i]+1);


	return 0 ;
}
