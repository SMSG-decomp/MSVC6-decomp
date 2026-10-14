void __fastcall coff_place_section_data(c2_coff_section *desc)

{
  c2_coff_section_out *sec;
  c2_coff_data *data;
  uint16_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  
  sec = desc->active;
  data = sec->data;
  uVar2 = coff_data_size(data);
  if (data->count_only == 1) {
    sec->data_offset = 0;
  }
  else {
    if (g_coff_place_in_free_space == 0) {
      uVar3 = ftell(g_coff_object_file);
    }
    else {
      uVar3 = sec->data_offset;
      iVar4 = coff_section_linenum_bytes(sec);
      iVar5 = coff_section_reloc_bytes(sec);
      uVar3 = coff_alloc_file_space(iVar5 + uVar2 + iVar4,uVar3);
      iVar4 = fseek(g_coff_object_file,uVar3,0);
      if (iVar4 != 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xb1c);
      }
    }
    sec->data_offset = uVar3;
  }
  uVar1 = desc->flags;
  sec->virtual_address = 0;
  if ((uVar1 & 0x10) == 0) {
    sec->fn_section_mark = 0;
  }
  else {
    sec->fn_section_mark = 1;
  }
  sec->size_of_raw_data = uVar2;
  coff_write_section_data(sec->data);
  if (sec->nrelocs == 0) {
    sec->reloc_offset = 0;
  }
  else {
    uVar2 = ftell(g_coff_object_file);
    sec->reloc_offset = uVar2;
    coff_write_section_relocs(sec,0);
  }
  if (sec->nlines == 0) {
    *(byte *)&sec->flags = (byte)sec->flags | 1;
    sec->line_offset = 0;
    return;
  }
  uVar2 = ftell(g_coff_object_file);
  sec->line_offset = uVar2;
  coff_write_section_linenums(sec,sec->virtual_address);
  *(byte *)&sec->flags = (byte)sec->flags | 1;
  return;
}

