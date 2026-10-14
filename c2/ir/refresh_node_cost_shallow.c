void __fastcall refresh_node_cost_shallow(c2_tuple *t)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  c2_symbol *pcVar4;
  c2_operand *child;
  uint uVar5;
  c2_operand *base;
  c2_tuple *def;
  c2_operand *index;
  
  if ((1 << (t->kind & 0x1f) & 0xffeU) == 0) {
    for (child = t->src; child != (c2_operand *)0x0; child = child->next) {
      uVar5 = 1 << (child->kind & 0x1f);
      if (((uVar5 & 6) == 0) || (def = child->sym->def, def == (c2_tuple *)0x0)) {
        if (((((uVar5 & 0x60) == 0) ||
             ((base = child->base, base != (c2_operand *)0x0 &&
              (((1 << (base->kind & 0x1f) & 6U) == 0 || (base->sym->def == (c2_tuple *)0x0)))))) ||
            ((index = child->index, index != (c2_operand *)0x0 &&
             (((1 << (index->kind & 0x1f) & 6U) == 0 || (index->sym->def == (c2_tuple *)0x0)))))) ||
           (base == index)) {
          if ((uVar5 & 0xffe) == 0) {
            iVar2 = tuple_is_commutative((c2_tuple *)child);
            if (iVar2 != 0) {
              pcVar4 = merge_sort_operand_list((child->u18).reg,compare_operand_cost_desc);
              (child->u18).reg = pcVar4;
            }
          }
          else {
            uVar1 = pack_expression_cost(child);
            child->rank = uVar1;
          }
        }
        else {
          child->rank = (uint32_t)base->sym->def->prev;
        }
      }
      else {
        child->rank = (uint32_t)def->prev;
      }
    }
    for (child = t->dst; child != (c2_operand *)0x0; child = child->next) {
      if ((((1 << (child->kind & 0x1f) & 0x60U) != 0) &&
          ((base = child->base, base == (c2_operand *)0x0 ||
           (((1 << (base->kind & 0x1f) & 6U) != 0 && (base->sym->def != (c2_tuple *)0x0)))))) &&
         (((index = child->index, index == (c2_operand *)0x0 ||
           (((1 << (index->kind & 0x1f) & 6U) != 0 && (index->sym->def != (c2_tuple *)0x0)))) &&
          (base != index)))) {
        child->rank = (uint32_t)base->sym->def->prev;
      }
    }
    iVar2 = tuple_is_commutative(t);
    if (iVar2 != 0) {
      child = merge_sort_operand_list(t->src,compare_operand_cost_desc);
      t->src = child;
    }
    uVar1 = hash_operand((c2_operand *)t);
    uVar3 = pack_expression_cost((c2_operand *)t);
    t->prev = (c2_tuple *)(uVar1 | uVar3);
  }
  return;
}

