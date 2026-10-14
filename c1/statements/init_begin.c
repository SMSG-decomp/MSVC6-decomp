void __cdecl init_begin(c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  
  if (sym != (c1_symbol *)0x0) {
    g_init_too_many_reported = 0;
    g_init_brace_depth = -1;
    PTR_1066b8ec = (c1_type *)0x0;
    if (((sym->flags4 & 1) == 0) || ((sym->flags4 & 4) == 0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    pcVar2 = sym->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    g_init_offset = 0;
    init_push_brace_level(sym);
    g_init_level->flags = '\x01';
    iVar5 = sym_has_scalar_type(g_init_level->cursor);
    if ((iVar5 != 0) || (bVar3)) {
      g_init_level->flags = g_init_level->flags | 4;
    }
    if ((((g_block_depth == '\0') || (bVar4 = g_init_level->cursor->storage & 7, bVar4 < 4)) ||
        (6 < bVar4)) && (PTR_1065df70 = sym, g_browse_file != (char *)0x0)) {
      (*g_il_emitter->vtbl->begin_block)();
      (*g_il_emitter->vtbl->set_owner)(PTR_1065df70);
      g_compile_flags_cc = g_compile_flags_cc | 0x4000;
    }
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffbffff;
  return;
}

