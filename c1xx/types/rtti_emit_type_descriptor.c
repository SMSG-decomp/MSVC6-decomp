void __cdecl rtti_emit_type_descriptor(int *item)

{
  c1_symbol *sym;
  c1_symbol *sym_00;
  c1_node *pcVar1;
  int iVar2;
  undefined4 uStack_1808;
  undefined4 uStack_1804;
  char acStack_1800 [6140];
  undefined4 uStack_4;
  
  uStack_4 = 0x104b4f95;
  if ((char)item[2] == '\0') {
    *(undefined1 *)(item + 2) = 1;
    sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
    init_begin(sym,'\0');
    sym_00 = rtti_type_info_vftable_symbol();
    init_emit_address_or_zero((int)sym_00);
    uStack_1808 = 0;
    uStack_1804 = 0;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_int,&uStack_1808,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    decorate_name_3(acStack_1800,acStack_1800,(c1_type *)item[1],'\x01');
    iVar2 = 0;
    pcVar1 = tree_new_string_literal(acStack_1800);
    init_process_initializer(pcVar1,iVar2);
    init_finish(sym);
  }
  return;
}

