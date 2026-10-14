char __cdecl pch_auto_check_usable(char *header_name)

{
  c1_vector *pcVar1;
  c1_vector *pcVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  fe_pch_header *pfVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  uint uVar10;
  c1_u8 *text;
  char *pcVar11;
  FILE *_File;
  byte *pbVar12;
  char *pcVar13;
  short sVar14;
  bool bVar15;
  int pch_time_in_pdb;
  c1xx_pdb *session_pdb;
  c1_pdb_namemap *session_namemap;
  c1_pdb_tpi *session_tpi;
  c1_mre_engine *session_mre;
  c1_pdb_blob_table *session_blob_table;
  c1_u8 session_read_only;
  char stat_buf [36];
  fe_pch_header pch_header;
  char local_100 [256];
  int note_id;
  
  if ((g_pch_file_name == (char *)0x0) || (pcVar11 = g_pch_file_name, g_use_pch != '\0')) {
    pcVar11 = path_make_default_pch_name(g_create_pch_header_name);
  }
  g_pch_file = (FILE *)_fsopen(pcVar11,"rb",0x20);
  if (g_pch_file == (FILE *)0x0) {
    return '\0';
  }
  fread(&g_pch_header_read,1,0x68,(FILE *)g_pch_file);
  if ((g_pch_file->_flag & 0x20) == 0) {
    pbVar12 = &g_pch_stamp;
    pfVar6 = &g_pch_header_read;
    do {
      bVar3 = pfVar6->stamp[0];
      bVar15 = bVar3 < *pbVar12;
      if (bVar3 != *pbVar12) {
LAB_10488349:
        iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        goto LAB_10488256;
      }
      if (bVar3 == 0) break;
      bVar3 = pfVar6->stamp[1];
      bVar15 = bVar3 < pbVar12[1];
      if (bVar3 != pbVar12[1]) goto LAB_10488349;
      pfVar6 = (fe_pch_header *)(pfVar6->stamp + 2);
      pbVar12 = pbVar12 + 2;
    } while (bVar3 != 0);
    iVar7 = 0;
LAB_10488256:
    if (((iVar7 == 0) && (g_pch_header_read.version == 0x12017d85)) &&
       (g_pch_header_read.magic == 0x8e4688c)) {
      if (((byte)g_pch_header_read.flags & 2) != 0) {
        pcVar13 = g_pch_header.compiler_date;
        pcVar8 = g_pch_header_read.compiler_date;
        do {
          bVar3 = *pcVar8;
          bVar15 = bVar3 < (byte)*pcVar13;
          if (bVar3 != *pcVar13) {
LAB_10488353:
            iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
            goto LAB_104882bd;
          }
          if (bVar3 == 0) break;
          bVar3 = pcVar8[1];
          bVar15 = bVar3 < (byte)pcVar13[1];
          if (bVar3 != pcVar13[1]) goto LAB_10488353;
          pcVar8 = pcVar8 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar3 != 0);
        iVar7 = 0;
LAB_104882bd:
        if (iVar7 != 0) goto LAB_1048832e;
      }
      if ((((byte)g_pch_header_read.flags & 1) != 0) && (g_pch_header_read.records_size != 0)) {
        if ((g_pch_header_read.pdb_copy_offset != 0) &&
           ((iVar7 = stat(g_pdb_file_name,stat_buf), iVar7 != -1 ||
            (piVar9 = _errno(), *piVar9 != 2)))) {
          if (g_pdb.pdb == (c1xx_pdb *)0x0) {
            if (g_batch_continuing == '\0') {
              session_pdb = (c1xx_pdb *)0x0;
              session_namemap = (c1_pdb_namemap *)0x0;
              session_tpi = (c1_pdb_tpi *)0x0;
              session_blob_table = (c1_pdb_blob_table *)0x0;
              session_read_only = '\0';
              session_mre = (c1_mre_engine *)0x0;
            }
            bVar3 = pdb_open_validated((c1_pdb_session *)&session_pdb,g_pdb_file_name,
                                       &g_pdb_signature,&g_pdb_age,0x1000,"r");
            if (bVar3 == 0) {
              diag_fatal_file_errno(0x53,0x162,g_pdb_file_name);
            }
            bVar3 = pdb_contrib_lookup_file((c1_pdb_session *)&session_pdb,pcVar11,&pch_time_in_pdb)
            ;
            if ((bVar3 == 0) || (bVar15 = true, pch_time_in_pdb != g_pch_header_read.time)) {
              bVar15 = false;
            }
            bVar3 = 1;
            if (session_blob_table != (c1_pdb_blob_table *)0x0) {
              bVar3 = pdb_stream_table_close(session_blob_table);
              session_blob_table = (c1_pdb_blob_table *)0x0;
              bVar3 = bVar3 & 1;
            }
            if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) &&
                 (session_read_only == '\0')) &&
                (iVar7 = (*session_pdb->vtbl->commit)(), iVar7 == 0)) ||
               (iVar7 = (*session_pdb->vtbl->close)(), iVar7 == 0)) {
              bVar4 = 0;
            }
            else {
              bVar4 = 1;
            }
            session_pdb = (c1xx_pdb *)0x0;
            if ((bVar3 & bVar4) == 0) {
              diag_error(0x1d7,g_pdb_file_name);
            }
            if (!bVar15) goto LAB_1048832e;
          }
          else {
            bVar3 = pdb_contrib_lookup_file(&g_pdb,pcVar11,&pch_time_in_pdb);
            if ((bVar3 == 0) || (pch_time_in_pdb != g_pch_header_read.time)) goto LAB_1048832e;
          }
        }
        fread(&g_pch_option_block_read,1,0x38c,(FILE *)g_pch_file);
        if ((g_pch_file->_flag & 0x20) == 0) {
          if (header_name == (char *)0x0) {
            g_pch_header_name[0] = '\0';
          }
          else {
            strncpy(g_pch_header_name,header_name,0x104);
            g_pch_header_name[0x103] = '\0';
          }
          cVar5 = file_name_equal((byte *)g_pch_header_name,
                                  (byte *)g_pch_option_block_read.header_name);
          if ((cVar5 != '\0') && (cVar5 = pch_check_options('\x01'), cVar5 != '\0')) {
            g_pch_records_buffer = mem_xmalloc(g_pch_header_read.records_size);
            fseek((FILE *)g_pch_file,g_pch_header_read.records_offset,0);
            if (((g_pch_file->_flag & 0x20) == 0) &&
               (fread(g_pch_records_buffer,1,g_pch_header_read.records_size,(FILE *)g_pch_file),
               pcVar2 = g_define_list, (g_pch_file->_flag & 0x20) == 0)) {
              g_pch_record_cursor = g_pch_records_buffer;
              sVar14 = 0;
              do {
                if ((pcVar2 == (c1_vector *)0x0) ||
                   (iVar7 = (int)sVar14, (int)(uint)pcVar2->count <= iVar7)) {
                  cVar5 = '\x01';
                  text = cwd_string();
                  uVar10 = pch_check_recorded_entry(7,0,(char *)text,cVar5);
                  pcVar2 = g_include_path_list;
                  if ((char)uVar10 != '\0') {
                    sVar14 = 0;
                    goto LAB_104885c5;
                  }
                  break;
                }
                sVar14 = sVar14 + 1;
                uVar10 = pch_check_recorded_entry(4,0,pcVar2->data[iVar7],'\0');
              } while ((char)uVar10 != '\0');
            }
          }
        }
      }
    }
  }
  goto LAB_1048832e;
  while( true ) {
    sVar14 = sVar14 + 1;
    uVar10 = pch_check_recorded_entry(7,0,pcVar2->data[iVar7],'\x01');
    if ((char)uVar10 == '\0') break;
LAB_104885c5:
    pcVar1 = g_forced_include_list;
    if ((pcVar2 == (c1_vector *)0x0) || (iVar7 = (int)sVar14, (int)(uint)pcVar2->count <= iVar7)) {
      sVar14 = 0;
      goto LAB_104885fd;
    }
  }
  goto LAB_1048832e;
