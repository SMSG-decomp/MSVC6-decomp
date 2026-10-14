c2_tuple * __fastcall prepare_and_simplify_tree(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *use;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  
  switch(t->kind) {
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
    t->flags12 = '\x01';
    break;
  default:
    decide_tree_substitution(t,(c2_operand *)0x0);
  }
  if (t->flags12 != '\x01') {
    prepare_subtree_operands(t);
    pcVar1 = t->dst;
    while (use = pcVar1, use != (c2_operand *)0x0) {
      pcVar1 = use->next;
      if (((((1 << (use->kind & 0x1f) & 0x60U) != 0) &&
           ((pcVar4 = use->base, pcVar4 == (c2_operand *)0x0 ||
            (((1 << (pcVar4->kind & 0x1f) & 6U) != 0 && (pcVar4->sym->def != (c2_tuple *)0x0))))))
          && ((pcVar2 = use->index, pcVar2 == (c2_operand *)0x0 ||
              (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0))))))
         && ((pcVar4 != pcVar2 &&
             ((pcVar3 = prepare_and_simplify_tree(pcVar4->sym->def), pcVar3->op == 0x15b &&
              (pcVar4 = propagate_copy_into_use(use,(c2_tuple *)0x0), pcVar4 != use)))))) {
        tuple_replace_dst(t,use,pcVar4);
      }
    }
    pcVar3 = simplify_expression_tree(t);
    return pcVar3;
  }
  tuple_unlink(t);
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
       (pcVar3 = pcVar1->sym->def, pcVar3 != (c2_tuple *)0x0)) {
      prepare_and_simplify_tree(pcVar3);
    }
  }
  tuple_unlink_mem_subops(t);
  return t;
}

