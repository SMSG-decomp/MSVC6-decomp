int __thiscall il_buffer_set_memory(Buffer *buf,c1_u8 *start,c1_u8 *cur)

{
  PB pOld;
  
  if (start == (c1_u8 *)0x0) {
    return 0;
  }
  pOld = buf->pbStart;
  buf->pbStart = start;
  buf->pbEnd = cur;
  if ((pOld != start) && (buf->pfnMove != (_func_44 *)0x0)) {
    (*buf->pfnMove)(buf->pfnMoveArg,pOld,start);
  }
  return 1;
}

