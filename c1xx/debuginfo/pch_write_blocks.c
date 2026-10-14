int __cdecl pch_write_blocks(int *list,FILE *f,int dst)

{
  uint uVar1;
  void *src;
  int local_4;
  
  local_4 = 0;
  block_list_rewind(list);
  src = (void *)list[2];
  if (src != (void *)0x0) {
    do {
      uVar1 = *(uint *)((int)src + 0x7fc);
      if (uVar1 == 0) {
        uVar1 = 0x7f8;
      }
      if (f == (FILE *)0x0) {
        if (dst != 0) {
          buffer_chain_append_bytes(src,1,uVar1 & 0xffff,(c1_byte_block_list *)dst);
        }
      }
      else {
        fwrite(src,1,uVar1 & 0xffff,(FILE *)f);
      }
      src = *(void **)((int)src + 0x7f8);
      local_4 = local_4 + (uVar1 & 0xffff);
    } while (src != (void *)0x0);
    return local_4;
  }
  return 0;
}

