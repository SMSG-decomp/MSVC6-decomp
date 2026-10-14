void __fastcall coff_write_section_relocs(c2_coff_section_out *sec,int offset_bias)

{
  c2_coff_reloc_chunk *pcVar1;
  c2_coff_section *pcVar2;
  c2_coff_reloc *pcVar3;
  size_t sVar4;
  uint32_t uVar5;
  c2_coff_reloc_chunk *pcVar6;
  c2_coff_reloc ovfl_count_reloc;
  
  if ((g_opt_edit_and_continue != 0) || (g_opt_ZX != 0)) {
    pcVar2 = sec->desc;
    uVar5 = coff_section_reloc_signature(sec,pcVar2->fn_signature);
    pcVar2->fn_signature = uVar5;
  }
  if (0xfffe < sec->nrelocs) {
    ovfl_count_reloc.offset = sec->nrelocs + 1;
    ovfl_count_reloc.symbol_index = 0;
    ovfl_count_reloc.type = 0;
    sVar4 = fwrite(&ovfl_count_reloc,10,1,g_coff_object_file);
    if (sVar4 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xe87);
    }
  }
  pcVar1 = sec->relocs;
  pcVar6 = pcVar1;
  do {
    pcVar6 = pcVar6->last;
    uVar5 = pcVar6->count;
    if (uVar5 != 0) {
      pcVar3 = pcVar6->relocs + (uVar5 - 1);
      do {
        uVar5 = uVar5 - 1;
        pcVar3->offset = pcVar3->offset + offset_bias;
        pcVar3 = pcVar3 + -1;
      } while (uVar5 != 0);
    }
    sVar4 = fwrite(pcVar6->relocs,10,pcVar6->count,g_coff_object_file);
    if (sVar4 != pcVar6->count) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xe94);
    }
  } while (pcVar6 != pcVar1);
  pcVar6 = pcVar1->last;
  pcVar1->last = g_coff_reloc_chunk_free_list;
  g_coff_reloc_chunk_free_list = pcVar6;
  return;
}

