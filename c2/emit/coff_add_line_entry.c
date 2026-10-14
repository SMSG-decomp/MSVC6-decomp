void __fastcall coff_add_line_entry(uint16_t line_delta,int offset)

{
  c2_coff_section_out *pcVar1;
  c2_coff_lineno_chunk *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  c2_coff_lineno_chunk *pcVar5;
  c2_coff_section *pcVar6;
  c2_coff_lineno_chunk *pcVar7;
  
  pcVar6 = g_coff_current_section;
  pcVar1 = g_coff_current_section->active;
  pcVar2 = pcVar1->lines;
  uVar3 = pcVar2->count;
  pcVar2->count = uVar3 + 1;
  uVar4 = pcVar6->base;
  pcVar1->nlines = pcVar1->nlines + 1;
  pcVar2->lines[uVar3].offset = offset - uVar4;
  uVar4 = pcVar2->count;
  pcVar2->lines[uVar3].line = line_delta;
  if (0x31 < (int)uVar4) {
    if (g_coff_lineno_chunk_free_list == (c2_coff_lineno_chunk *)0x0) {
      pcVar7 = (*g_coff_alloc_fn)(0x134);
    }
    else {
      pcVar7 = g_coff_lineno_chunk_free_list;
      g_coff_lineno_chunk_free_list = g_coff_lineno_chunk_free_list->last;
    }
    pcVar5 = pcVar2->last;
    pcVar7->count = 0;
    pcVar7->last = pcVar5;
    pcVar2->last = pcVar7;
    pcVar1->lines = pcVar7;
  }
  return;
}

