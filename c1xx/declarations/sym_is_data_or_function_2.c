int __fastcall sym_is_data_or_function_2(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
    return 0;
  }
  return 1;
}

