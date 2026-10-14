void __cdecl pch_auto_begin(void)

{
  int iVar1;
  byte bVar2;
  fe_vector *pfVar3;
  char cVar4;
  c1_u8 *text;
  fe_pch_header *pfVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  char *pcVar11;
  int *piVar12;
  short sVar13;
  uint *dst;
  c1_pch_options *pcVar14;
  bool bVar15;
  undefined4 uVar16;
  char local_100 [256];
  int line;
  
  block_list_open_or_rewind(&g_pch_directive_text_blocks);
  g_pch_directive_mode = 2;
  pch_set_name("vc60.pch");
  g_eh_declarations_injected = 1;
  g_pch_file = fopen(g_pch_file_name,"rb");
  if (g_pch_file != (FILE *)0x0) {
    fread(&g_pch_header_read,1,0x68,g_pch_file);
    if ((g_pch_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x54,0x158,g_pch_file_name);
    }
    pbVar10 = &g_pch_stamp;
    pfVar5 = &g_pch_header_read;
    do {
      bVar2 = pfVar5->stamp[0];
      bVar15 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_1063f23e:
        iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        goto LAB_1063f009;
      }
      if (bVar2 == 0) break;
      bVar2 = pfVar5->stamp[1];
      bVar15 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_1063f23e;
      pfVar5 = (fe_pch_header *)(pfVar5->stamp + 2);
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar6 = 0;
LAB_1063f009:
    if (((iVar6 == 0) && (g_pch_header_read.version == 0x12017885)) &&
       (g_pch_header_read.magic == 0x7646884)) {
      if (((byte)g_pch_header_read.flags & 2) != 0) {
        pcVar11 = g_pch_header.compiler_date;
        pcVar7 = g_pch_header_read.compiler_date;
        do {
          bVar2 = *pcVar7;
          bVar15 = bVar2 < (byte)*pcVar11;
          if (bVar2 != *pcVar11) {
LAB_1063f248:
            iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
            goto LAB_1063f06e;
          }
          if (bVar2 == 0) break;
          bVar2 = pcVar7[1];
          bVar15 = bVar2 < (byte)pcVar11[1];
          if (bVar2 != pcVar11[1]) goto LAB_1063f248;
          pcVar7 = pcVar7 + 2;
          pcVar11 = pcVar11 + 2;
        } while (bVar2 != 0);
        iVar6 = 0;
LAB_1063f06e:
        if (iVar6 != 0) goto LAB_1063f1a0;
      }
      if ((g_pch_header_read.records_size != 0) && (((byte)g_pch_header_read.flags & 1) == 0)) {
        fread(&g_pch_option_block_read,1,900,g_pch_file);
        if ((g_debug_types_in_pdb != '\0') &&
           (cVar4 = file_name_equal(&g_pdb_file_name,(byte *)g_pch_option_block_read.pdb_file_name),
           cVar4 != '\0')) {
          pcVar7 = g_pch_option_block_read.pdb_file_name;
          dst = (uint *)&g_pdb_file_name;
          for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
            *dst = *(uint *)pcVar7;
            pcVar7 = pcVar7 + 4;
            dst = dst + 1;
          }
        }
        iVar6 = 0xe1;
        bVar15 = true;
        piVar12 = &g_pch_option_block;
        pcVar14 = &g_pch_option_block_read;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          iVar1._0_1_ = pcVar14->opt_ZE;
          iVar1._1_1_ = pcVar14->pad01[0];
          iVar1._2_1_ = pcVar14->pad01[1];
          iVar1._3_1_ = pcVar14->pad01[2];
          bVar15 = *piVar12 == iVar1;
          piVar12 = piVar12 + 1;
          pcVar14 = (c1_pch_options *)&pcVar14->ms_extensions;
        } while (bVar15);
        if (bVar15) {
          g_pch_records_buffer = mem_xmalloc(g_pch_header_read.records_size);
          _g_io_result = fseek(g_pch_file,g_pch_header_read.records_offset,0);
          if (_g_io_result != 0) {
            diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
          }
          fread(g_pch_records_buffer,1,g_pch_header_read.records_size,g_pch_file);
          pfVar3 = g_define_list;
          g_pch_record_cursor = g_pch_records_buffer;
          sVar13 = 0;
          do {
            if ((pfVar3 == (fe_vector *)0x0) ||
               (iVar6 = (int)sVar13, (int)(uint)pfVar3->count <= iVar6)) {
              text = cwd_string();
              pch_record_entry(7,0,(char *)text);
              pfVar3 = g_include_path_list;
              if (g_pch_directive_mode != 1) {
                sVar13 = 0;
                do {
                  if ((pfVar3 == (fe_vector *)0x0) ||
                     (iVar6 = (int)sVar13, (int)(uint)pfVar3->count <= iVar6)) {
                    g_pch_include_count[0] = 0;
                    return;
                  }
                  sVar13 = sVar13 + 1;
                  pch_record_entry(7,0,pfVar3->data[iVar6]);
                } while (g_pch_directive_mode != 1);
              }
              break;
            }
            sVar13 = sVar13 + 1;
            pch_record_macro_definition(&g_empty_string,pfVar3->data[iVar6],0);
          } while (g_pch_directive_mode != 1);
        }
      }
    }
  }
LAB_1063f1a0:
  if ((g_opt_nologo == '\0') && (g_pch_auto_note == (char *)0x0)) {
    if (g_pch_file == (FILE *)0x0) {
      uVar16 = 0x15f;
      iVar6 = 0x100;
      pcVar7 = g_pch_file_name;
      pcVar11 = misc_string_get(0x386);
      format_snprintf(local_100,pcVar11,iVar6,uVar16,pcVar7);
    }
    else {
      line = 0x160;
      uVar16 = 0x161;
      iVar6 = 0x100;
      pcVar7 = g_pch_file_name;
      pcVar11 = misc_string_get(0x385);
      format_snprintf(local_100,pcVar11,iVar6,uVar16,line,pcVar7);
    }
    uVar8 = 0xffffffff;
    pcVar7 = local_100;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar4 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar4 != '\0');
    g_pch_auto_note = mem_xmalloc(~uVar8);
    uVar8 = 0xffffffff;
    pcVar7 = local_100;
    do {
      pcVar11 = pcVar7;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar11 = pcVar7 + 1;
      cVar4 = *pcVar7;
      pcVar7 = pcVar11;
    } while (cVar4 != '\0');
    uVar8 = ~uVar8;
    pcVar7 = pcVar11 + -uVar8;
    pcVar11 = g_pch_auto_note;
    for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar11 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  pch_auto_start_recording();
  return;
}

