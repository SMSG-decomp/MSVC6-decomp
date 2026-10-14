void __fastcall source_tracker_mark(c1_source_tracker *tracker)

{
  char *pcVar1;
  
  pcVar1 = lex_input_base_ptr();
  tracker->mark = pcVar1;
  return;
}

