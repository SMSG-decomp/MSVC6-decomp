void __cdecl pp_include_push_file_fragment(void)

{
  char cVar1;
  int iVar2;
  void *return_address;
  MREFile *pMStack00000020;
  
  pMStack00000020 = (MREFile *)0x0;
  cVar1 = pdb_file_stack_top_object(g_pdb_file_stack,&stack0x00000020);
  if (cVar1 != '\0') {
    iVar2 = (*g_idb->vtbl->idb_set_tracker)(g_idb,pMStack00000020);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\p0io.c",0x187);
    }
  }
  if ((g_opt_EP_no_line == '\0') && (g_pp_output_stream != 0)) {
    pp_emit_line_directive();
  }
  g_input_ptr = g_input_ptr + -1;
  *g_input_ptr = 10;
  return;
}

