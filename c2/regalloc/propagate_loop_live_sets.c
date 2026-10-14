void __fastcall propagate_loop_live_sets(c2_loop *loop)

{
  for (; loop != (c2_loop *)0x0; loop = loop->next) {
    propagate_loop_live_sets(loop->inner);
    if (loop->parent != (c2_loop *)0x0) {
      bitset_or(loop->parent->candidates,loop->candidates);
    }
  }
  return;
}

