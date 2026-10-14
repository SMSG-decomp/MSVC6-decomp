void __fastcall sched_fp_insert_fxch(c2_tuple *ctx,int a)

{
  c2_tuple *anchor;
  c2_operand *src;
  c2_operand *dst;
  
  if (a != 0) {
    sched_fp_swap_slots(a,0);
    anchor = ctx->prev;
    while( true ) {
      if (anchor == (c2_tuple *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x999);
      }
      if (((((anchor->type & 0xf000) == 0x4000) || (anchor->kind == '\x0e')) || (anchor->op == 0x5b)
          ) && (anchor->op != 0x162)) break;
      anchor = anchor->prev;
    }
    src = operand_new_hardreg(a + 0x1f,0x400a);
    dst = operand_new_hardreg(0x1f,0x400a);
    tuple_new(0x5f,0x400a,dst,src,tuple_insert_after,anchor);
  }
  return;
}

