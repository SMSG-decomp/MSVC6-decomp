void __thiscall func_definition_begin(void *declarator,int *spec)

{
  byte *pbVar1;
  c1_symbol *pcVar2;
  int iVar3;
  byte bVar4;
  
  *(byte *)((int)declarator + 0x2c) = *(byte *)((int)declarator + 0x2c) | 8;
  pcVar2 = decl_declare_declarator(declarator,(c1_decl_specifiers *)spec);
  *(c1_symbol **)((int)declarator + 0x20) = pcVar2;
  bVar4 = pcVar2->kind & 0x1f;
  if ((bVar4 != 7) && (bVar4 != 8)) {
    if (bVar4 == 6) {
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = sym_new_from_declarator(declarator,3);
      }
      diag_error(0xa9,pcVar2);
    }
    else {
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = sym_new_from_declarator(declarator,3);
      }
      diag_error(0x36,0x53,pcVar2);
    }
    pbVar1 = (byte *)(*(int *)((int)declarator + 0x20) + 2);
    *pbVar1 = *pbVar1 | 1;
    func_reset_state();
    return;
  }
  if ((*(byte *)((int)declarator + 0x2d) & 8) == 0) {
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = sym_new_from_declarator(declarator,3);
    }
    diag_error(0xce,pcVar2);
    g_pending_parameter_scope = (c1_scope_symbol_list *)0x0;
  }
  else if (g_pending_function_word == 4) {
    diag_error(0x37);
  }
  pcVar2 = *(c1_symbol **)((int)declarator + 0x20);
  if ((((pcVar2->flags22 & 8) != 0) && ((pcVar2->flags21 & 1) == 0)) &&
     ((g_compile_flags_c4 & 0x200) == 0)) {
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = sym_new_from_declarator(declarator,3);
    }
    diag_error(0x1eb,pcVar2,0x176);
  }
  if (g_code_seg_name != (void *)0x0) {
    sym_set_segment_checked(*(c1_symbol **)((int)declarator + 0x20),g_code_seg_name);
  }
  g_current_function = func_parameter_scope_begin(*(c1_symbol **)((int)declarator + 0x20));
  g_function_context_word = g_pending_function_word;
  g_function_parameter_scope = g_pending_parameter_scope;
  if (((byte)PTR_1065d46c->code >> 6 & 1) == 0) {
    iVar3 = type_size(PTR_1065d46c);
    if (iVar3 == 0) {
      diag_error(0x4f,g_current_function,PTR_1065d46c,(PTR_1065d46c->extra).sym);
    }
  }
  return;
}

