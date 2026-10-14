char __cdecl pch_auto_check_usable(char *header_name)

{
  fe_vector *pfVar1;
  fe_vector *pfVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char *pcVar6;
  fe_pch_header *pfVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  c1_u8 *text;
  uint uVar11;
  FILE *_File;
  byte *pbVar12;
  char *pcVar13;
  short sVar14;
  bool bVar15;
  int local_1ac;
  c1_pdb_state local_1a8;
  _stat pdb_stat;
  fe_pch_header header;
  char local_100 [256];
  int line;
  
  if ((g_pch_file_name == (char *)0x0) || (pcVar6 = g_pch_file_name, g_use_pch != '\0')) {
    pcVar6 = path_make_default_pch_name(g_create_pch_header_name);
  }
  g_pch_file = _fsopen(pcVar6,"rb",0x20);
  if (g_pch_file == (FILE *)0x0) {
    return '\0';
  }
  fread(&g_pch_header_read,1,0x68,g_pch_file);
  if ((g_pch_file->_flag & 0x20) == 0) {
    pbVar12 = &g_pch_stamp;
    pfVar7 = &g_pch_header_read;
    do {
      bVar3 = pfVar7->stamp[0];
      bVar15 = bVar3 < *pbVar12;
      if (bVar3 != *pbVar12) {
LAB_10641a9f:
        iVar8 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        goto LAB_106419a4;
      }
      if (bVar3 == 0) break;
      bVar3 = pfVar7->stamp[1];
      bVar15 = bVar3 < pbVar12[1];
      if (bVar3 != pbVar12[1]) goto LAB_10641a9f;
      pfVar7 = (fe_pch_header *)(pfVar7->stamp + 2);
      pbVar12 = pbVar12 + 2;
    } while (bVar3 != 0);
    iVar8 = 0;
LAB_106419a4:
    if (((iVar8 == 0) && (g_pch_header_read.version == 0x12017885)) &&
       (g_pch_header_read.magic == 0x7646884)) {
      if (((byte)g_pch_header_read.flags & 2) != 0) {
        pcVar13 = g_pch_header.compiler_date;
        pcVar9 = g_pch_header_read.compiler_date;
        do {
          bVar3 = *pcVar9;
          bVar15 = bVar3 < (byte)*pcVar13;
          if (bVar3 != *pcVar13) {
LAB_10641aa9:
            iVar8 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
            goto LAB_10641a0b;
          }
          if (bVar3 == 0) break;
          bVar3 = pcVar9[1];
          bVar15 = bVar3 < (byte)pcVar13[1];
          if (bVar3 != pcVar13[1]) goto LAB_10641aa9;
          pcVar9 = pcVar9 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar3 != 0);
        iVar8 = 0;
LAB_10641a0b:
        if (iVar8 != 0) goto LAB_10641a7c;
      }
      if ((((byte)g_pch_header_read.flags & 1) != 0) && (g_pch_header_read.records_size != 0)) {
        if ((g_pch_header_read.pdb_copy_offset != 0) &&
           ((iVar8 = stat(&g_pdb_file_name,&pdb_stat), iVar8 != -1 ||
            (piVar10 = _errno(), *piVar10 != 2)))) {
          if (g_pdb.pdb == (PDB *)0x0) {
            if (g_batch_continuing == '\0') {
              local_1a8.pdb = (PDB *)0x0;
              local_1a8.name_map = (NameMap *)0x0;
              local_1a8.tpi = (TPI *)0x0;
              local_1a8.stream_table = (fe_pdb_blob_table *)0x0;
              local_1a8.read_only = '\0';
              local_1a8.mre = (MREngine *)0x0;
            }
            bVar3 = pdb_open_validated(&local_1a8,&g_pdb_file_name,(int *)&g_pdb_signature,
                                       (int *)&g_pdb_age,0x1000,"r");
            if (bVar3 == 0) {
              diag_fatal_file_errno(0x53,0x162,&g_pdb_file_name);
            }
            bVar3 = pdb_contrib_lookup_file(&local_1a8,pcVar6,&local_1ac);
            if ((bVar3 == 0) || (bVar15 = true, local_1ac != g_pch_header_read.time)) {
              bVar15 = false;
            }
            bVar3 = 1;
            if (local_1a8.stream_table != (fe_pdb_blob_table *)0x0) {
              bVar3 = pdb_stream_table_close(local_1a8.stream_table);
              local_1a8.stream_table = (fe_pdb_blob_table *)0x0;
              bVar3 = bVar3 & 1;
            }
            if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) &&
                 (local_1a8.read_only == '\0')) &&
                (iVar8 = (*(local_1a8.pdb)->vtbl->Commit)(local_1a8.pdb), iVar8 == 0)) ||
               (iVar8 = (*(local_1a8.pdb)->vtbl->Close)(local_1a8.pdb), iVar8 == 0)) {
              bVar4 = 0;
            }
            else {
              bVar4 = 1;
            }
            local_1a8.pdb = (PDB *)0x0;
            if ((bVar3 & bVar4) == 0) {
              diag_error(0x1d7,&g_pdb_file_name);
            }
            if (!bVar15) goto LAB_10641a7c;
          }
          else {
            bVar3 = pdb_contrib_lookup_file(&g_pdb,pcVar6,&local_1ac);
            if ((bVar3 == 0) || (local_1ac != g_pch_header_read.time)) goto LAB_10641a7c;
          }
        }
        fread(&g_pch_option_block_read,1,900,g_pch_file);
        if ((g_pch_file->_flag & 0x20) == 0) {
          if (header_name == (char *)0x0) {
            g_pch_header_name[0] = '\0';
          }
          else {
            strncpy(g_pch_header_name,header_name,0x104);
            g_pch_header_name[0x103] = '\0';
          }
          cVar5 = file_name_equal((byte *)g_pch_header_name,
                                  (byte *)g_pch_option_block_read.header_file_name);
          if ((cVar5 != '\0') && (cVar5 = pch_check_options('\x01'), cVar5 != '\0')) {
            g_pch_records_buffer = mem_xmalloc(g_pch_header_read.records_size);
            fseek(g_pch_file,g_pch_header_read.records_offset,0);
            if (((g_pch_file->_flag & 0x20) == 0) &&
               (fread(g_pch_records_buffer,1,g_pch_header_read.records_size,g_pch_file),
               pfVar2 = g_define_list, (g_pch_file->_flag & 0x20) == 0)) {
              g_pch_record_cursor = g_pch_records_buffer;
              sVar14 = 0;
              do {
                if ((pfVar2 == (fe_vector *)0x0) ||
                   (iVar8 = (int)sVar14, (int)(uint)pfVar2->count <= iVar8)) {
                  cVar5 = '\x01';
                  text = cwd_string();
                  cVar5 = pch_check_recorded_entry(7,0,(char *)text,cVar5);
                  pfVar2 = g_include_path_list;
                  if (cVar5 != '\0') {
                    sVar14 = 0;
                    goto LAB_10641d1b;
                  }
                  break;
                }
                sVar14 = sVar14 + 1;
                cVar5 = pch_check_recorded_entry(4,0,pfVar2->data[iVar8],'\0');
              } while (cVar5 != '\0');
            }
          }
        }
      }
    }
  }
  goto LAB_10641a7c;
  while( true ) {
    sVar14 = sVar14 + 1;
    cVar5 = pch_check_recorded_entry(7,0,pfVar2->data[iVar8],'\x01');
    if (cVar5 == '\0') break;
LAB_10641d1b:
    pfVar1 = g_forced_include_list;
    if ((pfVar2 == (fe_vector *)0x0) || (iVar8 = (int)sVar14, (int)(uint)pfVar2->count <= iVar8)) {
      sVar14 = 0;
      goto LAB_10641d53;
    }
  }
  goto LAB_10641a7c;
