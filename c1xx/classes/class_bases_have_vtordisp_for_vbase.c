char __cdecl class_bases_have_vtordisp_for_vbase(c1_symbol *cls,c1_symbol *vbase)

{
  c1_vbase_record *pcVar1;
  c1_sym_link *first;
  c1_symbol *pcVar2;
  byte bVar3;
  int *piVar4;
  char local_18 [4];
  int *local_14;
  int *local_10;
  int *local_c;
  fe_name **local_8;
  int iter_filter;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((cls->x28).members)->head;
  }
  list_cursor_init(local_18,first);
  iter_filter = 4;
  piVar4 = local_14;
  local_c = (int *)0x0;
  local_8 = &cls->name;
  if (local_18[0] != '\0') {
    local_c = local_14;
  }
  do {
    do {
      do {
        while( true ) {
          local_10 = local_c;
          if (local_10 == (int *)0x0) {
            return '\0';
          }
          if ((piVar4 == (int *)0x0) ||
             (piVar4 = (int *)piVar4[1], local_c = piVar4, local_14 = piVar4, piVar4 == (int *)0x0))
          {
            local_c = (int *)0x0;
          }
          if ((*(byte *)(local_10 + -2) & 0x1f) != 3) break;
          if (((void *)*local_10 != g_name_vbptr) && ((void *)*local_10 != g_name_vfptr)) {
            return '\0';
          }
        }
      } while ((((g_compile_flags_cc & 0x100000) != 0) && ((*(byte *)(local_10 + -2) & 0x1f) == 0xf)
               ) && ((*(byte *)((int)local_10 + 0x12) & 2) != 0));
      if ((*(byte *)(local_10 + -2) & 0x1f) != 0xf) {
        return '\0';
      }
      bVar3 = *(byte *)((int)local_10 + 0x12) & 2;
      if (bVar3 == 0) {
        pcVar2 = g_scope_vector->entries[(short)local_10[4]];
      }
      else {
        pcVar2 = (c1_symbol *)0x0;
      }
    } while (((pcVar2->detail).cls)->vbases == (c1_vbase_vector *)0x0);
    if (bVar3 == 0) {
      pcVar2 = g_scope_vector->entries[(short)local_10[4]];
    }
    else {
      pcVar2 = (c1_symbol *)0x0;
    }
    pcVar1 = class_find_base_record(vbase,((pcVar2->detail).cls)->vbases);
    piVar4 = local_14;
    local_c = local_c;
  } while ((pcVar1 == (c1_vbase_record *)0x0) || (local_c = local_c, pcVar1->needs_vtordisp == '\0')
          );
  return '\x01';
}

