int __fastcall split_piece_regs_all_in(void *piece,uint32_t mask)

{
  int *piVar1;
  
  if ((*(uint *)(*(int *)((int)piece + 0x14) + 0x24) & mask) != 0) {
    piVar1 = *(int **)((int)piece + 0x20);
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 1;
      }
      if ((*(uint *)(*piVar1 + 0x28) & mask) == 0) break;
      piVar1 = (int *)piVar1[1];
    }
  }
  return 0;
}

