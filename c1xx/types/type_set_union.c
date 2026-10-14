short * __cdecl type_set_union(short *set,short *other)

{
  char cVar1;
  short *psVar2;
  c1_symbol_vector_iter local_c;
  
  psVar2 = other;
  if ((set != (short *)0x0) && (psVar2 = set, other != (short *)0x0)) {
    vector_iterator_init(&local_c,(c1_symbol_vector *)other);
    do {
      cVar1 = vector_iter_next((int *)&local_c);
      if (cVar1 == '\0') {
        return set;
      }
      set = vector_find_or_add(set,(int)local_c.current);
      psVar2 = (short *)0x0;
    } while (set != (short *)0x0);
  }
  return psVar2;
}

