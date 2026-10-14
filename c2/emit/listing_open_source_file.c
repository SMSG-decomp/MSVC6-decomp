void __fastcall listing_open_source_file(char *name)

{
  c2_listing_source_file **ppcVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  c2_listing_source_file **ppcVar5;
  c2_listing_source_file *pcVar6;
  FILE *pFVar7;
  char *message;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  char *file_name;
  
  iVar4 = g_listing_source_line_pos;
  pcVar6 = g_listing_source_files;
  if (g_listing_cur_source != (c2_listing_source_file *)0x0) {
    g_listing_cur_source->lines = g_listing_line_list;
    g_listing_cur_source->line_pos = iVar4;
    pcVar6 = g_listing_source_files;
  }
  do {
    g_listing_cur_source = pcVar6;
    if (pcVar6 == (c2_listing_source_file *)0x0) {
LAB_1078c719:
      if (4 < g_listing_open_source_count) {
        fclose(g_listing_open_sources[0]->fp);
        ppcVar5 = g_listing_open_sources;
        g_listing_open_sources[0]->is_open = 0;
        do {
          *ppcVar5 = ppcVar5[1];
          ppcVar5 = ppcVar5 + 1;
        } while ((int)ppcVar5 < 0x1079d740);
        g_listing_open_source_count = g_listing_open_source_count + -1;
      }
      if (g_listing_cur_source == (c2_listing_source_file *)0x0) {
        pcVar6 = arena_alloc(0,0x18);
        g_listing_cur_source = pcVar6;
        pcVar6->next = g_listing_source_files;
        pcVar6->name = name;
        pcVar6->lines = (c2_listing_line *)0x0;
        g_listing_source_files = pcVar6;
      }
      pFVar7 = fopen(name,"rb");
      pcVar6 = g_listing_cur_source;
      g_listing_cur_source->fp = pFVar7;
      if (pFVar7 == (FILE *)0x0) {
        file_name = pcVar6->name;
        message = load_message(0x138);
        fatal_error_errno(0x53,message,file_name);
      }
      pcVar6->line_pos = 0;
      pcVar6->is_open = 1;
      g_listing_seek_mark_offset = 0;
      g_listing_open_sources[g_listing_open_source_count] = pcVar6;
      g_listing_open_source_count = g_listing_open_source_count + 1;
      g_listing_seek_mark_line = 0;
LAB_1078c826:
      g_listing_source_fp = pcVar6->fp;
      g_listing_line_cursor = pcVar6->lines;
      g_listing_line_list = pcVar6->lines;
      g_listing_source_line_pos = pcVar6->line_pos;
      return;
    }
    pbVar3 = (byte *)pcVar6->name;
    pbVar9 = (byte *)name;
    do {
      bVar2 = *pbVar3;
      bVar10 = bVar2 < *pbVar9;
      if (bVar2 != *pbVar9) {
LAB_1078c7c5:
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_1078c705;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar10 = bVar2 < pbVar9[1];
      if (bVar2 != pbVar9[1]) goto LAB_1078c7c5;
      pbVar3 = pbVar3 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_1078c705:
    if (iVar4 == 0) {
      if ((pcVar6 != (c2_listing_source_file *)0x0) && (pcVar6->is_open != 0)) {
        iVar4 = 0;
        if (g_listing_open_sources[0] != pcVar6) {
          ppcVar5 = g_listing_open_sources;
          do {
            ppcVar1 = ppcVar5 + 1;
            ppcVar5 = ppcVar5 + 1;
            iVar4 = iVar4 + 1;
          } while (*ppcVar1 != pcVar6);
        }
        if (iVar4 < g_listing_open_source_count + -1) {
          iVar8 = (g_listing_open_source_count + -1) - iVar4;
          ppcVar5 = g_listing_open_sources + iVar4;
          iVar4 = iVar4 + iVar8;
          do {
            *ppcVar5 = ppcVar5[1];
            ppcVar5 = ppcVar5 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        g_listing_open_sources[iVar4] = pcVar6;
        goto LAB_1078c826;
      }
      goto LAB_1078c719;
    }
    pcVar6 = pcVar6->next;
  } while( true );
}

