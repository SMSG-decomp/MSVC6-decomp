c2_tuple * __fastcall compute_tree_cost_and_sort(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  uint uVar8;
  
  pcVar7 = t->src;
  if (pcVar7 != (c2_operand *)0x0) {
    do {
      uVar8 = 1 << (pcVar7->kind & 0x1f);
      if (((uVar8 & 6) == 0) || (pcVar6 = pcVar7->sym->def, pcVar6 == (c2_tuple *)0x0)) {
        if (((((uVar8 & 0x60) == 0) ||
             ((pcVar1 = pcVar7->base, pcVar1 != (c2_operand *)0x0 &&
              (((1 << (pcVar1->kind & 0x1f) & 6U) == 0 || (pcVar1->sym->def == (c2_tuple *)0x0))))))
            || ((pcVar2 = pcVar7->index, pcVar2 != (c2_operand *)0x0 &&
                (((1 << (pcVar2->kind & 0x1f) & 6U) == 0 || (pcVar2->sym->def == (c2_tuple *)0x0))))
               )) || (pcVar1 == pcVar2)) {
          if ((uVar8 & 0xffe) == 0) {
            compute_tree_cost_and_sort((c2_tuple *)pcVar7);
          }
          else {
            uVar3 = pack_expression_cost(pcVar7);
            pcVar7->rank = uVar3;
          }
        }
        else {
          pcVar6 = compute_tree_cost_and_sort(pcVar1->sym->def);
          pcVar7->rank = (uint32_t)pcVar6->prev;
        }
      }
      else {
        pcVar6 = compute_tree_cost_and_sort(pcVar6);
        pcVar7->rank = (uint32_t)pcVar6->prev;
      }
      pcVar7 = pcVar7->next;
    } while (pcVar7 != (c2_operand *)0x0);
    for (pcVar7 = t->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
      if ((((1 << (pcVar7->kind & 0x1f) & 0x60U) != 0) &&
          ((pcVar1 = pcVar7->base, pcVar1 == (c2_operand *)0x0 ||
           (((1 << (pcVar1->kind & 0x1f) & 6U) != 0 && (pcVar1->sym->def != (c2_tuple *)0x0)))))) &&
         (((pcVar2 = pcVar7->index, pcVar2 == (c2_operand *)0x0 ||
           (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))) &&
          (pcVar1 != pcVar2)))) {
        pcVar6 = compute_tree_cost_and_sort(pcVar1->sym->def);
        pcVar7->rank = (uint32_t)pcVar6->prev;
      }
    }
    iVar4 = tuple_is_commutative(t);
    if (iVar4 != 0) {
      pcVar7 = merge_sort_operand_list(t->src,compare_operand_cost_desc);
      t->src = pcVar7;
    }
    uVar3 = hash_operand((c2_operand *)t);
    uVar5 = pack_expression_cost((c2_operand *)t);
    t->prev = (c2_tuple *)(uVar3 | uVar5);
  }
  return t;
}

