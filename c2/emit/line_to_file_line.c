int __fastcall line_to_file_line(uint32_t abs_line,char **file)

{
  uint32_t uVar1;
  
  if ((abs_line == 0) || (g_line_high_water < abs_line)) {
    *file = (char *)0x0;
    return 0;
  }
  if (g_line_run_cursor == (c2_line_run *)0x0) {
    g_line_run_cursor = g_line_run_head;
  }
LAB_1073e282:
  do {
    if (g_line_run_cursor->first <= abs_line) {
      if (abs_line <= g_line_run_cursor->last) {
        uVar1 = g_line_run_cursor->first;
        *file = g_line_run_cursor->file;
        return (g_line_run_cursor->line - uVar1) + abs_line;
      }
      if (g_line_run_cursor->first <= abs_line) {
        if (g_line_run_cursor->last < abs_line) {
          g_line_run_cursor = g_line_run_cursor->newer;
        }
        goto LAB_1073e282;
      }
    }
    g_line_run_cursor = g_line_run_cursor->older;
  } while( true );
}

