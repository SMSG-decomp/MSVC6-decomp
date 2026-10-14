int __cdecl sym_is_static_data_member(c1_symbol *sym)

{
  byte bVar1;
  
  if ((sym != (c1_symbol *)0x0) &&
     (((bVar1 = sym->kind & 0x1f, bVar1 == 2 || (bVar1 == 3)) && ((sym->storage & 7) == 3)))) {
    return 1;
  }
  return 0;
}

