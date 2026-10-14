void __cdecl
init_check_string_initializer
          (char type_code_lo,c1_type *sym_type,c1_type *array_type,c1_symbol *sym,c1_node *value)

{
  char cVar1;
  bool bVar2;
  
  if (((value->op == '\a') && (type_code_lo < '\0')) && (-1 < (char)array_type->base->code)) {
    if (((uint)value->right & 0x10000) == 0) {
      cVar1 = (char)sym_type->code;
      while (cVar1 < '\0') {
        sym_type = sym_type->base;
        cVar1 = (char)sym_type->code;
      }
      bVar2 = sym_type->code == 0x2012;
    }
    else {
      cVar1 = (char)sym_type->code;
      while (cVar1 < '\0') {
        sym_type = sym_type->base;
        cVar1 = (char)sym_type->code;
      }
      bVar2 = (sym_type->code & 0xfff) == 0x11;
    }
    if (bVar2) {
      diag_error(0x35,sym);
      return;
    }
  }
  diag_error(0x4b,sym);
  return;
}

