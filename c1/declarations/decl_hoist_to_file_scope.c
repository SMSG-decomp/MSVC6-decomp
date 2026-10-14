void __cdecl decl_hoist_to_file_scope(c1_symbol *sym)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  fe_name *pfVar6;
  int iVar7;
  void *value;
  uint uVar8;
  
  if ((g_ms_extensions != '\0') && ((bVar4 = sym->kind & 0x1f, bVar4 == 7 || (bVar4 == 8)))) {
    diag_warning(4,0xd2);
    pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[sym->kind & 0x1f] + 3 & 0xfffffffc);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = sym_copy_unlinked(pcVar5,sym,0);
    }
    pcVar5->flags4 = pcVar5->flags4 | 0x20;
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar5);
    sym_mark_referenced(pcVar5);
    sym->flags1 = sym->flags1 | 2;
    return;
  }
  if ((sym->kind & 0x1f) == 10) {
    if (g_c9il_mode == '\0') {
      if ((sym->storage & 7) != 3) {
        return;
      }
      iVar7 = func_wants_inline(g_current_function);
      if ((char)iVar7 == '\0') {
        return;
      }
    }
    else if ((sym->storage & 7) != 3) {
      return;
    }
    pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[sym->kind & 0x1f] + 3 & 0xfffffffc);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = sym_copy_unlinked(pcVar5,sym,0);
    }
    pfVar6 = name_intern_symbol_decorated(sym);
    pcVar5->name = pfVar6;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar8 = pcVar5->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar5->entity = uVar8 & 0xffffff ^ pcVar5->entity;
    if ((sym->flags23 & 1) != 0) {
      value = sym_segment_record(sym);
      if (value == (void *)0x0) {
        pcVar5->flags23 = pcVar5->flags23 & 0xfe;
      }
      else {
        sym_set_segment(pcVar5,value);
      }
    }
    pcVar5->flags1 = pcVar5->flags1 | 1;
    sym->flags3 = sym->flags3 | 0x40;
    decl_record_file_scope_twin(sym,pcVar5);
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar5);
    if (((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags21 & 1) != 0)) &&
       ((g_current_function->storage & 7) != 3)) {
      if ((g_current_function->flags22 & 0xc) != 0) {
        bVar4 = (pcVar5->flags22 ^ g_current_function->flags22) & 4 ^ pcVar5->flags22;
        pcVar5->flags22 = bVar4;
        pcVar5->flags22 = (g_current_function->flags22 ^ bVar4) & 8 ^ bVar4;
        cVar1 = pcVar5->flags21;
        cVar2 = pcVar5->flags22;
        cVar3 = pcVar5->flags23;
        sym->storage = pcVar5->storage;
        sym->flags21 = cVar1;
        sym->flags22 = cVar2;
        sym->flags23 = cVar3;
      }
      bVar4 = pcVar5->storage & 0xf8 ^ 2;
      pcVar5->storage = bVar4;
      pcVar5->storage = bVar4 | 0x40;
    }
  }
  return;
}

