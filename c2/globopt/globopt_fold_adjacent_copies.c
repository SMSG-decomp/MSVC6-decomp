void __fastcall globopt_fold_adjacent_copies(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  uint32_t uVar3;
  
  pcVar1 = fn->cfg->last->end;
  pcVar2 = fn->cfg->first->head->next;
joined_r0x1071e1c9:
  t = pcVar2;
  if (t == pcVar1) {
    return;
  }
  pcVar2 = t->next;
  if (t->op == 0x15d) goto LAB_1071e1d8;
  if (((t->op == 0x162) &&
      ((((1 << (t->dst->kind & 0x1f) & 6U) != 0 && (t->dst->sym->def != (c2_tuple *)0x0)) &&
       ((1 << (t->src->kind & 0x1f) & 6U) != 0)))) &&
     ((t->src->sym->u18).expr != (c2_cse_expr *)0x0)) {
    t->op = 0x15b;
  }
  goto LAB_1071e1ec;
LAB_1071e1d8:
  t->op = 0x15b;
  if ((t->src->kind != '\a') && ((t->src->flags & 0x40) == 0)) {
LAB_1071e1ec:
    if ((t->op == 0x15b) && (uVar3 = fold_copy_into_previous_def(t), uVar3 == 0)) {
      fold_copy_into_next_use(t);
    }
  }
  goto joined_r0x1071e1c9;
}

