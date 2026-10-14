int __cdecl tmpl_parameters_equal(int a,int b)

{
  if ((*(int *)(a + 8) == *(int *)(b + 8)) && (*(int *)(a + 0x14) == *(int *)(b + 0x14))) {
    return 1;
  }
  return 0;
}