LAB_10488631:
  if (*g_pch_record_cursor == 6) {
    _File = _fsopen((char *)(g_pch_record_cursor + 3),"rb",0x20);
    if (_File == (FILE *)0x0) goto LAB_1048832e;
    fread(&pch_header,1,0x68,_File);
    uVar10 = _File->_flag;
    fclose(_File);
    if (((~(byte)(uVar10 >> 5) & 1) == 0) || (g_pch_record_cursor[2] != pch_header.time))
    goto LAB_1048832e;
  }
  else if ((*g_pch_record_cursor != 8) ||
          (uVar10 = file_mtime((char *)(g_pch_record_cursor + 3)), g_pch_record_cursor[2] != uVar10)
          ) goto LAB_1048832e;
  g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
  if (*g_pch_record_cursor == 0xc) {
    mem_free(g_pch_records_buffer);
    g_pch_record_cursor = (int *)0x0;
    g_pch_records_buffer = (int *)0x0;
    fclose((FILE *)g_pch_file);
    g_pch_file = (FILE *)0x0;
    if (g_opt_nologo == '\0') {
      pcVar8 = "\n";
      note_id = 0x38c;
      iVar7 = 0x100;
      pcVar11 = misc_string_get(0x386);
      format_snprintf(local_100,pcVar11,iVar7,note_id,pcVar8);
      diag_write_stderr(local_100);
    }
    return '\x01';
  }
  goto LAB_10488631;
  while( true ) {
    sVar14 = sVar14 + 1;
    uVar10 = pch_check_recorded_entry(5,0,pcVar1->data[iVar7],'\x01');
    if ((char)uVar10 == '\0') break;
LAB_104885fd:
    if ((pcVar1 == (c1_vector *)0x0) || (iVar7 = (int)sVar14, (int)(uint)pcVar1->count <= iVar7))
    goto LAB_10488631;
  }
LAB_1048832e:
  fclose((FILE *)g_pch_file);
  g_pch_file = (FILE *)0x0;
  return '\0';
}

