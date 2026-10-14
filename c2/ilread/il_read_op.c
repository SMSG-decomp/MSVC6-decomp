c2_reader_op * __fastcall il_read_op(c2_function *fn,c2_reader_op *op)

{
  uint uVar1;
  c2_reader_op *pcVar2;
  
  if (g_il_ex_eof != 0) {
    return (c2_reader_op *)0x0;
  }
  uVar1 = il_read_byte();
  if ((char)uVar1 != -1) {
    if ((char)uVar1 != 'M') {
      op->qualifiers = 0;
      op->type = 0;
      pcVar2 = il_read_op_operands(uVar1 & 0xff,fn,op);
      if ((pcVar2->type & 0xf000) == 0x4000) {
        fn->flags = fn->flags | 8;
      }
      return pcVar2;
    }
    g_il_ex_eof = 1;
    return (c2_reader_op *)0x0;
  }
  fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x80a);
}

