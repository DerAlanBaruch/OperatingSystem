#include "Library.h"

int main ( ) {

	int *argument;
	int answer;
	int counter;
	int secondCounter;

	answer = Menu ( );

	argument = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Reserve a space of memory of an integer. */
	Parameters.inputMatrix = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) ); /* Reserve memory space of a bidimentional pointer array. */
	matrixProduct = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) ); /* Reserve memory space of a bidimentional pointer array. */

	for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
		Parameters.inputMatrix [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Access to the input array and reserve memory for an integer. */
		matrixProduct [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Access to the input array and reserve memory for an integer. */
		argument [ counter ] = counter;
	} /* End of for. */
	
	ConstructMatrix ( answer );

	pthread_t Thread [ Parameters.size ];

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Create the threads to use. */
  	pthread_create ( &Thread [ counter ], NULL, ( void * ) ThreadProduct, ( void * ) &argument [ counter ] );
  } /* End of the for. */

	printf ( "\n\tResulting matrix: " );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Wait for each thread to finish. */
  	pthread_join ( Thread [ counter ], NULL );
   	for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) { /* Print the resulting matrinx. */
    	printf ( "\t%d\t", matrixProduct [ counter ] [ secondCounter ] );
    } /* End of nested for. */
    printf ( "\n\t\t\t" );
  } /* End of for. */

	printf ( "\n" );

} /* End of the main. */
