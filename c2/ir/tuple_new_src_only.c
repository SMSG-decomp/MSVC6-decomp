c2_tuple * __fastcall
tuple_new_src_only(uint32_t op,uint16_t type,c2_operand *src,c2_insert_fn *insert_fn,
                  c2_tuple *anchor)

{
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\f');
  t->op = op;
  t->type = type;
  t->flags = t->flags | 1;
  t->dst = (c2_operand *)0x0;
  if ((1 << (src->kind & 0x1f) & 0xffeU) != 0) {
    if ((src->flags & 0x10) != 0) {
      src = (c2_operand *)node_clone((c2_node *)src);
    }
    src->flags = src->flags | 0x10;
  }
  t->src = src;
  tuple_link_mem_subops(t);
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
    t->line = g_cur_line;
    return t;
  }
  t->line = g_cur_line;
  return t;
}

