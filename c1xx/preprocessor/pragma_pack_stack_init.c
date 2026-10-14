void __cdecl pragma_pack_stack_init(void)

{
  c1_pack_cell *pcVar1;
  int iVar2;
  
  g_pack_stack = (c1_pack_stack *)arena_alloc_aligned(8);
  pcVar1 = list_alloc_cell(g_pack_stack);
  iVar2 = g_opt_Zp;
  if (g_opt_Zp == -1) {
    iVar2 = 8;
  }
  pcVar1->packing = iVar2;
  pcVar1->ident = (void *)0x0;
  pragma_pack_push(0,0);
  return;
}

