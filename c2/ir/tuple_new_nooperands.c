c2_tuple * __fastcall
tuple_new_nooperands(uint32_t op,uint16_t type,c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\f');
  t->type = type;
  t->flags = t->flags | 1;
  t->op = op;
  t->dst = (c2_operand *)0x0;
  t->src = (c2_operand *)0x0;
  tuple_link_mem_subops(t);
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
    t->line = g_cur_line;
    return t;
  }
  t->line = g_cur_line;
  return t;
}

