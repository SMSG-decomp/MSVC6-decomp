int __thiscall il_buffer_set_memory(c1_byte_buffer *buf,c1_u8 *start,c1_u8 *cur)

{
  c1_u8 *old_start;
  
  if (start == (c1_u8 *)0x0) {
    return 0;
  }
  old_start = buf->start;
  buf->start = start;
  buf->cur = cur;
  if ((old_start != start) && (buf->on_move != (c1_il_buffer_move_fn)0x0)) {
    (*buf->on_move)(buf->move_ctx,old_start,start);
  }
  return 1;
}

