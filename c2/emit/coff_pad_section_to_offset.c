void __fastcall coff_pad_section_to_offset(c2_fe_symbol *sym)

{
  uint16_t section;
  c2_coff_chunk *pcVar1;
  uint gap;
  c2_coff_chunk *pcVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint32_t uVar7;
  uint8_t *dst;
  c2_coff_data *data;
  
  if (sym->coff_section == 0) {
    coff_section_for_symbol(sym);
  }
  section = (uint16_t)sym->coff_section;
  coff_select_comdat_section(section);
  gap = coff_section_current_offset(section);
  data = g_coff_current_section_data;
  if ((uint)sym->offset <= gap) {
    return;
  }
  gap = sym->offset - gap;
  if (g_coff_current_section_data->count_only != 1) {
    if (g_coff_current_section_data->buffered != 0) {
      if (500 - g_coff_current_section_data->fill < gap) {
        do {
          uVar6 = 500 - data->fill;
          gap = gap - uVar6;
          dst = data->cur->data + data->fill;
          for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            dst[0] = '\0';
            dst[1] = '\0';
            dst[2] = '\0';
            dst[3] = '\0';
            dst = dst + 4;
          }
          for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *dst = '\0';
            dst = dst + 1;
          }
          uVar7 = uVar6 + data->fill;
          data->fill = uVar7;
          if (uVar7 != 500) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdbe);
          }
          pcVar2 = coff_alloc_chunk();
          pcVar1 = data->cur;
          data->cur = pcVar2;
          data->fill = 0;
          pcVar2->next = pcVar1->next;
          pcVar1->next = pcVar2;
          data->full = data->full + 500;
        } while (500 < gap);
      }
      dst = data->cur->data + data->fill;
      for (uVar4 = gap >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        dst[0] = '\0';
        dst[1] = '\0';
        dst[2] = '\0';
        dst[3] = '\0';
        dst = dst + 4;
      }
      for (uVar4 = gap & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *dst = '\0';
        dst = dst + 1;
      }
      data->fill = data->fill + gap;
      data->writes = data->writes + 1;
      return;
    }
    dst = g_coff_fill_buffer;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      dst[0] = '\0';
      dst[1] = '\0';
      dst[2] = '\0';
      dst[3] = '\0';
      dst = dst + 4;
    }
    for (; gap < 0x51; gap = gap - 0x50) {
      sVar3 = fwrite(g_coff_fill_buffer,0x50,1,g_coff_object_file);
      if (sVar3 != 1) {
        (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdae);
      }
      data->fill = data->fill + 0x50;
    }
    if (gap == 0) goto LAB_1074fef0;
    sVar3 = fwrite(g_coff_fill_buffer,gap,1,g_coff_object_file);
    if (sVar3 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdb3);
    }
  }
  data->fill = data->fill + gap;
LAB_1074fef0:
  data->writes = data->writes + 1;
  return;
}

