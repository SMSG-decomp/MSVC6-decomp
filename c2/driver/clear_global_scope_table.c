void clear_global_scope_table(void)

{
  int iVar1;
  c2_fe_symbol **ppcVar2;
  
  g_global_scope.parent = (c2_scope_table *)0x0;
  ppcVar2 = g_global_scope.buckets;
  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar2 = (c2_fe_symbol *)0x0;
    ppcVar2 = ppcVar2 + 1;
  }
  return;
}

