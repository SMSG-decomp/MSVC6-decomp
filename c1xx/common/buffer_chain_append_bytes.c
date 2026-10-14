void __cdecl buffer_chain_append_bytes(void *src,int count,int size,c1_byte_block_list *chain)

{
  c1_byte_block *pcVar1;
  uint uVar2;
  uint *dst;
  uint uVar3;
  int iVar4;
  uint uVar5;
  c1_u8 *pcVar6;
  uint *puVar7;
  c1_u8 *pcVar8;
  uint *dst_2;
  char *lit_dst;
  uint *dst_3;
  
  uVar5 = count * size;
  if (chain == (c1_byte_block_list *)0x0) {
    lit_dst = g_string_literal_cur;
    for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)lit_dst = *(undefined4 *)src;
      src = (char *)((int)src + 4);
      lit_dst = lit_dst + 4;
    }
    for (uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *lit_dst = *(char *)src;
      src = (char *)((int)src + 1);
      lit_dst = lit_dst + 1;
    }
    g_string_literal_cur = g_string_literal_cur + uVar5;
    return;
  }
  pcVar1 = chain->block;
  uVar2 = 0x7f8 - chain->used;
  if (uVar2 < uVar5) {
    pcVar6 = src;
    pcVar8 = chain->cur;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    uVar5 = uVar5 - uVar2;
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    while( true ) {
      if (uVar5 == 0) {
        return;
      }
      if (pcVar1->next == (c1_byte_block *)0x0) {
        dst = mem_xmalloc(0x800);
        dst[0x1fe] = 0;
        pcVar1->next = (c1_byte_block *)dst;
      }
      pcVar1 = pcVar1->next;
      pcVar1->used = 0;
      if (uVar5 < 0x7f9) break;
      uVar5 = uVar5 - 0x7f8;
      puVar7 = (uint *)(uVar2 + (int)src);
      dst_3 = (uint *)pcVar1;
      for (iVar4 = 0x1fe; iVar4 != 0; iVar4 = iVar4 + -1) {
        *dst_3 = *puVar7;
        puVar7 = puVar7 + 1;
        dst_3 = dst_3 + 1;
      }
    }
    puVar7 = (uint *)(uVar2 + (int)src);
    dst_2 = (uint *)pcVar1;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(uint *)((c1_byte_block *)dst_2)->data = *puVar7;
      puVar7 = puVar7 + 1;
      dst_2 = (uint *)(((c1_byte_block *)dst_2)->data + 4);
    }
    for (uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(char *)dst_2 = (char)*puVar7;
      puVar7 = (uint *)((int)puVar7 + 1);
      dst_2 = (uint *)((int)dst_2 + 1);
    }
    chain->block = pcVar1;
    chain->used = uVar5;
    chain->cur = pcVar1->data + uVar5;
    return;
  }
  pcVar6 = chain->cur;
  for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)src;
    src = (c1_u8 *)((int)src + 4);
    pcVar6 = pcVar6 + 4;
  }
  for (uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar6 = *(c1_u8 *)src;
    src = (c1_u8 *)((int)src + 1);
    pcVar6 = pcVar6 + 1;
  }
  chain->cur = chain->cur + uVar5;
  chain->used = chain->used + uVar5;
  return;
}

