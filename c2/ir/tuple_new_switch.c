c2_tuple * __fastcall
tuple_new_switch(uint32_t op,uint16_t type,c2_operand *selector,c2_tuple *default_label,
                c2_switch_case *cases,c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\x13');
  t->op = op;
  t->type = type;
  t->flags = t->flags | 1;
  (t->u20).default_label = default_label;
  (t->u24).cases = cases;
  if (default_label != (c2_tuple *)0x0) {
    label_add_ref(default_label,(c2_node *)t);
  }
  if (selector != (c2_operand *)0x0) {
    if ((1 << (selector->kind & 0x1f) & 0xffeU) != 0) {
      if ((selector->flags & 0x10) != 0) {
        selector = (c2_operand *)node_clone((c2_node *)selector);
      }
      selector->flags = selector->flags | 0x10;
    }
    t->src = selector;
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

