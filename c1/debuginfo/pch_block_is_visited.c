c1_u8 __thiscall pch_block_is_visited(void *block,int n)

{
  return (*(byte *)((n >> 3) + *(int *)((int)block + 0xc)) & (byte)(1 << ((byte)n & 7))) != 0;
}

