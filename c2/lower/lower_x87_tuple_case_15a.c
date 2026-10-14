c2_tuple *
lower_x87_tuple_case_15a(c2_tuple *t,c2_tuple *zero,c2_operand *use_opnd,c2_tuple *result)

{
  uint16_t type;
  int iVar1;
  c2_tuple *pcVar2;
  c2_const_operand *src2;
  c2_operand *pcVar3;
  c2_insert_fn *insert_fn;
  
  iVar1 = g_fp_lower_depth;
  pcVar3 = t->src;
  if (((pcVar3->kind == '\x01') && (pcVar3->sym->cls == '\x03')) && (pcVar3->sym->def != zero)) {
    (pcVar3->u18).reg = g_reg_symbols + 0x1f;
    g_fp_lower_stack_syms[iVar1] = (c2_symbol *)zero;
  }
  else {
    emit_x87_load_operand(t);
  }
  pcVar2 = find_next_use_of_dst(t,&use_opnd);
  iVar1 = g_fp_lower_depth;
  if (pcVar2->op != 400) {
    if (((pcVar2->u24).call.conv == '\x18') && (use_opnd == pcVar2->src->next)) {
      tuple_replace_src(pcVar2,use_opnd,t->src);
      t->op = 0x145;
      g_fp_lower_depth = g_fp_lower_depth + -1;
      return result;
    }
    insert_fn = tuple_insert_before;
    pcVar2 = t;
    src2 = operand_new_intconst(0x1004,t->type & 0xfff,0);
    pcVar3 = operand_new_hardreg(5,0x1004);
    pcVar2 = tuple_new_binary_temp(0x32,0x1004,pcVar3,src2,insert_fn,pcVar2);
    type = t->type;
    use_opnd = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,pcVar2->dst,(c2_operand *)0x0,2);
    tuple_new(99,type,use_opnd,t->src,tuple_insert_after,pcVar2);
    pcVar3 = pcVar2->dst;
    (use_opnd->base->u18).reg = g_reg_symbols + 5;
    (pcVar3->u18).reg = g_reg_symbols + 5;
    g_fp_lower_depth = g_fp_lower_depth + -1;
    return result;
  }
  pcVar3 = t->src;
  t->op = 0x145;
  (pcVar3->u18).reg = g_reg_symbols + 0x1f;
  g_fp_lower_stack_syms[iVar1] = pcVar3->sym;
  use_opnd->sym = pcVar3->sym;
  return result;
}

