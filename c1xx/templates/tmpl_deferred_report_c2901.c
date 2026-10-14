void __fastcall tmpl_deferred_report_c2901(c1xx_obj_104ceec4 *action)

{
  if (g_ms_extensions != '\0') {
    diag_warning(1,0x29a,action[3].vtbl,action[1].vtbl);
    return;
  }
  diag_error(0x385,action[3].vtbl,action[1].vtbl);
  return;
}

