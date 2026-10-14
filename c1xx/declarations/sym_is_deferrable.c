char __cdecl sym_is_deferrable(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 0xb) && ((sym->flags3 & 8) == 0)) && ((bVar1 == 0 || (3 < bVar1)))) {
    return '\x01';
  }
  return '\0';
}

