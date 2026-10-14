void __cdecl pp_warn_include_depth(void)

{
  if (0x32 < g_include_depth) {
    diag_warning(1,0xb6,g_include_depth);
  }
  return;
}

