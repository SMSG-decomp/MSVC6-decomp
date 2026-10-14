int __cdecl pch_auto_match_end(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *fmt;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *src;
  uint *dst;
  char *pcVar7;
  char local_100 [256];
  int note_id;
  
  if ((g_pch_file_time_changed == 0) && (*g_pch_record_cursor == 0xc)) {
    src = (uint *)&g_pch_header_read;
    dst = (uint *)&g_pch_header;
    for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    pch_read();
    mem_free(g_pch_records_buffer);
    g_pch_record_cursor = (int *)0x0;
    g_pch_records_buffer = (int *)0x0;
    if (g_opt_Zi != '\0') {
      debug_begin('\x01');
    }
    g_pch_directive_mode = 0;
    if (g_opt_nologo == '\0') {
      pcVar7 = "\n";
      note_id = 0x15e;
      iVar4 = 0x100;
      pcVar3 = misc_string_get(0x386);
      format_snprintf(local_100,pcVar3,iVar4,note_id,pcVar7);
      diag_write_stderr(local_100);
    }
    return 3;
  }
  if (g_pch_header_read.include_key_alt == 0) {
    g_pch_header_read.include_key_alt = g_pch_header_read.include_key;
  }
  if (g_pch_auto_never_recreate == 0) {
    if (((g_pch_include_count.last_key == 0) ||
        ((g_pch_header_read.include_key << 7) / (int)(uint)(ushort)g_pch_include_count.last_key <
         100)) ||
       ((g_pch_header_read.include_key_alt << 7) / (int)(uint)(ushort)g_pch_include_count.last_key <
        0x50)) {
      iVar4 = 0;
      iVar2 = *g_pch_record_cursor;
      while (iVar2 != 0xc) {
        if (iVar2 == 2) {
          iVar4 = iVar4 + 1;
        }
        g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
        iVar2 = *g_pch_record_cursor;
      }
      iVar4 = g_pch_include_count.count + iVar4;
      if ((iVar4 == 0) || ((g_pch_include_count.count * 100) / iVar4 < 0x46)) {
        g_pch_include_count.count = -1;
      }
    }
  }
  else {
    g_pch_include_count.count = -1;
  }
  if (g_opt_nologo == '\0') {
    if (g_pch_include_count.count < 1) {
      pcVar3 = (char *)0x160;
      iVar4 = 0x100;
      pcVar7 = g_pch_file_name;
      fmt = misc_string_get(0x386);
    }
    else {
      pcVar7 = (char *)(int)g_pch_include_count.count;
      iVar4 = 0x100;
      pcVar3 = g_pch_file_name;
      fmt = misc_string_get(0x387);
    }
    format_snprintf(local_100,fmt,iVar4,pcVar3,pcVar7);
    uVar5 = 0xffffffff;
    pcVar3 = local_100;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    g_pch_auto_note = mem_xmalloc(~uVar5);
    uVar5 = 0xffffffff;
    pcVar3 = local_100;
    do {
      pcVar7 = pcVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar3 = pcVar7 + -uVar5;
    pcVar7 = g_pch_auto_note;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  pp_line_output_reset();
  pch_auto_start_recording();
  g_forced_include_index._0_2_ = 0;
  g_forced_include_files = g_forced_include_list;
  return 1;
}

