void __cdecl buffer_chain_append_bytes(void *src,int count,int size,c1_byte_block_list *chain)

{
  c1_byte_block *new_block;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *src_word;
  uint *block_src;
  uint *rest_src;
  uint *lit_dst;
  uint *fit_dst;
  uint *dst;
  uint *block_dst;
  uint *rest_dst;
  c1_byte_block *current;
  
  uVar4 = count * size;
  if (chain == (c1_byte_block_list *)0x0) {
    lit_dst = (uint *)g_string_literal_cur;
    for (uVar1 = uVar4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *lit_dst = *(uint *)src;
      src = (uint *)((int)src + 4);
      lit_dst = lit_dst + 1;
    }
    for (uVar1 = uVar4 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(char *)lit_dst = (char)*(uint *)src;
      src = (uint *)((int)src + 1);
      lit_dst = (uint *)((int)lit_dst + 1);
    }
    g_string_literal_cur = g_string_literal_cur + uVar4;
    return;
  }
  current = chain->block;
  uVar1 = 0x7f8 - chain->used;
  if (uVar1 < uVar4) {
    src_word = src;
    dst = (uint *)chain->cur;
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *dst = *src_word;
      src_word = src_word + 1;
      dst = dst + 1;
    }
    uVar4 = uVar4 - uVar1;
    for (uVar2 = uVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(char *)dst = (char)*src_word;
      src_word = (uint *)((int)src_word + 1);
      dst = (uint *)((int)dst + 1);
    }
    while( true ) {
      if (uVar4 == 0) {
        return;
      }
      if (current->next == (c1_byte_block *)0x0) {
        new_block = mem_xmalloc(0x800);
        new_block->next = (c1_byte_block *)0x0;
        current->next = new_block;
      }
      current = current->next;
      current->used = 0;
      if (uVar4 < 0x7f9) break;
      uVar4 = uVar4 - 0x7f8;
      block_src = (uint *)(uVar1 + (int)src);
      block_dst = (uint *)current;
      for (iVar3 = 0x1fe; iVar3 != 0; iVar3 = iVar3 + -1) {
        *block_dst = *block_src;
        block_src = block_src + 1;
        block_dst = block_dst + 1;
      }
    }
    rest_src = (uint *)(uVar1 + (int)src);
    rest_dst = (uint *)current;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *rest_dst = *rest_src;
      rest_src = rest_src + 1;
      rest_dst = rest_dst + 1;
    }
    for (uVar1 = uVar4 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(char *)rest_dst = (char)*rest_src;
      rest_src = (uint *)((int)rest_src + 1);
      rest_dst = (uint *)((int)rest_dst + 1);
    }
    chain->block = current;
    chain->used = uVar4;
    chain->cur = current->data + uVar4;
    return;
  }
  fit_dst = (uint *)chain->cur;
  for (uVar1 = uVar4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *fit_dst = *(uint *)src;
    src = (uint *)((int)src + 4);
    fit_dst = fit_dst + 1;
  }
  for (uVar1 = uVar4 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(char *)fit_dst = (char)*(uint *)src;
    src = (uint *)((int)src + 1);
    fit_dst = (uint *)((int)fit_dst + 1);
  }
  chain->cur = chain->cur + uVar4;
  chain->used = chain->used + uVar4;
  return;
}

