/* PR middle-end/57541 */
/* { dg-do compile } */
/* { dg-options "-fcilkplus" } */

int A[10];

void foo () {
  /* C compiler uses the term "undeclared" whereas C++ compiler uses
    "not declared".  Thus, grepping for declared seem to be the easiest.  */
  char c = (char)N; /* { dg-error "declared" } */
  /* { dg-message "note: each" "defined" { target c } .-1 } */
  short s = (short)N;
  long l = (long)N;
  A[l:s:c];
}

void foo1 (int N) {
  char c = (char)N;
  short s = (short)N;
  A[l:s:c]; /* { dg-error "declared" } */
}
