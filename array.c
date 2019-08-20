/*
** Array Opertaions In C Programming
** Authored By : Pradosh Ranjan Pattanayak
** Authored On : 19-Aug-2019 08:08 PM
** Github url : https://github.com/prpigitcse/data-structure
*/

#include "stdio.h"

/*
 * Defines Output Colors
 */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 * Defines contants
 */
#define  MAXSIZE 1000 // maxsize of array (change according to your requirement)
#define TRUE 1

/*
 * Function Prototype Definations
 */
int insert(int [], int);
int delete(int[], int);
void count(int);
void read(int[], int);
void write(int[], int);
int push(int[], int);
int pop(int[], int);
void display(int [], int);
void help();

/*
 * Implements main function
 */
int main(void) {
  int arr[MAXSIZE];
  int end = -1;
  char continueOp = 'Y';
  int op;

  help();

  while(TRUE) {
    if(continueOp == 'Y' || continueOp == 'y') {
      printf(ANSI_COLOR_YELLOW "Please enter the operation to perform: " ANSI_COLOR_RESET);
      scanf("%d", &op);
      switch (op) {
        case 1: // insert
          end = insert(arr, end);
          break;
        case 2: // delete
          end = delete(arr, end);
          break;
        case 3: // count
          count(end);
          break;
        case 4: // read
          read(arr, end);
          break;
        case 5: // write
          write(arr, end);
          break;
        case 6: // push
          end = push(arr, end);
          break;
        case 7: // pop
          end = pop(arr, end);
          break;
        case 8: // display
          display(arr, end);
          break;
        default: // help
         help();
      }
    } else {
      break;
    }

    printf(ANSI_COLOR_YELLOW "Please press (Y/y) to continue and any other key to terminate: " ANSI_COLOR_RESET);
    scanf(" %c", &continueOp); // There is space before %c to consume space due to Enter key
  }

  return 0;
}

/*
 * Implements insert operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 *
 * @return
 * position of last element after insertion
 */
int insert(int arr[], int end) {
  int pos;
  int num;

  printf(ANSI_COLOR_YELLOW "Please enter the position to insert (Min = 0, Max = %d): " ANSI_COLOR_RESET, end + 1 );
  scanf("%d", &pos);

  if(pos > end + 1) { // check max position to insert
    printf(ANSI_COLOR_RED "Maximum position to insert is %d" ANSI_COLOR_RESET "\n", end +1);
  } else if(pos < 0) { // check min position to insert
    printf(ANSI_COLOR_RED "Minimum position to insert is 0" ANSI_COLOR_RESET "\n");
  } else {
    for(int i = end; i >= pos; i--) {
      if(i + 1 >= MAXSIZE) { // check array overflow
        printf(ANSI_COLOR_RED "Array size overflowed. Please use link list implementation." ANSI_COLOR_RESET "\n");
        break;
        return end;
      }
      arr[i + 1] = arr[i]; // rewrite array
    }
    printf(ANSI_COLOR_YELLOW "Enter the number to insert: " ANSI_COLOR_RESET);
    scanf("%d", &num);
    arr[pos] = num; // inserting number at particular position
    end++; // increase the end by 1 after adding element
    display(arr, end); // display output
  }

  return end;
}

/*
 * Implements delete operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 *
 * @return
 * position of last element after insertion
 */
int delete(int arr[], int end) {
  int pos;

  if(end == -1) { // empty array check
    printf(ANSI_COLOR_RED "Empty array" ANSI_COLOR_RESET  "\n");
    return end;
  }

  printf(ANSI_COLOR_YELLOW "Please enter the position to delete (Min = 0, Max = %d): " ANSI_COLOR_RESET, end);
  scanf("%d", &pos);

  if(pos < 0) { // check min position to delete
    printf(ANSI_COLOR_RED "Minimum position to delete is 0" ANSI_COLOR_RESET  "\n");
  } else if(pos > end) { // check max position to delete
    printf(ANSI_COLOR_RED "Maxmimum position to delete is %d" ANSI_COLOR_RESET "\n", end );
  } else {
    for(int i = pos; i < end; i++) {
      arr[i] = arr[i + 1]; // rewrite array
    }
    end--; // decrease end by 1 after removing element
    display(arr, end);
  }

  return end;
}

/*
 * Implements count opertaion
 * Print number of elements in the array
 *
 * @param end
 * position of the last element
 */
