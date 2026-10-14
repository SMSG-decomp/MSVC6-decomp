void __fastcall optimize_expression_trees(c2_function *fn,int mode)

{
  ushort uVar1;
  c2_operand *pcVar2;
  c2_tuple *t;
  c2_tuple *end;
  c2_tuple *next;
  
  end = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  g_expr_pass_mode = mode;
  do {
    if (t == end) {
      return;
    }
    uVar1 = t->line;
    next = t->next;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    g_const_overflow_warned = 0;
    switch(*(undefined1 *)((int)optimize_expression_trees_jump_table + t->kind + 4)) {
    case 0:
      pcVar2 = t->dst;
      if (((pcVar2 == (c2_operand *)0x0) || ((1 << (pcVar2->kind & 0x1f) & 6U) == 0)) ||
         (pcVar2->sym->def == (c2_tuple *)0x0)) goto switchD_1070bbf0_caseD_1;
      break;
    case 1:
switchD_1070bbf0_caseD_1:
      simplify_tuple_tree(t);
    }
    t = next;
  } while( true );
}

