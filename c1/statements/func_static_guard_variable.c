void __cdecl func_static_guard_variable(c1_node *value)

{
  byte bVar1;
  c1_symbol *pcVar2;
  fe_name *name;
  c1_u8 *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_u8 level;
  
  if (g_static_guard_variable == (c1_symbol *)0x0) {
    level = '\x02';
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      level = g_block_depth;
    }
    name = name_new_S();
    g_static_guard_variable = sym_new_object(name,level);
    g_static_guard_variable->type = g_type_long;
    g_static_guard_variable->storage = g_static_guard_variable->storage & 0xf8 ^ 4;
    pcVar3 = &g_static_guard_variable->storage;
    bVar1 = *pcVar3;
    pcVar2 = g_static_guard_variable;
    pcVar2->storage = '\0';
    pcVar2->flags21 = '\0';
    pcVar2->flags22 = '\0';
    pcVar2->flags23 = '\0';
    *pcVar3 = (*pcVar3 ^ bVar1 & 7) & 7 ^ *pcVar3;
    g_bitfield_word_needs_reset = 1;
  }
  else if (g_bitfield_word_needs_reset == 0) goto LAB_10635bf1;
  pcVar4 = tree_new_int_constant(0);
  pcVar5 = tree_new_symbol_ref(g_static_guard_variable);
  pcVar5 = tree_new_rvalue(pcVar5);
  pcVar4 = expr_build_binary('t',pcVar5,pcVar4);
  stmt_emit_expression(pcVar4);
  g_bitfield_word_needs_reset = 0;
LAB_10635bf1:
  pcVar4 = tree_new_int_constant((uint)(g_init_level->cursor->x28).bytes.depth);
  pcVar5 = tree_new_int_constant(1);
  pcVar4 = expr_build_binary('C',pcVar5,pcVar4);
  pcVar5 = tree_new_int_constant(1);
  pcVar4 = expr_build_binary('F',pcVar4,pcVar5);
  pcVar4 = expr_build_binary('1',value,pcVar4);
  pcVar5 = tree_new_int_constant((uint)(g_init_level->cursor->x28).bytes.bit_position);
  pcVar4 = expr_build_binary('C',pcVar4,pcVar5);
  pcVar5 = tree_new_symbol_ref(g_static_guard_variable);
  pcVar5 = tree_new_rvalue(pcVar5);
  pcVar4 = expr_build_binary('N',pcVar5,pcVar4);
  stmt_emit_expression(pcVar4);
  return;
}

