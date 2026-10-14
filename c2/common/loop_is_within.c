int __fastcall loop_is_within(c2_loop *loop,c2_loop *outer)

{
  while( true ) {
    if (loop == (c2_loop *)0x0) {
      return 0;
    }
    if (loop == outer) break;
    loop = loop->parent;
  }
  return 1;
}

