void __cdecl class_build_destroy_and_delete(c1_symbol *cls)

{
  c1_node *obj;
  c1_node *pcVar1;
  c1_node *labelref;
  c1_node *pcVar2;
  c1_node *right;
  c1_symbol *delete_set;
  uint jump_if_true;
  
  obj = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = expr_lookup_name_expression(PTR_104d1628);
  labelref = label_new(0x1e);
  pcVar2 = expr_build_destructor_call(cls,obj,3,1,0);
  stmt_emit_expression(pcVar2);
  jump_if_true = 0;
  pcVar2 = labelref;
  right = tree_new_int_constant(1);
  pcVar1 = expr_build_builtin_binary('1',pcVar1,right);
  stmt_emit_condition(pcVar1,pcVar2,jump_if_true);
  delete_set = class_lookup_member_set(g_current_scope,cls,g_name_delete,2,0x181);
  if (delete_set != (c1_symbol *)0x0) {
    pcVar2 = expr_build_class_operator_delete_call(delete_set,obj,cls);
    stmt_emit_expression(pcVar2);
    label_emit_definition(labelref);
    return;
  }
  pcVar2 = (c1_node *)expr_build_generated_operator_delete_call(obj,'\0');
  stmt_emit_expression(pcVar2);
  label_emit_definition(labelref);
  return;
}

