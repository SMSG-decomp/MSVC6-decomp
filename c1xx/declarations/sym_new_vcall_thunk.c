c1_symbol * __cdecl sym_new_vcall_thunk(c1_vcall_thunk_key *key)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  bool bVar7;
  
  pcVar3 = key->member;
  pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[pcVar3->kind & 0x1f] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_copy_unlinked(pcVar2,pcVar3,0);
  }
  if (g_next_entity_id < 0x7fffffff) {
    uVar6 = pcVar3->entity ^ g_next_entity_id;
    bVar5 = *(byte *)((int)&pcVar3->tail + 10);
    bVar1 = pcVar3->flags1;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar3->entity = uVar6 & 0xffffff ^ pcVar3->entity;
    *(byte *)((int)&pcVar3->tail + 10) = bVar5 & 0xf1;
    pcVar3->flags1 = bVar1 & 0xfb;
    pcVar3->next = (c1_symbol *)0x0;
    *(byte *)((int)&pcVar3->tail + 9) = *(byte *)((int)&pcVar3->tail + 9) | 0xc;
    sym_set_attribute_15e8(pcVar3,(void *)key->vtable_offset);
    pcVar3->flags2 = pcVar3->flags2 | 4;
    bVar5 = pcVar3->storage & 0xf8 ^ 1;
    pcVar3->storage = bVar5;
    pcVar3->storage = '\0';
    pcVar3->flags21 = '\0';
    pcVar3->flags22 = '\0';
    pcVar3->flags23 = '\0';
    bVar5 = (pcVar3->storage ^ bVar5 & 7) & 7 ^ pcVar3->storage;
    pcVar3->storage = bVar5;
    pcVar3->storage = bVar5 | 0x40;
    if ((pcVar3->flags23 & 1) != 0) {
      pcVar2 = sym_segment_record(key->member);
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar3->flags23 = pcVar3->flags23 & 0xfe;
      }
      else {
        sym_set_segment(pcVar3,pcVar2);
      }
    }
    pcVar3->key_ref = pcVar3->key_ref & 7;
    if ((g_il_block_level != '\0') &&
       (bVar7 = g_c9il_mode == '\0', pcVar3->flags3 = bVar7 << 4 | pcVar3->flags3 & 0xef, bVar7)) {
      iVar4 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb);
      if (iVar4 == 0) {
        diag_fatal(0x49,"p1inl.inl",0x2ee);
      }
    }
    return pcVar3;
  }
  diag_fatal_simple(0x37);
}

