c1_node * __cdecl expr_lvalue_through_both_arms(c1_node *src,uint mode)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *e;
  c1_type *pcVar3;
  c1_type local_10;
  
  pcVar1 = expr_lvalue_address(*(c1_node **)((int)src->right + 0x10),mode);
  if (pcVar1 != (c1_node *)0x0) {
    pcVar2 = expr_lvalue_address(*(c1_node **)((int)src->right + 0x14),mode);
    if (pcVar2 != (c1_node *)0x0) {
      e = tree_copy_to_arena(src,0);
      local_10.debug_index = 0;
      local_10.code = 0x82;
      *(c1_node **)((int)e->right + 0x10) = pcVar1;
      *(c1_node **)((int)e->right + 0x14) = pcVar2;
      pcVar3 = e->type;
      local_10.flags = decl_apply_default_calling_convention(0x82,0);
      local_10.extra.cls = (c1_symbol *)0x0;
      local_10.base = pcVar3;
      pcVar3 = type_intern(&local_10);
      *(c1_type **)((int)e->right + 4) = pcVar3;
      e->type = *(c1_type **)((int)e->right + 4);
      pcVar1 = expr_spill_and_comma(e);
      return pcVar1;
    }
  }
  return (c1_node *)0x0;
}

