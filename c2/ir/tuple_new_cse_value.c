c2_tuple * __fastcall
tuple_new_cse_value(uint32_t op,uint16_t type,c2_operand *src,c2_insert_fn *insert_fn,
                   c2_tuple *anchor)

{
  byte bVar1;
  c2_operand *node;
  c2_tuple *t;
  
  node = operand_new_cse_sym(op,type,src,(c2_operand *)0x0);
  link_expression_operands(node->sym);
  t = (c2_tuple *)node_alloc('\f');
  bVar1 = node->kind;
  t->type = type;
  t->op = op;
  t->flags = t->flags | 1;
  if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
    if ((node->flags & 0x10) != 0) {
      node = (c2_operand *)node_clone((c2_node *)node);
    }
    node->flags = node->flags | 0x10;
  }
  t->dst = node;
  if ((1 << (src->kind & 0x1f) & 0xffeU) != 0) {
    if ((src->flags & 0x10) != 0) {
      src = (c2_operand *)node_clone((c2_node *)src);
    }
    src->flags = src->flags | 0x10;
  }
  t->src = src;
  tuple_link_mem_subops(t);
  if (insert_fn == (c2_insert_fn *)0x0) {
    t->line = g_cur_line;
    return t;
  }
  (*insert_fn)(anchor,t);
  t->line = g_cur_line;
  return t;
}

