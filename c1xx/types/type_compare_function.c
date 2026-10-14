char __thiscall type_compare_function(c1_type *a,c1_type *b,uint flags)

{
  char cVar1;
  c1_type *a_00;
  c1_type *b_00;
  
  if (a == b) {
    return '\x01';
  }
  if ((((byte)b->flags ^ (byte)a->flags) & 7) == 0) {
    cVar1 = type_compare_function_types((a->extra).params,(b->extra).params,flags);
    if (cVar1 != '\0') {
      a_00 = type_function_return(a);
      b_00 = type_function_return(b);
      cVar1 = type_compare(a_00,b_00,flags & 0xfffffffd);
      return cVar1;
    }
    return '\0';
  }
  return '\0';
}

