int __fastcall select_operands_allow_sbb(c2_operand *a,c2_operand *b)

{
  if (a->kind == 7) {
    if (b->kind != 7) {
      if (((g_opt_favor_speed != 0) && ((1 << (b->kind & 0x1f) & 6U) != 0)) &&
         (b->sym->def != (c2_tuple *)0x0)) {
        return 0;
      }
      return (uint)((a->u18).reg == (c2_symbol *)0x0);
    }
  }
  else {
    if (((g_opt_favor_speed != 0) && ((1 << (a->kind & 0x1f) & 6U) != 0)) &&
       (a->sym->def != (c2_tuple *)0x0)) {
      return 0;
    }
    if ((b->kind != '\a') || ((b->u18).reg != (c2_symbol *)0x0)) {
      return 0;
    }
  }
  return 1;
}

