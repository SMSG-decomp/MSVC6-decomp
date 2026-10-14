c2_tuple * __fastcall
tuple_new_call(uint32_t op,uint16_t type,c2_operand *dst,c2_operand *callee,uint8_t call_conv,
              c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  byte bVar1;
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\x0e');
  bVar1 = t->flags;
  (t->u24).call.conv = call_conv;
  t->op = op;
  t->flags = bVar1 | 1;
  t->type = type;
  if (dst != (c2_operand *)0x0) {
    if ((1 << (dst->kind & 0x1f) & 0xffeU) != 0) {
      if ((dst->flags & 0x10) != 0) {
        dst = (c2_operand *)node_clone((c2_node *)dst);
      }
      dst->flags = dst->flags | 0x10;
    }
    t->dst = dst;
  }
  if ((1 << (callee->kind & 0x1f) & 0xffeU) != 0) {
    if ((callee->flags & 0x10) != 0) {
      callee = (c2_operand *)node_clone((c2_node *)callee);
    }
    callee->flags = callee->flags | 0x10;
  }
  t->src = callee;
  tuple_link_mem_subops(t);
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
    t->line = g_cur_line;
    return t;
  }
  t->line = g_cur_line;
  return t;
}

