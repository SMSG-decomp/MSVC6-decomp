void __cdecl class_warn_access_declaration(c1_symbol *cls,c1_overload_set *qualified_name)

{
  c1_keyed_cell *pcVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  
  (*g_idb->vtbl->idb_note_access_declaration)(g_idb);
  pcVar1 = qualified_name->list->head;
  pcVar2 = pcVar1->sym;
  pcVar1 = pcVar1->key;
  if (((pcVar2 != (c1_symbol *)0x0) && (pcVar1 != (c1_keyed_cell *)0x0)) &&
     (pcVar3 = pcVar1->sym, (pcVar3->kind & 0x1f) == 0xf)) {
    diag_warning(4,0x204,pcVar3,pcVar2);
    ns_member_using_declaration(&qualified_name->kind);
    return;
  }
  diag_warning(4,0x205);
  ns_member_using_declaration(&qualified_name->kind);
  return;
}

