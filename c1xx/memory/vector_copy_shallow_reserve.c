c1_vector * __cdecl vector_copy_shallow_reserve(c1_vector *src,short extra,int arena)

{
  c1_u16 cVar1;
  c1_vector *pcVar2;
  uint uVar3;
  int iVar4;
  void **ppvVar5;
  void **ppvVar6;
  
  if (src == (c1_vector *)0x0) {
    cVar1 = 0;
  }
  else {
    cVar1 = src->count;
  }
  pcVar2 = vector_new(extra + cVar1,arena);
  cVar1 = src->count;
  pcVar2->count = cVar1;
  if (cVar1 != 0) {
    ppvVar5 = src->data;
    ppvVar6 = pcVar2->data;
    for (uVar3 = (uint)src->count; uVar3 != 0; uVar3 = uVar3 - 1) {
      *ppvVar6 = *ppvVar5;
      ppvVar5 = ppvVar5 + 1;
      ppvVar6 = ppvVar6 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)ppvVar6 = *(undefined1 *)ppvVar5;
      ppvVar5 = (void **)((int)ppvVar5 + 1);
      ppvVar6 = (void **)((int)ppvVar6 + 1);
    }
  }
  return pcVar2;
}

