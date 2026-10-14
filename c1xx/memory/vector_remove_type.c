short * __cdecl vector_remove_type(short *set,c1_type *type)

{
  int iVar1;
  int next_index;
  
  iVar1 = type_set_find(set,(int)type,(int *)&type);
  if ((char)iVar1 != '\0') {
    next_index = (int)&type->code + 1;
    if (next_index < *set) {
      memmove(set + next_index * 2,set + (int)type * 2 + 4,(next_index * 0x3fffffff + (int)*set) * 4
             );
    }
    *set = *set + -1;
  }
  return set;
}

