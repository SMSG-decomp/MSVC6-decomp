int __fastcall remove_redundant_branches_once(c2_function *fn)

{
  c2_tuple *label;
  c2_operand *pcVar1;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_block *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_tuple *pcVar7;
  int iVar8;
  int iVar9;
  
  iVar5 = 0;
  pcVar2 = fn->cfg->first->next;
  do {
    pcVar4 = pcVar2;
    if (pcVar4 == (c2_block *)0x0) {
      return iVar5;
    }
    pcVar2 = pcVar4->next;
    iVar9 = 0;
    pcVar3 = pcVar4->head->next;
    if (pcVar3->kind == '\x1a') {
      uVar6 = label_is_removable(pcVar3);
      if ((uVar6 != 0) || (iVar8 = label_try_remove(pcVar3), iVar8 == 0)) {
        if (((pcVar3->dst == (c2_operand *)0x0) ||
            ((((pcVar7 = tuple_next_real(pcVar3), pcVar7 == (c2_tuple *)0x0 ||
               (pcVar7->kind != '\x11')) || ((pcVar7->u20).cond_cells != (c2_cond_cell *)0x0)) ||
             ((pcVar7->op == 0x18b || (pcVar7->src->kind != '\x04')))))) ||
           ((label = *(c2_tuple **)((int)&pcVar7->src->sym->u30 + 2), label == (c2_tuple *)0x0 ||
            ((label == pcVar3 || ((pcVar7->flags & 8) != 0)))))) goto LAB_10719a10;
        for (pcVar1 = pcVar3->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if ((*(byte *)(pcVar1->rank + 9) & 8) != 0) goto LAB_10719a10;
        }
        label_redirect_and_delete(pcVar3,label);
      }
      iVar9 = 1;
    }
LAB_10719a10:
    pcVar3 = pcVar4->end->prev;
    if ((pcVar3->kind == '\x11') &&
       (((((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar3->op != 0x18b)) &&
         (iVar8 = delete_unreachable_after(fn,pcVar3), iVar8 != 0)) ||
        ((((pcVar3->src->kind == '\x04' && (*(int *)((int)&pcVar3->src->sym->u30 + 2) != 0)) &&
          ((pcVar3->flags & 8) == 0)) &&
         ((iVar8 = delete_jump_to_next(pcVar3,(c2_tuple **)0x0), iVar8 != 0 ||
          (((g_opt_global != 0 &&
            (((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar3->op == 0x18b)))) &&
           (iVar8 = invert_branch_over_jump(pcVar3), iVar8 != 0)))))))))) {
      iVar9 = iVar9 + 1;
    }
    if (iVar9 != 0) {
      iVar5 = iVar5 + iVar9;
      pcVar2 = pcVar4;
    }
  } while( true );
}

