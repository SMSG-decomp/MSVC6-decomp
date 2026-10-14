void __fastcall lower_1aa_markers(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  c2_tuple *t_00;
  c2_function *local_4;
  
  if ((g_eh_object_move_pending != 0) && ((fn->flags & 0x1000) == 0)) {
    g_eh_object_move_pending = 0;
    pcVar1 = fn->cfg->last->end;
    pcVar2 = fn->cfg->first->head->next;
    local_4 = fn;
    while (t = pcVar2, t != pcVar1) {
      pcVar2 = t->next;
      if (t->op == 0x1aa) {
        t_00 = find_next_use_of_dst(t,(c2_operand **)&local_4);
        lower_1aa_move_operand(t,t_00);
      }
    }
  }
  return;
}

