byte __cdecl parse_no_saved_declspecs_below(int depth)

{
  byte bVar1;
  
  bVar1 = 1;
  if (g_declarator_paren_base <= depth) {
    while ((g_paren_level_flags[depth] & 1) == 0) {
      depth = depth + -1;
      if (depth < g_declarator_paren_base) {
        return bVar1;
      }
    }
    bVar1 = 0;
  }
  return bVar1;
}

