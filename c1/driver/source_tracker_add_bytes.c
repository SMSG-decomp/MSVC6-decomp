void __thiscall source_tracker_add_bytes(c1_source_tracker *tracker,void *p,int n)

{
  uint uVar1;
  
  uVar1 = SigForPbCb(p,n,tracker->signature);
  tracker->signature = uVar1;
  return;
}

