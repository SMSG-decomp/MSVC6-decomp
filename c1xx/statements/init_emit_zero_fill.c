void __cdecl init_emit_zero_fill(void)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  int flag;
  int flag_00;
  int flag_01;
  
  flag_01 = 1;
  pcVar1 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
  flag_00 = 1;
  pcVar2 = tree_new_int_constant(0);
  flag = 1;
  pcVar3 = init_element_lvalue(g_type_int);
  pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,flag);
  pcVar2 = tree_append_list_item(pcVar3,pcVar2,flag_00);
  pcVar1 = tree_append_list_item(pcVar2,pcVar1,flag_01);
  stmt_emit_intrinsic_call(0xad,pcVar1);
  g_init_offset = g_init_offset + g_constant_value;
  return;
}

