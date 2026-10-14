void __thiscall import_text_putc(c1_il_buffer *buf,int c)

{
  int iVar1;
  c1_u8 *pcVar2;
  
  if ((&stack0x00000000 != (undefined1 *)0xfffffffc) &&
     (((buf->bytes).cur + 1 <= (buf->bytes).start + (buf->bytes).size ||
      (iVar1 = il_buffer_grow(&buf->bytes,1), iVar1 != 0)))) {
    pcVar2 = (c1_u8 *)c;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pcVar2 = (buf->bytes).cur;
    }
    if ((buf->bytes).start != (c1_u8 *)0x0) {
      (buf->bytes).cur = (buf->bytes).cur + 1;
    }
    *pcVar2 = (c1_u8)c;
    return;
  }
  diag_fatal_simple(0x3c);
}

