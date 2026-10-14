void __fastcall coff_write_section_header(c2_coff_section_out *sec)

{
  c2_coff_section *pcVar1;
  uint uVar2;
  size_t sVar3;
  c2_coff_section_header header;
  
  pcVar1 = sec->desc;
  coff_section_name_field(header.name,pcVar1->name);
  header.virtual_address = sec->virtual_address;
  header.virtual_size = sec->fn_section_mark;
  header.size_of_raw_data = sec->size_of_raw_data;
  header.data_offset = sec->data_offset;
  header.reloc_offset = sec->reloc_offset;
  uVar2 = sec->nrelocs;
  header.line_offset = sec->line_offset;
  header.nrelocs = (uint16_t)uVar2;
  if (0xfffe < uVar2) {
    header.nrelocs = 0xffff;
  }
  header.nlines = sec->nlines;
  header.characteristics = pcVar1->characteristics;
  if (0xfffe < uVar2) {
    header.characteristics = header.characteristics | 0x1000000;
  }
  sVar3 = fwrite(&header,0x28,1,g_coff_object_file);
  if (sVar3 != 1) {
    (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xcbe);
  }
  return;
}

