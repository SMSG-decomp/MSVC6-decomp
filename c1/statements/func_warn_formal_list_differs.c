void __cdecl
func_warn_formal_list_differs
          (c1_type **proto_types,int formal_number,int formal_link,c1_type *fn_type)

{
  c1_symbol *formal;
  int iVar1;
  int iVar2;
  byte bVar3;
  void *return_address;
  
  iVar2 = 0;
  if (formal_link != 0) {
    iVar2 = *(int *)(formal_link + 4);
  }
  formal = (c1_symbol *)(iVar2 + -8);
  bVar3 = *(byte *)(iVar2 + -8) & 0x1f;
  if (bVar3 != 0xb) {
    func_body_begin_fragment(bVar3,formal,proto_types,formal_number,iVar2,fn_type);
    return;
  }
  if ((fn_type->flags & 0x4000) == 0) {
    if (*(c1_type **)(iVar2 + 0xc) == g_type_void) {
      iVar2 = 0x1a;
    }
    else {
LAB_10619c0f:
      if (formal != (c1_symbol *)0x0) {
        while (formal_number <= ((fn_type->extra).params)->count) {
          if ((*proto_types != formal->type) &&
             (iVar1 = func_formal_types_compatible(*proto_types,formal->type), iVar1 == 0)) {
            diag_warning(1,0x1c,formal_number);
          }
          proto_types = proto_types + 1;
          formal_number = formal_number + 1;
          if (iVar2 == 0) {
LAB_10619c3a:
            formal = (c1_symbol *)0x0;
            break;
          }
          iVar2 = *(int *)(iVar2 + 4);
          while( true ) {
            if (iVar2 == 0) goto LAB_10619c3a;
            formal = (c1_symbol *)(iVar2 + -8);
            if (formal == (c1_symbol *)0x0) goto LAB_10619c3c;
            bVar3 = formal->kind & 0x1f;
            if ((bVar3 == 0xb) || (bVar3 == 0xc)) break;
            iVar2 = *(int *)(iVar2 + 4);
          }
          if (formal == (c1_symbol *)0x0) break;
        }
      }
LAB_10619c3c:
      if ((formal_number == ((fn_type->extra).params)->count + 1) &&
         ((formal == (c1_symbol *)0x0 || ((fn_type->flags & 0x8000) != 0)))) goto LAB_10619c52;
      iVar2 = 0x1d;
    }
  }
  else {
    if (*(c1_type **)(iVar2 + 0xc) == g_type_void) goto LAB_10619c0f;
    iVar2 = 0x1b;
  }
  diag_warning(1,iVar2);
LAB_10619c52:
  if (g_function_context_word == 1) {
    g_function_context_word = 5;
  }
  if ((g_function_context_word == 3) || (g_function_context_word == 5)) {
    if (g_opt_Zg != '\0') {
      iVar2 = format_buffer_acquire();
      format_buffer_free(iVar2);
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

