void __cdecl pch_write_file(void)

{
  char cVar1;
  PB src;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char local_40 [64];
  
  pcVar6 = fflush_exref;
  if (g_c9il_mode == '\0') {
    pch_begin_write();
    return;
  }
  if (g_use_pch == '\0') {
    if (g_pch_in_ex_file == '\0') {
      uVar4 = 0xffffffff;
      pcVar7 = g_opt_il_prefix;
      do {
        pcVar9 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar9 + -uVar4;
      pcVar9 = local_40;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar7 = "ex";
      do {
        pcVar9 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar2 = -1;
      pcVar7 = local_40;
      do {
        pcVar8 = pcVar7;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar4;
      pcVar9 = pcVar8 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      il_buffer_close(&g_il_ex);
      iVar2 = remove(g_pch_file_name);
      if ((iVar2 != 0) && (piVar3 = _errno(), *piVar3 == 0xd)) {
        diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
      }
      iVar2 = rename(local_40,g_pch_file_name);
      if (iVar2 == 0) {
        g_pch_file = fopen(g_pch_file_name,"r+b");
        if (g_pch_file == (FILE *)0x0) {
          diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
        }
        g_pch_file_unfinished = '\x01';
        il_file_open(&g_il_ex,(byte *)g_opt_il_prefix,"ex","wb");
      }
      else {
        piVar3 = _errno();
        switch(*piVar3) {
        case 2:
        case 0xd:
          diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
          break;
        case 0x12:
          g_pch_file = fopen(g_pch_file_name,"wb");
          if (g_pch_file == (FILE *)0x0) {
            diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
          }
          g_pch_file_unfinished = '\x01';
          il_file_open(&g_il_ex,(byte *)g_opt_il_prefix,"ex","r+b");
          g_file_copy_buffer = mem_xmalloc(0x8000);
          file_copy_contents(g_il_ex.file,g_pch_file,0x7fffffff);
          mem_free(g_file_copy_buffer);
          break;
        case 0x1c:
          diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
        }
      }
    }
    else {
      il_buffer_flush(&g_il_ex);
      fflush(g_il_ex.file);
      g_pch_file = g_il_ex.file;
      il_file_open(&g_il_ex,(byte *)g_opt_il_prefix,"ex","wb");
      g_pch_in_ex_file = '\0';
      g_pch_file_unfinished = '\x01';
    }
    _g_io_result = fflush(g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
    }
    _g_io_result = fseek(g_pch_file,0,2);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
    }
    iVar2 = ftell(g_pch_file);
    _g_io_result = iVar2;
    if (iVar2 == -1) {
      iVar2 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
    }
    g_pch_header.ex_size = iVar2 + -0x3ec;
    g_pch_sy_file_offset = iVar2;
    pch_save_il();
  }
  else {
    g_pch_write_file = fopen(g_pch_file_name,"w+b");
    if (g_pch_write_file == (FILE *)0x0) {
      diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
    }
    g_pch_write_file_unfinished = '\x01';
    rewind(g_pch_file);
    il_buffer_flush(&g_il_ex);
    pcVar6 = fflush_exref;
    fflush(g_il_ex.file);
    rewind(g_il_ex.file);
    g_file_copy_buffer = mem_xmalloc(0x8000);
    file_copy_contents(g_pch_file,g_pch_write_file,g_pch_header.ex_size + 0x3ec);
    iVar2 = file_copy_contents(g_il_ex.file,g_pch_write_file,0x7fffffff);
    g_pch_header.ex_size = g_pch_header.ex_size + iVar2;
    g_pch_sy_file_offset = g_pch_header.ex_size + 0x3ec;
    il_buffer_flush(&g_il_sy);
    fflush(g_il_sy.file);
    rewind(g_il_sy.file);
    file_copy_contents(g_pch_file,g_pch_write_file,g_pch_header.sy_size);
    iVar2 = file_copy_contents(g_il_sy.file,g_pch_write_file,0x7fffffff);
    g_pch_header.sy_size = g_pch_header.sy_size + iVar2;
    il_buffer_flush(&g_il_gl);
    fflush(g_il_gl.file);
    rewind(g_il_gl.file);
    g_pch_header.gl_size = file_copy_contents(g_il_gl.file,g_pch_write_file,0x7fffffff);
    src = g_il_pending_init.bytes.pbStart;
    uVar4 = (int)g_il_pending_init.bytes.pbEnd - (int)g_il_pending_init.bytes.pbStart;
    if (uVar4 != 0) {
      iVar2 = il_buffer_reserve(&g_il_in.bytes,uVar4 + 1);
      g_il_in.open = g_il_in.open & (byte)iVar2 & 1;
      if (g_il_in.open != 0) {
        il_buffer_put_bytes(&g_il_in,(uint *)src,uVar4);
      }
      g_il_pending_init.bytes.pbEnd = g_il_pending_init.bytes.pbStart;
    }
    il_buffer_flush(&g_il_in);
    fflush(g_il_in.file);
    rewind(g_il_in.file);
    g_pch_header.in_size = file_copy_contents(g_il_in.file,g_pch_write_file,0x7fffffff);
    if ((g_opt_Zi != '\0') &&
       ((g_pch_debug_in_object != '\0' ||
        ((g_auto_pch_creating != 0 && (g_debug_types_in_pdb == '\0')))))) {
      il_buffer_flush(&g_il_db);
      fflush(g_il_db.file);
      rewind(g_il_db.file);
      g_pch_header.db_size = file_copy_contents(g_il_db.file,g_pch_write_file,0x7fffffff);
    }
    _g_io_result = fclose(g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x153,(char *)0x0);
    }
    g_pch_file_unfinished = '\x01';
    g_pch_file = g_pch_write_file;
    g_pch_write_file_unfinished = '\0';
    pch_write_finish();
  }
  il_buffer_flush(&g_il_ex);
  (*pcVar6)(g_il_ex.file);
  rewind(g_il_ex.file);
  il_buffer_flush(&g_il_sy);
  (*pcVar6)(g_il_sy.file);
  rewind(g_il_sy.file);
  _g_io_result = _chsize((g_il_ex.file)->_file,0);
  if (_g_io_result == -1) {
    diag_fatal_file_errno(0x59,0x153,(char *)0x0);
  }
  _g_io_result = _chsize((g_il_sy.file)->_file,0);
  if (_g_io_result == -1) {
    diag_fatal_file_errno(0x59,0x153,(char *)0x0);
  }
  return;
}

