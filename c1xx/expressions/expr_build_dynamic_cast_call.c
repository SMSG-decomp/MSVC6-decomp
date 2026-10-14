c1_node * __cdecl
expr_build_dynamic_cast_call
          (c1_node *node,c1_type *target,c1_symbol *target_class,c1_symbol *source_class,
          c1_u8 is_reference)

{
  char cVar1;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  uint uVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_symbol *pcVar6;
  c1_node *pcVar7;
  c1_node *item;
  c1_node *pcVar8;
  c1_type *type;
  c1_node *local_c;
  c1_tree_visitor cStack_8;
  
  local_c = (c1_node *)0x0;
  if (PTR_104d2824 == (c1_symbol *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_RTDynamicCast,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar2 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar2 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    PTR_104d2824 = pcVar2->sym;
  }
  if (is_reference != '\0') {
    node = expr_build_address_of(node,8);
  }
  if ((((source_class->detail).cls)->layout_flags3a & 0x40) == 0) {
    cStack_8.kind_mask = 0xff;
    cStack_8.pad05[0] = '\0';
    cStack_8.pad05[1] = '\0';
    cStack_8.pad05[2] = '\0';
    cStack_8.vtbl = &g_side_effect_visitor_vtable;
    cVar1 = tree_has_side_effects(&cStack_8,node);
    if (cVar1 != '\0') {
      type = node->type;
      uVar3 = sym_new_local_key();
      pcVar4 = tree_new_leaf_9c(uVar3,type);
      local_c = tree_new_binary_typed_right('4',pcVar4,node);
      pcVar4 = tree_new_leaf_9c((int)pcVar4->left,pcVar4->type);
      node = tree_new_unary('=',pcVar4->type,pcVar4);
    }
    pcVar4 = tree_copy_to_arena(node,g_expr_arena_index);
    node = expr_vfptr_subobject_address(0xde,node,source_class);
    pcVar5 = tree_copy_to_arena(node,g_expr_arena_index);
    pcVar5 = tree_new_cast(g_type_unsigned_int,pcVar5);
    pcVar4 = tree_new_cast(g_type_unsigned_int,pcVar4);
    pcVar4 = tree_new_node('F',pcVar5,pcVar4,g_type_int);
  }
  else {
    pcVar4 = tree_new_int_constant(0);
  }
  pcVar6 = rtti_type_descriptor_symbol((int)source_class->type);
  uVar3 = 4;
  pcVar5 = expr_reference_named_entity(pcVar6,0);
  pcVar5 = expr_build_address_of(pcVar5,uVar3);
  pcVar6 = rtti_type_descriptor_symbol((int)target_class->type);
  uVar3 = 4;
  pcVar7 = expr_reference_named_entity(pcVar6,0);
  pcVar7 = expr_build_address_of(pcVar7,uVar3);
  item = tree_new_int_constant((uint)is_reference);
  pcVar8 = tree_new_cast(PTR_104d152c,node);
  pcVar8 = tree_append_list_item((c1_node *)0x0,pcVar8,2);
  pcVar4 = tree_append_list_item(pcVar8,pcVar4,2);
  pcVar4 = tree_append_list_item(pcVar4,pcVar5,2);
  pcVar4 = tree_append_list_item(pcVar4,pcVar7,2);
  pcVar4 = tree_append_list_item(pcVar4,item,2);
  pcVar5 = tree_new_symbol_ref(PTR_104d2824,'\0');
  pcVar4 = (c1_node *)expr_build_call(pcVar5,pcVar4);
  if (local_c != (c1_node *)0x0) {
    pcVar4 = tree_new_binary_typed_right('7',local_c,pcVar4);
  }
  pcVar4->type = target;
  if (is_reference != '\0') {
    pcVar4 = expr_build_builtin_unary(0x3d,pcVar4);
  }
  return pcVar4;
}

