int __cdecl backend_main(int argc,char **argv)

{
  char *flags;
  c2_seh_frame_record seh;
  
  seh.scopetable = &g_backend_main_scopetable;
  seh.handler = _except_handler3;
  seh.prev = ExceptionList;
  seh.saved_esp = (uint32_t)&stack0xffffffd4;
  g_backend_state = 1;
  seh.trylevel = 0;
  g_option_args_left = argc;
  g_option_argv_cursor = argv;
  ExceptionList = &seh.prev;
  flags = getenv("MSC_CMD_FLAGS");
  split_env_command_line(flags);
  parse_backend_options();
  _controlfp(0x8001f,0x8001f);
  if (g_opt_ide != 0) {
    ide_open_feedback_channel();
  }
  g_init_il_file = open_il_file(g_opt_il_path,"in","rb","init il");
  g_glo_il_file = open_il_file(g_opt_il_path,"gl","rb","glo il");
  read_global_il_header();
  clear_global_scope_table();
  g_null_fe_symbol = alloc_null_fe_symbol();
  init_builtin_type_symbols();
  init_intrinsic_descriptors();
  init_target_defaults();
  create_standard_sections();
  read_global_il_symbols();
  read_init_il();
  compile_functions();
  if (g_il_has_cormeta != 0) {
    emit_cormeta_section();
  }
  close_il_files();
  finish_object_file();
  finish_listing_files();
  if (g_pdb_il_mode != 0) {
    release_pdb_il_store();
  }
  seh.trylevel = -1;
  backend_cleanup(0);
  ExceptionList = seh.prev;
  return g_error_count;
}

