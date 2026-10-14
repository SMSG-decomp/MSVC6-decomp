c2_tuple * __fastcall lower_int64_shift_intrinsic(uint32_t op,c2_tuple *t)

{
  uint16_t type;
  c2_tuple *t_00;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *src2;
  c2_operand *dst;
  c2_operand *dst_00;
  c2_tuple *pcVar3;
  ushort type_00;
  
  pcVar2 = t->dst;
  if (((pcVar2->kind != '\x01') || (pcVar2->sym->cls != '\x03')) ||
     (pcVar2->sym->def == (c2_tuple *)0x0)) {
    type = pcVar2->type;
    pcVar1 = operand_new_temp(type);
    tuple_new(0x15b,type,pcVar2,pcVar1,tuple_insert_after,t);
    tuple_replace_dst(t,pcVar2,pcVar1);
    pcVar1->sym->def = t;
  }
  if (t->kind == '\x12') {
    pcVar2 = t->src;
    pcVar3 = pcVar2->sym->def;
    t_00 = pcVar2->next->sym->def;
    pcVar1 = t_00->src;
    pcVar2 = tuple_replace_src(t,pcVar2,pcVar3->src);
    pcVar1 = tuple_replace_src(t,t->src->next,pcVar1);
    tuple_unlink_free(pcVar3);
    tuple_unlink_free(t_00);
  }
  else {
    pcVar2 = t->src;
    pcVar1 = pcVar2->next;
  }
  if (((pcVar2->kind != '\x01') || (pcVar2->sym->cls != '\x03')) ||
     (pcVar2->sym->def == (c2_tuple *)0x0)) {
    pcVar2 = load_operand_into_register(t,pcVar2,g_reg_symbols);
  }
  type_00 = pcVar2->type & 0xf004 | 4;
  src2 = split_int64_operand_half(t,pcVar2,(c2_operand *)0x0,(c2_operand *)0x0);
  dst = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
  dst_00 = (c2_operand *)node_clone((c2_node *)t->dst);
  if (pcVar1->kind != '\a') {
    pcVar1 = load_operand_into_register(t,pcVar1,g_reg_symbols + 2);
  }
  if (op == 0x2a) {
    pcVar3 = tuple_new_binary(0xca,type_00,dst,src2,pcVar2,tuple_insert_before,t);
    dst->sym->def = pcVar3;
    tuple_append_src(pcVar3,pcVar1);
    retie_register_chain(pcVar3->src,pcVar3->dst);
    pcVar2 = bind_value_to_new_temp(pcVar3,pcVar2->sym,1);
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
      pcVar1 = bind_value_to_new_temp(pcVar3,pcVar1->sym,1);
    }
    op = 0x2a;
    dst = dst_00;
  }
  else {
    pcVar3 = tuple_new_binary(0xcb,type_00,dst_00,pcVar2,src2,tuple_insert_before,t);
    dst_00->sym->def = pcVar3;
    tuple_append_src(pcVar3,pcVar1);
    retie_register_chain(pcVar3->src,pcVar3->dst);
    pcVar2 = bind_value_to_new_temp(pcVar3,src2->sym,1);
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
      pcVar1 = bind_value_to_new_temp(pcVar3,pcVar1->sym,1);
    }
  }
  pcVar3 = tuple_new_binary(op,type_00,dst,pcVar2,pcVar1,tuple_insert_before,t);
  pcVar2 = pcVar3->dst;
  pcVar1 = pcVar3->src;
  pcVar2->sym->def = pcVar3;
  retie_register_chain(pcVar1,pcVar2);
  return pcVar3;
}

