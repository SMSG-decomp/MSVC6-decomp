void __cdecl pch_auto_begin(void)

{
  byte bVar1;
  c1_vector *pcVar2;
  char cVar3;
  uint *dst;
  c1_u8 *text;
  uint *dst_3;
  fe_pch_header *pfVar4;
  int iVar5;
  uint *src;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint *dst_2;
  uint *src_2;
  int *piVar9;
  uint *src_3;
  short sVar10;
  uint *dst_5;
  c1_pch_option_block *pcVar11;
  uint *puVar12;
  uint *src_4;
  uint *dst_6;
  uint *dst_4;
  bool bVar13;
  int iVar14;
  int action_id;
  char *pcVar15;
  uint local_100 [64];
  
  block_list_open_or_rewind((c1_byte_block_list **)&g_pch_directive_text_blocks);
  g_pch_directive_mode = 2;
  pch_set_name("vc60.pch");
  g_eh_declarations_injected = 1;
  g_pch_file = (FILE *)fopen(g_pch_file_name,"rb");
  if (g_pch_file != (FILE *)0x0) {
    fread(&g_pch_header_read,1,0x68,(FILE *)g_pch_file);
    if ((g_pch_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
    }
    pbVar8 = &g_pch_stamp;
    pfVar4 = &g_pch_header_read;
    do {
      bVar1 = pfVar4->stamp[0];
      bVar13 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_10486b01:
        iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        goto LAB_104868cc;
      }
      if (bVar1 == 0) break;
      bVar1 = pfVar4->stamp[1];
      bVar13 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_10486b01;
      pfVar4 = (fe_pch_header *)(pfVar4->stamp + 2);
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_104868cc:
    if (((iVar5 == 0) && (g_pch_header_read.version == 0x12017d85)) &&
       (g_pch_header_read.magic == 0x8e4688c)) {
      if (((byte)g_pch_header_read.flags & 2) != 0) {
        dst_2 = (uint *)g_pch_header.compiler_date;
        src = (uint *)g_pch_header_read.compiler_date;
        do {
          bVar1 = *(byte *)src;
          bVar13 = bVar1 < *(byte *)dst_2;
          if (bVar1 != *(byte *)dst_2) {
LAB_10486b0b:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_10486931;
          }
          if (bVar1 == 0) break;
          bVar1 = *(char *)((int)src + 1);
          bVar13 = bVar1 < (byte)*(char *)((int)dst_2 + 1);
          if (bVar1 != *(char *)((int)dst_2 + 1)) goto LAB_10486b0b;
          src = (uint *)((int)src + 2);
          dst_2 = (uint *)((int)dst_2 + 2);
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_10486931:
        if (iVar5 != 0) goto LAB_10486a63;
      }
      if ((g_pch_header_read.records_size != 0) && (((byte)g_pch_header_read.flags & 1) == 0)) {
        fread(&g_pch_option_block_read,1,0x38c,(FILE *)g_pch_file);
        if ((g_debug_types_in_pdb != '\0') &&
           (cVar3 = file_name_equal((byte *)g_pdb_file_name,
                                    (byte *)g_pch_option_block_read.pdb_file_name), cVar3 != '\0'))
        {
          src_2 = (uint *)g_pch_option_block_read.pdb_file_name;
          dst_5 = (uint *)g_pdb_file_name;
          for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
            *dst_5 = *src_2;
            src_2 = src_2 + 1;
            dst_5 = dst_5 + 1;
          }
        }
        iVar5 = 0xe3;
        bVar13 = true;
        piVar9 = &g_pch_option_block;
        pcVar11 = &g_pch_option_block_read;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar13 = *piVar9 == pcVar11->opt_ZE;
          piVar9 = piVar9 + 1;
          pcVar11 = (c1_pch_option_block *)&pcVar11->ms_extensions;
        } while (bVar13);
        if (bVar13) {
          g_pch_records_buffer = mem_xmalloc(g_pch_header_read.records_size);
          _g_io_result = fseek((FILE *)g_pch_file,g_pch_header_read.records_offset,0);
          if (_g_io_result != 0) {
            diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
          }
          fread(g_pch_records_buffer,1,g_pch_header_read.records_size,(FILE *)g_pch_file);
          pcVar2 = g_define_list;
          g_pch_record_cursor = g_pch_records_buffer;
          sVar10 = 0;
          do {
            if ((pcVar2 == (c1_vector *)0x0) ||
               (iVar5 = (int)sVar10, (int)(uint)pcVar2->count <= iVar5)) {
              text = cwd_string();
              pch_record_entry(7,0,(char *)text);
              pcVar2 = g_include_path_list;
              if (g_pch_directive_mode != 1) {
                sVar10 = 0;
                do {
                  if ((pcVar2 == (c1_vector *)0x0) ||
                     (iVar5 = (int)sVar10, (int)(uint)pcVar2->count <= iVar5)) {
                    g_pch_include_count.count = 0;
                    return;
                  }
                  sVar10 = sVar10 + 1;
                  pch_record_entry(7,0,pcVar2->data[iVar5]);
                } while (g_pch_directive_mode != 1);
              }
              break;
            }
            sVar10 = sVar10 + 1;
            pch_record_macro_definition((byte *)"",pcVar2->data[iVar5],0);
          } while (g_pch_directive_mode != 1);
        }
      }
    }
  }
LAB_10486a63:
  if ((g_opt_nologo == '\0') && (g_pch_auto_note == (char *)0x0)) {
    if (g_pch_file == (FILE *)0x0) {
      iVar14 = 0x15f;
      iVar5 = 0x100;
      pcVar15 = g_pch_file_name;
      dst_3 = (uint *)misc_string_get(0x386);
      format_snprintf((char *)local_100,(char *)dst_3,iVar5,iVar14,pcVar15);
    }
    else {
      action_id = 0x160;
      iVar14 = 0x161;
      iVar5 = 0x100;
      pcVar15 = g_pch_file_name;
      dst = (uint *)misc_string_get(0x385);
      format_snprintf((char *)local_100,(char *)dst,iVar5,iVar14,action_id,pcVar15);
    }
    uVar6 = 0xffffffff;
    puVar12 = local_100;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      uVar7 = *puVar12;
      puVar12 = (uint *)((int)puVar12 + 1);
    } while ((char)uVar7 != '\0');
    g_pch_auto_note = mem_xmalloc(~uVar6);
    uVar6 = 0xffffffff;
    src_4 = local_100;
    do {
      dst_6 = src_4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      dst_6 = (uint *)((int)src_4 + 1);
      uVar7 = *src_4;
      src_4 = dst_6;
    } while ((char)uVar7 != '\0');
    uVar6 = ~uVar6;
    src_3 = (uint *)((int)dst_6 - uVar6);
    dst_4 = (uint *)g_pch_auto_note;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *dst_4 = *src_3;
      src_3 = src_3 + 1;
      dst_4 = dst_4 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)dst_4 = (char)*src_3;
      src_3 = (uint *)((int)src_3 + 1);
      dst_4 = (uint *)((int)dst_4 + 1);
    }
  }
  pch_auto_start_recording();
  return;
}

