void __fastcall source_tracker_reset(c1_source_tracker_iface *iface)

{
  char *pcVar1;
  
  iface->signature = 0xffffffff;
  iface->count = 0;
  pcVar1 = lex_source_input_ptr();
  iface->mark = pcVar1;
  return;
}

