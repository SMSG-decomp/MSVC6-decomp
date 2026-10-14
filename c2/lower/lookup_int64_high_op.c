uint32_t __fastcall lookup_int64_high_op(c2_int64_op_pair *table,uint32_t il_op)

{
  uint32_t uVar1;
  
  uVar1 = table->il_op;
  while( true ) {
    if (uVar1 == 0x145) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0xa5);
    }
    if (il_op == uVar1) break;
    uVar1 = table[1].il_op;
    table = table + 1;
  }
  return table->x86_op;
}

