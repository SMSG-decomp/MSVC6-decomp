void __cdecl init_emit_address_or_zero(int sym)

{
  c1_node *pcVar1;
  uint mode;
  int iVar2;
  longlong zero_value;
  
  if (sym == 0) {
    zero_value._0_4_ = 0;
    zero_value._4_4_ = 0;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_int,&zero_value,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    return;
  }
  iVar2 = 0;
  mode = 0;
  pcVar1 = expr_reference_named_entity((c1_symbol *)sym,0);
  pcVar1 = expr_build_address_of(pcVar1,mode);
  init_process_initializer(pcVar1,iVar2);
  return;
}

