int __cdecl sym_is_member_function_via_alias(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = sym->kind & 0x1f;
  if (bVar1 == 8) {
    return 1;
  }
  if ((bVar1 == 0x1a) &&
     (iVar2 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar2 != '\0')) {
    return 1;
  }
  return 0;
}

