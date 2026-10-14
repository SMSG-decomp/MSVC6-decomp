void assign_eh_object_homes(void)

{
  c2_cxx_catch *pcVar1;
  c2_fe_symbol *pcVar2;
  uint uVar3;
  c2_cxx_try_block *prev;
  int iVar4;
  
  for (prev = eh_next_unhandled_object((c2_cxx_try_block *)0x0); prev != (c2_cxx_try_block *)0x0;
      prev = eh_next_unhandled_object(prev)) {
    for (pcVar1 = prev->catches; pcVar1 != (c2_cxx_catch *)0x0; pcVar1 = pcVar1->next) {
      pcVar2 = pcVar1->object;
      if ((pcVar2 != (c2_fe_symbol *)0x0) && (uVar3 = pcVar2->attrs, (uVar3 & 0x800) == 0)) {
        iVar4 = frame_alloc_local(pcVar2->size,0);
        pcVar2->offset = iVar4;
        pcVar2->attrs = uVar3 | 0x800;
      }
    }
  }
  return;
}

