void init_emit_zero_fill(void)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  int mode;
  int mode_00;
  int mode_01;
  
  mode_01 = 1;
  pcVar1 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
  mode_00 = 1;
  pcVar2 = tree_new_int_constant(0);
  mode = 1;
  pcVar3 = init_element_lvalue(g_type_int);
  pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,mode);
  pcVar2 = tree_append_list_item(pcVar3,pcVar2,mode_00);
  pcVar1 = tree_append_list_item(pcVar2,pcVar1,mode_01);
  stmt_emit_intrinsic_call(0xad,pcVar1);
  g_init_offset = g_init_offset + g_constant_value;
  return;
}

