void __fastcall source_tracker_accumulate(c1_source_tracker *tracker)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = lex_source_input_ptr();
  iVar3 = (int)pcVar1 - (int)tracker->mark;
  uVar2 = SigForPbCb(tracker->mark,iVar3,tracker->signature);
  tracker->signature = uVar2;
  tracker->count = tracker->count + iVar3;
  tracker->mark = pcVar1;
  return;
}

