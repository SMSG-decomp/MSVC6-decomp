void x87_snapshot_stack(void)

{
  int iVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  
  g_x87_saved_tos = g_x87_tos;
  puVar2 = g_x87_stack_ids;
  puVar3 = g_x87_saved_stack_ids;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

