// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

// function to get valid unsigned integer input
unsigned int getValidInput( void )
{
   unsigned int choice;
   int result;
   int c;
   
   while ( 1 ) {
      result = scanf( "%u", &choice );
      
      // check if input was valid
      if ( result == 1 ) {
         // consume newline from input buffer
         while ( ( c = getchar() ) != '\n' && c != EOF );
         return choice;
      }
      else {
         // clear invalid input from buffer
         while ( ( c = getchar() ) != '\n' && c != EOF );
         printf( "Invalid input! \n Please enter an integer: " );
      }
   }
}

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int id; // ID number
   char name[50]; // name

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );
   //  choice = getValidInput();

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter ID Name: " );
            scanf( "%d %s", &id, name );
            getchar(); // consume newline
            /* printf( "%s", "Enter name: " );
            fgets( name, sizeof(name), stdin );
            name[strcspn(name, "\n")] = 0; // remove newline */
            insert( &startPtr, id, name ); // insert item in list
            printList( startPtr );
            printListR( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter ID to be deleted: " );
               scanf( "%d", &id );

               // if ID is found, remove it
               if ( deletes( &startPtr, id ) ) { // remove item
                  printf( "%d deleted.\n", id );
                  printList( startPtr );
                  printListR( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", id );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
       scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
   clearList( &startPtr );
   puts( "End of run." );
   return 0;
} // end main
