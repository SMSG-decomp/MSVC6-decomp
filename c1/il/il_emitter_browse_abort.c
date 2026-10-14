void __thiscall il_emitter_browse_abort(c1_il_emitter_browse *emitter)

{
  FILE *pFVar1;
  
  pFVar1 = g_browse_out_file;
  browse_add_record(0xe,(c1_symbol *)0x0);
  g_browse_out_file = pFVar1;
  return;
}

