uint32_t __fastcall align_frame_offset(uint32_t offset,int size,int align)

{
  if (size == 2) {
    if (1 < align) {
      return offset + 1 & 0xfffffffe;
    }
  }
  else if (size == 1) {
    return offset;
  }
  return (offset - 1) + align & ~(align - 1U);
}

