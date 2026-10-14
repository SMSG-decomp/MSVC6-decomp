c1_node * __cdecl expr_build_static_typeid(c1_type *type)

{
  c1_type *pcVar1;
  c1_symbol *sym;
  c1_node *pcVar2;
  
  pcVar1 = type_strip_cv_qualifiers(type);
  sym = rtti_type_descriptor_symbol((int)pcVar1);
  pcVar2 = expr_reference_named_entity(sym,0);
  pcVar2 = expr_build_address_of(pcVar2,4);
  pcVar1 = expr_typeid_return_type();
  pcVar2 = tree_new_cast(pcVar1,pcVar2);
  pcVar2 = expr_build_builtin_unary(0x3d,pcVar2);
  return pcVar2;
}

