void __cdecl func_report_formal_bytes_differ(void *parameter_scope,c1_type *fn_type)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  c1_type **proto_types;
  int iVar4;
  void *return_address;
  
  diag_error(0x2c5);
  if (parameter_scope == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)((int)parameter_scope + 4);
  }
  if (iVar3 == 0) {
    if (((fn_type->flags & 0x4000) == 0) && (((fn_type->extra).params)->count != 0)) {
      func_body_begin_fragment_3();
      return;
    }
    goto LAB_10619c52;
  }
  pbVar1 = (byte *)(iVar3 + -8);
  if (((fn_type->extra).params)->count < 1) {
    if (g_pending_function_word == 2) goto LAB_10619c52;
    if ((fn_type->flags & 0x4000) == 0) {
      if (((fn_type->flags & 0x2000) == 0) || (**(short **)(iVar3 + 0xc) != 0x80d))
      goto LAB_10619c52;
      if (g_ms_extensions == '\0') {
        diag_error(0x8e);
        goto LAB_10619c52;
      }
      iVar3 = 0x34;
    }
    else {
      iVar3 = 0x1b;
    }
  }
  else {
    proto_types = ((fn_type->extra).params)->types;
    iVar4 = 1;
    if (((*pbVar1 & 0x1f) != 0xb) && ((*pbVar1 & 0x1f) != 0xc)) {
      func_warn_formal_list_differs(proto_types,1,iVar3,fn_type);
      return;
    }
    if ((fn_type->flags & 0x4000) == 0) {
      if (*(c1_type **)(iVar3 + 0xc) == g_type_void) {
        iVar3 = 0x1a;
      }
      else {
LAB_10619c0f:
        if (pbVar1 != (byte *)0x0) {
          while (iVar4 <= ((fn_type->extra).params)->count) {
            if ((*proto_types != *(c1_type **)(pbVar1 + 0x14)) &&
               (iVar2 = func_formal_types_compatible(*proto_types,*(c1_type **)(pbVar1 + 0x14)),
               iVar2 == 0)) {
              diag_warning(1,0x1c,iVar4);
            }
            proto_types = proto_types + 1;
            iVar4 = iVar4 + 1;
            if (iVar3 == 0) {
LAB_10619c3a:
              pbVar1 = (byte *)0x0;
              break;
            }
            iVar3 = *(int *)(iVar3 + 4);
            while( true ) {
              if (iVar3 == 0) goto LAB_10619c3a;
              pbVar1 = (byte *)(iVar3 + -8);
              if (pbVar1 == (byte *)0x0) goto LAB_10619c3c;
              if (((*pbVar1 & 0x1f) == 0xb) || ((*pbVar1 & 0x1f) == 0xc)) break;
              iVar3 = *(int *)(iVar3 + 4);
            }
            if (pbVar1 == (byte *)0x0) break;
          }
        }
LAB_10619c3c:
        if ((iVar4 == ((fn_type->extra).params)->count + 1) &&
           ((pbVar1 == (byte *)0x0 || ((fn_type->flags & 0x8000) != 0)))) goto LAB_10619c52;
        iVar3 = 0x1d;
      }
    }
    else {
      if (*(c1_type **)(iVar3 + 0xc) == g_type_void) goto LAB_10619c0f;
      iVar3 = 0x1b;
    }
  }
  diag_warning(1,iVar3);
LAB_10619c52:
  if (g_function_context_word == 1) {
    g_function_context_word = 5;
  }
  if ((g_function_context_word == 3) || (g_function_context_word == 5)) {
    if (g_opt_Zg != '\0') {
      iVar3 = format_buffer_acquire();
      format_buffer_free(iVar3);
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

