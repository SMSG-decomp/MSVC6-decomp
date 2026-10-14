void __cdecl browse_record_type(c1xx_browse_record *rec)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint *src;
  c1xx_browse_record *pcVar4;
  c1xx_browse_record local_18;
  
  if ((rec != (c1xx_browse_record *)0x0) && (g_browse_suspended == 0)) {
    bVar2 = rec->kind & 0xbf;
    if ((bVar2 != 0x12) && ((bVar2 != 0x13 && (bVar2 != 0x14)))) {
      switch(rec->kind & 0xbf) {
      case 0:
      case 2:
      case 8:
      case 9:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x16:
        break;
      case 1:
        g_browse_last_line = 0;
        g_browse_line_absolute = 0;
        break;
      default:
        if (g_browse_last_line != rec->line) {
          g_browse_skip_symbol = (c1_symbol *)0x0;
          src = g_browse_record_zero;
          pcVar4 = &local_18;
          for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
            uVar1 = *src;
            pcVar4->kind = (char)uVar1;
            pcVar4->flags = (char)(uVar1 >> 8);
            pcVar4->type = (char)(uVar1 >> 0x10);
            pcVar4->pad03 = (char)(uVar1 >> 0x18);
            src = src + 1;
            pcVar4 = (c1xx_browse_record *)&pcVar4->line;
          }
          if ((g_opt_GFR == '\0') || (g_browse_line_absolute != 0)) {
            local_18.line = rec->line;
            local_18.kind = '\x02';
            g_browse_line_absolute = 0;
          }
          else {
            local_18.kind = '\x15';
            local_18.line = rec->line - g_browse_last_line;
          }
          g_browse_last_line = rec->line;
          browse_record_type(&local_18);
        }
        break;
      case 10:
        g_browse_line_absolute = 1;
        break;
      case 0x15:
        if ((uint)rec->line < 0x11) {
          rec->kind = (char)rec->line + '\x1f';
        }
      }
      g_browse_out_file = g_browse_sbr_file;
      browse_record_write(rec);
    }
  }
  return;
}

