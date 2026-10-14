uint32_t __fastcall line_number_map(uint32_t line)

{
  char *pcVar1;
  c2_line_run *pcVar2;
  uint32_t uVar3;
  c2_line_run *pcVar4;
  uint uVar5;
  
  if (line == 0) {
    return 0;
  }
  if (((g_line_run_head != (c2_line_run *)0x0) && (g_line_run_closed == 0)) &&
     (g_line_run_head->file == g_reader_source_file)) {
    uVar5 = (g_line_run_head->last - g_line_run_head->first) + g_line_run_head->line;
    if ((uVar5 <= line) && (line <= uVar5 + 1000)) {
      uVar3 = (g_line_run_head->first - g_line_run_head->line) + line;
      if (uVar3 <= g_line_high_water) {
        return uVar3;
      }
      g_line_run_head->last = uVar3;
      g_line_high_water = uVar3;
      return uVar3;
    }
  }
  pcVar4 = arena_alloc(0,0x18);
  uVar3 = g_line_high_water + 1;
  g_line_run_closed = 0;
  pcVar2 = pcVar4;
  g_line_high_water = uVar3;
  if (g_line_run_head != (c2_line_run *)0x0) {
    g_line_run_head->newer = pcVar4;
    pcVar2 = g_line_run_first;
  }
  g_line_run_first = pcVar2;
  pcVar4->line = line;
  pcVar1 = g_reader_source_file;
  pcVar4->first = uVar3;
  pcVar4->last = uVar3;
  pcVar4->file = pcVar1;
  pcVar4->older = g_line_run_head;
  g_line_run_head = pcVar4;
  return uVar3;
}

