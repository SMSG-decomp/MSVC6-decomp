void * __thiscall ovl_candidate_init(void *cand,byte *sym,int p3,int conv,int p5,int prev)

{
  byte *pbVar1;
  c1_type *pcVar2;
  int iVar3;
  
  pbVar1 = sym;
  if ((*sym & 0x1f) == 0x1a) {
    pbVar1 = (byte *)**(int **)(sym + 0x14);
  }
  *(byte **)cand = pbVar1;
  *(uint *)((int)cand + 4) = ~-(uint)((*sym & 0x1f) != 0x1a) & (uint)sym;
  iVar3 = *(int *)(*(int *)(((uint)*(byte **)(pbVar1 + 0x14) &
                            -(uint)((**(byte **)(pbVar1 + 0x14) & 0x80) != 0)) + 8) + 0xc);
  *(int *)((int)cand + 8) = p3;
  iVar3 = iVar3 + 8;
  *(int *)((int)cand + 0xc) = iVar3;
  *(int *)((int)cand + 0x10) = iVar3;
  *(int *)((int)cand + 0x24) = p5;
  if (((pbVar1[1] & 4) != 0) &&
     (*(byte *)((int)cand + 0x3c) = *(byte *)((int)cand + 0x3c) | 2, (pbVar1[0x20] & 7) != 3)) {
    if (conv == 0) {
      pcVar2 = lookup_class_pointer_type(*(void **)(pbVar1 + 0x14),0);
      *(c1_type **)((int)cand + 0x18) = pcVar2;
    }
    else {
      *(int *)((int)cand + 0x18) = conv;
    }
  }
  if (prev != 0) {
    *(int *)((int)cand + 0x20) = prev;
    *(void **)(prev + 0x1c) = cand;
  }
  return cand;
}

