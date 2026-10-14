void __fastcall source_tracker_mark(c1xx_source_tracker *tracker)

{
  c1_u8 *pcVar1;
  
  pcVar1 = lex_input_base_ptr();
  (tracker->iface).mark = pcVar1;
  return;
}

