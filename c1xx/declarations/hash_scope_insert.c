void __thiscall hash_scope_insert(c1xx_hash_scope *scope,c1_symbol *sym)

{
  uint n;
  byte bVar1;
  c1_u32 cVar2;
  c1_sym_link **ppcVar3;
  bool bVar4;
  char cVar5;
  c1_symbol *sym_00;
  int iVar6;
  int iVar7;
  c1_arena *a;
  char cVar8;
  c1_sym_link **ppcVar9;
  
  sym_00 = sym_insert_check_alias(sym);
  if (sym_00 != (c1_symbol *)0x0) {
    if ((scope->kind == 0) || (0xf8 < scope->kind)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    bVar1 = sym_00->flags3;
    sym_00->flags3 = cVar5 << 3 | bVar1 & 0xf7;
    if ((cVar5 == '\0') && (g_il_block_level != '\0')) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if ((g_c9il_mode == '\0') && (bVar4)) {
      cVar8 = '\x01';
    }
    else {
      cVar8 = '\0';
    }
    sym_00->flags3 = cVar8 << 4 | cVar5 << 3 | bVar1 & 0xe7;
    if ((cVar8 != '\0') && (iVar6 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb), iVar6 == 0)) {
      diag_fatal(0x49,"p1inl.inl",0x2ee);
    }
    if (scope->buckets == (c1_sym_link **)0x0) {
      iVar6 = (*scope->vtbl->has_entries)(scope);
      if ((scope->kind == '\0') || ((g_compile_flags_c8 & 0x50000000) != 0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = 4;
      }
      cVar2 = scope->mask;
      n = cVar2 * 4 + 4;
      if (iVar7 == 0) {
        if (g_scope_pool_left < n) {
          pool_reserve((c1xx_pool *)&g_scope_pool,n);
        }
        g_scope_pool_left = g_scope_pool_left - n;
        ppcVar9 = (c1_sym_link **)g_scope_pool;
        g_scope_pool = g_scope_pool + n;
      }
      else {
        a = g_arenas + iVar7;
        ppcVar9 = (c1_sym_link **)a->cur;
        ppcVar3 = (c1_sym_link **)g_arenas[iVar7].end;
        a->cur = (c1_u8 *)(ppcVar9 + cVar2 + 1);
        if (ppcVar3 < ppcVar9 + cVar2 + 1) {
          arena_grow(a);
        }
      }
      scope->buckets = ppcVar9;
      if ((char)iVar6 == '\0') {
        scope_push_block(g_current_scope,(c1xx_scope *)scope);
      }
    }
    (*scope->vtbl->link)(scope,sym_00);
  }
  return;
}

