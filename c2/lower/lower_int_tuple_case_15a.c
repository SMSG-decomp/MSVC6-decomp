void lower_int_tuple_case_15a(c2_tuple *t)

{
  c2_operand *new_op;
  c2_operand *pcVar1;
  
  pcVar1 = t->dst;
  if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->cls == '\x01')) {
    return;
  }
  new_op = operand_new_hardreg(5,0x1004);
  tuple_replace_dst(t,pcVar1,new_op);
  pcVar1 = operand_new_hardreg(5,0x1004);
  tuple_append_src(t,pcVar1);
  return;
}

