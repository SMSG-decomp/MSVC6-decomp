void * __thiscall arena_alloc_copy_bytes(c1_arena *a,void *src,uint src_size,uint new_size)

{
  c1_u8 *pcVar1;
  uint uVar2;
  c1_u8 *pcVar3;
  
  pcVar1 = a->cur;
  a->cur = pcVar1 + new_size;
  if (a->end < pcVar1 + new_size) {
    arena_grow(a);
  }
  if (new_size < src_size) {
    src_size = new_size;
  }
  pcVar3 = pcVar1;
  for (uVar2 = src_size >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)src;
    src = (c1_u8 *)((int)src + 4);
    pcVar3 = pcVar3 + 4;
  }
  for (uVar2 = src_size & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar3 = *(c1_u8 *)src;
    src = (c1_u8 *)((int)src + 1);
    pcVar3 = pcVar3 + 1;
  }
  return pcVar1;
}

