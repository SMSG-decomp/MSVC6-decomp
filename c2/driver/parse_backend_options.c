void parse_backend_options(void)

{
  char *arg;
  char *pcVar1;
  char *pcVar2;
  code *next_argument_00;
  int iVar3;
  c2_next_argument_fn *next_argument;
  
  pcVar1 = g_opt_off;
  pcVar2 = g_opt_db;
  iVar3 = 0;
  next_argument = option_next_argument;
  arg = option_next_argument();
  for (iVar3 = option_match_pattern(g_option_table,arg,next_argument,iVar3); iVar3 != 0;
      iVar3 = option_match_pattern(g_option_table,arg,next_argument_00,iVar3)) {
    if (iVar3 == 6) {
      fatal_error(7,g_opt_unknown_option,"p2");
    }
    if (g_opt_db != pcVar2) {
      pcVar2 = g_opt_db;
    }
    if (g_opt_off != pcVar1) {
      pcVar1 = g_opt_off;
    }
    iVar3 = 0;
    next_argument_00 = option_next_argument;
    arg = option_next_argument();
  }
  string_end(g_opt_A);
  if (g_opt_object_path != (char *)0x0) {
    g_opt_object_path_given = 1;
  }
  if (0x81e < g_opt_max_identifier) {
    g_opt_max_identifier = 0x81e;
  }
  if (g_opt_listing_kind != (char *)0x0) {
    g_opt_S = 1;
    pcVar1 = strpbrk(g_opt_listing_kind,"cC");
    if (pcVar1 != (char *)0x0) {
      g_opt_listing_code_bytes = 1;
    }
    pcVar1 = strpbrk(g_opt_listing_kind,"sS");
    if (pcVar1 != (char *)0x0) {
      g_opt_listing_source = 1;
    }
    pcVar1 = strpbrk(g_opt_listing_kind,"bB");
    if (pcVar1 != (char *)0x0) {
      g_opt_listing_bytes_comment = 1;
    }
  }
  if (g_opt_Fs != (char *)0x0) {
    g_opt_Fs_given = 1;
  }
  if (g_opt_listing_path != (char *)0x0) {
    g_opt_S = 1;
    g_listing_file = fopen(g_opt_listing_path,"wt");
    if (g_listing_file == (FILE *)0x0) {
      pcVar1 = g_opt_listing_path;
      pcVar2 = load_message(0x136);
      fatal_error_errno(0x53,pcVar2,pcVar1);
    }
    g_listing_unfinished = 1;
  }
  if (((g_opt_S != 0) || (g_opt_listing_code_bytes != 0)) || (g_opt_Fs_given != 0)) {
    g_opt_incremental = 0;
  }
  return;
}

