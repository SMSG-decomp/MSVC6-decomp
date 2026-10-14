int __fastcall frame_alloc_local(uint32_t size,int align)

{
  uint32_t uVar1;
  
  if (align != 0) {
    size = (size - 1) + align & ~(align - 1U);
  }
  g_frame_cursor = g_frame_cursor - size;
  if (align == 0) {
    align = g_default_stack_align;
  }
  uVar1 = align_frame_offset(-g_frame_cursor,size,align);
  g_frame_cursor = -uVar1;
  if (g_frame_cursor < 1) {
    return g_frame_cursor;
  }
  fatal_error(0x7e,"2G");
}

