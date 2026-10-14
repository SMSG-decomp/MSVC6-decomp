void c1_compile_begin(void)

{
  char *pcVar1;
  char cVar2;
  c1_scope_stack *state;
  int iVar3;
  uchar *stream;
  char local_18;
  c1_type local_14;
  
  if (((g_incremental == '\0') || (g_opt_E_preprocess != 0)) ||
     (local_18 = '\x01', g_opt_Zg != '\0')) {
    local_18 = '\0';
  }
  cVar2 = source_tracker_new(local_18,&g_source_tracker,&g_source_tracker_iface);
  if (cVar2 == '\0') {
    diag_fatal(0x49,".\\main.c",0xb6);
  }
  SetHandleCount(0x1e);
  if ((g_opt_EP_no_line != '\0') || (g_opt_EP_no_line = '\0', g_opt_E_preprocess == 0)) {
    g_opt_EP_no_line = '\x01';
  }
  iVar3 = g_opt_Zp;
  if (g_opt_Zp == -1) {
    iVar3 = 8;
  }
  g_pack_stack->top->packing = iVar3;
  g_pragma_check_stack = g_opt_stack_probes;
  g_pragma_optimize_q = g_opt_Oq;
  g_string_pooling = g_opt_Gf;
  g_string_pooling_readonly_active = g_string_pooling_readonly;
  if (6 < g_opt_G_cpu) {
    format_snprintf((char *)&local_14,"-G%d",0x14,g_opt_G_cpu);
    diag_fatal(7,&local_14,"c1");
  }
  opt_set_target_cpu_mask();
  if ((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) {
    if (g_opt_FR_browse != (char *)0x0) {
      g_browse_full = 1;
      g_opt_Fr_browse = g_opt_FR_browse;
    }
    g_opt_browse_info = g_opt_Fr_browse != (char *)0x0;
    g_browse_file = g_opt_Fr_browse;
  }
  else {
    g_opt_FR_browse = (char *)0x0;
    g_opt_Fr_browse = (char *)0x0;
    g_browse_full = 0;
    g_opt_browse_info = '\0';
  }
  il_emitters_create(g_opt_Fr_browse);
  g_il_emitter = il_emitter_get_default();
  if ((g_pch_create == '\0') && (g_use_pch != '\0')) {
    g_pch_use_only = 1;
  }
  else {
    g_pch_use_only = 0;
  }
  g_pch_record_references = g_pch_create;
  if (g_opt_pch_types_in_pdb != '\0') {
    if ((g_create_pch_header_name == (char *)0x0) &&
       ((g_pch_file_name == (char *)0x0 || (g_use_pch != '\0')))) {
      g_opt_pch_types_in_pdb = '\0';
    }
    else {
      cVar2 = pch_auto_check_usable(g_create_pch_header_name);
      if (cVar2 == '\0') {
        g_auto_pch_creating = 1;
        pch_record_environment();
      }
      else {
        g_auto_pch_saved_use_pch = g_use_pch;
        g_auto_pch_saved_header = g_use_pch_header_name;
        g_auto_pch_using = 1;
        if (g_use_pch != '\0') {
          g_pch_file_name = (char *)0x0;
        }
        g_use_pch_header_name = g_create_pch_header_name;
        g_use_pch = '\x01';
        g_pch_create = '\0';
        g_create_pch_header_name = (char *)0x0;
      }
    }
  }
  if (((g_opt_Zi == '\0') || (g_pch_debug_in_object != '\0')) ||
     (g_pch_precomp_types = '\x01', g_pch_create == '\0')) {
    g_pch_precomp_types = '\0';
  }
  g_pch_creating = g_pch_create;
  token_static_records_init();
  name_table_init();
  keywords_init();
  compile_begin_nop();
  type_tables_init();
  if ((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) {
    if (g_c9il_mode == '\0') {
      g_il_sy.ilstore_space = '\x03';
      g_il_gl.ilstore_space = '\x01';
      g_il_in.ilstore_space = '\x04';
      g_il_ex.ilstore_space = '\x02';
      g_il_gi_buffer.ilstore_space = '\x01';
      g_il_gi_fdef.ilstore_space = '\x05';
    }
    else {
      il_open_ex();
      il_file_open(&g_il_sy,(byte *)g_opt_il_prefix,"sy","w+b");
      il_file_open(&g_il_gl,(byte *)g_opt_il_prefix,"gl","w+b");
      il_file_open(&g_il_in,(byte *)g_opt_il_prefix,"in","w+b");
      if (g_opt_Zi != '\0') {
        il_file_open(&g_il_db,(byte *)g_opt_il_prefix,"db","w+b");
      }
    }
  }
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_none = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x2011;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_unsigned_char = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x11;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_char = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x13;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_int = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x2013;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_unsigned_int = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x19;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_int8 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x2019;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_uint8 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x1a;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_int16 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x201a;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_uint16 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x1b;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_int32 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x201b;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_uint32 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x1c;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_int64 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x201c;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_uint64 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x803;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_code_803 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x2013;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_unsigned_int_2 = type_intern(&local_14);
  local_14.base = (c1_type *)0x0;
  local_14.debug_index = 0;
  local_14.code = 0x12;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_short = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x2012;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_unsigned_short = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x14;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_long = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x2014;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_unsigned_long = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x26;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_float = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x27;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_double = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x28;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_long_double = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x402;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_segment = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x40;
  local_14.flags = 0;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_void = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x11;
  local_14.flags = 0x20;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_const_char = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x2011;
  local_14.flags = 0x20;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_const_unsigned_char = type_intern(&local_14);
  type_descriptor_clear(&local_14);
  local_14.code = 0x13;
  local_14.flags = 0x20;
  local_14.extra.sym = (c1_symbol *)0x0;
  g_type_const_int = type_intern(&local_14);
  token_arenas_reset();
  keywords_intern();
  vector_new_main_arena((int *)&g_line_map);
  vector_push_triple((int *)&g_line_map,0,0,0);
  state = (c1_scope_stack *)pool_alloc_raw(&g_scope_pool,0x218);
  if (state == (c1_scope_stack *)0x0) {
    g_current_scope = (c1_scope_stack *)0x0;
  }
  else {
    g_current_scope = scope_file_init(state);
  }
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    g_pdb_file_stack = arena_alloc(g_arenas + 1,4);
    if (g_pdb_file_stack == (void **)0x0) {
      g_pdb_file_stack = (void **)0x0;
    }
    else {
      *g_pdb_file_stack = (void *)0x0;
    }
  }
  if (g_opt_E_preprocess == 0) {
    g_type_function_returning_int = type_new_function_returning(0,g_type_int);
    g_type_void_basic = type_basic(0x40);
    if (g_opt_Zg == '\0') {
      c1_declare_intrinsics();
    }
    c1_new_builtin_labels();
  }
  lex_begin_source_file(g_define_list);
  if (g_opt_Fi_file != (char *)0x0) {
    iVar3 = _dup(1);
    if (iVar3 == -1) {
      diag_fatal_file_errno(0x53,0x154,g_opt_Fi_file);
    }
    else {
      g_preprocess_output_file = freopen(g_opt_Fi_file,"wt+",(FILE *)(_iob_exref + 0x20));
      if (g_preprocess_output_file == (FILE *)0x0) {
        c1_compile_begin_fragment(0);
        return;
      }
    }
  }
  g_pp_output_stream = _iob_exref + 0x20;
  if (g_opt_EP_no_line == '\0') {
    pp_emit_line_directive();
  }
  stream = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x50;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (stream == (uchar *)0x0) {
    stream = (uchar *)0x0;
  }
  else {
    token_stream_init((c1_saved_token_stream *)stream,1,1);
    stream[0x38] = '\0';
    stream[0x39] = '\0';
    stream[0x3a] = '\0';
    stream[0x3b] = '\0';
    *(undefined ***)stream = &PTR_source_stream_next_token_10654860;
  }
  token_source_push(&g_token_position,(int)stream,7,0,0,&g_token_position);
  if (g_emitter_suspend == (c1_emitter_suspend *)0x0) {
    g_emitter_suspend = __2_YAPAXI_Z(0xc);
    pcVar1 = g_browse_file;
    if (g_emitter_suspend == (c1_emitter_suspend *)0x0) {
      g_emitter_suspend = (c1_emitter_suspend *)0x0;
    }
    else {
      g_emitter_suspend->depth = 0;
      g_emitter_suspend->active = pcVar1 != (char *)0x0;
      g_emitter_suspend->saved = g_il_emitter;
    }
  }
  if (g_use_pch == '\0') {
    pdb_open();
  }
  return;
}

