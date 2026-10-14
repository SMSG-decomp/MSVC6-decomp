int __fastcall sym_kind_is_alias_or_using(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 0x10) && (bVar1 != 0x11)) && (bVar1 != 0x1b)) {
    return 0;
  }
  return 1;
}

