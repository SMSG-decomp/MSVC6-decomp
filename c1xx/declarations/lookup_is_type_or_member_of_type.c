char __cdecl lookup_is_type_or_member_of_type(c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  
  bVar3 = sym->kind & 0x1f;
  if ((bVar3 == 4) || (bVar3 == 0x19)) {
    return '\x01';
  }
  pcVar2 = sym->type;
  if (pcVar2 == (c1_type *)0x0) {
    return '\0';
  }
  if ((sym->flags2 & 0x10) != 0) {
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    if ((pcVar2->code & 0x100) != 0) {
      return '\x01';
    }
  }
  return '\0';
}

