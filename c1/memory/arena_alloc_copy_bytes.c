void * __thiscall arena_alloc_copy_bytes(fe_arena *a,void *src,uint src_size,uint new_size)

{
  uint *puVar1;
  uint uVar2;
  uint *dst;
  
  puVar1 = (uint *)a->cur;
  a->cur = (uchar *)((int)puVar1 + new_size);
  if (a->end < (uchar *)((int)puVar1 + new_size)) {
    arena_grow(a);
  }
  if (new_size < src_size) {
    src_size = new_size;
  }
  dst = puVar1;
  for (uVar2 = src_size >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *dst = *(uint *)src;
    src = (uint *)((int)src + 4);
    dst = dst + 1;
  }
  for (uVar2 = src_size & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(char *)dst = (char)*(uint *)src;
    src = (uint *)((int)src + 1);
    dst = (uint *)((int)dst + 1);
  }
  return puVar1;
}

