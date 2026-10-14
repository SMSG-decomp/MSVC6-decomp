void __fastcall
coff_add_relocation(uint32_t target_id,int offset,uint32_t symbol_index,uint16_t type)

{
  c2_coff_reloc *reloc;
  c2_coff_section_out *pcVar1;
  c2_coff_reloc_chunk *pcVar2;
  uint32_t uVar3;
  c2_coff_reloc_chunk *pcVar4;
  c2_coff_section *pcVar5;
  c2_coff_reloc_chunk *pcVar6;
  
  pcVar5 = g_coff_current_section;
  pcVar1 = g_coff_current_section->active;
  pcVar2 = pcVar1->relocs;
  uVar3 = pcVar2->count;
  pcVar2->count = uVar3 + 1;
  reloc = pcVar2->relocs + uVar3;
  reloc->offset = offset - pcVar5->base;
  reloc->symbol_index = symbol_index;
  reloc->type = type;
  if (symbol_index == 0) {
    coff_hash32_insert(target_id,reloc);
  }
  uVar3 = pcVar2->count;
  pcVar1->nrelocs = pcVar1->nrelocs + 1;
  if (0x31 < (int)uVar3) {
    if (g_coff_reloc_chunk_free_list == (c2_coff_reloc_chunk *)0x0) {
      pcVar6 = (*g_coff_alloc_fn)(0x1fc);
    }
    else {
      pcVar6 = g_coff_reloc_chunk_free_list;
      g_coff_reloc_chunk_free_list = g_coff_reloc_chunk_free_list->last;
    }
    pcVar4 = pcVar2->last;
    pcVar6->count = 0;
    pcVar6->last = pcVar4;
    pcVar2->last = pcVar6;
    pcVar1->relocs = pcVar6;
  }
  return;
}

