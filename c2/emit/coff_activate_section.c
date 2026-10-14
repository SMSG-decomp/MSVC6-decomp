int __fastcall coff_activate_section(uint16_t section,uint32_t characteristics)

{
  c2_coff_section_out *sec;
  uint32_t uVar1;
  uint16_t uVar2;
  c2_coff_section *pcVar3;
  c2_coff_section_out *sec_00;
  c2_coff_data *pcVar4;
  c2_coff_reloc_chunk *pcVar5;
  c2_coff_lineno_chunk *pcVar6;
  uint32_t uVar7;
  
  pcVar3 = coff_chunked_array_get(g_coff_sections,(uint)section);
  if ((((pcVar3 == (c2_coff_section *)0x0) || ((pcVar3->flags & 2) != 0)) ||
      (((pcVar3->flags & 1) != 0 &&
       (((pcVar3->characteristics & 0x1000) != 0 || ((short)g_coff_header_section_count != 0))))))
     || ((g_coff_writer_mode == 3 && (g_coff_header_section_count._2_2_ != 0)))) {
    return 0;
  }
  sec = pcVar3->active;
  if (g_coff_incremental_update == 0) {
    if ((sec != (c2_coff_section_out *)0x0) && ((sec->flags & 1) == 0)) goto LAB_10740a2c;
  }
  else if (sec != (c2_coff_section_out *)0x0) {
    sec->flags = 0;
    pcVar4 = coff_new_section_chunk(1,(uint)(characteristics == 0xc0000080));
    sec->data = pcVar4;
    pcVar5 = (*g_coff_alloc_fn)(0x1fc);
    pcVar5->count = 0;
    pcVar5->last = pcVar5;
    sec->relocs = pcVar5;
    pcVar6 = (*g_coff_alloc_fn)(0x134);
    pcVar6->count = 0;
    pcVar6->last = pcVar6;
    sec->lines = pcVar6;
    coff_add_section_symbol(sec);
    uVar7 = coff_insert_comdat_section(sec);
    sec->header_number = (uint16_t)uVar7;
    goto LAB_10740a2c;
  }
  sec_00 = (*g_coff_alloc_fn)(0x3c);
  uVar2 = pcVar3->flags;
  sec_00->flags = 0;
  pcVar4 = coff_new_section_chunk
                     (((byte)~(byte)uVar2 & 4) >> 2,(uint)(characteristics == 0xc0000080));
  sec_00->data = pcVar4;
  pcVar5 = (*g_coff_alloc_fn)(0x1fc);
  pcVar5->count = 0;
  pcVar5->last = pcVar5;
  sec_00->relocs = pcVar5;
  pcVar6 = (*g_coff_alloc_fn)(0x134);
  pcVar6->count = 0;
  pcVar6->last = pcVar6;
  sec_00->lines = pcVar6;
  sec_00->desc = pcVar3;
  if (sec == (c2_coff_section_out *)0x0) {
    sec_00->next = sec_00;
    pcVar3->active = sec_00;
    pcVar3->base = 0;
  }
  else {
    uVar7 = sec->size_of_raw_data;
    sec_00->next = sec->next;
    uVar1 = pcVar3->base;
    sec->next = sec_00;
    pcVar3->active = sec_00;
    pcVar3->base = uVar1 + uVar7;
  }
  coff_add_section_symbol(sec_00);
  uVar7 = coff_insert_comdat_section(sec_00);
  sec_00->header_number = (uint16_t)uVar7;
LAB_10740a2c:
  *(byte *)&pcVar3->flags = (byte)pcVar3->flags | 3;
  g_coff_header_section_count._2_2_ = g_coff_header_section_count._2_2_ + 1;
  return 1;
}

