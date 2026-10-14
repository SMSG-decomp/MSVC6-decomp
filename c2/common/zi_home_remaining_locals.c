void zi_home_remaining_locals(void)

{
  uint8_t *puVar1;
  c2_fe_symbol *pcVar2;
  c2_enc_local *pcVar3;
  int iVar4;
  
  iVar4 = g_default_stack_align;
  for (pcVar3 = g_enc_local_list; pcVar3 != (c2_enc_local *)0x0; pcVar3 = pcVar3->next) {
    pcVar2 = pcVar3->sym;
    g_default_stack_align = iVar4;
    if ((pcVar2->attrs & 0x800) == 0) {
      pcVar2->attrs = pcVar2->attrs | 0x800;
      iVar4 = frame_alloc_local(pcVar2->size,iVar4);
      pcVar2->offset = iVar4;
      if (pcVar2->storage_sym != (c2_symbol *)0x0) {
        puVar1 = &pcVar2->storage_sym->flags5;
        *puVar1 = *puVar1 | 0x20;
      }
    }
    iVar4 = g_default_stack_align;
  }
  g_default_stack_align = iVar4;
  return;
}

