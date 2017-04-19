#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isDigi(char);
int toInt(char*);
int isOperator(char);
int computeValue ( int, int, char);
void main()
{
   char str[100],ch;
   char nn[10] ;
   int vv[2] ;

   int i=0,k=0,b=0,h1=0, h2 = 0 ;
   printf("Enter the string: ");
   scanf("%s",str);
   k=strlen(str);
   int nnIndx = 0 ;
   int vvIndx = 0 ;
   char oper = 'A', poper = 'A' ;

   for(i=0;i<=k;i++)
   {

      if ( i == k ) {

         nn[nnIndx] = 0;
         vv[vvIndx++] = toInt ( nn ) ;
         printf ("\nGot Value: %s => %d", nn, vv[vvIndx-1] ) ; 
         nnIndx = 0 ;
         vv[0] = computeValue ( vv[0], vv[1], oper ) ;
         continue ;
      }

      ch=str[i];

      if(isDigi(ch)) nn[nnIndx++] = ch ;

      if ( isOperator ( ch ) ) {
         poper = oper ;
         oper = ch ;

         nn[nnIndx] = 0;
         vv[vvIndx++] = toInt ( nn ) ;
         printf ("\nGot Value: %s => %d", nn, vv[vvIndx-1] ) ; 
         nnIndx = 0 ;
         if ( vvIndx == 2 ) {
            vv[0] = computeValue ( vv[0], vv[1], poper ) ; 
            vvIndx = 1 ; 
         }      
      }

   }

   printf ("\nExpr '%s' = %d\n\n", str, vv[0] ) ;
   
}


int isDigi(char ch)
{
   if(ch>='0' && ch<='9')
   {
        return 1;
   }

   return 0;
   
}
int toInt(char *ch)
{
   int n = 0 ;
   int l = strlen ( ch ) ;
   
   for ( int i = 0 ; i < l ; i++ ) {
      n = n*10 + ch[i] - '0' ;
   }

   return n ;
   
}

int isOperator(char ch)
{
   if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
   {
   	return 1;
   }

   return 0 ;
}

int computeValue ( int n1, int n2, char oper ) {

   switch ( oper ) {

      case '+':  return (n1 + n2) ; break ;
      case '-':  return (n1 - n2) ; break ;
      case '*':  return (n1 * n2) ; break ;
      case '/':  return (n1 / n2) ; break ;
      default : return 0 ; 

   }

}
