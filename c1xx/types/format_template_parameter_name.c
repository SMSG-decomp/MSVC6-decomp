char * __cdecl format_template_parameter_name(short code)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  c1_dlist_node *pcVar4;
  
  uVar2 = (int)code >> 8;
  if ((0 < (int)uVar2) && (uVar2 <= (uint)g_format_template_arg_depth)) {
    pcVar4 = g_format_template_arg_stack->next;
    if (1 < (int)uVar2) {
      iVar3 = uVar2 - 1;
      do {
        pcVar4 = pcVar4->next;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (pcVar4->value != (void *)0x0) {
      uVar2 = 1;
      for (piVar1 = *(int **)((int)pcVar4->value + 4); piVar1 != (int *)0x0;
          piVar1 = (int *)piVar1[1]) {
        if (uVar2 == ((int)code & 0xffU)) {
          return *(char **)(*piVar1 + 4);
        }
        uVar2 = uVar2 + 1;
        if (piVar1 == (int *)0x0) {
          return (char *)0x0;
        }
      }
    }
  }
  return (char *)0x0;
}

