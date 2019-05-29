#include <stdio.h>
#include <stdlib.h>
int main( int argv, char * argc[ ] ) {
   int num = atoi( argc[ 1 ] );
   int i;
   FILE *p;
   FILE *play;
   FILE *g;
   int pos, sal, touch, total, day, day1, day2, r, a, tick, t1, t2, j = 1;
   char *name[ 5 ];
   char *t_name[ 5 ];
   char *stad[ 5 ];
   char *post[ 3 ];
   char *res[ 3 ];
   post[ 0 ] = "QB";
   post[ 1 ] = "RB";
   post[ 2 ] = "WR";
   p = fopen( "Players.txt", "w" );
   play = fopen( "Play.txt", "w" );
   g = fopen( "Games.txt", "w" );
   name[ 0 ] = "Carson";
   name[ 1 ] = "Dak";
   name[ 2 ] = "Todd";
   name[ 3 ] = "Odell";
   name[ 4 ] = "Antonio"; 
   t_name[ 0 ] = "Eagles";
   t_name[ 1 ] = "Cowboys";
   t_name[ 2 ]= "Rams";
   t_name[ 3 ] = "Giants";
   t_name[ 4 ] = "Steelers";
   stad[ 1 ] = "AT&T Stadium";
   stad[ 0 ] = "Lincoln Financial Field";
   stad[ 3 ] = "Metlife Stadium";
   stad[ 2 ] = "LA Memorial Coliseum";
   stad[ 4 ] = "Heinz Field";
   res[ 0 ] = "W";
   res[ 1 ] = "L";
   res[ 2 ] = "T"; 
   for( i = 1; i <= num; i++ ){
      pos = ( rand( ) % 3 ) + 1;
      sal = ( rand( ) % 1000000 ) + 100000;
      touch = rand( ) % 10;
      total = rand( ) % 5000;
      fprintf( p, "\'%s\', %d, \'%s\', \'%s\', %d, %d, %d\n", name[ i % 5 ], i, t_name[ i % 5 ], post[ i % 3 ], touch, total, sal );
   }
   for( i = 1; i <= num; i++ ){
      day = ( rand( ) % 3 ) + 2016 ;
      day1 = ( rand( ) % 5 ) + 8;
      day2 = ( rand( ) % 30 ) + 1;
      r = rand( ) % 2;
      a = rand( ) % 100000 + 50000;
      tick = a * 100;
      fprintf( g, "%d, \'%d-%d-%d\', \'%s\', \'%s\', %d, %d\n", i, day, day1, day2, stad[ i % 5 ], res[ r ], a, tick );
   }
   for( i = 1; i<=num/2; i++ ){
      fprintf( play, "%d, %d\n", j, i );
      j++;
      fprintf( play, "%d, %d\n", j, i );
      j++;
   }
}
