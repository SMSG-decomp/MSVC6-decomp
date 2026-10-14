void __fastcall source_tracker_reset(c1xx_source_tracker_iface *iface)

{
  c1_u8 *pcVar1;
  
  iface->signature = 0xffffffff;
  iface->count = 0;
  pcVar1 = lex_source_input_ptr();
  iface->mark = pcVar1;
  return;
}

