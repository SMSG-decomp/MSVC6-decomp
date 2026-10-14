int __fastcall sym_kind_is_declared_entity(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 0) && (bVar1 < 0xf)) && (bVar1 != 5)) {
    return 1;
  }
  return 0;
}

