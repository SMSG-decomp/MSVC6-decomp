int __fastcall lower_switch_pseudo_ops(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *anchor;
  c2_tuple *pcVar3;
  
  pcVar3 = fn->cfg->first->head;
  pcVar1 = fn->cfg->last->end;
  pcVar2 = pcVar3->next;
  while (anchor = pcVar2, anchor != pcVar1) {
    pcVar3 = (c2_tuple *)anchor->op;
    pcVar2 = anchor->next;
    if (pcVar3 == (c2_tuple *)0x18d) {
      if (anchor->line != 0) {
        g_current_line_abs = fn->line_base + (uint)anchor->line;
        g_cur_line = anchor->line;
      }
      pcVar3 = (c2_tuple *)lower_switch_to_jump_table(anchor,fn);
    }
  }
  return (int)pcVar3;
}

