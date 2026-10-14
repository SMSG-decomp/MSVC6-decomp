void __cdecl parse_report_missing_token(c1_token *found,int missing)

{
  byte bVar1;
  
  if ((g_compile_flags_c8 & 0x200) == 0) {
    if ((found == (c1_token *)0x0) || (bVar1 = found->code, bVar1 == 5)) {
      diag_fatal_simple(4);
    }
    if (bVar1 == 6) {
      if ((found->value).ptr == (void *)0x0) {
        diag_error(0x91,missing);
      }
      else {
        diag_error(0x92,missing,(found->value).ptr);
      }
    }
    else if (bVar1 == 0x1f) {
      diag_error(0x90,missing,0x4c,0x1f);
    }
    else if (bVar1 == 0x1e) {
      diag_error(0x90,missing,0x53,(found->value).words[4]);
    }
    else {
      diag_error(0x8f,missing,(uint)bVar1);
    }
    if (missing == 0x7e) {
      if (g_paren_depth == 0) {
        g_paren_depth = 1;
        return;
      }
    }
    else {
      g_paren_depth = 0;
    }
  }
  return;
}

