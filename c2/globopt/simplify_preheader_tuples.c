void __fastcall simplify_preheader_tuples(c2_tuple *first,int *end,c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  uint32_t uVar3;
  
  pcVar1 = (c2_tuple *)*end;
  pcVar2 = first;
  while (t = pcVar2, t != pcVar1) {
    pcVar2 = t->next;
    if (t->line != 0) {
      g_current_line_abs = fn->line_base + (uint)t->line;
      g_cur_line = t->line;
    }
    if (((t->flags & 1) != 0) && (t->flags13 != '\x02')) {
      resimplify_tuple(t);
    }
  }
  pcVar1 = (c2_tuple *)*end;
  while (pcVar2 = first, pcVar2 != pcVar1) {
    first = pcVar2->next;
    if ((((pcVar2->op == 0x15b) && ((1 << (pcVar2->dst->kind & 0x1f) & 6U) != 0)) &&
        (pcVar2->dst->sym->def != (c2_tuple *)0x0)) &&
       (uVar3 = fold_copy_into_previous_def(pcVar2), uVar3 == 0)) {
      fold_copy_into_next_use(pcVar2);
    }
  }
  return;
}

