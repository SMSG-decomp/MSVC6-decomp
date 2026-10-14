void __cdecl lex_put_string_byte(byte c,c1_byte_block_list *buf)

{
  c1_byte_block *block;
  c1_u8 *cursor;
  
  if (buf != (c1_byte_block_list *)0x0) {
    cursor = buf->cur;
    if (0x7f7 < (int)buf->used) {
      block = buf->block->next;
      if (block == (c1_byte_block *)0x0) {
        block = mem_xmalloc(0x800);
        block->next = (c1_byte_block *)0x0;
        buf->block->next = block;
      }
      buf->block = block;
      block->used = 0;
      buf->used = 0;
      cursor = block->data;
    }
    *cursor = c;
    buf->used = buf->used + 1;
    buf->cur = cursor + 1;
    return;
  }
  if ((char *)0x1066918f < g_string_literal_cur) {
    diag_fatal_simple(0x40);
  }
  *g_string_literal_cur = c;
  g_string_literal_cur = g_string_literal_cur + 1;
  return;
}

