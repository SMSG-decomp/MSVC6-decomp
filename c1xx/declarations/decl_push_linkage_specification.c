void __cdecl decl_push_linkage_specification(int linkage)

{
  g_linkage_depth = g_linkage_depth + 1;
  if (g_linkage_depth != 10) {
    g_linkage_stack[g_linkage_depth] = linkage;
    return;
  }
  diag_fatal_simple(0x2d);
}

