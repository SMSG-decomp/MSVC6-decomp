c2_split_marker * __fastcall new_split_marker(c2_bitset *ranges)

{
  uint16_t uVar1;
  c2_split_marker *pcVar2;
  
  pcVar2 = (c2_split_marker *)node_alloc('\x1b');
  uVar1 = g_cur_line;
  pcVar2->ranges = ranges;
  pcVar2->op = 0x1b2;
  pcVar2->line = uVar1;
  return pcVar2;
}

