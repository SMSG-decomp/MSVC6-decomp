short * __cdecl vector_find_or_add(short *set,int value)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  iVar1 = value;
  iVar2 = type_set_find(set,value,&value);
  if ((char)iVar2 == '\0') {
    if (*set == set[1]) {
      set = vector_grow_checked((c1_symbol_vector *)set);
      if (set == (short *)0x0) {
        psVar3 = vector_find_or_add_return_fragment((short *)0x0);
        return psVar3;
      }
    }
    if (value < *set) {
      memmove(set + value * 2 + 4,set + value * 2 + 2,(value * 0x3fffffff + (int)*set) * 4);
    }
    *(int *)(set + value * 2 + 2) = iVar1;
    *set = *set + 1;
  }
  return set;
}

