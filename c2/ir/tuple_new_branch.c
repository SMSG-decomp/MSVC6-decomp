c2_tuple * __fastcall
tuple_new_branch(uint32_t op,uint8_t cc,c2_node *target,c2_operand *cond,c2_tuple *cond_def,
                c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  uint8_t uVar1;
  c2_tuple *t;
  
  t = (c2_tuple *)node_alloc('\x11');
  uVar1 = target->kind;
  t->flags = t->flags | 1;
  t->op = op;
  *(uint8_t *)&t->type = cc;
  if (uVar1 == '\x1a') {
    label_add_ref((c2_tuple *)target,(c2_node *)t);
    target = (c2_node *)operand_new_labelref((c2_tuple *)target,0);
  }
  if ((1 << (((c2_operand *)target)->kind & 0x1f) & 0xffeU) != 0) {
    if ((((c2_operand *)target)->flags & 0x10) != 0) {
      target = node_clone(target);
    }
    ((c2_operand *)target)->flags = ((c2_operand *)target)->flags | 0x10;
  }
  t->src = (c2_operand *)target;
  if (cond != (c2_operand *)0x0) {
    if ((1 << (cond->kind & 0x1f) & 0xffeU) != 0) {
      if ((cond->flags & 0x10) != 0) {
        cond = (c2_operand *)node_clone((c2_node *)cond);
      }
      cond->flags = cond->flags | 0x10;
    }
    ((c2_operand *)target)->next = cond;
    tuple_push_cell20((c2_node *)t,(uint32_t)cond_def);
  }
  if ((0x186 < op) && (op < 0x18d)) {
    t->flags = t->flags | 8;
  }
  tuple_link_mem_subops(t);
  if (insert_fn == (c2_insert_fn *)0x0) {
    t->line = g_cur_line;
    return t;
  }
  (*insert_fn)(anchor,t);
  t->line = g_cur_line;
  return t;
}

