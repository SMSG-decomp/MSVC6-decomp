c2_tuple * __fastcall
tuple_new_intrinsic(uint32_t op,uint16_t type,c2_operand *dst,c2_operand *a,c2_operand *b,
                   c2_operand *c,c2_operand *d,uint16_t id,c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  byte bVar1;
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\x12');
  bVar1 = t->flags;
  (t->u20).intrinsic.id = id;
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
  if (a != (c2_operand *)0x0) {
    if ((1 << (a->kind & 0x1f) & 0xffeU) != 0) {
      if ((a->flags & 0x10) != 0) {
        a = (c2_operand *)node_clone((c2_node *)a);
      }
      a->flags = a->flags | 0x10;
    }
    t->src = a;
  }
  if (b != (c2_operand *)0x0) {
    if ((1 << (b->kind & 0x1f) & 0xffeU) != 0) {
      if ((b->flags & 0x10) != 0) {
        b = (c2_operand *)node_clone((c2_node *)b);
      }
      b->flags = b->flags | 0x10;
    }
    t->src->next = b;
  }
  if (c != (c2_operand *)0x0) {
    if ((1 << (c->kind & 0x1f) & 0xffeU) != 0) {
      if ((c->flags & 0x10) != 0) {
        c = (c2_operand *)node_clone((c2_node *)c);
      }
      c->flags = c->flags | 0x10;
    }
    t->src->next->next = c;
  }
  if (d != (c2_operand *)0x0) {
    if ((1 << (d->kind & 0x1f) & 0xffeU) != 0) {
      if ((d->flags & 0x10) != 0) {
        d = (c2_operand *)node_clone((c2_node *)d);
      }
      d->flags = d->flags | 0x10;
    }
    t->src->next->next->next = d;
  }
  tuple_link_mem_subops(t);
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
    t->line = g_cur_line;
    return t;
  }
  t->line = g_cur_line;
  return t;
}

