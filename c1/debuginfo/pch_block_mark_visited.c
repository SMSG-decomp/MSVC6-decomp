void __thiscall pch_block_mark_visited(void *block,int n)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)((int)block + 0xc) + (n >> 3));
  *pbVar1 = *pbVar1 | '\x01' << ((byte)n & 7);
  return;
}

