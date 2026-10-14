void __thiscall pch_block_mark_visited(c1xx_bitvec *visited,int bit)

{
  visited->bits[bit >> 3] = visited->bits[bit >> 3] | '\x01' << ((byte)bit & 7);
  return;
}

