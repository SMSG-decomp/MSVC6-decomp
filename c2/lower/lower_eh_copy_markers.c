void __fastcall lower_eh_copy_markers(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_operand *op;
  c2_symbol *sym;
  c2_tuple *t;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *local_4;
  
  pcVar1 = fn->cfg->last->end;
  pcVar3 = fn->cfg->first->head->next;
  while (t = pcVar3, t != pcVar1) {
    pcVar3 = t->next;
    if ((t->kind == '\x14') && ((t->op == 0x1ab || (t->op == 0x1ac)))) {
      op = t->dst;
      if (op != (c2_operand *)0x0) {
        if (((((1 << (op->kind & 0x1f) & 6U) == 0) || (op->sym->def == (c2_tuple *)0x0)) ||
            (pcVar2 = find_next_use_of_dst(t,&local_4), pcVar2 == (c2_tuple *)0x0)) ||
           (pcVar2->op != 0x19e)) {
          pcVar2 = tuple_new(0x15b,t->type,t->dst,t->src,tuple_insert_before,t);
          if (((1 << (pcVar2->dst->kind & 0x1f) & 6U) != 0) &&
             (sym = pcVar2->dst->sym, sym->def != (c2_tuple *)0x0)) {
            if (sym->storage->part_next == (c2_symbol *)0x0) {
              sym->def = (c2_tuple *)0x0;
            }
            else {
              symbol_mark_overlapping_parts(sym,(c2_tuple *)0x0);
            }
          }
          number_assignment(pcVar2,1);
        }
        else {
          tuple_unlink_free(pcVar2);
          pcVar3 = t->next;
          tuple_remove_dst(t,op);
        }
      }
      pcVar2 = tuple_prev_real_before_boundary(t);
      if ((pcVar2 == (c2_tuple *)0x0) &&
         (pcVar2 = tuple_next_real_before_boundary(t), pcVar2 == (c2_tuple *)0x0)) {
        g_flowgraph_dirty = 1;
      }
      tuple_unlink_free(t);
      g_need_extra_dce = 1;
    }
  }
  return;
}

