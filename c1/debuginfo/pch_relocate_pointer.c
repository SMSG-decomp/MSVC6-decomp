char __thiscall pch_relocate_pointer(c1_pch_image *image,uint *slot)

{
  c1_u8 *pcVar1;
  c1_pch_segment *pcVar2;
  
  pcVar1 = (c1_u8 *)*slot;
  if (((pcVar1 != (c1_u8 *)0x0) &&
      (pcVar2 = image->saved_page_table[(uint)pcVar1 >> 0x10], pcVar2 != (c1_pch_segment *)0x0)) &&
     (pcVar1 < pcVar2->saved_end)) {
    if (pcVar2->state == 5) {
      *slot = (uint)(pcVar1 + pcVar2->delta);
    }
    return '\x01';
  }
  return '\0';
}

