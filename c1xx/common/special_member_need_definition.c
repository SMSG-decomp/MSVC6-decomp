void __cdecl special_member_need_definition(c1_symbol *fn)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = fn->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) && ((*(byte *)((int)&fn->tail + 8) & 8) != 0)) {
    if (g_pending_special_members == (c1_symbol_vector *)0x0) {
      g_pending_special_members = (c1_symbol_vector *)symtab_record_new_kind4();
    }
    if (g_pending_special_members->count == g_pending_special_members->capacity) {
      g_pending_special_members = vector_grow_checked(g_pending_special_members);
    }
    g_pending_special_members->entries[(short)g_pending_special_members->count] = fn;
    g_pending_special_members->count = g_pending_special_members->count + 1;
    *(byte *)((int)&fn->tail + 8) = *(byte *)((int)&fn->tail + 8) & 0xf7;
    iVar2 = (*g_idb->vtbl->idb_note_special_members)(g_idb);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\special.c",0x5af);
    }
  }
  return;
}

