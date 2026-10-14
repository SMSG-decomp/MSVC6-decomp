int __cdecl sym_is_kind_6_7_through_alias(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 6)) {
    return 1;
  }
  if ((bVar1 == 0x1a) &&
     (iVar2 = sym_is_kind_6_7_through_alias(*(c1_symbol **)sym->type), (char)iVar2 != '\0')) {
    return 1;
  }
  return 0;
}

