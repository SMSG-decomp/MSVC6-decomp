void __fastcall source_tracker_accumulate(c1xx_source_tracker *tracker)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_u32 cVar3;
  int iVar4;
  
  pcVar2 = lex_source_input_ptr();
  pcVar1 = (tracker->iface).mark;
  iVar4 = (int)pcVar2 - (int)pcVar1;
  cVar3 = SigForPbCb(pcVar1,iVar4,(tracker->iface).signature);
  (tracker->iface).signature = cVar3;
  (tracker->iface).count = (tracker->iface).count + iVar4;
  (tracker->iface).mark = pcVar2;
  return;
}

