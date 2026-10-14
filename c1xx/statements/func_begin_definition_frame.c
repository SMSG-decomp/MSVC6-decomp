void func_begin_definition_frame(void)

{
  char cVar1;
  c1_line_map_row *pcVar2;
  uint uVar3;
  c1_type *pcVar4;
  int handle;
  c1_u32 class_ni;
  int local_c;
  uint local_8;
  int local_4;
  
  if (g_current_function == (c1_symbol *)0x0) {
    return;
  }
  if ((g_token_source->stream->flags & 1) != 0) {
    class_ni = 0;
    if ((g_current_function->kind & 0x1f) == 8) {
      class_ni = ((g_scope_vector->entries[(short)g_current_function->scope_index]->detail).cls)->
                 gm_name_index;
    }
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar2 = &g_line_map_cached_row;
    }
    else {
      pcVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    uVar3 = (*g_idb->vtbl->idb_function_begin)
                      (g_idb,class_ni,
                       CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                (short)pcVar2->line - (short)pcVar2->position) + g_token_position,
                       g_macro_expansion_depth,&g_ilstore_status,&local_4,(short *)&local_8,&local_c
                      );
    if (uVar3 == 0) {
      diag_fatal(0x49,".\\funcs.c",0x584);
    }
    il_emitter_begin_region_at_top_level(g_il_emitter,local_c == 0);
    g_function_il_reused = g_ilstore_status == 4;
    if (((bool)g_function_il_reused) &&
       (cVar1 = lex_skip_unchanged_function_body(local_4,local_8), cVar1 == '\0')) {
      diag_fatal(0x49,".\\funcs.c",0x58b);
    }
    if (g_browse_file != (char *)0x0) {
      func_emit_function_symbol();
    }
  }
  func_body_begin_emit();
  if (g_warned_fastcall_stack_check == 0) {
    pcVar4 = g_current_function->type;
    if ((pcVar4->code & 0x8f) == 0x83) {
      pcVar4 = type_skip_arrays(pcVar4->base);
    }
    if (((pcVar4->flags & 0x1f) == 3) && (g_pragma_check_stack != 0)) {
      diag_warning(1,0x7c);
      g_warned_fastcall_stack_check = 1;
    }
  }
  if (g_opt_Zg == '\0') {
    pcVar4 = g_current_function->type;
    if ((pcVar4->code & 0x8f) == 0x83) {
      pcVar4 = type_skip_arrays(pcVar4->base);
    }
    if ((pcVar4->flags & 0x1f) == 5) {
LAB_10428826:
      if ((g_current_function->flags1 & 2) != 0) {
        uVar3 = func_argument_bytes((int)g_function_parameter_scope);
        if ((g_current_function->flags5 & 0x40) == 0) {
          if (0xffff < uVar3) {
            diag_fatal(0x1fc,g_current_function);
          }
          (g_current_function->tail).fn.unk2c = (c1_u16)uVar3;
          g_current_function->flags5 = g_current_function->flags5 | 0x40;
        }
        else if (uVar3 != (g_current_function->tail).fn.unk2c) {
          diag_error(0x2c5,g_current_function);
        }
      }
    }
    else {
      pcVar4 = g_current_function->type;
      if ((pcVar4->code & 0x8f) == 0x83) {
        pcVar4 = type_skip_arrays(pcVar4->base);
      }
      if ((pcVar4->flags & 0x1f) == 3) goto LAB_10428826;
    }
    if (g_opt_Zg != '\0') goto LAB_1046e6d4;
  }
  else {
LAB_1046e6d4:
    if ((g_current_function->flags1 & 4) == 0) {
      handle = format_buffer_acquire();
      format_buffer_free(handle);
      decl_emit_prototype_text(g_current_function,g_pp_output_stream);
      format_buffer_leave();
      goto LAB_104287e3;
    }
    if (g_opt_Zg != '\0') goto LAB_104287e3;
  }
  if (g_ilstore_status != 4) {
    func_flow_state_push(g_current_function,g_pending_parameter_scope);
  }
LAB_104287e3:
  if (((g_opt_Zi != '\0') && (g_opt_Zg == '\0')) && (g_ilstore_status != 4)) {
    il_emit_pragma_or_segment_record(0x11);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  return;
}

