void __cdecl c1xx_compile_begin(void)

{
  char *pcVar1;
  char cVar2;
  c1_scope_stack *stack;
  c1_declarator *d;
  int iVar3;
  c1_u32 *spec_cursor;
  c1xx_lex_source_stream *source_stream;
  c1_u32 *spec_cursor_2;
  c1_u32 *spec_dst;
  char local_74;
  c1_type basic_type;
  c1_decl_record local_4c;
  
  if (((g_incremental == '\0') || (g_opt_E_preprocess != 0)) ||
     (local_74 = '\x01', g_opt_Zg != '\0')) {
    local_74 = '\0';
  }
  cVar2 = source_tracker_new(local_74,(void **)&g_source_tracker,(void **)&g_source_tracker_iface);
  if (cVar2 != '\0') {
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
    g_string_pooling_readonly_state = g_string_pooling_readonly;
    if (g_opt_G_cpu < 7) {
      opt_set_target_cpu_mask();
      if ((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) {
        if (g_opt_FR_browse != (char *)0x0) {
          g_opt_Fr_browse = g_opt_FR_browse;
          g_browse_info_full = 1;
        }
        g_browse_info = g_opt_Fr_browse != (char *)0x0;
        g_browse_file = g_opt_Fr_browse;
      }
      else {
        g_opt_FR_browse = (char *)0x0;
        g_opt_Fr_browse = (char *)0x0;
        g_browse_info_full = 0;
        g_browse_info = 0;
      }
      il_emitters_create(g_opt_Fr_browse);
      g_il_emitter = il_emitter_get_default();
      if ((g_pch_create == '\0') && (g_use_pch != '\0')) {
        g_pch_use_only = 1;
      }
      else {
        g_pch_use_only = 0;
      }
      g_pch_create_explicit = g_pch_create;
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
            g_auto_pch_saved_yu_header = g_opt_Yu_header;
            g_auto_pch_using = 1;
            if (g_use_pch != '\0') {
              g_pch_file_name = (char *)0x0;
            }
            g_opt_Yu_header = g_create_pch_header_name;
            g_use_pch = '\x01';
            g_pch_create = '\0';
            g_create_pch_header_name = (char *)0x0;
          }
        }
      }
      if (((g_opt_Zi == '\0') || (g_pch_debug_in_object != '\0')) ||
         (g_pch_precomp_types = 1, g_pch_create == '\0')) {
        g_pch_precomp_types = 0;
      }
      g_pch_creating = g_pch_create;
      token_static_records_init();
      name_table_init();
      keywords_configure();
      compile_begin_stub_a();
      scope_table_init();
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
          il_file_open(&g_il_sy,g_opt_il_prefix,"sy","w+b");
          il_file_open(&g_il_gl,g_opt_il_prefix,"gl","w+b");
          il_file_open(&g_il_in,g_opt_il_prefix,"in","w+b");
          if (g_opt_Zi != '\0') {
            il_file_open(&g_il_db,g_opt_il_prefix,"db","w+b");
          }
        }
      }
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_none = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x2011;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_unsigned_char = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x11;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_char = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x13;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_int = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x2013;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_unsigned_int = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x19;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_int8 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x2019;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_uint8 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x1a;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_int16 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x201a;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_uint16 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x1b;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_int32 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x201b;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_uint32 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x1c;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_int64 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x201c;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_uint64 = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x10;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_bool = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x803;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_any_integral = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x2013;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      PTR_104d151c = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x12;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_short = type_intern(&basic_type);
      basic_type.base = (c1_type *)0x0;
      basic_type.debug_index = 0;
      basic_type.code = 0x2012;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_unsigned_short = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x14;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_long = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x2014;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_unsigned_long = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x26;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_float = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x27;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_double = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x28;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_long_double = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x402;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_segment = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x40;
      basic_type.flags = 0;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_void = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x11;
      basic_type.flags = 0x20;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_const_char = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x2011;
      basic_type.flags = 0x20;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_const_unsigned_char = type_intern(&basic_type);
      type_descriptor_clear(&basic_type);
      basic_type.code = 0x13;
      basic_type.flags = 0x20;
      basic_type.extra.cls = (c1_symbol *)0x0;
      g_type_const_int = type_intern(&basic_type);
      token_arena_reset();
      keywords_intern();
      vector_new_main_arena((int *)&g_line_map);
      vector_push_triple((int *)&g_line_map,0,0,0);
      stack = (c1_scope_stack *)pool_alloc_raw(&g_scope_pool,0x230);
      if (stack == (c1_scope_stack *)0x0) {
        g_current_scope = (c1_scope_stack *)0x0;
      }
      else {
        g_current_scope = scope_stack_new_global(stack);
      }
      if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
        g_minimal_rebuild_tracker = arena_alloc(g_arenas + 1,0xc);
        if (g_minimal_rebuild_tracker == (c1_mre_tracker *)0x0) {
          g_minimal_rebuild_tracker = (c1_mre_tracker *)0x0;
        }
        else {
          g_minimal_rebuild_tracker->current = (c1_source_file_record *)0x0;
          g_minimal_rebuild_tracker->pending = (c1_mre_note *)0x0;
          g_minimal_rebuild_tracker->busy = '\0';
          g_minimal_rebuild_tracker->draining = '\0';
        }
      }
      if (g_opt_E_preprocess == 0) {
        symtab_new_global_16();
        g_pragma_vtordisp = g_opt_vd;
        g_builtin_int_function = sym_new_builtin_helper(0,g_type_int);
        PTR_104d152c = type_basic(0x40);
        if (g_opt_Zg == '\0') {
          compile_begin_stub_b();
        }
        c1xx_new_builtin_labels();
      }
      lex_begin_source_file(&g_define_list->count);
      if ((g_opt_Fi_output != (char *)0x0) &&
         ((iVar3 = _dup(1), iVar3 == -1 ||
          (g_fi_output_file = (FILE *)freopen(g_opt_Fi_output,"wt+",(FILE *)(_iob_exref + 0x20)),
          g_fi_output_file == (FILE *)0x0)))) {
        diag_fatal_file_errno(0x53,0x154,g_opt_Fi_output);
      }
      g_pp_output_stream = _iob_exref + 0x20;
      if (g_opt_EP_no_line == '\0') {
        pp_emit_line_directive();
      }
      if ((g_opt_E_preprocess == 0) && (operator_names_init(), g_use_pch == '\0')) {
        decl_vector_iterator_helpers();
        sym_init_purecall();
        if ((g_ms_extensions != '\0') && (g_opt_noBool == '\0')) {
          spec_cursor_2 = (c1_u32 *)&basic_type;
          for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
            *spec_cursor_2 = 0;
            spec_cursor_2 = spec_cursor_2 + 1;
          }
          basic_type.code = basic_type.code | 7;
          decl_record_init(&local_4c,g_type_bool,g_default_decl_specifiers);
          decl_finish_declarator(&local_4c);
          d = (c1_declarator *)g_arenas[5].cur;
          g_arenas[5].cur = g_arenas[5].cur + 0x58;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (d == (c1_declarator *)0x0) {
            d = (c1_declarator *)0x0;
          }
          else {
            d->name = g_name_bool;
            *(c1_decl_record **)((int)d + 4) = &local_4c;
            *(c1_u8 *)((int)d + 0x30) = '\x01';
            *(c1_u8 *)((int)d + 0x4c) = '\0';
            *(c1_u8 *)((int)d + 0x4d) = '\0';
            *(c1_u8 *)((int)d + 0x4e) = '\0';
            *(c1_u8 *)((int)d + 0x4f) = '\0';
            *(int *)((int)d + 0x24) = g_token_position;
          }
          spec_cursor = (c1_u32 *)&basic_type;
          spec_dst = (c1_u32 *)d->spec;
          for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
            *spec_dst = *spec_cursor;
            spec_cursor = spec_cursor + 1;
            spec_dst = spec_dst + 1;
          }
          decl_declare_and_check(d,(byte *)&basic_type);
        }
      }
      source_stream = (c1xx_lex_source_stream *)g_arenas[1].cur;
      g_arenas[1].cur = g_arenas[1].cur + 0x50;
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      if (source_stream == (c1xx_lex_source_stream *)0x0) {
        source_stream = (c1xx_lex_source_stream *)0x0;
      }
      else {
        token_stream_init((c1xx_token_stream *)source_stream,1,1);
        *(c1_u8 *)((int)source_stream + 0x38) = '\0';
        *(c1_u8 *)((int)source_stream + 0x39) = '\0';
        *(c1_u8 *)((int)source_stream + 0x3a) = '\0';
        *(c1_u8 *)((int)source_stream + 0x3b) = '\0';
        *(undefined ***)source_stream = &PTR_lex_source_next_token_104c58b4;
      }
      token_source_push((c1_token_reader *)&g_token_position,(c1xx_token_stream *)source_stream,10,0
                        ,(void *)0x0,&g_token_position);
      if (g_emitter_suspend == (c1xx_emitter_suspend *)0x0) {
        g_emitter_suspend = __2_YAPAXI_Z(0xc);
        pcVar1 = g_browse_file;
        if (g_emitter_suspend == (c1xx_emitter_suspend *)0x0) {
          g_emitter_suspend = (c1xx_emitter_suspend *)0x0;
        }
        else {
          g_emitter_suspend->depth = 0;
          g_emitter_suspend->enabled = pcVar1 != (char *)0x0;
          g_emitter_suspend->saved = g_il_emitter;
        }
      }
      if (g_use_pch == '\0') {
        pdb_open();
      }
      return;
    }
    format_snprintf((char *)&basic_type,"-G%d",0x14,g_opt_G_cpu);
    diag_fatal(7,&basic_type,"c1");
  }
  diag_fatal(0x49,".\\main.c",0xb6);
}

