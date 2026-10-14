c2_tuple * __fastcall
tuple_new_binary(uint32_t op,uint16_t type,c2_operand *dst,c2_operand *src1,c2_operand *src2,
                c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\f');
  t->op = op;
  t->type = type;
  t->flags = t->flags | 1;
  if ((1 << (dst->kind & 0x1f) & 0xffeU) != 0) {
    if ((dst->flags & 0x10) != 0) {
      dst = (c2_operand *)node_clone((c2_node *)dst);
    }
    dst->flags = dst->flags | 0x10;
  }
  t->dst = dst;
  if ((1 << (src1->kind & 0x1f) & 0xffeU) != 0) {
    if ((src1->flags & 0x10) != 0) {
      src1 = (c2_operand *)node_clone((c2_node *)src1);
    }
    src1->flags = src1->flags | 0x10;
  }
  t->src = src1;
  if ((1 << (src2->kind & 0x1f) & 0xffeU) != 0) {
    if ((src2->flags & 0x10) != 0) {
      src2 = (c2_operand *)node_clone((c2_node *)src2);
    }
    src2->flags = src2->flags | 0x10;
  }
  src1->next = src2;
  tuple_link_mem_subops(t);
  if (insert_fn == (c2_insert_fn *)0x0) {
    t->line = g_cur_line;
    return t;
  }
  (*insert_fn)(anchor,t);
  t->line = g_cur_line;
  return t;
}

