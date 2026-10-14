void __fastcall x87_insert_fxch_pair(c2_tuple *t,int a,int b)

{
  if (a != b) {
    x87_insert_fxch(t,a);
    x87_insert_fxch(t,b);
  }
  return;
}

