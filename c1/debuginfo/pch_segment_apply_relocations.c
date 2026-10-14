void __thiscall pch_segment_apply_relocations(c1_pch_segment *segment,c1_pch_image *image)

{
  char cVar1;
  int iVar2;
  
  cVar1 = bitvec_iter_first(segment->reloc_bitmap);
  while (cVar1 != '\0') {
    iVar2 = bitvec_iter_index(segment->reloc_bitmap);
    pch_relocate_pointer(image,(uint *)(segment->address + iVar2 * 4));
    cVar1 = bitvec_iter_next(segment->reloc_bitmap);
  }
  return;
}

