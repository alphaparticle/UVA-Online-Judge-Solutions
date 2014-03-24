//ak92thelooser
// Naive Approach

#include <bits/stdc++.h>
using namespace std ;

char words [105] [300];
char rules [1005] [300];
int n , m ; 
int cont [1005] ;
int arr [1005] ;



int main(){

int i , j, k ;
while  ( scanf("%d",&n) == 1){
       getchar() ;
      
      for ( i = 0 ; i < n ; i++)
      gets( words[i] );

      scanf("%d",&m);
      getchar() ;
      for( i = 0 ; i < m ; i++){
           gets( rules[i] );
      }
      printf("--\n");
      for ( i  = 0 ; i < m ; i++){
      	  cont[i] = 0 ;
      	  for( j =0 ; j < strlen( rules[i] ) ; j++ )
      	  if ( rules[i][j] == '0' ){
      	  	cont[i]++;
      	  }
      }

      for ( i = 0 ; i < n ; i++ ){
      	   for ( j = 0 ; j < m ; j++)
      	   {
      	   	  // memset ( arr , 0 , sizeof arr );
      	   	   for ( k = 0 ; k < (int)pow(10,cont[j]) ; k++)
                {   int temp = k ;
                    int divi = cont[j]-1 ;
                   //cout << temp <<" " ; puts(rules[j]) ;cout << endl;
                    for (int l = 0 ; l < strlen(rules[j]) ; l++){
                    if ( rules[j][l] == '#')
                    printf("%s",words[i]);
                    else if ( rules [j][l] == '0'){
                       printf("%d",temp/(int)pow(10,divi)) ;
                       temp %= (int)pow(10,divi) ; divi -- ;
                   }
                }
                
                 printf("\n");
              } 
      	   }
      }

}

	return 0 ;
}
