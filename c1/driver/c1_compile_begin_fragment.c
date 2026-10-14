void __cdecl c1_compile_begin_fragment(int zero)

{
  char *pcVar1;
  c1_emitter_suspend *pcVar2;
  uchar *stream;
  void *return_address;
  
  diag_fatal_file_errno(0x53,0x154,g_opt_Fi_file);
  g_pp_output_stream = _iob_exref + 0x20;
  if (g_opt_EP_no_line == (c1_u8)zero) {
    pp_emit_line_directive();
  }
  stream = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x50;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (stream == (uchar *)zero) {
    stream = (uchar *)0x0;
  }
  else {
    token_stream_init((c1_saved_token_stream *)stream,1,1);
    *(int *)(stream + 0x38) = zero;
    *(undefined ***)stream = &PTR_source_stream_next_token_10654860;
  }
  token_source_push(&g_token_position,(int)stream,7,zero,zero,&g_token_position);
  if ((g_emitter_suspend == (c1_emitter_suspend *)zero) &&
     (pcVar2 = __2_YAPAXI_Z(0xc), pcVar1 = g_browse_file,
     g_emitter_suspend = (c1_emitter_suspend *)zero, pcVar2 != (c1_emitter_suspend *)zero)) {
    pcVar2->depth = zero;
    pcVar2->active = pcVar1 != (char *)zero;
    pcVar2->saved = g_il_emitter;
    g_emitter_suspend = pcVar2;
  }
  if (g_use_pch == (c1_u8)zero) {
    pdb_open();
  }
  return;
}

