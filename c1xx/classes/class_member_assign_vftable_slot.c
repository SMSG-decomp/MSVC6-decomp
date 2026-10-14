void __cdecl class_member_assign_vftable_slot(c1_sym_link *fn,c1_symbol *cls)

{
  byte bVar1;
  int iVar2;
  c1_vtable_record *rec;
  c1_symbol_type_word cVar3;
  c1_u8 needs_vtordisp;
  c1_vtable_slot local_34;
  int local_24;
  c1_vtable_vector *local_20;
  short local_1c;
  c1_vtable_record *local_18;
  c1_vbase_vector *local_14;
  short vbase_index;
  int local_c;
  c1_vtable_record *local_8;
  int local_4;
  
  local_24 = 0;
  local_4 = 0;
  local_20 = ((cls->detail).cls)->vftables;
  local_1c = 0;
  local_14 = ((cls->detail).cls)->vbases;
  vbase_index = 0;
  while( true ) {
    while ((local_20 != (c1_vtable_vector *)0x0 && ((int)local_1c < (int)(uint)local_20->count))) {
      iVar2 = (int)local_1c;
      local_1c = local_1c + 1;
      local_18 = local_20->data[iVar2];
      if ((local_4 == 0) || (*(char *)(local_4 + 0x1d) == '\0')) {
        needs_vtordisp = '\0';
      }
      else {
        needs_vtordisp = '\x01';
      }
      local_8 = local_18;
      class_override_vtable_slots((int *)fn,local_18,cls,needs_vtordisp);
    }
    iVar2 = vector_iterator_next((uint *)&local_14);
    if ((char)iVar2 == '\0') break;
    local_4 = local_c;
    local_20 = *(c1_vtable_vector **)(local_c + 0x14 + local_24 * 4);
    local_1c = 0;
  }
  bVar1 = *(byte *)((int)&fn[1].position + 1);
  if ((*(byte *)&fn[2].type & 2) != 0) {
    *(byte *)((int)&fn[1].position + 1) = bVar1 | 2;
    fn->name->flags = fn->name->flags | 0x100000;
    return;
  }
  if ((bVar1 & 2) != 0) {
    rec = class_first_vftable_record(cls);
    class_vtable_slot_init(&local_34,(int *)fn);
    class_vtable_record_append_slot(rec,&local_34);
    iVar2 = type_size((fn->type).type);
    cVar3 = (c1_symbol_type_word)class_vtable_record_reserve_bytes(rec,iVar2);
    fn[1].type = cVar3;
    *(c1_u16 *)((int)&fn[2].name + 2) = ((cls->detail).cls)->scope_index;
  }
  return;
}

