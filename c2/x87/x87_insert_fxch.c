void __fastcall x87_insert_fxch(c2_tuple *t,int n)

{
  uint8_t uVar1;
  uint32_t uVar2;
  c2_tuple *anchor;
  int iVar3;
  c2_operand *src;
  c2_operand *dst;
  
  if (n != 0) {
    uVar2 = g_x87_stack_ids[g_x87_tos];
    if (7 < n) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x1a3);
    }
    iVar3 = g_x87_tos - n;
    g_x87_stack_ids[g_x87_tos] = g_x87_stack_ids[iVar3];
    g_x87_stack_ids[iVar3] = uVar2;
    anchor = t->prev;
    while( true ) {
      if (anchor == (c2_tuple *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x1bc);
      }
      if (((((((anchor->type & 0xf000) == 0x4000) || (uVar1 = anchor->kind, uVar1 == '\x0e')) ||
            (uVar1 == '\x11')) || ((uVar1 == '\x1a' || (uVar1 == '\x13')))) ||
          ((uVar1 == '\x12' || ((uVar1 == '\x19' || (anchor->op == 0x5b)))))) &&
         (anchor->op != 0x162)) break;
      anchor = anchor->prev;
    }
    src = operand_new_hardreg(n + 0x1f,0x400a);
    dst = operand_new_hardreg(0x1f,0x400a);
    tuple_new(0x5f,0x400a,dst,src,tuple_insert_after,anchor);
  }
  return;
}

