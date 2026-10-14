void __fastcall lower_x87_binary_op(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  
  iVar5 = g_fp_lower_depth;
  pcVar1 = t->src;
  if (((pcVar1->kind == '\x01') && (pcVar1->sym->cls == '\x03')) &&
     (pcVar1->sym->def != (c2_tuple *)0x0)) {
    pcVar2 = pcVar1->next;
    if (((pcVar2->kind == '\x01') && (pcVar3 = pcVar2->sym, pcVar3->cls == '\x03')) &&
       (pcVar3->def != (c2_tuple *)0x0)) {
      pcVar4 = g_fp_lower_stack_syms[g_fp_lower_depth];
      g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
      if (pcVar4->storage == pcVar3->storage) {
        (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
        (pcVar2->u18).reg = (c2_symbol *)0x107ad15c;
        (pcVar1->u18).reg = g_reg_symbols + 0x20;
        g_fp_lower_depth = g_fp_lower_depth + -1;
        select_x87_arith_form(t,1,1);
      }
      else {
        (pcVar1->u18).reg = g_reg_symbols + 0x1f;
        pcVar1 = pcVar1->next;
        (&g_fp_lower_depth)[g_fp_lower_depth] = 0;
        g_fp_lower_depth = g_fp_lower_depth + -1;
        (pcVar1->u18).reg = (c2_symbol *)0x107ad1b0;
        select_x87_arith_form(t,0,1);
        tuple_swap_first_srcs(t);
      }
    }
    else {
      (pcVar1->u18).reg = g_reg_symbols + 0x1f;
      g_fp_lower_stack_syms[iVar5] = (c2_symbol *)0x0;
    }
  }
  else {
    pcVar1 = pcVar1->next;
    if (((pcVar1->kind == '\x01') && (pcVar1->sym->cls == '\x03')) &&
       (pcVar1->sym->def != (c2_tuple *)0x0)) {
      (pcVar1->u18).reg = (c2_symbol *)0x107ad15c;
      g_fp_lower_stack_syms[iVar5] = (c2_symbol *)0x0;
      select_x87_arith_form(t,1,0);
      tuple_swap_first_srcs(t);
    }
    else {
      emit_x87_load_operand(t);
    }
  }
  iVar5 = g_fp_lower_depth;
  pcVar1 = t->dst;
  if (pcVar1->kind == '\x01') {
    (pcVar1->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[iVar5] = pcVar1->sym;
    return;
  }
  bind_result_to_register(t,g_reg_symbols + 0x1f);
  g_fp_lower_depth = g_fp_lower_depth + -1;
  return;
}

