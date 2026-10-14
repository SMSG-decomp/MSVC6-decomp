c1_u8 __cdecl scope_symbol_emits_late(c1_symbol *sym)

{
  char cVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_type *pcVar4;
  
  bVar2 = sym->kind & 0x1f;
  if ((bVar2 == 4) || (bVar2 == 5)) {
    if (((sym->flags1 & 2) != 0) && ((sym->flags1 & 0x80) == 0)) {
      return '\x01';
    }
    return '\0';
  }
  if ((bVar2 == 10) && ((sym->storage & 7) == 7)) {
    pcVar4 = sym->type;
    cVar1 = (char)pcVar4->code;
    while (cVar1 < '\0') {
      pcVar4 = pcVar4->base;
      cVar1 = (char)pcVar4->code;
    }
    if (((pcVar4->code & 0x300) != 0) ||
       (((bVar2 = (byte)pcVar4->code, (char)bVar2 < '\0' && ((bVar2 & 0x8f) == 0x80)) &&
        (pcVar4 = pcVar4->base, (pcVar4->code & 0x300) != 0)))) {
      if ((sym->flags1 & 0x80) != 0) {
        return '\0';
      }
      cVar3 = scope_symbol_emits_late((pcVar4->extra).sym);
      if (cVar3 == '\0') {
        return '\0';
      }
      return '\x01';
    }
  }
  return '\0';
}