void count(int end) {
  printf(ANSI_COLOR_GREEN "Number of element in the array is: %d" ANSI_COLOR_RESET "\n", end+1); // end + 1 because array index starts from 0
}

/*
 * Implements read operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 */
 void read(int arr[], int end) {
   int pos;
   int num;

   if(end == -1) { // empty array check
     printf(ANSI_COLOR_RED "Empty array" ANSI_COLOR_RESET  "\n");
   } else {
     printf(ANSI_COLOR_YELLOW "Please enter the position to read (Min = 0, Max = %d): " ANSI_COLOR_RESET, end);
     scanf("%d", &pos);

     if(pos < 0) { // check min position to delete
       printf(ANSI_COLOR_RED "Minimum position to read is 0" ANSI_COLOR_RESET "\n");
     } else if(pos > end) { // check max position to delete
       printf(ANSI_COLOR_RED "Maxmimum position to read is %d" ANSI_COLOR_RESET "\n", end);
     } else {
       printf(ANSI_COLOR_GREEN "Elements at position %d is %d" ANSI_COLOR_RESET "\n", pos, arr[pos]);
     }
   }
 }

/*
 * Implements write operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 */
 void write(int arr[], int end) {
   int pos;
   int num;

   if(end == -1) { // empty array check
     printf(ANSI_COLOR_RED "Empty array" ANSI_COLOR_RESET  "\n");
   } else {
     printf(ANSI_COLOR_YELLOW "Please enter the position to write (Min = 0, Max = %d): " ANSI_COLOR_RESET, end);
     scanf("%d", &pos);

     if(pos < 0) { // check min position to delete
       printf(ANSI_COLOR_RED "Minimum position to write is 0" ANSI_COLOR_RESET "\n");
     } else if(pos > end) { // check max position to delete
       printf(ANSI_COLOR_RED "Maxmimum position to write is %d" ANSI_COLOR_RESET "\n", end);
     } else {
       printf(ANSI_COLOR_YELLOW "Enter the number to replace: " ANSI_COLOR_RESET);
       scanf("%d", &num);
       arr[pos] = num; // write in the position
       display(arr, end);
     }
   }
 }

 /*
  * Implements push operation
  *
  * @param arr
  * array of elements
  *
  * @param end
  * position of the last element
  *
  * @return
  * position of last element after push
  */
int push(int arr[], int end) {
 int num;

 if(end >= MAXSIZE - 1) {
   printf(ANSI_COLOR_RED "Array Maximum Size Reached" ANSI_COLOR_RESET "\n");
 } else {
   printf(ANSI_COLOR_YELLOW "Enter the number to push: " ANSI_COLOR_RESET);
   scanf("%d", &num);
   arr[end+1] = num; // insert number at the end
   end++; // increase the end by 1 after adding element
   display(arr, end);
 }

 return end;
}

/*
 * Implements pop operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 *
 * @return
 * position of last element after pop operation
 */
 int pop(int arr[], int end) {
   if(end == -1) { // check empty array
     printf(ANSI_COLOR_RED "Empty array" ANSI_COLOR_RESET "\n");
   } else {
     printf(ANSI_COLOR_GREEN "Last element: %d" ANSI_COLOR_RESET "\n", arr[end]); //print last element
     end--; // decrease the end by 1 after removing element
     display(arr, end);
   }

   return end;
 }

/*
 * Implements display operation
 *
 * @param arr
 * array of elements
 *
 * @param end
 * position of the last element
 */
void display(int arr[], int end) {
  printf(ANSI_COLOR_GREEN "Output: [");
  for(int i = 0; i <= end; i++) {
    if(i != end) {
      printf("%d, ", arr[i]); // check not to add comma(',') at last element
    }
    else {
      printf("%d", arr[i]);
    }
  }
  printf(ANSI_COLOR_GREEN "]" ANSI_COLOR_RESET "\n");
}

/*
 * Implements help opertaion
 */
void help() {
  printf(ANSI_COLOR_YELLOW "Enter your choice of opertaion:\n"
  "[1]. insert\n"
  "[2]. delete\n"
  "[3]. count\n"
  "[4]. read\n"
  "[5]. write\n"
  "[6]. push\n"
  "[7]. pop\n"
  "[8]. display\n"
  "[9]. help"
  ANSI_COLOR_RESET "\n");
}
