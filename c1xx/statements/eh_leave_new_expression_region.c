c1_node * __cdecl eh_leave_new_expression_region(void)

{
  int iVar1;
  void *pvVar2;
  c1_eh_state *pcVar3;
  int iVar4;
  int iVar5;
  void *state;
  c1_node *local_4;
  
  iVar5 = 0;
  local_4 = (c1_node *)0x0;
  iVar4 = g_eh_current_state;
  if ((g_eh_current_state != g_eh_new_region_base_state) &&
     (iVar4 = g_eh_new_region_base_state, g_eh_new_region_base_state < g_eh_current_state)) {
    state = (void *)0x0;
    iVar1 = g_eh_current_state << 4;
    pvVar2 = (void *)g_eh_current_state;
    pcVar3 = g_eh_state_table;
    iVar4 = g_eh_new_region_base_state;
    do {
      if ((*(int *)(pcVar3->pad01 + iVar1 + 3) == 4) && (pcVar3->pad01[iVar1 + -1] == '\0')) {
        pcVar3->pad01[iVar1 + -1] = '\x01';
        iVar5 = iVar5 + 1;
        pcVar3 = g_eh_state_table;
        iVar4 = g_eh_new_region_base_state;
        state = pvVar2;
      }
      pvVar2 = (void *)((int)pvVar2 + -1);
      iVar1 = iVar1 + -0x10;
    } while (iVar4 < (int)pvVar2);
    if (0 < iVar5) {
      local_4 = tree_new_node_with_fields(0xc2,(ushort)iVar5,state,0);
      iVar4 = g_eh_new_region_base_state;
    }
  }
  g_eh_current_state = iVar4;
  g_eh_context_kind = g_eh_state_stack->value;
  list_pop_head((int *)&g_eh_state_stack);
  g_eh_new_region_base_state = g_eh_new_region_base_stack->value;
  list_pop_head((int *)&g_eh_new_region_base_stack);
  PTR_104d2c58 = g_eh_init_target_stack->sym;
  list_pop_head((int *)&g_eh_init_target_stack);
  init_set_target_symbol(PTR_104d2c58);
  g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
  return local_4;
}

