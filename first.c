#include <stdio.h>

int
main ()
{

  int a = -100;
  int b = 0;
  int c = 300;
  printf ("%d, %d, %d\n", a, b, c);

  float d = 3.14;
  float e = 37.0;
  printf ("%.2f, %.1f\n", d, e);

  char f = 'a';
  char g = '@';
  printf ("%c, %c\n", f, g);


  //==============================================================
  printf ("==============================================================\n");
  char aa = 'a';
  printf ("char: %d    %c\n", sizeof (aa), aa);
  unsigned char bb = 'a';
  printf ("unsigned char: %d   %c\n", sizeof (bb), bb);
  int cc = 1;
  printf ("int: %d    %d\n", sizeof (cc), cc);
  short dd = 1;
  printf ("short: %d   %d\n", sizeof (dd), dd);
  long ee = 1;
  printf ("long: %d   %d\n", sizeof (ee), ee);
  unsigned short us = 1;
  printf ("u short: %d   %d\n", sizeof (us), us);
  unsigned int ui = 1;
  printf ("u int: %d   %d\n", sizeof (ui), ui);
  unsigned long ul = 12;
  printf ("u long: %d   %d\n", sizeof (ul), ul);

  //==============================================================
  printf ("==============================================================\n");
  int A = 9;
  int B = 7;
  printf ("%d\n", A + B);
  printf ("%d\n", A - B);
  printf ("%d\n", A * B);
  printf ("%d\n", A / B);
  printf ("%d\n", A % B);

  printf ("%d\n", A++);
  printf ("%d\n", ++A);
  printf ("%d\n", B--);
  printf ("%d\n", --B);

  printf ("A += B : %d\n", A += B);
  printf ("%d\n", A -= B);
  printf ("%d\n", A *= B);
  printf ("%d\n", A /= B);
  printf ("%d\n", A %= B);
 
  printf("A && B : %d\n", 1&&0);
  printf("A || B : %d\n", 1||0);
 
  printf("A & B : %d\n", 101 & 110);
  printf("A | B :  %d\n", 100 | 110);
  printf("%d %d\n",A,B);
  printf("~A : %d\n", ~A);
  printf("A^B : %d\n", A^B);
  printf("A<<B : %d\n", A<<B);
  printf("A>>B : %d\n", A>>B);



  return 0;
}