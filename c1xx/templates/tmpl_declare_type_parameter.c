c1_symbol * __cdecl tmpl_declare_type_parameter(fe_name *name)

{
  uint *puVar1;
  c1_u32 cVar2;
  c1_symbol *pcVar3;
  c1_type *pcVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int arena;
  c1_symbol *pcVar6;
  c1_u16 in_stack_fffffff0;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    arena = 0;
    puVar1 = g_symbol_free_lists[g_symbol_size_class_table[0x16]];
    if (puVar1 != (uint *)0x0) {
      pcVar3 = (c1_symbol *)(puVar1 + -2);
      g_symbol_free_lists[g_symbol_size_class_table[0x16]] = (uint *)puVar1[1];
      *puVar1 = 0;
      puVar1[1] = 0;
      cVar2 = g_symbol_size_table[0x16];
      pcVar6 = pcVar3;
      for (uVar5 = g_symbol_size_table[0x16] >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        pcVar6->kind = '\0';
        pcVar6->flags1 = '\0';
        pcVar6->flags2 = '\0';
        pcVar6->flags3 = '\0';
        pcVar6 = (c1_symbol *)&pcVar6->flags4;
      }
      for (uVar5 = cVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        pcVar6->kind = '\0';
        pcVar6 = (c1_symbol *)&pcVar6->flags1;
      }
      *puVar1 = (uint)name;
      pcVar3->kind = pcVar3->kind & 0xf6 | 0x16;
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = tmpl_declare_type_parameter_alloc_record(unaff_EBP,unaff_EBX,in_stack_fffffff0,0);
        return pcVar3;
      }
      goto LAB_1044f2a9;
    }
  }
  else {
    arena = 4;
  }
  pcVar3 = sym_alloc_record(0x38,0x16,arena);
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_init_kind(pcVar3,'\x16',name,arena);
  }
LAB_1044f2a9:
  if (g_template_parameter_index != 0x40) {
    g_template_parameter_index = g_template_parameter_index + 1;
    pcVar4 = type_intern((c1_type *)&stack0xfffffff0);
    pcVar3->type = pcVar4;
    pcVar3->flags2 = pcVar3->flags2 | 0x10;
    (*g_current_scope->current->vtbl->insert)(pcVar3);
    name->flags = name->flags | 0x20000;
    return pcVar3;
  }
  diag_fatal_simple(0x6f);
}

