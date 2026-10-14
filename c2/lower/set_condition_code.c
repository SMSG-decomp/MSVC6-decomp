void __fastcall set_condition_code(c2_tuple *t,uint8_t cc)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  
  uVar1 = x86_fixed_reg_class(t);
  if (cc != uVar1) {
    pcVar2 = find_src_overlapping_reg(t,g_reg_symbols + 0x42);
    if ((t->op != 0) && (t->op < 0x144)) {
      (pcVar2->u18).reg = g_reg_symbols + g_flags_subreg_by_cc[g_cond_to_x86_cc[cc]];
    }
    if (t->kind != '\x10') {
      if (t->kind == '\x11') {
        *(uint8_t *)&t->type = cc;
        return;
      }
      t->op = g_setcc_opcode_by_cc[g_cond_to_x86_cc[cc]];
      return;
    }
    (t->u20).cc = cc;
  }
  return;
}

