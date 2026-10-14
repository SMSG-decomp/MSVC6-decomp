c2_operand * __fastcall simplify_select_same_arms(c2_tuple *t,c2_tuple *parent)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_operand *b;
  int iVar3;
  c2_operand *op;
  c2_operand *pcVar4;
  
  pcVar4 = t->src;
  if (pcVar4->op == 0x17d) {
    uVar1 = (t->u20).cc;
    if (uVar1 == '\x02') {
      op = pcVar4->next;
      b = op->next;
    }
    else {
      b = pcVar4->next;
      op = b->next;
    }
    iVar3 = compare_trees((c2_node *)op,(c2_node *)b);
    if (iVar3 == 0) {
      discard_expression_tree((c2_node *)t);
LAB_1074d636:
      tuple_detach_src((c2_node *)t,op);
      if (parent != (c2_tuple *)0x0) {
        tuple_replace_src(parent,(c2_operand *)t,op);
        return op;
      }
      node_free((c2_node *)t);
      return op;
    }
    if ((uVar1 == '\x02') || (uVar1 == '\x01')) {
      pcVar4 = (pcVar4->u18).children;
      if (((1 << (pcVar4->kind & 0x1f) & 0x380U) == 0) ||
         ((pcVar4->u18).reg != (c2_symbol *)0x0 || pcVar4->tag != 0)) {
        pcVar2 = pcVar4->next;
        if ((1 << (pcVar2->kind & 0x1f) & 0x380U) == 0) {
          return (c2_operand *)0x0;
        }
        if ((pcVar2->u18).reg != (c2_symbol *)0x0 || pcVar2->tag != 0) {
          return (c2_operand *)0x0;
        }
      }
      else {
        pcVar4 = pcVar4->next;
      }
      if (((((b->kind == '\a') && ((b->u18).reg == (c2_symbol *)0x0 && b->tag == 0)) &&
           (iVar3 = compare_trees((c2_node *)pcVar4,(c2_node *)op), iVar3 == 0)) &&
          (iVar3 = tree_has_side_effect_or_mem_read((c2_node *)pcVar4), iVar3 == 0)) ||
         (((op->kind == '\a' && ((op->u18).reg == (c2_symbol *)0x0 && op->tag == 0)) &&
          ((iVar3 = compare_trees((c2_node *)pcVar4,(c2_node *)b), iVar3 == 0 &&
           (iVar3 = tree_has_side_effect_or_mem_read((c2_node *)pcVar4), iVar3 == 0))))))
      goto LAB_1074d636;
    }
  }
  return (c2_operand *)0x0;
}

