#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void TreeProcess ( );
void nLevelConstructor ( int processNumber, int nLevels, int counter );
void spaces ( int counter );

static const int mainChilds = 2; /* Stores the number of the direct childs of main process. */
static const int leftChilds = 3; /* Stores the number of left childs per level. */
static const int rightChilds = 4; /* Stores the number of rigtht childs per level. */
static int selection = 0;

int main ( ) { TreeProcess ( ); } /* End of the main. */

void TreeProcess ( ) {

  int idProcess; /* Stores the return value of fork. */
  int nLevels; /* Variable that will store the levels of the tree. */
  int processNumber;
  int counter = 0;
  int secondCounter = 0;

  if ( selection == 0 ) {
    printf ( "\n\n\t\tOPERATING SYSTEMS: TREE OF PROCESS." );
    printf ( "\n\n\tAdd the number of levels of the tree process: " );
    scanf ( "%d", &nLevels );
    selection++;
  } /* End of if. */

  for ( counter = 0 ; counter < mainChilds ; counter++ ) { /* Controls the number of main childs. */
    idProcess = fork ( );
    switch ( idProcess ) {
      case 0: /* Fork return a value = 0, if the id it's of child. */
        if ( counter == 0 ) { /* First child of main parent. */
          printf ( "\n\tFirst child of the main process: %d.", getpid ( ) ); /* Getpid returns the value of the child process. */
          printf ( "\tThe parent id is: %d.\n", getppid ( ) ); /* Getppid returns the id of the direct parent of the process. */
          counter++;
          processNumber = leftChilds;
        } else if ( counter == 1 ) { /* Second child of main process. */
          printf ( "\n\tSecond child of the main process: %d.", getpid ( ) ); /* Getpid returns the value of the child process. */
          printf ( "\tThe parent id is: %d.\n", getppid ( ) ); /* Getppid returns the id of the direct parent of the process. */
          processNumber = rightChilds;
          counter++;
        } /* End of the if - else. */
        nLevelConstructor ( processNumber, nLevels, 1 );
        exit ( 0 );
        break;
      case -1: /* Fork return a value = -1, if've been a error creating a new process. */
        printf ( "\n\tError creating a new process." );
        break;
      default: /* Fork return a value > 0, for the parent process. */
        if ( counter == 0 ) {
          printf ( "\n\tMain parent process: %d.\n", getpid ( ) ); /* Main parent process it's also a child of the shell process. */
        } /* End of if. */
        if ( counter == 1 ) {
          while ( secondCounter < 2 ) { /* Execute wait the same times of the number of child process of the parent. */
            wait ( 0 ); /* The main parent process will "wait", until his childs process finishes the execution. */
            secondCounter++;
          } /* End of the while. */
        } /* End of the if. */
        break;
        printf ( "\n" );
    } /* End of switch. */
  } /* End of the For. */

  printf ( "\n\n" );

} /* End of TreeProcess function. */

void nLevelConstructor ( int processNumber, int nLevels, intcounter ) { /* Creates the levels of the tree process. */

  int idProcess;
  int status = 0;
  int secondCounter = 0;

  for ( secondCounter = 0 ; secondCounter < processNumber ; secondCounter ++ ) { /* Controls the loop of the tree. */
    idProcess = fork ( );
    switch ( idProcess ) {
      case -1:
        printf ( "\n\tError creating new process in level: %d.\n", counter );
        exit ( -1 );
        break;
      case 0:
        printf ( "\n\tChild process id: %d.", getpid ( ) );
        printf ( "\tParent id: %d. Level: %d.", getppid ( ), counter );
        if ( nLevels > 1 ) { /* Condition for the recursive function. */
          nLevelConstructor ( processNumber, nLevels - 1, counter + 1 ); /* Recursion. */
        } /* End of the if. */
        exit ( 0 );
        break;
      default:
      if ( secondCounter == ( processNumber - 1 ) ) {
        while ( status < processNumber ) {
          wait ( NULL );
          status++;
        } /* End of the while. */
      } /* End of the if. */
      break;
    } /* End of the switch. */
  } /* End of the For. */

} /* End of nLevelConstructor function. */
