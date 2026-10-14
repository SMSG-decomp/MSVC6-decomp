int __cdecl format_buffer_reserve(int buf,int at_end,uint n)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *block;
  uint *block_2;
  uint uVar4;
  uint uVar5;
  uint *from_2;
  uint *from;
  uint *from_4;
  uint *to;
  uint *from_3;
  uint *to_2;
  
  piVar3 = format_buffer_find(buf);
  if (piVar3 != (int *)0x0) {
    if (at_end == 0) {
      if ((uint)piVar3[2] < n) {
        uVar1 = piVar3[4] + 0x20 + n;
        block = mem_xmalloc(uVar1);
        from_4 = block;
        for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *from_4 = 0;
          from_4 = from_4 + 1;
        }
        for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)from_4 = 0;
          from_4 = (uint *)((int)from_4 + 1);
        }
        uVar5 = (piVar3[3] - piVar3[2]) - 1;
        from_2 = (uint *)(piVar3[2] + 1 + piVar3[1]);
        to = (uint *)((int)block + n + 0x21);
        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *to = *from_2;
          from_2 = from_2 + 1;
          to = to + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)to = (char)*from_2;
          from_2 = (uint *)((int)from_2 + 1);
          to = (uint *)((int)to + 1);
        }
        mem_free((void *)piVar3[1]);
        piVar3[1] = (int)block;
        piVar3[3] = piVar3[3] + n + 0x20;
        piVar3[4] = uVar1;
        piVar3[2] = n + 0x20;
      }
      iVar2 = piVar3[2];
      piVar3[2] = iVar2 - n;
      return piVar3[1] + iVar2;
    }
    if (at_end == 1) {
      if ((uint)piVar3[4] <= piVar3[3] + n) {
        uVar1 = n + 0x20 + piVar3[4];
        block_2 = mem_xmalloc(uVar1);
        from_3 = block_2;
        for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *from_3 = 0;
          from_3 = from_3 + 1;
        }
        for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)from_3 = 0;
          from_3 = (uint *)((int)from_3 + 1);
        }
        uVar4 = piVar3[3];
        from = (uint *)piVar3[1];
        to_2 = block_2;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *to_2 = *from;
          from = from + 1;
          to_2 = to_2 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)to_2 = (char)*from;
          from = (uint *)((int)from + 1);
          to_2 = (uint *)((int)to_2 + 1);
        }
        mem_free((void *)piVar3[1]);
        piVar3[1] = (int)block_2;
        piVar3[4] = uVar1;
      }
      iVar2 = piVar3[3];
      piVar3[3] = iVar2 + n;
      return piVar3[1] + iVar2;
    }
  }
  return 0;
}

