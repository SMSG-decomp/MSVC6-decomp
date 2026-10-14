void __cdecl tu_emit_pending_vtables(void)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_record *rec;
  c1_symbol *cls;
  char cVar2;
  int iVar3;
  short sVar4;
  ushort *puVar5;
  short sVar6;
  int local_18;
  c1_symbol_vector_iter local_c;
  
  if (g_pending_vtable_classes != (short *)0x0) {
    vector_iterator_init(&local_c,(c1_symbol_vector *)g_pending_vtable_classes);
    cVar2 = vector_iter_next((int *)&local_c);
    cls = local_c.current;
    while (cVar2 != '\0') {
      local_18 = 8;
      local_c.current = cls;
      do {
        sVar6 = 0;
        sVar4 = 0;
        puVar5 = *(ushort **)((int)&((cls->detail).cls)->size + local_18);
        pcVar1 = ((cls->detail).cls)->vbases;
        while( true ) {
          while ((puVar5 != (ushort *)0x0 && ((int)sVar6 < (int)(uint)*puVar5))) {
            iVar3 = (int)sVar6;
            sVar6 = sVar6 + 1;
            rec = *(c1_vtable_record **)(*(int *)(puVar5 + 4) + iVar3 * 4);
            if (rec->emitted == '\0') {
              vtable_record_emit(rec,cls);
            }
          }
          if ((pcVar1 == (c1_vbase_vector *)0x0) ||
             (iVar3 = (int)sVar4, (int)(uint)pcVar1->count <= iVar3)) break;
          sVar4 = sVar4 + 1;
          sVar6 = 0;
          puVar5 = *(ushort **)((int)&pcVar1->data[iVar3]->vbase_index + local_18);
        }
        local_18 = local_18 + 4;
      } while (local_18 < 0x10);
      cVar2 = vector_iter_next((int *)&local_c);
      cls = local_c.current;
    }
  }
  return;
}

