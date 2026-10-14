void __fastcall factor_emit_combined(c2_tuple *t,c2_node *a,c2_node *b,int op,int inner)

{
  uint16_t type;
  c2_operand *t_00;
  c2_operand *a_00;
  c2_operand *b_00;
  c2_tuple *t_01;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  factor_combine_dispatch(a,b,op);
  tuple_detach_src((c2_node *)t,(c2_operand *)a);
  tuple_detach_src((c2_node *)t,(c2_operand *)b);
  factor_replace_with_combined(a,(c2_tuple *)t_00,op,inner);
  factor_replace_with_combined(b,(c2_tuple *)t_00,op,inner);
  type = t->type;
  if (t->op == 0x17d) {
    t_01 = tuple_new_compare(0x17d,type,a_00,b_00,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  }
  else {
    t_01 = tuple_new_binary_temp(t->op,type,a_00,b_00,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  }
  tuple_unlink_mem_subops(t_01);
  t_01->flags12 = '\x02';
  pcVar1 = (c2_operand *)fold_constant_operands(t_01,(c2_tuple *)0x0);
  if ((op == 0x171) || (pcVar2 = t_00, op == 0x177)) {
    pcVar2 = pcVar1;
    pcVar1 = t_00;
  }
  pcVar2 = (c2_operand *)
           tuple_new_binary_temp(op,type,pcVar2,pcVar1,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  tuple_unlink_mem_subops((c2_tuple *)pcVar2);
  pcVar1 = t->src;
  *(uint8_t *)&pcVar2->x12 = '\x02';
  pcVar2->next = pcVar1;
  t->src = pcVar2;
  return;
}

