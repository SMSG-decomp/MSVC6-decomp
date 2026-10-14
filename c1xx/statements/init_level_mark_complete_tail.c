int __cdecl init_level_mark_complete_tail(byte *level,int one)

{
  level[0x14] = level[0x14] | 2;
  return one;
}

