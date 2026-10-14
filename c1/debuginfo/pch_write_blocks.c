int __cdecl pch_write_blocks(c1_byte_block_list *list,FILE *f,c1_byte_block_list *dst)

{
  uint uVar1;
  c1_byte_block *src;
  int local_4;
  
  local_4 = 0;
  block_list_rewind(list);
  src = list->block;
  if (src != (c1_byte_block *)0x0) {
    do {
      uVar1 = src->used;
      if (uVar1 == 0) {
        uVar1 = 0x7f8;
      }
      if (f == (FILE *)0x0) {
        if (dst != (c1_byte_block_list *)0x0) {
          buffer_chain_append_bytes(src,1,uVar1 & 0xffff,dst);
        }
      }
      else {
        fwrite(src,1,uVar1 & 0xffff,f);
      }
      src = src->next;
      local_4 = local_4 + (uVar1 & 0xffff);
    } while (src != (c1_byte_block *)0x0);
    return local_4;
  }
  return 0;
}

