int __cdecl symtab_equal_4_words(int *a,int *b)

{
  if ((((*a == *b) && (a[1] == b[1])) && (a[2] == b[2])) && (a[3] == b[3])) {
    return 1;
  }
  return 0;
}

