void __fastcall emit_x87_load_operand(c2_tuple *t)

{
  c2_symbol *a;
  c2_operand *pcVar1;
  int iVar2;
  uint32_t op;
  
  if ((g_opt_favor_speed == 0) && (pcVar1 = t->src, pcVar1->kind == '\t')) {
    a = pcVar1->sym;
    iVar2 = float_const_compare_mask(1,(c2_float_const *)a,&g_ld_const_zero);
    if (iVar2 != 0) {
      op = 0x7f;
      goto LAB_1075d3c3;
    }
    iVar2 = float_const_compare_mask(1,(c2_float_const *)a,&g_ld_const_one);
    if (iVar2 != 0) {
      op = 0x94;
      goto LAB_1075d3c3;
    }
  }
  else {
    pcVar1 = t->src;
  }
  op = 0x60;
LAB_1075d3c3:
  pcVar1 = emit_load_into_register(op,t,pcVar1,g_reg_symbols + 0x1f);
  if (g_fp_lower_depth == 7) {
    x87_spill_stack_entries(t->prev,1,0);
  }
  if (t->prev->dst->kind == '\x01') {
    g_fp_lower_depth = g_fp_lower_depth + 1;
    (pcVar1->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[g_fp_lower_depth] = pcVar1->sym;
  }
  else {
    bind_result_to_register(t->prev,g_reg_symbols + 0x1f);
  }
  tuple_replace_src(t,t->src,pcVar1);
  g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)0x0;
  return;
}

