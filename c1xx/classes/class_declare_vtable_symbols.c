void __cdecl class_declare_vtable_symbols(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_record *rec;
  c1_symbol *pcVar2;
  int iVar3;
  ushort *puVar4;
  short sVar5;
  int local_2c;
  int local_28;
  short local_10;
  
  local_2c = 0;
  local_28 = 8;
  do {
    sVar5 = 0;
    local_10 = 0;
    puVar4 = *(ushort **)((int)&((cls->detail).cls)->size + local_28);
    pcVar1 = ((cls->detail).cls)->vbases;
    while( true ) {
      while ((puVar4 != (ushort *)0x0 && ((int)sVar5 < (int)(uint)*puVar4))) {
        iVar3 = (int)sVar5;
        sVar5 = sVar5 + 1;
        rec = *(c1_vtable_record **)(*(int *)(puVar4 + 4) + iVar3 * 4);
        pcVar2 = class_declare_vtable_symbol(local_2c,rec,cls);
        rec->table = pcVar2;
        if ((pcVar2 != (c1_symbol *)0x0) && ((rec->kind == 0 || (rec->kind == 2)))) {
          if ((pcVar2->flags22 & 8) == 0) {
            rec->alt_table = (c1_symbol *)0x0;
            rec->alt_used = '\0';
          }
          else {
            pcVar2 = class_declare_vtable_symbol(5,rec,cls);
            rec->alt_table = pcVar2;
            rec->alt_used = '\0';
          }
        }
      }
      if ((pcVar1 == (c1_vbase_vector *)0x0) ||
         (iVar3 = (int)local_10, (int)(uint)pcVar1->count <= iVar3)) break;
      local_10 = local_10 + 1;
      sVar5 = 0;
      puVar4 = *(ushort **)((int)&pcVar1->data[iVar3]->vbase_index + local_28);
    }
    local_28 = local_28 + 4;
    local_2c = local_2c + 1;
  } while (local_28 < 0x10);
  return;
}

