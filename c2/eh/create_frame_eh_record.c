c2_symbol * __fastcall create_frame_eh_record(int size,int pushed_by_prolog,char *name)

{
  c2_fe_symbol *fs;
  c2_symbol *pcVar1;
  
  fs = fe_symbol_new_local_cur(6,size,1,1,'\x04',0);
  g_frame_eh_record = fs;
  if (name != (char *)0x0) {
    fs->name = name;
  }
  g_eh_record_pushed = pushed_by_prolog;
  if ((((g_opt_global == 0) || (g_opt_dlp != 0)) || ((g_cur_function->fsym->attrs & 0x1000) != 0))
     || (((g_cur_function->flags & 0x10000) != 0 && (g_opt_eh_enabled == 0)))) {
    scope_for_each(1,shift_auto_below_eh_record_cb);
    fs = g_frame_eh_record;
  }
  pcVar1 = fe_symbol_get_storage(fs);
  return pcVar1;
}

