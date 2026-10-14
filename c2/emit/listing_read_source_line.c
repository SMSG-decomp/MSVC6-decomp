int __fastcall listing_read_source_line(char *buf,uint32_t line)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  if (line <= g_listing_seek_mark_line) {
    g_listing_seek_mark_line = 0;
    g_listing_seek_mark_offset = 0;
  }
  if (line <= (uint)g_listing_source_line_pos) {
    fseek(g_listing_source_fp,g_listing_seek_mark_offset,0);
    g_listing_source_line_pos = g_listing_seek_mark_line;
    if (g_listing_seek_mark_line == line) goto LAB_1078c503;
  }
  do {
    pcVar2 = fgets(buf,0x100,g_listing_source_fp);
    if (pcVar2 == (char *)0x0) {
      *buf = '\0';
      return 0;
    }
    pcVar2 = strchr(buf,10);
    if (pcVar2 == (char *)0x0) {
      uVar3 = 0xffffffff;
      pcVar2 = buf;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iVar4 = ~uVar3 - 1;
      if (iVar4 != 0xff) {
        buf[iVar4] = '\n';
        buf[~uVar3] = '\0';
        return 0;
      }
      if (g_listing_source_line_pos == line - 1) {
        return 1;
      }
      g_listing_source_line_pos = g_listing_source_line_pos + -1;
    }
    g_listing_source_line_pos = g_listing_source_line_pos + 1;
  } while (g_listing_source_line_pos != line);
LAB_1078c503:
  if (g_listing_seek_mark_line == 0) {
    g_listing_seek_mark_offset = ftell(g_listing_source_fp);
    g_listing_seek_mark_line = line;
  }
  pcVar2 = strchr(buf,0xd);
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\n';
    pcVar2[1] = '\0';
  }
  return 0;
}

