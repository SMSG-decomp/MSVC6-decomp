c2_tuple * __fastcall lower_switch_chain(c2_tuple *t)

{
  uint16_t uVar1;
  c2_switch_case *pcVar2;
  c2_operand *dst;
  c2_tuple *pcVar3;
  uint32_t lo;
  c2_const_operand *pcVar4;
  code *insert_fn_00;
  int local_4;
  c2_insert_fn *insert_fn;
  c2_tuple *target;
  
  uVar1 = t->type;
  local_4 = 0;
  dst = operand_new_temp_sym(uVar1);
  pcVar3 = tuple_new(1,uVar1,dst,t->src,tuple_insert_after,t);
  for (pcVar2 = (t->u24).cases; pcVar2 != (c2_switch_case *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->next == (c2_switch_case *)0x0) && ((t->switch_flags & 2) != 0)) goto LAB_1074ef4c;
    uVar1 = t->type;
    lo = pcVar2->lo - local_4;
    insert_fn = tuple_insert_after;
    pcVar4 = operand_new_intconst(uVar1,lo,(int)lo >> 0x1f);
    pcVar3 = tuple_new_binary(0x32,uVar1,dst,dst,pcVar4,insert_fn,pcVar3);
    insert_fn_00 = tuple_insert_after;
    pcVar4 = operand_new_intconst(uVar1,0,0);
    pcVar3 = tuple_new_compare(0x17d,uVar1,dst,pcVar4,insert_fn_00,pcVar3);
    pcVar3 = tuple_new_branch(0x185,'\x01',(c2_node *)pcVar2->label,pcVar3->dst,pcVar3,
                              tuple_insert_after,pcVar3);
    local_4 = pcVar2->lo;
  }
  if ((t->switch_flags & 2) == 0) {
    target = (t->u20).default_label;
  }
  else {
LAB_1074ef4c:
    target = pcVar2->label;
  }
  tuple_new_branch(0x186,'\0',(c2_node *)target,(c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after
                   ,pcVar3);
  pcVar3 = t->next;
  switch_free(t);
  return pcVar3;
}

