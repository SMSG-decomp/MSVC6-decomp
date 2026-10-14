void __cdecl class_build_vector_deleting_dtor_body(c1_symbol *cls)

{
  c1_node *left;
  c1_node *pcVar1;
  c1_node *labelref;
  c1_node *labelref_00;
  c1_node *pcVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_node *right;
  c1_symbol *delete_set;
  uint uVar5;
  
  left = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = expr_lookup_name_expression(PTR_104d1628);
  labelref = label_new(0x1d);
  labelref_00 = label_new(0x1e);
  uVar5 = 0;
  pcVar4 = labelref;
  pcVar2 = tree_new_int_constant(2);
  pcVar1 = expr_build_builtin_binary('1',pcVar1,pcVar2);
  stmt_emit_condition(pcVar1,pcVar4,uVar5);
  iVar3 = type_size_checked(g_type_int);
  pcVar4 = tree_new_int_constant(iVar3);
  pcVar4->type = g_type_int;
  pcVar4 = tree_new_binary('F',left,pcVar4);
  pcVar1 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
  pcVar4 = tree_new_unary('=',g_type_int,pcVar4);
  if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
    mre_note_class_layout_use(g_minimal_rebuild_tracker,cls);
  }
  pcVar4 = expr_build_vector_dtor_call(left,((cls->detail).cls)->size,pcVar4,left->type);
  stmt_emit_expression(pcVar4);
  pcVar2 = expr_lookup_name_expression(PTR_104d1628);
  uVar5 = 0;
  pcVar4 = labelref_00;
  right = tree_new_int_constant(1);
  pcVar2 = expr_build_builtin_binary('1',pcVar2,right);
  stmt_emit_condition(pcVar2,pcVar4,uVar5);
  delete_set = class_lookup_member_set(g_current_scope,cls,g_name_array_delete,0x82,0);
  if (delete_set == (c1_symbol *)0x0) {
    pcVar4 = (c1_node *)expr_build_generated_operator_delete_call(pcVar1,'\x01');
  }
  else {
    pcVar4 = expr_build_class_operator_delete_call(delete_set,pcVar1,cls);
  }
  stmt_emit_expression(pcVar4);
  label_emit_definition(labelref_00);
  func_flow_state_note_8();
  iVar3 = 2;
  pcVar4 = tree_copy_to_arena(pcVar1,g_expr_arena_index);
  stmt_emit_return_value(pcVar4,iVar3);
  label_emit_definition(labelref);
  class_build_destroy_and_delete(cls);
  func_flow_state_note_8();
  stmt_emit_return_value(left,2);
  return;
}

