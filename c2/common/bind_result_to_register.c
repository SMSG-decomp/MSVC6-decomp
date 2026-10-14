void __fastcall bind_result_to_register(c2_tuple *t,c2_symbol *sym)

{
  uint16_t type;
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *anchor;
  c2_operand *pcVar4;
  c2_operand *new_op;
  uint32_t op;
  c2_symbol *target_reg;
  c2_tuple *reader;
  bind_result_to_register_replace_fn_fn *replace_fn;
  
  pcVar3 = t->dst;
  target_reg = sym;
  if (((pcVar3->kind != '\x01') || (pcVar3->sym->cls != '\x03')) ||
     (pcVar3->sym->def == (c2_tuple *)0x0)) {
    type = pcVar3->type;
    pcVar4 = operand_new_temp(type);
    if ((t->type & 0xf000) == 0x4000) {
      (pcVar4->u18).reg = g_reg_symbols + 0x1f;
      op = 99;
    }
    else {
      op = 1;
    }
    pcVar2 = tuple_new(op,type,pcVar3,pcVar4,tuple_insert_after,t);
    pcVar3 = pcVar2->dst;
    tuple_replace_dst(t,t->dst,pcVar4);
    if (((((1 << (pcVar3->kind & 0x1f) & 0x60U) != 0) &&
         (pcVar3 = pcVar3->base, pcVar3->kind == '\x01')) &&
        ((pcVar1 = pcVar3->sym, pcVar1->cls == '\x03' &&
         ((pcVar1->def != (c2_tuple *)0x0 && (((pcVar3->u18).reg)->storage != pcVar1->storage))))))
       && (pcVar3 = find_dst_clobbering_reg(t,(pcVar3->u18).reg), pcVar3 != (c2_operand *)0x0)) {
      tuple_append_dst(pcVar2,pcVar3);
      pcVar3->sym->def = pcVar2;
      tuple_remove_dst(t,pcVar3);
    }
    pcVar4->sym->def = t;
  }
  pcVar3 = t->dst;
  if (target_reg != g_reg_symbols) {
    if (((pcVar3->type & 0xfff) < 4) && (target_reg->offset == 0)) {
      target_reg = reg_find_subreg(g_reg_symbols + target_reg->id,(pcVar3->type & 0xfff) << 3,0);
    }
    if ((pcVar3->u18).reg != target_reg) {
      (pcVar3->u18).reg = target_reg;
    }
  }
  if ((t->type & 0xf000) != 0x4000) {
    pcVar2 = tuple_new_unary_temp(1,pcVar3->type,pcVar3,tuple_insert_after,t);
    pcVar4 = (c2_operand *)reader;
    if ((t->dst->type & 0xfff) == 8) {
      pcVar4 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
      tuple_append_dst(t,pcVar4);
      if (((t->dst->kind == '\x01') && (pcVar1 = t->dst->sym, pcVar1->cls == '\x03')) &&
         (pcVar1->def != (c2_tuple *)0x0)) {
        pcVar4->sym->def = t;
      }
    }
    pcVar3 = find_next_reader_of(pcVar2->next,pcVar3,&reader);
    if (((pcVar2->type & 0xfff) == 8) && ((pcVar3->type & 0xfff) < 8)) {
      anchor = (c2_tuple *)node_clone((c2_node *)pcVar2);
      pcVar4 = find_next_reader_of(pcVar2->next,pcVar4,(c2_tuple **)&target_reg);
      replace_fn = tuple_replace_src;
      new_op = split_int64_operand_half(anchor,anchor->dst,(c2_operand *)0x0,(c2_operand *)0x0);
      try_substitute_operand((c2_tuple *)target_reg,pcVar4,new_op,(c2_replace_fn *)replace_fn);
      node_free((c2_node *)anchor);
    }
    try_substitute_operand(reader,pcVar3,pcVar2->dst,tuple_replace_src);
  }
  return;
}

