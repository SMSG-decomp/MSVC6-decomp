void __cdecl init_begin(c1_symbol *sym,char force_selectany_check)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  int iVar5;
  int scalar_flag;
  
  if (sym != (c1_symbol *)0x0) {
    g_init_too_many_reported = 0;
    g_init_brace_depth = -1;
    PTR_104e0a40 = (c1_type *)0x0;
    if (((sym->flags5 & 1) == 0) || ((sym->flags5 & 4) == 0)) {
      scalar_flag = 0;
    }
    else {
      scalar_flag = 1;
    }
    pcVar2 = sym->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    g_init_remaining_error = 0;
    g_init_remaining_offset = 0;
    g_init_remaining_count = 0;
    g_init_offset = 0;
    init_push_brace_level(sym);
    g_init_level->flags = '\x01';
    if ((force_selectany_check != '\0') ||
       (pcVar4 = sym_class_needing_init(sym), pcVar4 != (c1_symbol *)0x0)) {
      init_begin_dynamic_initializer(sym);
    }
    pcVar2 = g_init_level->sym->type;
    if (((pcVar2->code & 0x200) != 0) &&
       ((((((pcVar2->extra).cls)->detail).cls)->layout_flags3c & 1) == 0)) {
      init_check_non_aggregate(sym,g_init_level->sym,scalar_flag);
      return;
    }
    iVar5 = sym_has_scalar_type(g_init_level->sym);
    if ((iVar5 != 0) || (scalar_flag != 0)) {
      g_init_level->flags = g_init_level->flags | 4;
    }
    if ((((g_block_depth == '\0') || (bVar3 = g_init_level->sym->storage & 7, bVar3 < 4)) ||
        (6 < bVar3)) && (g_init_pending_data_symbol = sym, g_browse_file != (char *)0x0)) {
      (*g_il_emitter->vtbl->begin_block)();
      (*g_il_emitter->vtbl->set_owner)((int)g_init_pending_data_symbol);
      g_compile_flags_cc = g_compile_flags_cc | 0x4000;
    }
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffbffff;
  return;
}

