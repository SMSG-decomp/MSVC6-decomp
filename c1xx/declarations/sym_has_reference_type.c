int __cdecl sym_has_reference_type(c1_symbol *sym)

{
  byte bVar1;
  
  if (sym == (c1_symbol *)0x0) {
    return 0;
  }
  bVar1 = (byte)sym->type->code;
  if (((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x80)) {
    return 1;
  }
  return 0;
}

