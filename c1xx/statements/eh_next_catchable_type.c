uint * __cdecl eh_next_catchable_type(uint *value,int flag)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  c1_u8 *rec;
  c1_symbol *pcVar4;
  c1_type *pcVar5;
  c1_catchable_type *pcVar6;
  c1_type *pcVar7;
  uint *puVar8;
  uint uVar9;
  c1_type local_20;
  c1_type local_10;
  
  do {
    while( true ) {
      if ((c1_catchable_type *)value == (c1_catchable_type *)0x0) {
        return (uint *)0x0;
      }
      uVar9 = ((c1_catchable_type *)value)->flags;
      if ((uVar9 & 0x100) == 0) {
        ((c1_catchable_type *)value)->flags = ((c1_catchable_type *)value)->flags | 0x100;
        uVar9 = eh_catchable_type_access_flags((c1_catchable_type *)value,(char)flag);
        if ((((uVar9 != 0) &&
             (((c1_catchable_type *)value)->flags = ((c1_catchable_type *)value)->flags | uVar9,
             (char)flag == '\0')) ||
            ((uVar9 = eh_catchable_type_register((c1_catchable_type *)value,(char)flag), uVar9 != 0
             && (((c1_catchable_type *)value)->flags = ((c1_catchable_type *)value)->flags | uVar9,
                (char)flag == '\0')))) && (g_warning_state->level < 4)) {
          puVar8 = eh_next_catchable_type((uint *)((c1_catchable_type *)value)->derived,0);
          return puVar8;
        }
        return (uint *)(c1_catchable_type *)value;
      }
      if (((char)flag != '\0') || ((uVar9 & 20000) == 0)) break;
LAB_104aaab6:
      value = (uint *)((c1_catchable_type *)value)->derived;
    }
    if ((uVar9 & 0xd) == 0) {
      return (uint *)0x0;
    }
LAB_104aaa79:
    pvVar2 = (((c1_catchable_type *)value)->bases).next;
    (((c1_catchable_type *)value)->bases).current = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_104aaab6;
    pvVar2 = (((c1_catchable_type *)value)->bases).cursor.current;
    if (pvVar2 == (void *)0x0) {
LAB_104aaabd:
      (((c1_catchable_type *)value)->bases).next = (void *)0x0;
    }
    else {
      pvVar2 = *(void **)((int)pvVar2 + 4);
      (((c1_catchable_type *)value)->bases).cursor.current = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_104aaabd;
      (((c1_catchable_type *)value)->bases).next = pvVar2;
    }
    rec = g_arenas[5].cur;
    piVar3 = (((c1_catchable_type *)value)->bases).current;
    if ((*(byte *)(piVar3 + -2) & 0x1f) == 3) {
      if (((void *)*piVar3 == g_name_vbptr) || ((void *)*piVar3 == g_name_vfptr)) goto LAB_104aaa79;
      goto LAB_104aaab6;
    }
    if (((g_compile_flags_cc & 0x100000) != 0) &&
       (((*(byte *)(piVar3 + -2) & 0x1f) == 0xf && ((*(byte *)((int)piVar3 + 0x12) & 2) != 0))))
    goto LAB_104aaa79;
    if ((*(byte *)((int)(((c1_catchable_type *)value)->bases).current + -8) & 0x1f) != 0xf)
    goto LAB_104aaab6;
    g_arenas[5].cur = g_arenas[5].cur + 0x44;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    pvVar2 = (((c1_catchable_type *)value)->bases).current;
    if ((*(byte *)((int)pvVar2 + 0x12) & 2) == 0) {
      local_20.extra = *(c1_type_extra *)(g_scope_vector->entries + *(short *)((int)pvVar2 + 0x10));
    }
    else {
      local_20.extra.cls = (c1_symbol *)0x0;
    }
    pvVar2 = (((c1_catchable_type *)value)->bases).current;
    if ((*(byte *)((int)pvVar2 + 0x12) & 2) == 0) {
      pcVar4 = g_scope_vector->entries[*(short *)((int)pvVar2 + 0x10)];
    }
    else {
      pcVar4 = (c1_symbol *)0x0;
    }
    pcVar7 = pcVar4->type;
    cVar1 = (char)pcVar7->code;
    while (cVar1 < '\0') {
      pcVar7 = pcVar7->base;
      cVar1 = (char)pcVar7->code;
    }
    local_20.code = pcVar7->code;
    local_20.base = (c1_type *)0x0;
    local_20.debug_index = 0;
    local_20.flags = 0;
    pcVar5 = type_intern(&local_20);
    *(c1_type **)(rec + 8) = pcVar5;
    pcVar7 = ((c1_catchable_type *)value)->type;
    if ((char)pcVar7->code < '\0') {
      if (pcVar7->base != pcVar5) {
        local_10.code = pcVar7->code;
        local_10.flags = pcVar7->flags;
        local_10.extra = pcVar7->extra;
        local_10.debug_index = pcVar7->debug_index;
        local_10.base = pcVar5;
        pcVar7 = type_intern(&local_10);
      }
      *(c1_type **)(rec + 8) = pcVar7;
    }
    pcVar6 = eh_catchable_type_init((c1_catchable_type *)rec,*(c1_type **)(rec + 8),(char)flag);
    pcVar6->derived = (c1_catchable_type *)value;
    pvVar2 = (((c1_catchable_type *)value)->bases).current;
    pcVar6->base = (c1_symbol *)((int)pvVar2 + -8);
    uVar9 = pcVar6->flags | ((c1_catchable_type *)value)->flags & 0x1000;
    pcVar6->flags = uVar9;
    if ((*(byte *)((int)pvVar2 + 0x12) & 1) == 0) {
      pcVar6->this_offset = *(int *)((int)pvVar2 + 0xc) + ((c1_catchable_type *)value)->this_offset;
      value = (uint *)pcVar6;
    }
    else {
      pcVar6->this_offset = 0;
      pcVar6->flags = uVar9 | 0x3000;
      value = (uint *)pcVar6;
    }
  } while( true );
}

