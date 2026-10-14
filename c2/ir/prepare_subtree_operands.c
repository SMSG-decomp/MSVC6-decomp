void __fastcall prepare_subtree_operands(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  uint uVar4;
  uint32_t uVar5;
  c2_tuple *t_00;
  
  pcVar1 = t->src;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      tuple_unlink(t);
      for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((1 << (pcVar1->kind & 0x1f) & 0x60U) != 0) {
          pcVar1->flags11 = pcVar1->flags11 | 0x20;
        }
      }
      pcVar1 = t->src;
      pcVar2 = (c2_operand *)0x0;
      while (pcVar3 = pcVar2, pcVar2 = pcVar1, pcVar2 != (c2_operand *)0x0) {
        pcVar1 = pcVar2->next;
        uVar4 = 1 << (pcVar2->kind & 0x1f);
        if ((uVar4 & 0x60) != 0) {
          pcVar2->flags11 = pcVar2->flags11 | 0x20;
        }
        if (((uVar4 & 0xffe) != 0) && ((pcVar2->flags & 0x20) != 0)) {
          pcVar3->next = pcVar1;
          pcVar2->next = (c2_operand *)0x0;
          pcVar2 = pcVar3;
        }
      }
      return;
    }
    if ((pcVar1->flags & 0x20) == 0) {
      uVar4 = 1 << (pcVar1->kind & 0x1f);
      if (((uVar4 & 6) == 0) || (t_00 = pcVar1->sym->def, t_00 == (c2_tuple *)0x0)) {
        if (((((uVar4 & 0x60) != 0) &&
             ((pcVar2 = pcVar1->base, pcVar2 == (c2_operand *)0x0 ||
              (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0))))))
            && ((pcVar3 = pcVar1->index, pcVar3 == (c2_operand *)0x0 ||
                (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 && (pcVar3->sym->def != (c2_tuple *)0x0))))
               )) && (pcVar2 != pcVar3)) {
          t_00 = pcVar2->sym->def;
          goto LAB_107078f8;
        }
      }
      else {
        uVar5 = decide_tree_substitution(t_00,pcVar1);
        if (uVar5 == 0) {
          prepare_subtree_operands(t_00);
        }
        else {
LAB_107078f8:
          prepare_and_simplify_tree(t_00);
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

