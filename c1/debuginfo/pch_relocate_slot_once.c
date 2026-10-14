char __thiscall pch_relocate_slot_once(c1_pch_image *image,uint slot)

{
  c1_pch_segment *pcVar1;
  c1_u8 cVar2;
  char cVar3;
  
  pcVar1 = image->loaded_page_table[slot >> 0x10];
  if ((pcVar1 != (c1_pch_segment *)0x0) && (slot < pcVar1->loaded_end)) {
    cVar2 = pch_block_is_visited(pcVar1->reloc_bitmap,(int)(slot - (int)pcVar1->address) >> 2);
    if (cVar2 == '\0') {
      pch_block_mark_visited(pcVar1->reloc_bitmap,(int)(slot - (int)pcVar1->address) >> 2);
      cVar3 = pch_relocate_pointer(image,(uint *)slot);
      return cVar3;
    }
  }
  return '\0';
}

