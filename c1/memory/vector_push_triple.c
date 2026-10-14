void __thiscall vector_push_triple(int *v,int a,int b,int c)

{
  int *piVar1;
  
  piVar1 = vector_push_12(v);
  *piVar1 = a;
  piVar1[1] = b;
  piVar1[2] = c;
  return;
}

