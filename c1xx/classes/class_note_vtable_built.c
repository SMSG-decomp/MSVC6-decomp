void __cdecl class_note_vtable_built(c1_symbol *sym)

{
  int iVar1;
  
  if ((((sym->detail).cls)->layout_flags3a & 0xc0) != 0) {
    if (g_pending_vtable_classes == (short *)0x0) {
      g_pending_vtable_classes = (short *)symtab_record_new(1);
    }
    g_pending_vtable_classes = vector_find_or_add(g_pending_vtable_classes,(int)sym);
  }
  class_find_special_members(sym);
  iVar1 = (*g_idb->vtbl->idb_note_special_members)(g_idb);
  if (iVar1 != 0) {
    return;
  }
  diag_fatal(0x49,".\\objmodel.c",0xc68);
}

