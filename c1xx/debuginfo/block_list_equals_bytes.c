byte __cdecl block_list_equals_bytes(c1_byte_block_list *list,char *bytes,uint n)

{
  c1_byte_block *pcVar1;
  uint uVar2;
  uint uVar3;
  c1_byte_block *pcVar4;
  c1_u8 *pcVar5;
  bool bVar6;
  
  block_list_rewind((int *)list);
  pcVar1 = list->block;
  do {
    if (pcVar1 == (c1_byte_block *)0x0) {
      return 1;
    }
    uVar2 = pcVar1->used;
    if (uVar2 == 0) {
      uVar2 = 0x7f8;
    }
    uVar2 = uVar2 & 0xffff;
    if (n < uVar2) {
      return 0;
    }
    bVar6 = true;
    uVar3 = uVar2;
    pcVar4 = pcVar1;
    pcVar5 = (c1_u8 *)bytes;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar6 = pcVar4->data[0] == *pcVar5;
      pcVar4 = (c1_byte_block *)(pcVar4->data + 1);
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      return 0;
    }
    pcVar1 = pcVar1->next;
    n = n - uVar2;
  } while( true );
}

