int __fastcall invert_branch_over_jump(c2_tuple *t)

{
  c2_tuple *jump;
  c2_tuple *after;
  
  jump = t->next;
  if (jump != (c2_tuple *)0x0) {
    while (((((jump->kind != '\x11' || ((jump->u20).cond_cells != (c2_cond_cell *)0x0)) ||
             (jump->op == 0x18b)) ||
            ((jump->src->kind != '\x04' || (*(int *)((int)&jump->src->sym->u30 + 2) == 0)))) ||
           ((jump->flags & 8) != 0))) {
      if ((jump->flags & 1) != 0) {
        return 0;
      }
      if (jump->kind == '\x1a') {
        return 0;
      }
      jump = jump->next;
      if (jump == (c2_tuple *)0x0) {
        return 0;
      }
    }
    after = jump->next;
    if (after != (c2_tuple *)0x0) {
      while( true ) {
        if ((after->kind == '\x1a') && (after == *(c2_tuple **)((int)&t->src->sym->u30 + 2))) {
          branch_invert_condition(t);
          tuple_retarget(t,*(c2_node **)((int)&jump->src->sym->u30 + 2),0);
          t->line = jump->line;
          branch_free(jump);
          return 1;
        }
        if ((after->flags & 1) != 0) break;
        after = after->next;
        if (after == (c2_tuple *)0x0) {
          return 0;
        }
      }
    }
  }
  return 0;
}

