short * __cdecl class_share_base_conversion_type_set(short *set,c1_symbol *cls)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  c1_symbol *pcVar4;
  void *pvVar5;
  c1_symbol_vector *pcVar6;
  void *pvVar7;
  c1_symbol_vector *local_1c;
  c1_member_iter base_iter;
  
  local_1c = (c1_symbol_vector *)0x0;
  if (set == (short *)0x0) {
    return (short *)0x0;
  }
  uVar3 = counted_array_count((ushort *)set);
  pcVar6 = g_empty_symbol_vector;
  pvVar5 = base_iter.next;
  if (uVar3 != 0) {
    list_cursor_init_from_head(&base_iter.cursor,(cls->x28).members);
    base_iter.next = (void *)0x0;
    base_iter.filter = 4;
    pvVar7 = base_iter.cursor.current;
    pvVar5 = base_iter.next;
    base_iter.cls = &cls->name;
    if (base_iter.cursor.valid != '\0') {
      base_iter.next = base_iter.cursor.current;
      pvVar5 = base_iter.next;
    }
    do {
      while( true ) {
        base_iter.next = pvVar5;
        pcVar6 = local_1c;
        base_iter.current = base_iter.next;
        pvVar5 = base_iter.next;
        if (base_iter.next == (void *)0x0) goto LAB_1041d6ac;
        if ((pvVar7 == (void *)0x0) ||
           (pvVar5 = *(void **)((int)pvVar7 + 4), pvVar7 = pvVar5, base_iter.cursor.current = pvVar5
           , pvVar5 == (void *)0x0)) {
          pvVar5 = (void *)0x0;
        }
        bVar1 = *(byte *)((int)base_iter.next + -8) & 0x1f;
        if (bVar1 == 3) break;
        if ((((g_compile_flags_cc & 0x100000) == 0) || (bVar1 != 0xf)) ||
           ((*(byte *)((int)base_iter.next + 0x12) & 2) == 0)) {
          if ((*(byte *)((int)base_iter.next + -8) & 0x1f) != 0xf) goto LAB_1041d6ac;
          if (local_1c != (c1_symbol_vector *)0x0) {
            base_iter.next = pvVar5;
            vector_release((int)set);
            return (short *)local_1c;
          }
          if ((*(byte *)((int)base_iter.next + 0x12) & 2) == 0) {
            pcVar4 = g_scope_vector->entries[*(short *)((int)base_iter.next + 0x10)];
          }
          else {
            pcVar4 = (c1_symbol *)0x0;
          }
          base_iter.next = pvVar5;
          cVar2 = type_set_equal(set,(short *)((pcVar4->detail).cls)->conversion_functions);
          if (cVar2 == '\0') {
            if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
              pcVar4 = g_scope_vector->entries[*(short *)((int)base_iter.current + 0x10)];
            }
            else {
              pcVar4 = (c1_symbol *)0x0;
            }
            cVar2 = type_set_equal(set,((pcVar4->detail).cls)->repeated_conversion_types);
            pvVar7 = base_iter.cursor.current;
            pvVar5 = base_iter.next;
            if (cVar2 != '\0') {
              if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
                local_1c = (c1_symbol_vector *)
                           ((g_scope_vector->entries[*(short *)((int)base_iter.current + 0x10)]->
                            detail).cls)->repeated_conversion_types;
              }
              else {
                local_1c = *(c1_symbol_vector **)(iRam00000024 + 0x1c);
              }
            }
          }
          else {
            pvVar7 = base_iter.cursor.current;
            if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
              local_1c = ((g_scope_vector->entries[*(short *)((int)base_iter.current + 0x10)]->
                          detail).cls)->conversion_functions;
              pvVar5 = base_iter.next;
            }
            else {
              local_1c = *(c1_symbol_vector **)(iRam00000024 + 0x18);
              pvVar5 = base_iter.next;
            }
          }
        }
      }
    } while ((*(void **)base_iter.next == g_name_vbptr) ||
            (*(void **)base_iter.next == g_name_vfptr));
  }
LAB_1041d6ac:
  base_iter.next = pvVar5;
  if (pcVar6 == (c1_symbol_vector *)0x0) {
    return set;
  }
  vector_release((int)set);
  return (short *)pcVar6;
}

