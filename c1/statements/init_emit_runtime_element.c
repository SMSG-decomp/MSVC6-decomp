void __cdecl init_emit_runtime_element(c1_symbol *sym,c1_node *init)

{
  c1_type *type;
  ushort uVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_node *expr;
  c1_node *expr_00;
  int mode;
  
  iVar2 = init_is_constant_initializer(sym,&init);
  if (iVar2 == 0) {
    diag_extension_warning_or_error(0xcc,0x61);
  }
  pcVar3 = init_element_lvalue(sym->type);
  iVar2 = init_is_char_array_string_init(sym,init);
  if (iVar2 == 0) {
    type = sym->type;
    pcVar3->type = type;
    iVar2 = type_size(type);
    init_emit_runtime_assignment(pcVar3,init);
    g_init_offset = g_init_offset + iVar2;
    return;
  }
  uVar1 = expr_warn_array_bounds_overflow(sym,init);
  *(ushort *)&init->right = uVar1;
  mode = 1;
  expr = tree_new_int_constant((uint)*(ushort *)&init->right);
  iVar2 = 1;
  expr_00 = init;
  pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,1);
  pcVar3 = tree_append_list_item(pcVar3,expr_00,iVar2);
  pcVar3 = tree_append_list_item(pcVar3,expr,mode);
  stmt_emit_intrinsic_call(0xac,pcVar3);
  g_init_offset = g_init_offset + (uint)*(ushort *)&init->right;
  return;
}

