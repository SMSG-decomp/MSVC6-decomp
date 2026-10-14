uint32_t __fastcall
distribute_constant_over_op(c2_tuple **node_slot,uint32_t inner_op,c2_tuple *parent)

{
  uint16_t type;
  uint32_t op;
  c2_operand *const_copy;
  c2_operand *term;
  c2_operand *const_opnd;
  c2_operand *src1;
  bool bVar1;
  c2_insert_fn *insert_fn;
  c2_tuple *pcVar2;
  c2_tuple *inner;
  c2_operand *child;
  c2_operand *next_term;
  
  const_opnd = (c2_operand *)0x0;
  child = (*node_slot)->src;
  if (child != (c2_operand *)0x0) {
    do {
      if (child->op != inner_op) {
        if ((1 << (child->kind & 0x1f) & 0x380U) == 0) {
          return 0;
        }
        bVar1 = const_opnd != (c2_operand *)0x0;
        const_opnd = child;
        if (bVar1) {
          return 0;
        }
      }
      child = child->next;
    } while (child != (c2_operand *)0x0);
    if (const_opnd != (c2_operand *)0x0) {
      pcVar2 = *node_slot;
      tuple_detach_src((c2_node *)pcVar2,const_opnd);
      inner = (c2_tuple *)pcVar2->src;
      src1 = inner->src;
      inner->src = (c2_operand *)0x0;
      if (src1 != (c2_operand *)0x0) {
        type = pcVar2->type;
        op = pcVar2->op;
        do {
          next_term = src1->next;
          if ((1 << (src1->kind & 0x1f) & 0xffeU) != 0) {
            src1->flags = src1->flags & 0xef;
          }
          pcVar2 = (c2_tuple *)0x0;
          insert_fn = (c2_insert_fn *)0x0;
          src1->next = (c2_operand *)0x0;
          const_copy = (c2_operand *)node_clone((c2_node *)const_opnd);
          term = (c2_operand *)tuple_new_binary_temp(op,type,src1,const_copy,insert_fn,pcVar2);
          *(undefined1 *)&term->x12 = 2;
          tuple_append_src(inner,term);
          pcVar2 = simplify_node_algebraic((c2_tuple *)term,inner);
          fold_constant_operands(pcVar2,inner);
          src1 = next_term;
        } while (next_term != (c2_operand *)0x0);
      }
      node_free((c2_node *)const_opnd);
      g_simplify_changed = 1;
      pcVar2 = simplify_node_algebraic(*node_slot,parent);
      *node_slot = pcVar2;
      return 1;
    }
  }
  return 0;
}

