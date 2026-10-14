int __fastcall rebuild_subtractions(c2_node *node,c2_node *t2)

{
  byte bVar1;
  c2_node *pcVar2;
  c2_node *node_00;
  c2_operand *n;
  uint32_t uVar3;
  c2_operand *pcVar4;
  c2_tuple *sub_tuple;
  c2_tuple *term;
  c2_node *next_term;
  c2_operand *earlier;
  c2_operand *minuend;
  c2_operand *earlier_term;
  
  pcVar2 = *(c2_node **)&node[1].kind;
  while (node_00 = pcVar2, node_00 != (c2_node *)0x0) {
    pcVar2 = node_00->next;
    if ((node_00->flags & 1) != 0) {
      rebuild_subtractions(node_00,node);
    }
  }
  if (node->op == 0x16d) {
    earlier = (c2_operand *)0x0;
    pcVar4 = (c2_operand *)0x0;
    next_term = (c2_node *)*(c2_operand **)&node[1].kind;
    while (earlier_term = earlier, n = (c2_operand *)next_term, minuend = pcVar4,
          n != (c2_operand *)0x0) {
      next_term = (c2_node *)n->next;
      pcVar4 = n;
      earlier = minuend;
      if ((node->op == 0x16d) &&
         (uVar3 = try_negate_in_place((c2_node *)n,(c2_tuple *)node,
                                      (uint)((node->type & 0xf000) != 0x4000)), earlier = minuend,
         uVar3 != 0)) {
        if (minuend == (c2_operand *)0x0) {
          uVar3 = ((c2_operand *)next_term)->op;
          minuend = (c2_operand *)next_term;
          while (uVar3 == 0x161) {
            minuend = minuend->next;
            if (minuend == (c2_operand *)0x0) {
              minuend = (c2_operand *)**(undefined4 **)&node[1].kind;
              break;
            }
            uVar3 = minuend->op;
          }
          tuple_detach_src(node,minuend);
          bVar1 = minuend->kind;
          minuend->next = *(c2_operand **)&node[1].kind;
          *(c2_operand **)&node[1].kind = minuend;
          if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
            minuend->flags = minuend->flags | 0x10;
          }
          next_term = (c2_node *)minuend->next->next;
        }
        if ((earlier_term == (c2_operand *)0x0) && (next_term == (c2_node *)0x0)) {
          node->op = 0x16e;
          pcVar4 = minuend;
          earlier = earlier_term;
        }
        else {
          pcVar4 = minuend->next;
          tuple_detach_src(node,pcVar4);
          sub_tuple = tuple_new_unary_temp
                                (0x16e,node->type,pcVar4,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
          tuple_unlink_mem_subops(sub_tuple);
          sub_tuple->flags12 = '\x02';
          if (earlier_term != (c2_operand *)0x0) {
            tuple_detach_src(node,minuend);
            term = tuple_new_unary_temp
                             (0x16d,node->type,minuend,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
            tuple_unlink_mem_subops(term);
            pcVar4 = *(c2_operand **)&node[1].kind;
            earlier_term->next = minuend;
            term->flags12 = '\x02';
            minuend->next = (c2_operand *)0x0;
            term->src = pcVar4;
            minuend = (c2_operand *)term;
          }
          pcVar4 = sub_tuple->src;
          sub_tuple->src = minuend;
          minuend->next = pcVar4;
          *(c2_tuple **)&node[1].kind = sub_tuple;
          sub_tuple->next = (c2_tuple *)next_term;
          earlier = (c2_operand *)0x0;
          pcVar4 = (c2_operand *)sub_tuple;
        }
      }
    }
    if (**(int **)&node[1].kind == 0) {
      pcVar4 = tuple_forward_src_and_free((c2_tuple *)node,(c2_tuple *)t2);
      return (int)pcVar4;
    }
  }
  return (int)node;
}

