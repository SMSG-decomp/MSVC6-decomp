void __cdecl class_init_table_pointers(int cls,int kind,char mode)

{
  ushort *puVar1;
  c1_vtable_record *rec;
  char use_type;
  int iVar2;
  c1_node *value;
  c1_keyed_cell *member;
  ushort *puVar3;
  short sVar4;
  c1_type *type;
  byte *member_00;
  short local_10;
  
  sVar4 = 0;
  puVar3 = *(ushort **)(*(int *)(cls + 0x24) + 8 + kind * 4);
  puVar1 = *(ushort **)(*(int *)(cls + 0x24) + 0x10);
  local_10 = 0;
  while( true ) {
    while ((puVar3 != (ushort *)0x0 && ((int)sVar4 < (int)(uint)*puVar3))) {
      iVar2 = (int)sVar4;
      sVar4 = sVar4 + 1;
      rec = *(c1_vtable_record **)(*(int *)(puVar3 + 4) + iVar2 * 4);
      if ((kind == 0) || (kind == 2)) {
        use_type = '\x01';
      }
      else {
        use_type = '\0';
      }
      value = tree_new_symbol_ref(rec->table,use_type);
      if (mode == '\0') {
        member = scope_list_from_class(rec,(c1_symbol *)cls);
        class_member_init_by_copy((int *)member,value);
      }
      else {
        type = value->type;
        member_00 = (byte *)0x0;
        iVar2 = class_vtable_vptr_offset(rec);
        init_member_initializer_store(iVar2,&type->code,value,member_00);
      }
    }
    if ((puVar1 == (ushort *)0x0) || (iVar2 = (int)local_10, (int)(uint)*puVar1 <= iVar2)) break;
    local_10 = local_10 + 1;
    sVar4 = 0;
    puVar3 = *(ushort **)(*(int *)(*(int *)(puVar1 + 4) + iVar2 * 4) + 0x14 + kind * 4);
  }
  return;
}

