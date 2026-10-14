void __thiscall set_loop_depths(c2_loop *loop,int depth)

{
  if (loop != (c2_loop *)0x0) {
    do {
      set_loop_depths(loop->inner,depth + 1);
      set_loop_depth_and_exits(loop,(int16_t)depth);
      loop = loop->next;
    } while (loop != (c2_loop *)0x0);
  }
  return;
}

