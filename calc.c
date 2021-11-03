#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define PLUS +
#define MINUS -
#define MULTIPLY *
#define DIVIDE /
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9

int errors(int x){
  switch(x){
  //  int y;
    case 1:
            printf("\n Error: not enough operands");
            return -1;
    case 2:
            printf("\n Error: too many elements");
            return -1;
    case 3:
            printf("\n Error: not an operator");
            return -1;
    case 4:
            printf("\n Error: not an operand");
            return -1;
    case 5:
            printf("\n Error: divide by zero");
            return -1;
  }
}
double convertInt(char *opers){
  if(strcmp(opers, "zero") == 0){
    return 0;
  }
  else if(strcmp(opers, "one") == 0){
    return 1;
  }
  else if(strcmp(opers, "two") == 0){
    return 2;
  }
  else if(strcmp(opers, "three") == 0){
    return 3;
  }
  else if(strcmp(opers, "four") == 0){
    return 4;
  }
  else if(strcmp(opers, "five") == 0){
    return 5;
  }
  else if(strcmp(opers, "six") == 0){
    return 6;
  }
  else if(strcmp(opers, "seven") == 0){
    return 7;
  }
  else if(strcmp(opers, "eight") == 0){
    return 8;
  }
  else if(strcmp(opers, "nine") == 0){
    return 9;
  }
  else{
    return -1;
  }
}

int operation(int ops, double a, double b){
  switch(ops){
    float answer;
    case 1: //add
            answer = a PLUS b;
            printf("\n%2.2lf", answer);
            break;
    case 2: //subtract
            answer = a MINUS b;
            printf("\n%2.2lf", answer);
            break;
    case 3: //multiply
            answer = a MULTIPLY b;
            printf("\n%2.2lf", answer);
            break;
    case 4: //divide
            if(b == 0){
            errors(5);
            }
            else{
              answer = a DIVIDE b;
              printf("\n%2.2lf", answer);
            }

  }
  return 0;
}

int main(int argc, char *argv[]){
  if(argc > 4){
      errors(2);
  }
  else if(argc < 4){
      errors(1);
  }
  double num1;
  double num2;
  num1 = convertInt(argv[2]);
  num2 = convertInt(argv[3]);
  if(num1 == -1){
    printf("\n Error: not an operand: %s", argv[2]);
    return -1;
  }
  else if(num2 == -1){
    printf("\n Error: not an operand: %s", argv[3]);
    return -1;
    }
  if (strncmp(argv[1], "plus", strlen(argv[1])) == 0) {
    operation(1, num1, num2);
  }
   else if (strncmp(argv[1], "minus", strlen(argv[1])) == 0) {
    operation(2, num1, num2);
  }
  else if (strncmp(argv[1], "multiply", strlen(argv[1])) == 0) {
    operation(3, num1, num2);
  }
  else if (strncmp(argv[1], "divide", strlen(argv[1])) == 0) {
    operation(4, num1, num2);
  }
  else{
      printf("\n Error: not an operator: %s", argv[1]);
  }

}
