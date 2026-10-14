void __cdecl vtable_record_write_data(c1_vtable_record *rec,c1_symbol *table,c1_symbol *cls)

{
  byte bVar1;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  void *name;
  c1_symbol *pcVar4;
  c1_node *pcVar5;
  int iVar6;
  c1_vtable_slot *slot;
  int iVar7;
  uint mode;
  c1_symbol *local_10;
  
  local_10 = sym_take_free_record(10,(void *)0x0,5);
  if (local_10 == (c1_symbol *)0x0) {
    pcVar3 = arena_alloc(g_arenas + 5,g_symbol_size_table[10] + 3 & 0xfffffffc);
    if (pcVar3 == (c1_symbol *)0x0) {
      local_10 = (c1_symbol *)0x0;
    }
    else {
      local_10 = sym_init_kind(pcVar3,'\n',(void *)0x0,5);
    }
  }
  bVar1 = table->storage;
  table->flags2 = table->flags2 | 4;
  table->flags4 = table->flags4 | 4;
  table->storage = bVar1 | 0x40;
  table->storage = (bVar1 & 0xf8 | 0x40) ^ 2;
  init_emit_symbol_data(table,(c1_node *)0x0,&g_il_in);
  pcVar3 = cls;
  if ((g_rtti != '\0') && ((rec->kind == 0 || (rec->kind == 2)))) {
    name = name_intern_rtti_locator_name((int)table);
    iVar7 = 0;
    iVar6 = class_vtable_vptr_offset(rec);
    pcVar4 = rtti_symbol_new(cls,iVar6,iVar7,name);
    pcVar5 = expr_reference_named_entity(pcVar4,0);
    pcVar3 = (c1_symbol *)expr_build_unary(0x31,pcVar5);
    pcVar2 = pcVar4->type;
    pcVar4->type = *(c1_type **)&pcVar3->flags4;
    init_emit_initializer(pcVar4,(c1_node *)pcVar3,&g_il_in);
    pcVar4->type = pcVar2;
  }
  iVar6 = 0;
  local_10->name = (fe_name *)0x0;
  while (iVar6 < rec->nslots) {
    slot = rec->slots + iVar6;
    iVar6 = iVar6 + 1;
    if (slot == (c1_vtable_slot *)0x0) break;
    switch(rec->kind) {
    case 0:
    case 2:
      pcVar4 = vtable_slot_target(slot,cls,rec);
      if ((*(byte *)(slot->member + 0xb) & 4) == 0) {
        mode = 0x10;
        pcVar5 = tree_new_symbol_ref(pcVar4,'\x01');
        pcVar3 = (c1_symbol *)expr_build_address_of(pcVar5,mode);
      }
      else {
        pcVar3 = (c1_symbol *)vtable_purecall_slot_value((int)(slot->member + -2));
      }
      if (((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) &&
         ((pcVar4->flags21 & 1) != 0)) {
        mre_note_member_use(g_minimal_rebuild_tracker,cls,pcVar4->name);
      }
      break;
    case 1:
    case 3:
      iVar7 = class_vbtable_entry_offset((int *)slot,cls,rec);
      pcVar3 = (c1_symbol *)tree_new_int_constant(iVar7);
    }
    local_10->type = *(c1_type **)&pcVar3->flags4;
    init_emit_initializer(local_10,(c1_node *)pcVar3,&g_il_in);
  }
  il_emit_in_marker();
  return;
}

