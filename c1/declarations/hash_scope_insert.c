void __thiscall hash_scope_insert(c1_scope_object *block,c1_symbol *sym)

{
  byte bVar1;
  bool bVar2;
  uchar *puVar3;
  char cVar4;
  int iVar5;
  char cVar6;
  
  if ((block->level == 0) || (0xf8 < block->level)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  bVar1 = sym->flags2;
  sym->flags2 = cVar4 << 1 | bVar1 & 0xfd;
  if ((cVar4 == '\0') && (g_il_block_level != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((g_c9il_mode == '\0') && (bVar2)) {
    cVar6 = '\x01';
  }
  else {
    cVar6 = '\0';
  }
  sym->flags2 = cVar6 << 2 | cVar4 << 1 | bVar1 & 0xf9;
  if (cVar6 != '\0') {
    iVar5 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb);
    if (iVar5 == 0) {
      diag_fatal(0x49,"p1inl.inl",0x2ee);
    }
  }
  puVar3 = g_arenas[2].cur;
  if ((block->entries).buckets == (void **)0x0) {
    g_arenas[2].cur = g_arenas[2].cur + block->mask * 4 + 4;
    if (g_arenas[2].end < g_arenas[2].cur) {
      arena_grow(g_arenas + 2);
    }
    (block->entries).buckets = (void **)puVar3;
    scope_push_block(g_current_scope,block);
  }
  (*block->vtbl->link)(block,(int)sym);
  return;
}

