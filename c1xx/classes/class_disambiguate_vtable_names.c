void __cdecl class_disambiguate_vtable_names(c1_symbol *cls)

{
  c1_vbase_vector *pcVar1;
  c1_vbase_vector *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  short sVar8;
  int local_4c;
  ushort *local_44;
  short local_40;
  short local_34;
  short local_10;
  
  local_4c = 8;
  do {
    local_44 = *(ushort **)((int)&((cls->detail).cls)->size + local_4c);
    pcVar1 = ((cls->detail).cls)->vbases;
    local_40 = 0;
    local_34 = 0;
    while( true ) {
      while ((local_44 != (ushort *)0x0 && ((int)local_40 < (int)(uint)*local_44))) {
        sVar8 = 0;
        iVar5 = (int)local_40;
        local_40 = local_40 + 1;
        iVar5 = *(int *)(*(int *)(local_44 + 4) + iVar5 * 4);
        if (*(int *)(iVar5 + 0x30) != 0) {
          bVar3 = false;
          local_10 = 0;
          puVar7 = *(ushort **)((int)&((cls->detail).cls)->size + local_4c);
          pcVar2 = ((cls->detail).cls)->vbases;
          while( true ) {
            while ((puVar7 != (ushort *)0x0 && ((int)sVar8 < (int)(uint)*puVar7))) {
              iVar6 = (int)sVar8;
              sVar8 = sVar8 + 1;
              iVar6 = *(int *)(*(int *)(puVar7 + 4) + iVar6 * 4);
              if ((*(int *)(iVar6 + 0x30) != 0) &&
                 ((iVar6 != iVar5 &&
                  (cVar4 = vector_equal(*(c1_vector **)(iVar5 + 0x34),*(c1_vector **)(iVar6 + 0x34))
                  , cVar4 != '\0')))) {
                bVar3 = true;
                vector_push(*(c1_vector **)(iVar6 + 0x34),*(void **)(iVar6 + 0x30));
                *(undefined4 *)(iVar6 + 0x30) = 0;
              }
            }
            if ((pcVar2 == (c1_vbase_vector *)0x0) ||
               (iVar6 = (int)local_10, (int)(uint)pcVar2->count <= iVar6)) break;
            local_10 = local_10 + 1;
            sVar8 = 0;
            puVar7 = *(ushort **)((int)&pcVar2->data[iVar6]->vbase_index + local_4c);
          }
          if (bVar3) {
            vector_push(*(c1_vector **)(iVar5 + 0x34),*(void **)(iVar5 + 0x30));
            *(undefined4 *)(iVar5 + 0x30) = 0;
          }
        }
      }
      if ((pcVar1 == (c1_vbase_vector *)0x0) ||
         (iVar5 = (int)local_34, (int)(uint)pcVar1->count <= iVar5)) break;
      local_34 = local_34 + 1;
      local_40 = 0;
      local_44 = *(ushort **)((int)&pcVar1->data[iVar5]->vbase_index + local_4c);
    }
    local_4c = local_4c + 4;
  } while (local_4c < 0x10);
  return;
}

