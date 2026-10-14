c1_vbase_record * __cdecl class_new_vbase_record(c1_symbol *base_entry,c1_symbol *cls,int arena)

{
  c1_vbase_record *pcVar1;
  c1_vbase_record *pcVar2;
  c1_symbol *pcVar3;
  c1_vtable_vector *copies;
  c1_arena *a;
  c1_vtable_vector **ppcVar4;
  int iVar5;
  
  a = g_arenas + arena;
  pcVar1 = (c1_vbase_record *)a->cur;
  pcVar2 = (c1_vbase_record *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  iVar5 = 8;
  ppcVar4 = &pcVar1->vftables;
  pcVar3 = g_scope_vector->entries[(short)base_entry->key_ref];
  pcVar1->access = '\x03';
  pcVar1->base = pcVar3;
  do {
    copies = (c1_vtable_vector *)
             vector_copy(*(c1_vector **)
                          ((int)&((g_scope_vector->entries[(short)base_entry->key_ref]->detail).cls)
                                 ->size + iVar5),arena,class_vtable_record_copy_for_vbase);
    *ppcVar4 = copies;
    class_vtable_vector_link_copies
              (copies,*(c1_vtable_vector **)
                       ((int)&((g_scope_vector->entries[(short)base_entry->key_ref]->detail).cls)->
                              size + iVar5),base_entry);
    iVar5 = iVar5 + 4;
    ppcVar4 = ppcVar4 + 1;
  } while (iVar5 < 0x10);
  return pcVar1;
}

