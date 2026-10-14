int __fastcall sym_is_member_function_or_class_alias(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 != 0x11) && (bVar1 != 8)) {
    return 0;
  }
  return 1;
}

