void __fastcall loop_set_latch(c2_loop *loop,c2_block *block)

{
  c2_block *pcVar1;
  
  pcVar1 = loop->last;
  do {
    loop->last = block;
    loop = loop->parent;
    if (loop == (c2_loop *)0x0) {
      return;
    }
  } while (loop->last == pcVar1);
  return;
}