LAB_10641d87:
  if (*g_pch_record_cursor == 6) {
    _File = _fsopen((char *)(g_pch_record_cursor + 3),"rb",0x20);
    if (_File == (FILE *)0x0) goto LAB_10641a7c;
    fread(&header,1,0x68,_File);
    uVar11 = _File->_flag;
    fclose(_File);
    if (((~(byte)(uVar11 >> 5) & 1) == 0) || (g_pch_record_cursor[2] != header.time))
    goto LAB_10641a7c;
  }
  else if ((*g_pch_record_cursor != 8) ||
          (uVar11 = file_mtime((char *)(g_pch_record_cursor + 3)), g_pch_record_cursor[2] != uVar11)
          ) goto LAB_10641a7c;
  g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
  if (*g_pch_record_cursor == 0xc) {
    mem_free(g_pch_records_buffer);
    g_pch_record_cursor = (int *)0x0;
    g_pch_records_buffer = (int *)0x0;
    fclose(g_pch_file);
    g_pch_file = (FILE *)0x0;
    if (g_opt_nologo == '\0') {
      pcVar9 = "\n";
      line = 0x38c;
      iVar8 = 0x100;
      pcVar6 = misc_string_get(0x386);
      format_snprintf(local_100,pcVar6,iVar8,line,pcVar9);
      diag_write_stderr(local_100);
    }
    return '\x01';
  }
  goto LAB_10641d87;
  while( true ) {
    sVar14 = sVar14 + 1;
    cVar5 = pch_check_recorded_entry(5,0,pfVar1->data[iVar8],'\x01');
    if (cVar5 == '\0') break;
LAB_10641d53:
    if ((pfVar1 == (fe_vector *)0x0) || (iVar8 = (int)sVar14, (int)(uint)pfVar1->count <= iVar8))
    goto LAB_10641d87;
  }
LAB_10641a7c:
  fclose(g_pch_file);
  g_pch_file = (FILE *)0x0;
  return '\0';
}

