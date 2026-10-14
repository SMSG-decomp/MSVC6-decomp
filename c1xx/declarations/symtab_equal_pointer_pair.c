int __cdecl symtab_equal_pointer_pair(int *a,int *b)

{
  if ((*a == *b) && (a[1] == b[1])) {
    return 1;
  }
  return 0;
}

