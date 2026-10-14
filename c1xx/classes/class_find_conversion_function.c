c1_symbol * __cdecl class_find_conversion_function(c1_type *type,c1_symbol *cls)

{
  c1_symbol_vector *v;
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  c1_symbol *pcVar5;
  c1_type *pcVar6;
  fe_name **ppfVar7;
  c1_type local_40;
  c1_member_iter local_30;
  c1_member_iter base_iter;
  
  v = ((cls->detail).cls)->conversion_functions;
  if ((v != (c1_symbol_vector *)0x0) &&
     (cVar1 = vector_contains_type((short *)v,type), cVar1 != '\0')) {
    ppfVar7 = &cls->name;
    list_cursor_init_from_head(&local_30.cursor,(cls->x28).members);
    local_30.next = (void *)0x0;
    local_30.filter = 5;
    local_30.cls = ppfVar7;
    if (local_30.cursor.valid != '\0') {
      local_30.next = local_30.cursor.current;
    }
    while (local_30.current = local_30.next, local_30.next != (void *)0x0) {
      if ((local_30.cursor.current == (void *)0x0) ||
         (local_30.cursor.current = *(void **)((int)local_30.cursor.current + 4),
         local_30.next = local_30.cursor.current, local_30.cursor.current == (void *)0x0)) {
        local_30.next = (void *)0x0;
      }
      uVar3 = class_member_iter_matches(&local_30);
      if ((char)uVar3 != '\0') {
        pcVar5 = (c1_symbol *)((int)local_30.current + -8);
        if ((*(byte *)((int)local_30.current + -8) & 0x1f) != 8) {
          pcVar5 = (c1_symbol *)ovl_first_function_of_set(pcVar5);
        }
        pcVar6 = pcVar5->type->base;
        if ((pcVar6->flags & 0x1f) != 0) {
          uVar3._0_2_ = pcVar6->code;
          uVar3._2_2_ = pcVar6->flags;
          local_40.base = pcVar6->base;
          local_40.extra = pcVar6->extra;
          local_40._0_4_ = uVar3 & 0x1fffff;
          local_40.debug_index = pcVar6->debug_index;
          pcVar6 = type_intern(&local_40);
        }
        if (pcVar6 == type) {
          return (c1_symbol *)((int)local_30.current + -8);
        }
      }
    }
    list_cursor_init_from_head(&base_iter.cursor,(cls->x28).members);
    base_iter.next = (void *)0x0;
    base_iter.filter = 4;
    base_iter.cls = ppfVar7;
    if (base_iter.cursor.valid != '\0') {
      base_iter.next = base_iter.cursor.current;
    }
    do {
      while( true ) {
        if (base_iter.next == (void *)0x0) {
          return (c1_symbol *)0x0;
        }
        base_iter.current = base_iter.next;
        iVar4 = class_member_iter_step(&base_iter.cursor);
        base_iter.next = (void *)(-(uint)((char)iVar4 != '\0') & (uint)base_iter.cursor.current);
        bVar2 = *(byte *)((int)base_iter.current + -8) & 0x1f;
        if (bVar2 == 3) break;
        if (((g_compile_flags_cc & 0x100000) == 0) ||
           ((bVar2 != 0xf || ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0)))) {
          if ((*(byte *)((int)base_iter.current + -8) & 0x1f) != 0xf) {
            return (c1_symbol *)0x0;
          }
          if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
            pcVar5 = g_scope_vector->entries[*(short *)((int)base_iter.current + 0x10)];
          }
          else {
            pcVar5 = (c1_symbol *)0x0;
          }
          pcVar5 = class_find_conversion_function(type,pcVar5);
          if (pcVar5 != (c1_symbol *)0x0) {
            return pcVar5;
          }
        }
      }
    } while ((*(void **)base_iter.current == g_name_vbptr) ||
            (*(void **)base_iter.current == g_name_vfptr));
  }
  return (c1_symbol *)0x0;
}

