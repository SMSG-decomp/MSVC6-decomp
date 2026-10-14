c2_tuple * __fastcall
reader_new_call_tuple
          (uint32_t op,uint16_t type,c2_operand *fn,uint8_t flag,c2_insert_fn *insert_fn,
          c2_tuple *anchor)

{
  c2_symbol *pcVar1;
  c2_operand *node;
  c2_tuple *t;
  c2_operand *pcVar2;
  
  node = operand_new_temp(type);
  t = (c2_tuple *)node_alloc('\x0e');
  t->op = op;
  t->type = type;
  t->flags = t->flags | 1;
  (t->u24).call.conv = flag;
  if (node != (c2_operand *)0x0) {
    pcVar2 = node;
    if ((1 << (node->kind & 0x1f) & 0xffeU) != 0) {
      if ((node->flags & 0x10) == 0) {
        node->flags = node->flags | 0x10;
      }
      else {
        pcVar2 = (c2_operand *)node_clone((c2_node *)node);
        pcVar2->flags = pcVar2->flags | 0x10;
      }
    }
    t->dst = pcVar2;
  }
  if ((1 << (fn->kind & 0x1f) & 0xffeU) != 0) {
    if ((fn->flags & 0x10) != 0) {
      fn = (c2_operand *)node_clone((c2_node *)fn);
    }
    fn->flags = fn->flags | 0x10;
  }
  t->src = fn;
  tuple_link_mem_subops(t);
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
  }
  pcVar1 = node->sym;
  t->line = g_cur_line;
  pcVar1->def = t;
  return t;
}

