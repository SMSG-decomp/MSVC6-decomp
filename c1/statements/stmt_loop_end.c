void stmt_loop_end(void)

{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  
  il_emit_tuple(0x3a,g_continue_label_stack->label);
  label_emit_definition(g_break_label_stack->label);
  g_loop_top_label_stack = g_loop_top_label_stack->next;
  g_continue_label_stack = g_continue_label_stack->next;
  g_break_label_stack = g_break_label_stack->next;
  g_loop_label_count = g_loop_label_count + -3;
  if (g_loop_label_count == 0) {
    uVar1 = (int)g_arenas[4].cur - (int)g_arenas[4].base;
    g_loop_label_count = 0;
    puVar3 = g_arenas[4].base;
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar3[0] = '\0';
      puVar3[1] = '\0';
      puVar3[2] = '\0';
      puVar3[3] = '\0';
      puVar3 = puVar3 + 4;
    }
    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = '\0';
      puVar3 = puVar3 + 1;
    }
    g_arenas[4].cur = g_arenas[4].base;
    return;
  }
  return;
}

