int __cdecl symtab_equal_vcall_key(int a,int b)

{
  if ((*(int *)(a + 4) == *(int *)(b + 4)) && (*(short *)(a + 8) == *(short *)(b + 8))) {
    return 1;
  }
  return 0;
}

