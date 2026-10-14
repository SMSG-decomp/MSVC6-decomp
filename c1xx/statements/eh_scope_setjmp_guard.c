void __cdecl eh_scope_setjmp_guard(c1_flow_state *from_rec,c1_flow_state *to_rec,int mode)

{
  void *target;
  c1_flow_state *rec;
  c1_flow_state *rec_00;
  int iVar1;
  int jmpbuf [16];
  c1_node *local_8;
  
  local_8 = (c1_node *)0x0;
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar1 = _setjmp3(jmpbuf,0);
    if (iVar1 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  rec = from_rec->prev;
  rec_00 = to_rec->prev;
  target = to_rec->subject;
  if (rec != rec_00) {
    do {
      if (rec_00->depth < rec->depth) {
        if ((mode == 2) || (mode == 3)) {
          rec = stmt_jump_unwind_step(&local_8,rec,2,(int)target);
        }
        else {
          rec = stmt_jump_unwind_step(&local_8,rec,0,(int)target);
        }
      }
      else {
        if ((mode == 1) || (mode == 3)) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
        rec_00 = stmt_jump_unwind_step(&local_8,rec_00,iVar1,(int)target);
      }
    } while (rec != rec_00);
  }
  if ((local_8 == (c1_node *)0x0) && ((g_compile_flags_c8 & 0x8000) != 0)) {
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10000;
  }
  stmt_emit_merged_expression(local_8);
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

