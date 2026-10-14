int __fastcall block_first_numbered_index(c2_block *b)

{
  while( true ) {
    if (b == (c2_block *)0x0) {
      return 0;
    }
    if (-1 < b->rpo) break;
    b = b->next;
  }
  if (b == (c2_block *)0x0) {
    return 0;
  }
  return (int)b->rpo;
}

