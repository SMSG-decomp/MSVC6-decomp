void pragma_pack_stack_init(void)

{
  int *piVar1;
  int iVar2;
  
  g_pack_stack = (fe_pack_stack *)arena_alloc_aligned(8);
  piVar1 = list_alloc_cell((int *)g_pack_stack);
  iVar2 = g_opt_Zp;
  if (g_opt_Zp == -1) {
    iVar2 = 8;
  }
  piVar1[1] = iVar2;
  piVar1[2] = 0;
  pragma_pack_push(0,0);
  return;
}

