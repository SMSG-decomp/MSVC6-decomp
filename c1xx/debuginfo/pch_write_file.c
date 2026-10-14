void __cdecl pch_write_file(void)

{
  char cVar1;
  c1_u8 *src;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  c1_fflush_fn fflush_fn;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  fflush_fn = fflush_exref;
  if (g_c9il_mode == '\0') {
    pch_begin_write();
    return;
  }
  if (g_use_pch == '\0') {
    if (g_pch_in_ex_file == 0) {
      uVar4 = 0xffffffff;
      pcVar6 = g_opt_il_prefix;
      do {
        pcVar8 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar6 = pcVar8 + -uVar4;
      pcVar8 = &stack0xffffffc0;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      uVar4 = 0xffffffff;
      pcVar6 = "ex";
      do {
        pcVar8 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar2 = -1;
      pcVar6 = &stack0xffffffc0;
      do {
        pcVar7 = pcVar6;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar4;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      il_buffer_close(&g_il_ex);
      iVar2 = remove(g_pch_file_name);
      if ((iVar2 != 0) && (piVar3 = _errno(), *piVar3 == 0xd)) {
        diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
      }
      iVar2 = rename(&stack0xffffffc0,g_pch_file_name);
      if (iVar2 == 0) {
        g_pch_file = (FILE *)fopen(g_pch_file_name,"r+b");
        if (g_pch_file == (FILE *)0x0) {
          diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
        }
        g_pch_file_unfinished = 1;
        il_file_open(&g_il_ex,g_opt_il_prefix,"ex","wb");
      }
      else {
        piVar3 = _errno();
        switch(*piVar3) {
        case 2:
        case 0xd:
          diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
          break;
        case 0x12:
          g_pch_file = (FILE *)fopen(g_pch_file_name,"wb");
          if (g_pch_file == (FILE *)0x0) {
            diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
          }
          g_pch_file_unfinished = 1;
          il_file_open(&g_il_ex,g_opt_il_prefix,"ex","r+b");
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
      fflush((FILE *)g_il_ex.file);
      g_pch_file = g_il_ex.file;
      il_file_open(&g_il_ex,g_opt_il_prefix,"ex","wb");
      g_pch_in_ex_file = 0;
      g_pch_file_unfinished = 1;
    }
    _g_io_result = fflush((FILE *)g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
    }
    _g_io_result = fseek((FILE *)g_pch_file,0,2);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
    }
    iVar2 = ftell((FILE *)g_pch_file);
    _g_io_result = iVar2;
    if (iVar2 == -1) {
      iVar2 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
    }
    g_pch_header.ex_size = iVar2 + -0x3f4;
    g_pch_sy_file_offset = iVar2;
    pch_save_il();
  }
  else {
    g_pch_write_file = (FILE *)fopen(g_pch_file_name,"w+b");
    if (g_pch_write_file == (FILE *)0x0) {
      diag_fatal_file_errno(0x53,0x158,g_pch_file_name);
    }
    g_pch_write_file_unfinished = 1;
    rewind((FILE *)g_pch_file);
    il_buffer_flush(&g_il_ex);
    fflush_fn = fflush_exref;
    fflush((FILE *)g_il_ex.file);
    rewind((FILE *)g_il_ex.file);
    g_file_copy_buffer = mem_xmalloc(0x8000);
    file_copy_contents(g_pch_file,g_pch_write_file,g_pch_header.ex_size + 0x3f4);
    iVar2 = file_copy_contents(g_il_ex.file,g_pch_write_file,0x7fffffff);
    g_pch_header.ex_size = g_pch_header.ex_size + iVar2;
    g_pch_sy_file_offset = g_pch_header.ex_size + 0x3f4;
    il_buffer_flush(&g_il_sy);
    fflush((FILE *)g_il_sy.file);
    rewind((FILE *)g_il_sy.file);
    file_copy_contents(g_pch_file,g_pch_write_file,g_pch_header.sy_size);
    iVar2 = file_copy_contents(g_il_sy.file,g_pch_write_file,0x7fffffff);
    g_pch_header.sy_size = g_pch_header.sy_size + iVar2;
    il_buffer_flush(&g_il_gl);
    fflush((FILE *)g_il_gl.file);
    rewind((FILE *)g_il_gl.file);
    g_pch_header.gl_size = file_copy_contents(g_il_gl.file,g_pch_write_file,0x7fffffff);
    src = g_il_pending_init.bytes.start;
    uVar4 = (int)g_il_pending_init.bytes.cur - (int)g_il_pending_init.bytes.start;
    if (uVar4 != 0) {
      iVar2 = il_buffer_reserve(&g_il_in.bytes,uVar4 + 1);
      g_il_in.open = g_il_in.open & (byte)iVar2 & 1;
      if (g_il_in.open != 0) {
        il_buffer_put_bytes(&g_il_in,(uint *)src,uVar4);
      }
      g_il_pending_init.bytes.cur = g_il_pending_init.bytes.start;
    }
    il_buffer_flush(&g_il_in);
    fflush((FILE *)g_il_in.file);
    rewind((FILE *)g_il_in.file);
    g_pch_header.in_size = file_copy_contents(g_il_in.file,g_pch_write_file,0x7fffffff);
    if ((g_opt_Zi != '\0') &&
       ((g_pch_debug_in_object != '\0' ||
        ((g_auto_pch_creating != 0 && (g_debug_types_in_pdb == '\0')))))) {
      il_buffer_flush(&g_il_db);
      fflush((FILE *)g_il_db.file);
      rewind((FILE *)g_il_db.file);
      g_pch_header.db_size = file_copy_contents(g_il_db.file,g_pch_write_file,0x7fffffff);
    }
    _g_io_result = fclose((FILE *)g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x153,(char *)0x0);
    }
    g_pch_file_unfinished = 1;
    g_pch_file = g_pch_write_file;
    g_pch_write_file_unfinished = 0;
    pch_write_finish();
  }
  il_buffer_flush(&g_il_ex);
  (*fflush_fn)(g_il_ex.file);
  rewind((FILE *)g_il_ex.file);
  il_buffer_flush(&g_il_sy);
  (*fflush_fn)(g_il_sy.file);
  rewind((FILE *)g_il_sy.file);
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

