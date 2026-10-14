uint32_t __fastcall loop_body_is_scattered(c2_function *fn)

{
  c2_block *pcVar1;
  c2_loop *pcVar2;
  
  pcVar1 = fn->cfg->first;
  while( true ) {
    if (pcVar1 == (c2_block *)0x0) {
      return 0;
    }
    pcVar2 = pcVar1->loop;
    if (((pcVar2 != (c2_loop *)0x0) && ((pcVar2->flags & 1) == 0)) &&
       (pcVar2->last->rpo < pcVar1->rpo)) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

