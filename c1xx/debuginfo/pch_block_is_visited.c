byte __thiscall pch_block_is_visited(c1xx_bitvec *visited,int bit)

{
  return (visited->bits[bit >> 3] & (byte)(1 << ((byte)bit & 7))) != 0;
}

