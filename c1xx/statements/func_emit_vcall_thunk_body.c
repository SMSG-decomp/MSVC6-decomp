void __cdecl func_emit_vcall_thunk_body(c1_vcall_thunk_key *key,c1_symbol *thunk)

{
  c1_symbol *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  int flag;
  
  il_begin_function_body(1);
  func_record_alloc(thunk);
  g_function_parameter_scope = (c1_sym_list *)0x0;
  il_emit_tuple(0x53,(node *)0x0);
  pcVar3 = (c1_node *)0x0;
  pcVar2 = tree_new_symbol_ref(thunk,'\0');
  pcVar2 = tree_new_binary('l',pcVar2,pcVar3);
  il_emit_expression_tree(pcVar2);
  flag = 2;
  pcVar2 = tree_new_int_constant(key->vtable_offset);
  pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,flag);
  pcVar3 = tree_new_int_constant(3);
  pcVar2 = tree_new_binary(0x9d,pcVar3,pcVar2);
  il_emit_expression_tree(pcVar2);
  il_emit_tuple(0x47,(node *)0x0);
  pcVar2 = tree_new_int_constant(0);
  il_emit_tuple(0x54,pcVar2);
  if (((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) &&
     (pcVar1 = key->member, (pcVar1->flags21 & 1) != 0)) {
    mre_note_member_use(g_minimal_rebuild_tracker,
                        g_scope_vector->entries[(short)pcVar1->scope_index],pcVar1->name);
  }
  func_end_emit_il(thunk);
  return;
}

