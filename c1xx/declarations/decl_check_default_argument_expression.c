char __cdecl decl_check_default_argument_expression(c1_symbol *sym)

{
  byte bVar1;
  byte bVar2;
  
  if (((((g_compile_flags_cc & 0x10) != 0) &&
       (((g_symbol_scope_level != 0xfa || ((sym->flags5 & 0x40) == 0)) &&
        (bVar2 = sym->kind & 0x1f, bVar2 != 0x10)))) &&
      ((((bVar2 != 7 && (bVar2 != 6)) && (bVar2 != 0x11)) && ((bVar2 != 8 && (bVar2 != 0x1b)))))) &&
     ((bVar2 != 0x1a ||
      (((((bVar1 = **(byte **)sym->type & 0x1f, bVar1 != 0x10 && (bVar1 != 7)) && (bVar1 != 6)) &&
        ((bVar1 != 0x11 && (bVar1 != 8)))) && (bVar1 != 0x1b)))))) {
    if ((bVar2 == 2) || (bVar2 == 3)) {
      diag_error(0x288,sym);
      return '\0';
    }
    if (((((g_compile_flags_cc & 0x100000) == 0) && (bVar2 != 0x17)) &&
        (bVar2 = sym->storage & 7, 3 < bVar2)) && (bVar2 < 7)) {
      diag_error(0x24b,sym);
      return '\0';
    }
  }
  return '\x01';
}

