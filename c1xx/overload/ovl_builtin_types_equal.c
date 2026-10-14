char __cdecl ovl_builtin_types_equal(c1_type *t,c1_type *type)

{
  byte bVar1;
  c1_symbol *pcVar2;
  char cVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  
  if (t == type) {
    return '\x01';
  }
  bVar1 = type_derivations_equal(t,type);
  if (bVar1 != 0) {
    cVar3 = (char)t->code;
    while (cVar3 < '\0') {
      t = t->base;
      cVar3 = (char)t->code;
    }
    cVar3 = (char)type->code;
    while (cVar3 < '\0') {
      type = type->base;
      cVar3 = (char)type->code;
    }
    if (t->code == type->code) {
      cVar3 = (char)t->code;
      pcVar4 = t;
      while (cVar3 < '\0') {
        pcVar4 = pcVar4->base;
        cVar3 = (char)pcVar4->code;
      }
      if ((pcVar4->code & 0x300) == 0) {
        pcVar2 = (c1_symbol *)0x0;
      }
      else {
        pcVar2 = (pcVar4->extra).cls;
      }
      pcVar4 = type;
      if ((type->code >> 7 & 1) != 0) {
        do {
          pcVar4 = pcVar4->base;
        } while ((char)pcVar4->code < '\0');
      }
      if ((pcVar4->code & 0x300) == 0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = (pcVar4->extra).cls;
      }
      if (pcVar2 == pcVar5) {
        return '\x01' - (((type->flags ^ t->flags) & 0xfff8) != 0);
      }
    }
  }
  return '\0';
}

