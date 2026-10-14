void eh_labels_leave_try_scope(void)

{
  byte bVar1;
  c1_symbol *pcVar2;
  
  pcVar2 = g_function_labels;
  while( true ) {
    if (pcVar2 == (c1_symbol *)0x0) {
      return;
    }
    bVar1 = (pcVar2->x28).bytes.depth;
    if (g_seh_finally_depth + g_seh_except_depth + g_seh_try_depth <= (int)(uint)bVar1) {
      if ((pcVar2->flags1 & 1) == 0) {
        (pcVar2->x28).bytes.depth = bVar1 - 1;
      }
      else {
        pcVar2->flags4 = pcVar2->flags4 | 2;
      }
    }
    if (pcVar2->next == (c1_sym_link *)0x0) break;
    pcVar2 = (c1_symbol *)&pcVar2->next[-1].position;
  }
  return;
}

