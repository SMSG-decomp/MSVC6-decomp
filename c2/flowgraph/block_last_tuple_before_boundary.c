c2_tuple * __fastcall block_last_tuple_before_boundary(c2_block *block)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar2 = block->head->next;
  pcVar3 = pcVar2->next;
  uVar1 = pcVar3->kind;
  while (uVar1 != '\x19') {
    uVar1 = pcVar3->next->kind;
    pcVar2 = pcVar3;
    pcVar3 = pcVar3->next;
  }
  return pcVar2;
}

