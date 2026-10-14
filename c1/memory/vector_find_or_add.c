short * __cdecl vector_find_or_add(short *set,int value)

{
  int iVar1;
  int iVar2;
  
  iVar1 = value;
  iVar2 = type_set_find(set,value,&value);
  if ((char)iVar2 == '\0') {
    if (*set == set[1]) {
      set = (short *)vector_grow_checked((c1_symbol_vector *)set);
      if ((c1_symbol_vector *)set == (c1_symbol_vector *)0x0) {
        return (short *)0x0;
      }
    }
    if (value < (short)((c1_symbol_vector *)set)->count) {
      memmove(((c1_symbol_vector *)((int)set + 8))->entries + value + -1,
              ((c1_symbol_vector *)set)->entries + value,
              (value * 0x3fffffff + (int)(short)((c1_symbol_vector *)set)->count) * 4);
    }
    ((c1_symbol_vector *)set)->entries[value] = (c1_symbol *)iVar1;
    ((c1_symbol_vector *)set)->count = ((c1_symbol_vector *)set)->count + 1;
  }
  return (short *)(c1_symbol_vector *)set;
}

