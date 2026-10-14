void __fastcall coff_write_symbol_record(c2_coff_slot *slot)

{
  char cVar1;
  c2_coff_data *pcVar2;
  c2_coff_data *pcVar3;
  c2_coff_section *assoc_desc;
  uint32_t uVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  uint32_t enc_signature;
  c2_coff_aux_section aux_rec;
  c2_coff_symbol sym_rec;
  undefined3 uStack_6;
  c2_coff_section_out *out;
  c2_coff_file_payload *file_payload;
  c2_coff_section *desc;
  
  switch(slot->kind) {
  case 1:
    strncpy(sym_rec.short_name,".file",8);
    file_payload = slot->payload;
    sym_rec.value = file_payload->value;
    sym_rec.section = -2;
    sym_rec.type = 0;
    sym_rec.storage_class = 'g';
    uVar7 = 0xffffffff;
    pcVar8 = file_payload->name;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar6 = ~uVar7 - 1;
    stack0xfffffff9 = CONCAT31(uStack_6,(char)(uVar6 / 0x12) + '\x01');
    sVar5 = fwrite(&sym_rec,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc0a);
    }
    sVar5 = fwrite(file_payload->name,~uVar7,1,g_coff_object_file);
    if (sVar5 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc0e);
    }
    iVar10 = (stack0xfffffff9 & 0xff) * 0x12 - uVar6;
    while (iVar10 = iVar10 + -1, iVar10 != 0) {
      fputc(0,g_coff_object_file);
    }
    g_coff_cur_symbol_record = (c2_coff_symbol *)0x0;
    break;
  case 2:
    out = slot->payload;
    desc = out->desc;
    coff_write_section_name(sym_rec.short_name,desc->name,1);
    sym_rec.value = 0;
    if (g_coff_section_numbers_final == 0) {
      sym_rec.section = -2 - out->header_number;
    }
    else {
      sym_rec.section = out->header_number;
    }
    sym_rec.type = 0;
    sym_rec.storage_class = '\x03';
    if (g_opt_edit_and_continue == 0) {
      stack0xfffffff9 = CONCAT31(uStack_6,1);
      if (g_opt_ZX != 0) goto LAB_107816c6;
    }
    else {
LAB_107816c6:
      stack0xfffffff9 = CONCAT31(uStack_6,2);
    }
    sVar5 = fwrite(&sym_rec,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc2b);
    }
    aux_rec.number = 0;
    aux_rec.selection = '\0';
    aux_rec.pad_0f[0] = '\0';
    aux_rec.pad_0f[1] = '\0';
    aux_rec.pad_0f[2] = '\0';
    aux_rec.length = out->size_of_raw_data;
    aux_rec.nrelocs = (uint16_t)out->nrelocs;
    if (0xfffe < out->nrelocs) {
      aux_rec.nrelocs = 0xffff;
    }
    aux_rec.nlines = out->nlines;
    aux_rec.checksum = desc->signature;
    if ((desc->characteristics & 0x1000) != 0) {
      aux_rec._12_4_ = (uint)desc->comdat_selection << 0x10;
      if (desc->comdat_assoc == 0) {
        aux_rec._12_4_ = (uint)desc->comdat_selection << 0x10;
      }
      else {
        assoc_desc = coff_chunked_array_get(g_coff_sections,(uint)desc->comdat_assoc);
        if (g_coff_section_numbers_final == 0) {
          aux_rec.number = -assoc_desc->active->header_number - 2;
        }
        else {
          aux_rec.number = assoc_desc->active->header_number;
        }
      }
    }
    sVar5 = fwrite(&aux_rec,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc4c);
    }
    g_coff_cur_symbol_record = (c2_coff_symbol *)0x0;
    if ((g_opt_edit_and_continue != 0) || (g_opt_ZX != 0)) {
      enc_signature = desc->fn_signature;
      sVar5 = fwrite(&enc_signature,4,1,g_coff_object_file);
      if (sVar5 != 1) {
        (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc55);
      }
      iVar10 = 0xe;
      do {
        fputc(0,g_coff_object_file);
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      return;
    }
    break;
  case 3:
    g_coff_cur_symbol_record = slot->payload;
    if ((((g_coff_incremental_update != 0) || (g_opt_edit_and_continue != 0)) || (g_opt_ZX != 0)) &&
       (*(int *)g_coff_cur_symbol_record->short_name == 0)) {
      pcVar8 = *(char **)(g_coff_cur_symbol_record->short_name + 4);
      uVar4 = coff_data_size(g_coff_string_table);
      pcVar2 = g_coff_string_table;
      *(uint32_t *)(g_coff_cur_symbol_record->short_name + 4) = uVar4 + 4;
      pcVar3 = g_coff_current_section_data;
      uVar7 = 0xffffffff;
      pcVar9 = pcVar8;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      g_coff_current_section_data = pcVar2;
      coff_write_bytes(pcVar8,~uVar7);
      g_coff_current_section_data = pcVar3;
    }
    sVar5 = fwrite(g_coff_cur_symbol_record,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      iVar10 = 0xc74;
LAB_107817dc:
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",iVar10);
      return;
    }
    break;
  case 4:
    sVar5 = fwrite(slot->payload,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc7b);
    }
    g_coff_cur_symbol_record = (c2_coff_symbol *)0x0;
    return;
  case 5:
    break;
  case 6:
  case 7:
    strncpy(sym_rec.short_name,"$unused$",8);
    sym_rec.value = 0;
    sym_rec.section = 0;
    sym_rec.type = 0;
    sym_rec.storage_class = '\x0e';
    stack0xfffffff9 = stack0xfffffff9 & 0xffffff00;
    sVar5 = fwrite(&sym_rec,0x12,1,g_coff_object_file);
    if (sVar5 != 1) {
      iVar10 = 0xc8e;
      goto LAB_107817dc;
    }
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xc93);
  }
  return;
}

