void __cdecl class_collect_conversion_types(c1_symbol *cls)

{
  bool bVar1;
  char cVar2;
  short *psVar3;
  c1_symbol_vector *pcVar4;
  int iVar5;
  c1_type *pcVar6;
  c1_symbol *pcVar7;
  int *piVar8;
  byte bVar9;
  int *piVar10;
  short *local_2c;
  c1_symbol_vector_iter local_24;
  c1_member_iter local_18;
  
  local_2c = (short *)symtab_record_new_kind4();
  psVar3 = (short *)symtab_record_new_kind4();
  bVar1 = false;
  if ((((cls->detail).cls)->flags3f & 4) != 0) {
    bVar1 = true;
    class_member_iter_init(&local_18,&cls->name,4);
    piVar10 = local_18.cursor.current;
    piVar8 = local_18.next;
    do {
      while( true ) {
        local_18.next = piVar8;
        piVar8 = local_18.next;
        if (local_18.next == (int *)0x0) goto LAB_1041d3d1;
        if ((piVar10 == (int *)0x0) ||
           (piVar8 = (int *)piVar10[1], piVar10 = piVar8, local_18.cursor.current = piVar8,
           piVar8 == (int *)0x0)) {
          piVar8 = (int *)0x0;
        }
        if ((*(byte *)((int)local_18.next + -8) & 0x1f) == 3) break;
        if (((g_compile_flags_cc & 0x100000) == 0) ||
           (((*(byte *)((int)local_18.next + -8) & 0x1f) != 0xf ||
            ((*(byte *)((int)local_18.next + 0x12) & 2) == 0)))) {
          if ((*(byte *)((int)local_18.next + -8) & 0x1f) != 0xf) goto LAB_1041d3d1;
          bVar9 = *(byte *)((int)local_18.next + 0x12) & 2;
          if (bVar9 == 0) {
            pcVar7 = g_scope_vector->entries[(short)*(int *)((int)local_18.next + 0x10)];
          }
          else {
            pcVar7 = (c1_symbol *)0x0;
          }
          if ((((pcVar7->detail).cls)->flags3f & 2) != 0) {
            if (bVar9 == 0) {
              pcVar7 = g_scope_vector->entries[(short)*(int *)((int)local_18.next + 0x10)];
            }
            else {
              pcVar7 = (c1_symbol *)0x0;
            }
            local_18.current = local_18.next;
            local_18.next = piVar8;
            psVar3 = type_set_union(psVar3,((pcVar7->detail).cls)->repeated_conversion_types);
            piVar10 = local_18.cursor.current;
            piVar8 = local_18.next;
          }
        }
      }
    } while ((*(void **)local_18.next == g_name_vbptr) || (*(void **)local_18.next == g_name_vfptr))
    ;
LAB_1041d3d1:
    local_18.next = piVar8;
    if (*(int *)((int)local_18.cls + 0x20) == 0) {
      local_18.cursor.current = (int *)0x0;
    }
    else {
      local_18.cursor.current = *(void **)(*(int *)((int)local_18.cls + 0x20) + 4);
    }
    local_18.cursor.valid = local_18.cursor.current != (int *)0x0;
    if ((bool)local_18.cursor.valid) {
      local_18.next = local_18.cursor.current;
    }
    do {
      while( true ) {
        local_18.current = local_18.next;
        if (local_18.next == (int *)0x0) goto LAB_1041d43e;
        iVar5 = class_member_iter_step(&local_18.cursor);
        local_18.next = (void *)(-(uint)((char)iVar5 != '\0') & (uint)local_18.cursor.current);
        if ((*(byte *)((int)local_18.current + -8) & 0x1f) == 3) break;
        if (((g_compile_flags_cc & 0x100000) == 0) ||
           (((*(byte *)((int)local_18.current + -8) & 0x1f) != 0xf ||
            ((*(byte *)((int)local_18.current + 0x12) & 2) == 0)))) {
          if ((*(byte *)((int)local_18.current + -8) & 0x1f) != 0xf) goto LAB_1041d43e;
          if ((*(byte *)((int)local_18.current + 0x12) & 2) == 0) {
            pcVar7 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
          }
          else {
            pcVar7 = (c1_symbol *)0x0;
          }
          vector_iterator_init(&local_24,((pcVar7->detail).cls)->conversion_functions);
          cVar2 = vector_iter_next((int *)&local_24);
          pcVar7 = local_24.current;
          while (local_24.current = pcVar7, cVar2 != '\0') {
            cVar2 = vector_contains_type(local_2c,pcVar7);
            if (cVar2 == '\0') {
              local_2c = vector_find_or_add(local_2c,(int)pcVar7);
            }
            else {
              psVar3 = vector_find_or_add(psVar3,(int)pcVar7);
            }
            cVar2 = vector_iter_next((int *)&local_24);
            pcVar7 = local_24.current;
          }
        }
      }
    } while ((*(void **)local_18.current == g_name_vbptr) ||
            (*(void **)local_18.current == g_name_vfptr));
  }
LAB_1041d43e:
  bVar9 = ((cls->detail).cls)->flags3f;
  if ((bVar9 & 2) == 0) {
    if (bVar1) {
      ((cls->detail).cls)->flags3f = bVar9 | 2;
    }
  }
  else {
    class_conversion_iter_init(&local_18,cls);
    cVar2 = class_member_iter_next(&local_18);
    while (cVar2 != '\0') {
      pcVar6 = class_conversion_iter_result_type(&local_18);
      local_2c = vector_find_or_add(local_2c,(int)pcVar6);
      pcVar6 = class_conversion_iter_result_type(&local_18);
      psVar3 = vector_remove_type(psVar3,pcVar6);
      g_compile_flags_cc = g_compile_flags_cc | 0x80;
      cVar2 = class_member_iter_next(&local_18);
    }
  }
  pcVar4 = (c1_symbol_vector *)class_share_base_conversion_type_set(local_2c,cls);
  psVar3 = class_share_base_conversion_type_set(psVar3,cls);
  ((cls->detail).cls)->conversion_functions = pcVar4;
  ((cls->detail).cls)->repeated_conversion_types = psVar3;
  return;
}

