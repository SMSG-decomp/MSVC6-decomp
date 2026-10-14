void __fastcall coff_write_section_linenums(c2_coff_section_out *sec,int offset_bias)

{
  c2_coff_lineno_chunk *pcVar1;
  uint8_t uVar2;
  c2_coff_slot **ppcVar3;
  c2_coff_lineno *pcVar4;
  size_t sVar5;
  int iVar6;
  c2_coff_lineno_chunk *pcVar7;
  uint32_t uVar8;
  
  pcVar1 = sec->lines;
  uVar8 = sec->line_offset;
  pcVar7 = pcVar1;
  do {
    ppcVar3 = g_coff_symbol_slots;
    uVar2 = g_coff_line_info;
    pcVar7 = pcVar7->last;
    iVar6 = 0;
    if (0 < (int)pcVar7->count) {
      pcVar4 = pcVar7->lines;
      do {
        if ((pcVar4->line == 0) && ((uVar2 & 1) != 0)) {
          *(uint32_t *)((int)ppcVar3[pcVar4->offset + 1]->payload + 8) = uVar8;
        }
        else {
          pcVar4->offset = pcVar4->offset + offset_bias;
        }
        iVar6 = iVar6 + 1;
        pcVar4 = pcVar4 + 1;
        uVar8 = uVar8 + 6;
      } while (iVar6 < (int)pcVar7->count);
    }
    sVar5 = fwrite(pcVar7->lines,6,pcVar7->count,g_coff_object_file);
    if (sVar5 != pcVar7->count) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xec3);
    }
  } while (pcVar7 != pcVar1);
  pcVar7 = pcVar1->last;
  pcVar1->last = g_coff_lineno_chunk_free_list;
  g_coff_lineno_chunk_free_list = pcVar7;
  return;
}

