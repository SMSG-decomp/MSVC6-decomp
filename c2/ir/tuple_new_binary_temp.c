c2_tuple * __fastcall
tuple_new_binary_temp
          (uint32_t op,uint16_t type,c2_operand *src1,c2_operand *src2,c2_insert_fn *insert_fn,
          c2_tuple *anchor)

{
  byte bVar1;
  c2_symbol *pcVar2;
  c2_operand *node;
  c2_tuple *t;
  c2_operand *pcVar3;
  
  node = operand_new_temp(type);
  t = (c2_tuple *)node_alloc('\f');
  bVar1 = node->kind;
  t->op = op;
  t->type = type;
  t->flags = t->flags | 1;
  pcVar3 = node;
  if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
    if ((node->flags & 0x10) == 0) {
      node->flags = node->flags | 0x10;
    }
    else {
      pcVar3 = (c2_operand *)node_clone((c2_node *)node);
      pcVar3->flags = pcVar3->flags | 0x10;
    }
  }
  t->dst = pcVar3;
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
  if (insert_fn != (c2_insert_fn *)0x0) {
    (*insert_fn)(anchor,t);
  }
  pcVar2 = node->sym;
  t->line = g_cur_line;
  pcVar2->def = t;
  return t;
}

