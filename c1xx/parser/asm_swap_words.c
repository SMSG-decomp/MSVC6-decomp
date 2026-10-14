void __cdecl asm_swap_words(int *a,int *b)

{
  int iVar1;
  
  iVar1 = *a;
  *a = *b;
  *b = iVar1;
  return;
}

