void * seh_innermost_scope_without_filter(void)

{
  int iVar1;
  int *piVar2;
  
  if (g_seh_scope_depth != 0) {
    piVar2 = &g_seh_except_nesting + g_seh_scope_depth;
    iVar1 = g_seh_scope_depth;
    do {
      if (*(int *)(*piVar2 + 4) == 0) {
        return (void *)(&g_seh_except_nesting)[iVar1];
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -1;
    } while (iVar1 != 0);
  }
  return (void *)0x0;
}

