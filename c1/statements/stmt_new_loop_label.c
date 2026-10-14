void __cdecl stmt_new_loop_label(c1_label_cell **label_stack,int kind)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = list_push_in_arena((int *)label_stack,4);
  pcVar2 = label_new(kind);
  *(c1_node **)(iVar1 + 4) = pcVar2;
  g_loop_label_count = g_loop_label_count + 1;
  return;
}

