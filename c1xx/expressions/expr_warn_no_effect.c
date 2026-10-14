c1_node * __cdecl expr_warn_no_effect(c1_node *expr,char statement)

{
  byte bVar1;
  c1_u16 cVar2;
  int n;
  
  if (expr == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if ((expr->kind & 8) != 0) {
    return expr;
  }
  cVar2 = expr->type->code;
  if ((cVar2 == 0x80c) || (cVar2 == 0x80e)) {
    n = 0x227;
  }
  else {
    if (expr->type->code != 0x4086) goto LAB_1040e603;
    n = 0x226;
  }
  diag_warning(1,n);
LAB_1040e603:
  if (statement != '\0') {
    bVar1 = expr->op;
    if (((g_op_flags_table[bVar1] & 2) != 0) && ((expr->flags & 2) == 0)) {
      if (bVar1 == 0x3b) {
        diag_warning(1,0x229,0x3b,0x34);
        return expr;
      }
      diag_warning(1,0x228,(uint)bVar1);
    }
  }
  return expr;
}

