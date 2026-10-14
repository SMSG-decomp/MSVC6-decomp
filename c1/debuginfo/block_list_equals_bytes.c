byte __cdecl block_list_equals_bytes(c1_byte_block_list *list,c1_u8 *bytes,uint n)

{
  c1_byte_block *pcVar1;
  uint uVar2;
  uint uVar3;
  c1_u8 *block_cursor;
  c1_u8 *bytes_cursor;
  bool bVar4;
  
  block_list_rewind(list);
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
    bVar4 = true;
    uVar3 = uVar2;
    block_cursor = pcVar1->data;
    bytes_cursor = bytes;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar4 = *block_cursor == *bytes_cursor;
      block_cursor = block_cursor + 1;
      bytes_cursor = bytes_cursor + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0;
    }
    pcVar1 = pcVar1->next;
    n = n - uVar2;
  } while( true );
}

