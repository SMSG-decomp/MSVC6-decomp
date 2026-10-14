char __cdecl ovl_conversion_types_next(c1_conversion_type_iter *iter)

{
  c1_symbol *item;
  char cVar1;
  c1_u8 cVar2;
  
  if (iter->types != (void *)0x0) {
    cVar1 = vector_iter_next((int *)&iter->functions);
    if (cVar1 != '\0') {
      item = (iter->functions).current;
      iter->type = (c1_type *)item;
      cVar2 = vector_contains_type(iter->types,item);
      iter->seen = cVar2;
      return '\x01';
    }
  }
  return '\0';
}

