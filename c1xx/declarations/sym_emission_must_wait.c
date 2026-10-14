char __cdecl sym_emission_must_wait(c1_symbol *sym)

{
  byte bVar1;
  char cVar2;
  c1_type *pcVar3;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 4) || (bVar1 == 5)) {
    if (((sym->flags2 & 8) != 0) && ((sym->flags3 & 2) == 0)) {
      return '\x01';
    }
    return '\0';
  }
  if ((bVar1 == 10) && ((sym->storage & 7) == 7)) {
    pcVar3 = sym->type;
    cVar2 = (char)pcVar3->code;
    while (cVar2 < '\0') {
      pcVar3 = pcVar3->base;
      cVar2 = (char)pcVar3->code;
    }
    if (((pcVar3->code & 0x300) != 0) ||
       (((bVar1 = (byte)pcVar3->code, (char)bVar1 < '\0' && ((bVar1 & 0x8f) == 0x80)) &&
        (pcVar3 = pcVar3->base, (pcVar3->code & 0x300) != 0)))) {
      if ((sym->flags3 & 2) != 0) {
        return '\0';
      }
      cVar2 = sym_emission_must_wait((pcVar3->extra).cls);
      if (cVar2 == '\0') {
        return '\0';
      }
      return '\x01';
    }
  }
  return '\0';
}

