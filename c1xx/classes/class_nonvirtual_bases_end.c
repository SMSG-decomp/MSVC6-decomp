int __cdecl class_nonvirtual_bases_end(c1_symbol *cls)

{
  c1_sym_link *first;
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  char local_18 [4];
  int *local_14;
  
  pcVar3 = (char *)0x0;
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((cls->x28).members)->head;
  }
  list_cursor_init(local_18,first);
  piVar2 = (int *)0x0;
  if (local_18[0] != '\0') {
    piVar2 = local_14;
  }
  do {
    while( true ) {
      piVar1 = piVar2;
      if (piVar1 == (int *)0x0) {
        return (int)pcVar3;
      }
      if ((local_14 == (int *)0x0) ||
         (piVar2 = (int *)local_14[1], local_14 = piVar2, piVar2 == (int *)0x0)) {
        piVar2 = (int *)0x0;
      }
      if ((*(byte *)(piVar1 + -2) & 0x1f) == 3) break;
      if ((((g_compile_flags_cc._2_1_ & 0x10) == 0) || ((*(byte *)(piVar1 + -2) & 0x1f) != 0xf)) ||
         ((*(byte *)((int)piVar1 + 0x12) & 2) == 0)) {
        if ((*(byte *)(piVar1 + -2) & 0x1f) != 0xf) {
          return (int)pcVar3;
        }
        if ((*(byte *)((int)piVar1 + 0x12) & 1) == 0) {
          if ((*(byte *)((int)piVar1 + 0x12) & 2) == 0) {
            pcVar3 = ((g_scope_vector->entries[(short)piVar1[4]]->detail).segment_class)->text +
                     piVar1[3];
          }
          else {
            pcVar3 = (char *)(*(int *)(iRam00000024 + 4) + piVar1[3]);
          }
        }
      }
    }
  } while (((void *)*piVar1 == g_name_vbptr) || ((void *)*piVar1 == g_name_vfptr));
  return (int)pcVar3;
}

