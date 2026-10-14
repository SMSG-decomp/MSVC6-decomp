c1_symbol * __cdecl sym_class_type_of(c1_symbol *sym)

{
  c1_type *pcVar1;
  
  pcVar1 = sym->type;
  if ((char)pcVar1->code < '\0') {
    if ((sym->flags2 & 0x80) == 0) {
      return (c1_symbol *)0x0;
    }
    do {
      pcVar1 = pcVar1->base;
    } while ((char)pcVar1->code < '\0');
  }
  if ((pcVar1->code & 0x200) != 0) {
    return (pcVar1->extra).cls;
  }
  return (c1_symbol *)0x0;
}

