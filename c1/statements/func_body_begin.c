void __cdecl func_body_begin(void)

{
  c1_scope_symbol_list *parameter_scope;
  char cVar1;
  fe_line_map_row *pfVar2;
  uint uVar3;
  void *pvVar4;
  byte *pbVar5;
  c1_type *pcVar6;
  int iVar7;
  c1_type *fn_type;
  c1_type **proto_types;
  int *formal_link;
  int iVar8;
  int local_c;
  ushort local_8 [2];
  int local_4;
  
  if (g_current_function == (c1_symbol *)0x0) {
    return;
  }
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar2 = &g_line_map_cached_row;
    }
    else {
      pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    uVar3 = (*g_idb->vtbl->idb_function_begin)
                      (g_idb,0,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                        (short)pfVar2->line - (short)pfVar2->position) +
                               g_token_position,g_macro_expansion_depth,&g_ilstore_status,&local_4,
                       (short *)local_8,&local_c);
    if (uVar3 == 0) {
      diag_fatal(0x49,".\\funcs.c",0x584);
    }
    il_emitter_begin_region_at_top_level(local_c == 0);
    g_function_body_reused = g_ilstore_status == 4;
    if (((bool)g_function_body_reused) &&
       (cVar1 = func_skip_unchanged_body(local_4,local_8[0]), cVar1 == '\0')) {
      diag_fatal(0x49,".\\funcs.c",0x58b);
    }
    if (g_browse_file != (char *)0x0) {
      func_emit_function_symbol();
    }
  }
  func_emit_body_begin_il();
  pcVar6 = g_current_function->type;
  fn_type = (c1_type *)(-(uint)((pcVar6->code & 0x80) != 0) & (uint)pcVar6);
  if (g_fastcall_check_stack_warned == 0) {
    if ((pcVar6->code & 0x8f) == 0x83) {
      pcVar6 = type_skip_arrays(pcVar6->base);
    }
    if (((pcVar6->flags & 0x1f) == 3) && (g_pragma_check_stack != 0)) {
      diag_warning(1,0x7c);
      g_fastcall_check_stack_warned = 1;
    }
  }
  parameter_scope = g_function_parameter_scope;
  if (g_opt_Zg == '\0') {
    pcVar6 = g_current_function->type;
    if ((pcVar6->code & 0x8f) == 0x83) {
      pcVar6 = type_skip_arrays(pcVar6->base);
    }
    if ((pcVar6->flags & 0x1f) != 5) {
      pcVar6 = g_current_function->type;
      if ((pcVar6->code & 0x8f) == 0x83) {
        pcVar6 = type_skip_arrays(pcVar6->base);
      }
      if ((pcVar6->flags & 0x1f) != 3) goto LAB_10619bb6;
    }
    pvVar4 = (void *)func_argument_bytes((int)g_function_parameter_scope);
    if ((g_current_function->flags4 & 0x40) == 0) {
      if ((void *)0xffff < pvVar4) {
        diag_fatal(0x1fc,g_current_function);
      }
      g_current_function->detail = (void *)((uint)pvVar4 & 0xffff);
      g_current_function->flags4 = g_current_function->flags4 | 0x40;
    }
    else if (pvVar4 != g_current_function->detail) {
      func_report_formal_bytes_differ(parameter_scope,fn_type);
      return;
    }
  }
LAB_10619bb6:
  if (parameter_scope == (c1_scope_symbol_list *)0x0) {
    formal_link = (int *)0x0;
  }
  else {
    formal_link = parameter_scope->first;
  }
  if (formal_link == (int *)0x0) {
    if (((fn_type->flags & 0x4000) == 0) && (((fn_type->extra).params)->count != 0)) {
      func_body_begin_fragment_3();
      return;
    }
    goto LAB_10619c52;
  }
  pbVar5 = (byte *)(formal_link + -2);
  if (((fn_type->extra).params)->count < 1) {
    if (g_pending_function_word == 2) goto LAB_10619c52;
    if ((fn_type->flags & 0x4000) == 0) {
      if (((fn_type->flags & 0x2000) == 0) || (*(short *)formal_link[3] != 0x80d))
      goto LAB_10619c52;
      if (g_ms_extensions == '\0') {
        diag_error(0x8e);
        goto LAB_10619c52;
      }
      iVar8 = 0x34;
    }
    else {
      iVar8 = 0x1b;
    }
  }
  else {
    proto_types = ((fn_type->extra).params)->types;
    iVar8 = 1;
    if (((*pbVar5 & 0x1f) != 0xb) && ((*pbVar5 & 0x1f) != 0xc)) {
      func_warn_formal_list_differs(proto_types,1,(int)formal_link,fn_type);
      return;
    }
    if ((fn_type->flags & 0x4000) == 0) {
      if ((c1_type *)formal_link[3] == g_type_void) {
        iVar8 = 0x1a;
      }
      else {
LAB_10619c0f:
        if (pbVar5 != (byte *)0x0) {
          while (iVar8 <= ((fn_type->extra).params)->count) {
            if ((*proto_types != *(c1_type **)(pbVar5 + 0x14)) &&
               (iVar7 = func_formal_types_compatible(*proto_types,*(c1_type **)(pbVar5 + 0x14)),
               iVar7 == 0)) {
              diag_warning(1,0x1c,iVar8);
            }
            proto_types = proto_types + 1;
            iVar8 = iVar8 + 1;
            if (formal_link == (int *)0x0) {
LAB_10619c3a:
              pbVar5 = (byte *)0x0;
              break;
            }
            formal_link = (int *)formal_link[1];
            while( true ) {
              if (formal_link == (int *)0x0) goto LAB_10619c3a;
              pbVar5 = (byte *)(formal_link + -2);
              if (pbVar5 == (byte *)0x0) goto LAB_10619c3c;
              if (((*pbVar5 & 0x1f) == 0xb) || ((*pbVar5 & 0x1f) == 0xc)) break;
              formal_link = (int *)formal_link[1];
            }
            if (pbVar5 == (byte *)0x0) break;
          }
        }
LAB_10619c3c:
        if ((iVar8 == ((fn_type->extra).params)->count + 1) &&
           ((pbVar5 == (byte *)0x0 || ((fn_type->flags & 0x8000) != 0)))) goto LAB_10619c52;
        iVar8 = 0x1d;
      }
    }
    else {
      if ((c1_type *)formal_link[3] == g_type_void) goto LAB_10619c0f;
      iVar8 = 0x1b;
    }
  }
  diag_warning(1,iVar8);
LAB_10619c52:
  if (g_function_context_word == 1) {
    g_function_context_word = 5;
  }
  if ((g_function_context_word == 3) || (g_function_context_word == 5)) {
    if (g_opt_Zg != '\0') {
      iVar8 = format_buffer_acquire();
      format_buffer_free(iVar8);
      zg_write_function_prototype(g_current_function,g_pp_output_stream);
      format_buffer_leave();
    }
  }
  else if (g_opt_Zg != '\0') {
    func_body_begin_fragment_2(g_current_function->type);
    return;
  }
  if (((g_opt_Zi != '\0') && (g_opt_Zg == '\0')) && (g_ilstore_status != 4)) {
    il_emit_pragma_or_segment_record(0x11);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  return;
}

