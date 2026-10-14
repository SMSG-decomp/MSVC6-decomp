c2_tuple * __fastcall
narrow_operator_through_conversion(c2_tuple *parent,c2_tuple *t,uint32_t type,c2_tuple *user)

{
  uint16_t type_00;
  c2_operand *pcVar1;
  c2_tuple *conv;
  c2_symbol *sym;
  c2_symbol *pcVar2;
  uint16_t type_01;
  
  type_00 = t->type;
  type_01 = (uint16_t)type;
  if (type_01 == t->src->type) {
    tuple_forward_src_and_free(t,parent);
  }
  else {
    pcVar1 = t->dst;
    t->type = type_01;
    symbol_free_chain(pcVar1->sym);
    sym = symbol_new_temp(type_01);
    pcVar2 = sym->storage;
    pcVar1->sym = sym;
    pcVar1->type = type_01;
    if (pcVar2->part_next == (c2_symbol *)0x0) {
      sym->def = t;
      simplify_conversion_chain(t,parent);
    }
    else {
      symbol_mark_overlapping_parts(sym,t);
      simplify_conversion_chain(t,parent);
    }
  }
  parent->type = type_01;
  if (parent->op != 0x17d) {
    pcVar1 = parent->dst;
    pcVar2 = symbol_get_part(pcVar1->sym,type_01,type & 0xfff,0);
    pcVar1->sym = pcVar2;
    if ((pcVar1->kind == '\x01') && (pcVar2->def != (c2_tuple *)0x0)) {
      (pcVar1->u18).reg = pcVar2;
    }
    pcVar1->type = type_01;
  }
  if (user != (c2_tuple *)0x0) {
    type = (uint32_t)list_find_prev((c2_link *)user->src,(c2_link *)parent);
    tuple_detach_src((c2_node *)user,(c2_operand *)parent);
  }
  pcVar1 = operand_new_temp(type_00);
  conv = tuple_new_unary_temp(0x15f,type_00,pcVar1,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  tuple_replace_src(conv,conv->src,(c2_operand *)parent);
  conv->flags12 = '\x02';
  if (user != (c2_tuple *)0x0) {
    if (type == 0) {
      pcVar1 = user->src;
      user->src = (c2_operand *)conv;
      conv->next = (c2_tuple *)pcVar1;
    }
    else {
      tuple_insert_src_after(user,(c2_operand *)type,(c2_operand *)conv);
    }
  }
  tuple_unlink_mem_subops(conv);
  conv->flags12 = '\x02';
  g_simplify_changed = 1;
  return conv;
}

