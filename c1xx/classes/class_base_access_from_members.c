char __cdecl class_base_access_from_members(int base,c1_symbol *cls)

{
  char cVar1;
  c1_symbol *pcVar2;
  c1_vbase_record *pcVar3;
  byte bVar4;
  byte best;
  int *piVar5;
  byte local_19;
  c1_list_cursor local_18;
  int *local_10;
  int *local_c;
  fe_name **local_8;
  int iter_filter;
  
  best = 0;
  local_19 = 0;
  list_cursor_init_from_head(&local_18,(cls->x28).members);
  iter_filter = 4;
  piVar5 = local_18.current;
  local_c = (int *)0x0;
  local_8 = &cls->name;
  if (local_18.valid != '\0') {
    local_c = local_18.current;
  }
LAB_10451cd9:
  do {
    while( true ) {
      local_10 = local_c;
      if (local_10 == (int *)0x0) {
        return best;
      }
      if ((piVar5 == (int *)0x0) ||
         (piVar5 = (int *)piVar5[1], local_c = piVar5, local_18.current = piVar5,
         piVar5 == (int *)0x0)) {
        local_c = (int *)0x0;
      }
      if ((*(byte *)(local_10 + -2) & 0x1f) != 3) break;
      if (((void *)*local_10 != g_name_vbptr) && ((void *)*local_10 != g_name_vfptr)) {
        cVar1 = class_base_access_from_members_tail(best);
        return cVar1;
      }
    }
  } while ((((g_compile_flags_cc & 0x100000) != 0) && ((*(byte *)(local_10 + -2) & 0x1f) == 0xf)) &&
          ((*(byte *)((int)local_10 + 0x12) & 2) != 0));
  if ((*(byte *)(local_10 + -2) & 0x1f) != 0xf) {
    return best;
  }
  bVar4 = *(byte *)((int)local_10 + 0x12) & 2;
  if (bVar4 == 0) {
    pcVar2 = g_scope_vector->entries[(short)local_10[4]];
    best = local_19;
  }
  else {
    pcVar2 = (c1_symbol *)0x0;
  }
  if (pcVar2 != (c1_symbol *)base) goto LAB_104aef98;
  bVar4 = *(byte *)((int)local_10 + -6) & 3;
  goto LAB_10451d5d;
LAB_104aef98:
  if (bVar4 == 0) {
    pcVar2 = g_scope_vector->entries[(short)local_10[4]];
  }
  else {
    pcVar2 = (c1_symbol *)0x0;
  }
  pcVar3 = class_find_base_record((c1_symbol *)base,((pcVar2->detail).cls)->vbases);
  piVar5 = local_18.current;
  if (pcVar3 != (c1_vbase_record *)0x0) {
    bVar4 = access_compose(pcVar3->access,*(byte *)((int)local_10 + -6) & 3);
    piVar5 = local_18.current;
LAB_10451d5d:
    if (best < bVar4) {
      best = bVar4;
      local_19 = bVar4;
    }
  }
  goto LAB_10451cd9;
}

