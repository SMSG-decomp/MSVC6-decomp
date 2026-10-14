c1_u8 __cdecl asm_operand_mode(c1_asm_expr *expr)

{
  byte bVar1;
  c1_symbol **ppcVar2;
  
  bVar1 = g_asm_kind_index[expr->kind & 0x1f];
  switch(bVar1) {
  case 1:
    if ((expr->base & 0xc0) == 0xc0) {
      return '\x14';
    }
    break;
  case 3:
    if (expr->sym == (c1_symbol *)0x0) {
      expr._0_1_ = 0x10;
      bVar1 = (byte)expr;
    }
    break;
  case 4:
    if (expr->index != '?') {
      return '\x06';
    }
    break;
  case 5:
    if (expr->index != '?') {
      return '\a';
    }
    break;
  case 8:
    ppcVar2 = &expr->sym;
    expr._0_1_ = bVar1;
    if ((*ppcVar2 == g_builtin_label_1) &&
       ((((g_asm_form == 0x10 || (g_asm_form == 0xf)) || (g_asm_form == 0x1b)) ||
        (g_asm_form == 0xe)))) {
      expr._0_1_ = 0xc;
    }
    bVar1 = (byte)expr;
    if ((*ppcVar2 == g_builtin_label_10) && ((g_asm_form == 6 || (g_asm_form == 0xd)))) {
      return '\v';
    }
  }
  expr._0_1_ = bVar1;
  return (byte)expr;
}

