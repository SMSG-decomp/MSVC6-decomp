int __cdecl type_array_element_count(c1_type *type,c1_type **element)

{
  c1_type_extra *pcVar1;
  int iVar2;
  
  iVar2 = 1;
  if (type == (c1_type *)0x0) {
    return 0;
  }
  if ((type->code & 0x8f) != 0x83) {
    return 0;
  }
  do {
    pcVar1 = &type->extra;
    type = type->base;
    iVar2 = iVar2 * pcVar1->count;
  } while ((type->code & 0x8f) == 0x83);
  if (element != (c1_type **)0x0) {
    *element = type;
  }
  return iVar2;
}

