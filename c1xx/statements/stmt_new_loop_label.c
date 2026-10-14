void __cdecl stmt_new_loop_label(c1xx_label_cell **stack,int role)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = list_push_in_arena((int *)stack,6);
  pcVar2 = label_new(role);
  *(c1_node **)(iVar1 + 4) = pcVar2;
  g_loop_label_count = g_loop_label_count + 1;
  return;
}

