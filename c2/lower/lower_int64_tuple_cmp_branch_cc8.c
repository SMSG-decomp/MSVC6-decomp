c2_tuple *
lower_int64_tuple_cmp_branch_cc8
          (c2_tuple *branch,c2_operand *cond,c2_tuple *cmp,uint8_t lo_cc,c2_tuple *result,
          c2_operand *flags_opnd)

{
  c2_symbol *pcVar1;
  c2_tuple *anchor;
  c2_operand *cond_00;
  c2_fe_symbol *label_sym;
  c2_tuple *t;
  
  anchor = tuple_new_branch(0x185,'\b',*(c2_node **)((int)&branch->src->sym->u30 + 2),cond,cmp,
                            tuple_insert_after,cmp);
  cond_00 = operand_new_hardreg(0x42,0x8000);
  label_sym = label_symbol_new();
  t = tuple_new_label(label_sym);
  tuple_new_branch(0x185,'\a',(c2_node *)t,cond_00,cmp,tuple_insert_after,anchor);
  tuple_insert_after(branch,t);
  if ((((cmp != (c2_tuple *)0x0) && (cmp->dst->kind == '\x01')) &&
      (pcVar1 = cmp->dst->sym, pcVar1->cls == '\x03')) && (pcVar1->def != (c2_tuple *)0x0)) {
    pcVar1->def = cmp;
  }
  return result;
}

