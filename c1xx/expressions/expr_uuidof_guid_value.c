c1_node * __cdecl expr_uuidof_guid_value(c1_symbol *guid_sym)

{
  c1_node *pcVar1;
  c1_type *type;
  
  pcVar1 = expr_reference_named_entity(guid_sym,0);
  pcVar1 = expr_build_address_of(pcVar1,4);
  type = expr_uuidof_return_type();
  pcVar1 = tree_new_cast(type,pcVar1);
  pcVar1 = expr_build_builtin_unary(0x3d,pcVar1);
  return pcVar1;
}

