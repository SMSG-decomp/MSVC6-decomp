int __cdecl mem_chain_read(c1_byte_block_list *cursor,void *dest,uint n)

{
  c1_u32 cVar1;
  c1_u8 *src;
  uint uVar2;
  c1_byte_block *pcVar3;
  int local_4;
  
  pcVar3 = cursor->block;
  local_4 = 0;
  if (pcVar3 == (c1_byte_block *)0x0) {
    return 0;
  }
  do {
    src = cursor->cur;
    cVar1 = cursor->used;
    if (pcVar3->used == 0) {
      if (0x7f8 - cVar1 < n) {
        cursor->used = 0;
        uVar2 = 0x7f8 - cVar1;
        n = n - uVar2;
        pcVar3 = cursor->block->next;
        cursor->block = pcVar3;
        cursor->cur = pcVar3->data;
      }
      else {
        cursor->used = cVar1 + n;
        pcVar3 = (c1_byte_block *)0x0;
        cursor->cur = src + n;
        uVar2 = n;
      }
    }
    else {
      uVar2 = pcVar3->used - cVar1;
      if (n <= uVar2) {
        uVar2 = n;
      }
      cursor->used = cVar1 + uVar2;
      cursor->cur = src + uVar2;
      pcVar3 = (c1_byte_block *)0x0;
    }
    local_4 = local_4 + uVar2;
    if (0 < (int)uVar2) {
      do {
        *(c1_u8 *)dest = *src;
        dest = (void *)((int)dest + 1);
        src = src + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  } while (pcVar3 != (c1_byte_block *)0x0);
  return local_4;
}

