c1_node * __cdecl expr_reference_named_entity(c1_symbol *sym)

{
  c1_type pointer_type;
  byte bVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_u16 in_stack_fffffff0;
  c1_u16 in_stack_fffffff2;
  c1_type *in_stack_fffffff4;
  c1_type_x08 in_stack_fffffff8;
  c1_u32 in_stack_fffffffc;
  
  if ((sym->kind & 0x1f) == 5) {
    pcVar2 = tree_new_enumerator_constant(sym);
    return pcVar2;
  }
  if (((sym->storage & 7) == 5) && ((sym->flags4 & 4) != 0)) {
    pointer_type.flags = in_stack_fffffff2;
    pointer_type.code = in_stack_fffffff0;
    pointer_type.base = in_stack_fffffff4;
    pointer_type.extra.sym = in_stack_fffffff8.sym;
    pointer_type.debug_index = in_stack_fffffffc;
    pcVar2 = expr_report_register_address(sym,pointer_type);
    return pcVar2;
  }
  pcVar2 = tree_new_symbol_ref(sym);
  if (pcVar2 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) {
    pcVar3 = type_intern((c1_type *)&stack0xfffffff0);
    pcVar2->type = pcVar3;
  }
  else if ((sym->flags4 & 4) == 0) {
    pcVar2 = tree_new_rvalue(pcVar2);
    return pcVar2;
  }
  return pcVar2;
}

