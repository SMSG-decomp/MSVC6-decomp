void __cdecl pch_open(void)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  fe_pch_header *pfVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  char *pcVar8;
  bool bVar9;
  char stat_buf [36];
  byte local_400 [256];
  byte local_300 [256];
  byte local_200 [256];
  byte local_100 [256];
  
  pcVar3 = "r+b";
  if (g_auto_pch_using == 0) {
    pcVar3 = "rb";
  }
  g_pch_file = (FILE *)_fsopen(g_pch_file_name,pcVar3,0x20);
  if (g_pch_file == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
    return;
  }
  fread(&g_pch_header,1,0x68,(FILE *)g_pch_file);
  pbVar7 = &g_pch_stamp;
  pfVar4 = &g_pch_header;
  do {
    bVar1 = pfVar4->stamp[0];
    bVar9 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_10487595:
      iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_104498f3;
    }
    if (bVar1 == 0) break;
    bVar1 = pfVar4->stamp[1];
    bVar9 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_10487595;
    pfVar4 = (fe_pch_header *)(pfVar4->stamp + 2);
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_104498f3:
  if (iVar5 != 0) {
    diag_fatal(0x354,g_pch_file_name);
  }
  if (g_pch_header.version == 0x12017d85) {
    if (((byte)g_pch_header.flags & 2) != 0) {
      pcVar8 = "Jun 17 199810:24:46";
      pcVar3 = g_pch_header.compiler_date;
      do {
        bVar1 = *pcVar3;
        bVar9 = bVar1 < (byte)*pcVar8;
        if (bVar1 != *pcVar8) {
LAB_104875bc:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_1044994a;
        }
        if (bVar1 == 0) break;
        bVar1 = pcVar3[1];
        bVar9 = bVar1 < (byte)pcVar8[1];
        if (bVar1 != pcVar8[1]) goto LAB_104875bc;
        pcVar3 = pcVar3 + 2;
        pcVar8 = pcVar8 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_1044994a:
      if (iVar5 != 0) goto LAB_104877b6;
    }
    if (g_pch_header.magic == 0x8e4688c) {
      if ((g_pch_header.records_size != 0) && (((byte)g_pch_header.flags & 1) == 0)) {
        diag_fatal(0x354,g_pch_file_name);
      }
      fread(&g_pch_option_block_read,1,0x38c,(FILE *)g_pch_file);
      cVar2 = pch_check_options('\0');
      if (cVar2 != '\0') {
        if ((g_debug_types_in_pdb != '\0') || (g_c9il_mode == '\0')) {
          _splitpath(g_pdb_file_name,(char *)0x0,(char *)0x0,(char *)local_400,(char *)local_100);
          _splitpath(g_pch_option_block_read.pdb_file_name,(char *)0x0,(char *)0x0,(char *)local_200
                     ,(char *)local_300);
          cVar2 = file_name_equal(local_400,local_200);
          if ((cVar2 == '\0') || (cVar2 = file_name_equal(local_100,local_300), cVar2 == '\0')) {
            diag_error(0x35a,0x187,"/Fd",g_pdb_file_name,"/Fd",0x104e2887);
          }
        }
        pcVar8 = g_pch_option_block_read.pch_library_id;
        pcVar3 = g_pch_library_id;
        do {
          bVar1 = *pcVar3;
          bVar9 = bVar1 < (byte)*pcVar8;
          if (bVar1 != *pcVar8) {
LAB_10487640:
            iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_10449a3f;
          }
          if (bVar1 == 0) break;
          bVar1 = pcVar3[1];
          bVar9 = bVar1 < (byte)pcVar8[1];
          if (bVar1 != pcVar8[1]) goto LAB_10487640;
          pcVar3 = pcVar3 + 2;
          pcVar8 = pcVar8 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_10449a3f:
        if ((iVar5 != 0) && (g_pch_creating == 0)) {
          iVar5 = -1;
          pcVar3 = g_pch_library_id;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar2 != '\0');
          if (iVar5 != -2) {
            diag_warning(1,0x28d,0x195);
          }
        }
        if (g_auto_pch_using == 0) {
          if (g_auto_pch_creating != 0) {
            pragma_section_record(6,g_pch_header.time,g_pch_file_name);
          }
        }
        else {
          _g_io_result = futime(g_pch_file->_file,0);
          if (_g_io_result != 0) {
            diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
          }
          if (((g_pch_header.pdb_copy_offset != 0) &&
              (iVar5 = stat(g_pdb_file_name,stat_buf), iVar5 == -1)) &&
             (piVar6 = _errno(), *piVar6 == 2)) {
            _g_io_result = fseek((FILE *)g_pch_file,g_pch_header.pdb_copy_offset,0);
            if (_g_io_result != 0) {
              diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
            }
            if (g_pch_header.pdb_copy_size != 0) {
              pch_extract_file_rle(g_pdb_file_name,g_pch_header.pdb_copy_size);
            }
            if (g_pch_header.idb_copy_size != 0) {
              if (g_split_pdbs == '\0') {
                pcVar3 = g_pdb_file_name;
              }
              else {
                if (g_idb_file_name == '\0') {
                  pdb_make_idb_name(&g_idb_file_name);
                }
                pcVar3 = &g_idb_file_name;
              }
              pch_extract_file_rle(pcVar3,g_pch_header.idb_copy_size);
            }
          }
        }
        pdb_open();
        pch_read();
        if ((g_pch_use_only != 0) && (g_opt_BnoWorkList == '\0')) {
          g_function_record_first_block = (c1_function_record_block *)0x0;
          g_function_record_block = (c1_function_record_block *)0x0;
          g_function_record_index = 0x13;
          if (g_rtti != '\0') {
            rtti_reset_pending_descriptors();
            return;
          }
        }
      }
      return;
    }
  }
LAB_104877b6:
  diag_fatal(0x355,g_pch_file_name);
}

