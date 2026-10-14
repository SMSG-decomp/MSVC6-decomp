void __fastcall rehash_after_reassociation(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_tuple *pcVar4;
  c2_tuple *t;
  c2_function *local_4;
  
  pcVar1 = fn->cfg->last->end;
  pcVar2 = fn->cfg->first->head->next;
  local_4 = fn;
joined_r0x10748f99:
  do {
    t = pcVar2;
    if (t == pcVar1) {
      return;
    }
    pcVar2 = t->next;
  } while (((t->flags & 1) == 0) ||
          ((((t->op == 0x15b && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) &&
            (t->dst->sym->def != (c2_tuple *)0x0)) &&
           (uVar3 = fold_copy_into_previous_def(t), uVar3 != 0))));
  if (t->op == 0x17d) goto LAB_10748fc7;
  if (t->kind == '\x10') {
    t = t->src->sym->def;
  }
  goto LAB_10748fd8;
LAB_10748fc7:
  pcVar4 = find_next_use_of_dst(t,(c2_operand **)&local_4);
  if (pcVar4->kind != '\x10') {
LAB_10748fd8:
    enter_tuple_in_expression_table(t,1);
  }
  goto joined_r0x10748f99;
}

