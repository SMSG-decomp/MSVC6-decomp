void __fastcall seh_lower_try_regions(c2_function *fn)

{
  g_seh_next_try_level = 0;
  g_seh_except_nesting = 0;
  g_seh_try_records = (c2_seh_try_scope *)0x0;
  g_seh_exit_label = (c2_tuple *)0x0;
  seh_clear_current_scope();
  if (g_opt_basic != 0) {
    seh_prepare_function(fn);
  }
  seh_collect_try_scopes(fn);
  seh_clear_current_scope();
  if ((g_opt_basic == 0) || (g_seh_try_records != (c2_seh_try_scope *)0x0)) {
    seh_lower_try_markers(fn);
    seh_lower_scope_ops(fn);
  }
  return;
}

