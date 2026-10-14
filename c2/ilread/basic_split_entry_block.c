void __fastcall basic_split_entry_block(c2_function *fn)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  
  pcVar2 = fn->cfg->last->end;
  uVar1 = pcVar2->kind;
  while (uVar1 != '\x18') {
    pcVar2 = pcVar2->prev;
    uVar1 = pcVar2->kind;
  }
  pcVar2 = pcVar2->next;
  for (pcVar4 = pcVar2; (pcVar4->kind == '\x1a' || ((pcVar4->flags & 1) != 0));
      pcVar4 = pcVar4->next) {
  }
  g_vb_entry_tail_chain = pcVar2;
  pcVar4->prev->next = (c2_tuple *)0x0;
  pcVar4->prev = pcVar2->prev;
  pcVar3 = pcVar2->prev;
  pcVar2->prev = (c2_tuple *)0x0;
  pcVar3->next = pcVar4;
  return;
}

