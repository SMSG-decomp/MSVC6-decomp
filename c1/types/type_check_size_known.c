void __cdecl type_check_size_known(c1_type *type)

{
  c1_symbol *pcVar1;
  
  if ((type->code & 0x300) != 0) {
    pcVar1 = (type->extra).sym;
    if ((pcVar1->flags2 & 1) != 0) {
      return;
    }
    if ((pcVar1->flags1 & 1) == 0) {
      if (g_opt_Zg == '\0') {
        diag_error(0x1b,pcVar1);
      }
      pcVar1->flags2 = pcVar1->flags2 | 1;
      return;
    }
  }
  diag_error(0x24,type);
  return;
}

