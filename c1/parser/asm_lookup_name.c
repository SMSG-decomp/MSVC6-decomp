c1_symbol * __cdecl asm_lookup_name(int name,int labels_allowed)

{
  c1_scope_lookup *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  
  if ((void *)name == g_name_dollar) {
    return g_builtin_label_1;
  }
  if ((void *)name != g_name_local_size) {
    pcVar1 = scope_stack_lookup(g_current_scope,name);
    if (pcVar1 == (c1_scope_lookup *)0x0) {
      pcVar2 = (c1_symbol *)0x0;
    }
    else {
      pcVar2 = pcVar1->sym;
    }
    if (pcVar2 == (c1_symbol *)0x0) {
      if (labels_allowed == 0) {
        iVar3 = asm_operand_description_id();
        diag_error(0x196,name,iVar3);
        pcVar2 = sym_new_object((void *)name,g_block_depth);
      }
      else {
        pcVar2 = label_find_in_function((void *)name);
        if (pcVar2 == (c1_symbol *)0x0) {
          pcVar2 = label_new_user(name);
          label_register(pcVar2);
          return pcVar2;
        }
      }
    }
    return pcVar2;
  }
  if ((g_current_function->flags22 & 1) == 0) {
    diag_error(0x1e6);
  }
  return g_builtin_label_10;
}

