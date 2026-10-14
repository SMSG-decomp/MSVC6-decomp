void __thiscall
pch_segment_apply_relocations(c1xx_pch_stream_reader *pch_stream_reader,c1xx_pch_image *image)

{
  char cVar1;
  int iVar2;
  
  cVar1 = bitvec_iter_first(pch_stream_reader->bitmap);
  while (cVar1 != '\0') {
    iVar2 = bitvec_iter_index(pch_stream_reader->bitmap);
    pch_relocate_pointer(image,(uint *)(pch_stream_reader->address + iVar2 * 4));
    cVar1 = bitvec_iter_next(pch_stream_reader->bitmap);
  }
  return;
}

